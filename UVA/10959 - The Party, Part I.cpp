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
    //int x[8] = { 0, 0, 1, -1, 1, 1, -1, -1};
    //int y[8] = { 1, -1, 0, 0, -1, 1, 1, -1};
    //int x[6] = { 0, 0, 1, -1, 0, 0};
    //int y[6] = { 1, -1, 0, 0, 0, 0};
    //int z[6] = { 0, 0, 0, 0, 1, -1};
    
    int casos;
    bool first = true;
    vvi g;
    vi vs;
    scanf("%d", &casos);
    
    while(casos--)
    {
        if(!first)
            printf("\n");
        else 
            first = false;
        int n, m;
        int a, b;
        scanf("%d%d", &n, &m);
        g = vvi(n);
        vs = vi(n, 0);
        
        for(int i = 0; i < m ;i++)
        {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        queue<int> q;
        q.push(0);
        vs[0] = 1;
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            
            //vs[t] = true;
            int sz = g[t].size();
            for(int i = 0; i < sz; i++)
            {
                int as = g[t][i];
                if(vs[as] == 0)
                {
                    vs[as] = vs[t] + 1;
                    q.push(as);
                }
            }
        }
        for(int i = 1; i < n; i++)
        {
            printf("%d\n", vs[i] - 1);
        }
    }
    
    return 0;
}

