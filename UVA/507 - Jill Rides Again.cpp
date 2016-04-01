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
#define EPS 1e-9
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

double dabs(double a)
{
    return (a < 0) ? (a * -1) : a;
}

int dcomp (double a, double b) {
    if (a - b > EPS) return 1;// a > b
    else if (b - a > EPS) return -1; // a < b
    return 0; // a == b
}
//int x[6] = { 0, 0, 1, -1, 0, 0};
//int y[6] = { 1, -1, 0, 0, 0, 0};
//int z[6] = { 0, 0, 0, 0, 1, -1};
//int x[8] = { 0, 0, 1, -1, -1, 1, -1, 1};
//int y[8] = { 1, -1, 0, 0, -1, 1, 1, -1};

int main()
{
    int casos;
    
    scanf("%d", &casos);
    vi vec;
    vi aux;
    vi pos;
    for(int ca = 0; ca < casos; ca++)
    {
        int n;
        scanf("%d", &n);
        vec.clear();
        aux.clear();
        pos.clear();
        int a;
        for(int i = 0; i < n-1; i++)
        {
            scanf("%d", &a);
            vec.push_back(a);
        }
        int suma=0;
        int ans = vec[0];
        bool fix = false;
        for(int i = 0; i < n-1; i++)
        {
            if(suma == 0 && !fix)
                pos.push_back(i);
            else
                pos.push_back(pos[i-1]);
            fix = false;
            suma += vec[i];
            
            ans = max(ans,suma);
            
            
            
            if(suma < 0)
            {
                suma = 0;
                pos[i] = i;
            }
            else if(suma == 0)
            {
                fix = true;
            }
                
            aux.push_back(suma);
        }
        for(int i = 0; i < pos.size(); i++)
            printf("%d ", pos[i]);
        printf("\n%d\n", ans);
        if(ans <= 0)
        {
            printf("Route %d has no nice parts\n", ca+1);
        }
        else
        {
            int ansr=0;
            int ansl=0;
            for(int i = aux.size() - 1; i >= 0; i--)
            {
                if(aux[i] == ans)
                {
                    if(ansr-ansl <= i - pos[i])
                    {
                        ansr = i;
                        ansl = pos[i];
                    }
                }
            }
            printf("The nicest part of route %d is between stops %d and %d\n", ca+1, ansl+1, ansr+2);
            
        }
        
        
        
    }
    
    return 0;
}

