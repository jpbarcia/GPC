#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
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
    
    //int x[6] = { 0, 0, 1, -1, 0, 0};
    //int y[6] = { 1, -1, 0, 0, 0, 0};
    //int z[6] = { 0, 0, 0, 0, 1, -1};
    
    //int x[8] = { 0, 0, 1, -1, -1, 1, -1, 1};
    //int y[8] = { 1, -1, 0, 0, -1, 1, 1, -1};
    int f, c, qu;
    int vec[510][510];
    int ans = 0;
    bool debug = false;
    while(scanf("%d%d", &f, &c) != EOF && ( f || c ))
    {
        for(int i = 0; i < f; i++)
            for(int k = 0; k < c; k++)
                scanf("%d", &vec[i][k]);
        int a,b;
        scanf("%d", &qu);
        for(int ca = 0; ca < qu; ca++)
        {
            scanf("%d%d", &a, &b);
            ans = 0;
            for(int i = 0; i < f; i++)
            {
                int l,r,m;
                l = 0; r = c-1;
                while(l < r)
                {
                    m = (l + r)/2;
                    if(debug)
                        printf("deb1: m: %d, vec[%d][%d]: %d\n", m, i, m, vec[i][m]);
                    if(vec[i][m] < a)
                    {
                        l = m + 1;
                    }
                    else
                    {
                        r = m;
                    }
                }
                if(vec[i][l] > b || vec[i][l] < a)
                {
                    continue;
                }
                int mini = l;
                l = 0; r = min(f - 1 - i, c - 1 - mini);
                if(debug)
                    printf("mini: %d, l: %d, r: %d\n", mini,l,r);
                while(l < r)
                {
                    m = (l + r+1)/2;
                    if(debug)
                        printf("deb2: m: %d, vec[%d][%d]: %d\n", m, i+m, m+mini, vec[i+m][mini+m]);
                    if(vec[i+m][mini+m] > b)
                    {
                        r = m - 1;
                    }
                    else
                    {
                        l = m;
                    }
                }
                ans = max(ans, l+1);
                if(debug)
                    printf("debug i: %d, mini: %d, l: %d\n",i, mini, l);
            }
            
            printf("%d\n", ans);
            
        }
        printf("-\n");
        
    }
    
    
    return 0;
}

