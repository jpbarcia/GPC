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

vvi g;
bool vis[1010];
int main()
{   
    int n;
    int a, b;
    while(scanf("%d", &n) != EOF && n)
    {
        g=vvi(n+1);
        
        while(scanf("%d", &a) != EOF && a)
        {
            while(scanf("%d", &b) != EOF && b)
            {
                g[a].push_back(b);
                //g[a].push_back(a);
            }
        }
        scanf("%d", &a);
        queue<int> q;
        for(int i = 0; i < a; i++)
        {
            scanf("%d", &b);
            memset(vis, 0, sizeof vis);
            //bfs
            int sz = g[b].size();
            for(int j = 0; j < sz; j++)
                q.push(g[b][j]);
            while(!q.empty())
            {
                int t = q.front();
                q.pop();
                if(!vis[t])
                {
                    vis[t] = true;
                    int sz = g[t].size();
                    for(int j = 0; j < sz; j++)
                        q.push(g[t][j]);
                }
            }
            int cont = 0;
            for(int j = 1; j < n+1; j++)
                if(!vis[j])
                    cont++;
                    
            printf("%d", cont);
            for(int j = 1; j < n+1; j++)
                if(!vis[j])
                    printf(" %d", j);
            printf("\n");
            
        }
    }
    
    return 0;
}

