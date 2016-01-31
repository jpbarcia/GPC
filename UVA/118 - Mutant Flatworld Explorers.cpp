#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<string> vstr;
#define IOS std::ios_base::sync_with_stdio(false)
//funciones
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

void split(char *input, char *tokens, vector<string> &v)
{
    v.clear();
    char *p;
    p = strtok(input, tokens);
    while(p != NULL)
    {
        v.push_back(p);
        p = strtok(NULL, tokens);
    }
}

int main()
{   
    //N S E O
    int x[4] = { 0, 0, 1, -1};
    int y[4] = { 1, -1, 0, 0};
    int dir;
    int maxx, maxy;
    scanf("%d %d\n", &maxx, &maxy);
    int posx, posy;
    int tposx, tposy;
    char cam[1000];
    bool perd[100][100] = { 0 }; 
    char temp;
    while(scanf("%d %d %c\n", &posx, &posy, &temp) != EOF)
    {
        if(temp =='N') dir = 0;
        if(temp =='S') dir = 1;
        if(temp =='E') dir = 2;
        if(temp =='W') dir = 3;
        
        gets(cam);
        int sz = strlen(cam);
        bool lost = false;
        for(int i = 0; i < sz; i++)
        {
            tposx = posx;
            tposy = posy;
            if(cam[i] == 'F')
            {
                tposx = posx+x[dir];
                tposy = posy+y[dir];
            }
            if(cam[i] == 'L')
            {
                if(dir == 0)    dir = 3;
                else if(dir == 1)    dir = 2;
                else if(dir == 2)    dir = 0;
                else if(dir == 3)    dir = 1;
            }
            if(cam[i] == 'R')
            {
                if(dir == 0)    dir = 2;
                else if(dir == 1)    dir = 3;
                else if(dir == 2)    dir = 1;
                else if(dir == 3)    dir = 0;
            }
            if(tposx < 0 || tposx > maxx || tposy > maxy || tposy < 0)
            {
                if(perd[posx][posy])
                    continue;
                
                perd[posx][posy] = true;
                lost = true;
                break;
            }
            else
            {
                posx = tposx;
                posy = tposy;
            }
        }
        printf("%d %d", posx, posy);
        if(dir == 0) temp = 'N';
        if(dir == 1) temp = 'S';
        if(dir == 2) temp = 'E';
        if(dir == 3) temp = 'W';
        printf(" %c",temp);
        if(lost)
            printf(" LOST\n");
        else printf("\n");
    }
    
    return 0;
}

