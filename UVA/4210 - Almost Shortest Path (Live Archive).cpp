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
    int n, m;
    int ini, fin;
    vvii g;
    int vs[510];
    bool vsd[510][510];
    int p[510];
    bool debug = false;
    while(scanf("%d%d", &n, &m) != EOF && (n || m))
    {
        scanf("%d%d", &ini, &fin);
        if(debug)
            printf("ini: %d, fin: %d\n", ini,fin);
        g = vvii(n);
        int a, b, w;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &a, &b, &w);
            g[a].push_back(ii(w, b));
        }
        int sp = 1 << 30;
        priority_queue<ii> q;
        ii t;
        bool enc = true;

        memset(vsd, 0, sizeof vsd);
        while(true)
        {
            for(int i = 0; i < n; i++)
            {
                vs[i] = -1;
                p[i] = i;
            }
            q.push(ii(0,ini));
            int mini = 1 << 30;
            vs[ini] = 0;
            while(!q.empty())
            {
                t = q.top();
                q.pop();
                t.first = abs(t.first);
                if(t.second == fin)
                {
                    mini = min(mini, t.first);
                    int temp = fin;
                    while(temp != p[temp])
                    {
                        vsd[p[temp]][temp] = true;
                        temp = p[temp];
                    }
                }
                int sz = g[t.second].size();
                for(int i = 0; i < sz; i++)
                {
                    int as = g[t.second][i].second;
                    int ws = g[t.second][i].first;
                    if(vsd[t.second][as]) 
                        continue;
                    if(vs[as] == -1 || ws + t.first <= vs[as])
                    {
                        if(debug)
                            printf("debug desde: %d hacia %d\n", t.second, as);
                        p[as] = t.second;
                        vs[as] = ws + t.first;
                        q.push(ii(-1 * (ws + t.first),as));
                    }
                }
            }
            if(debug)
            {
                printf("deb mini: %d, sp: %d\n", mini, sp);
            }
            if(vs[fin] == -1)
            {
                enc = false;
                break;
            }
            if(sp == (1 << 30) || sp == mini)
            {
                sp = mini;
                /*
                    reconstruir camino
                */
                
                continue;
            }
            sp = mini;
            break;    
            
        }
        if(enc)
            printf("%d\n", sp);
        else 
            printf("-1\n");
    }
    
    return 0;
}

