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
    bool debug = false;
    int f,c;
    vvi g;
    int vx[5100];
    //double pe[1010][1010];
    int vy[5100];
    bool vs[5100];
    int las;
    while(scanf("%d %d", &f, &las) != EOF && (f || las))
    {
        c = f;
        memset(vx, 0, sizeof vx);
        memset(vy, 0, sizeof vy);
        memset(vs, 0, sizeof vs);
        for(int i = 0; i < las; i++)
            scanf("%d%d", &vx[i], &vy[i]);

            
        double l, m, r;
        l = f; r = 0;
        queue<int> q;
        for(int z = 0; z < 26; z++)
        {
            m = (l + r)/2;
            if(debug)
                printf("debug- l: %lf, r: %lf, m: %lf\n",l,r, m);
            g = vvi(las+2);
            double dist;
            for(int i = 0; i < las; i++)
            {
                for(int k = 0; k < las; k++)
                {
                    if(i == k)
                        continue;
                    dist = sqrt((vx[i] - vx[k])*(vx[i] - vx[k]) + (vy[i] - vy[k])*(vy[i] - vy[k]));
                    if(dist < m)
                    {
                        g[i].push_back(k);
                        g[k].push_back(i);
                    }
                }
                dist = sqrt((vy[i])*(vy[i]));
                if(dist < m)
                {
                    g[i].push_back(las);
                    g[las].push_back(i);
                }
                dist = sqrt((vy[i] - f)*(vy[i] - f));
                if(dist < m)
                {
                    g[i].push_back(las+1);
                    g[las+1].push_back(i);
                }
            }
            
            
            q.push(las+1);
            memset(vs, 0, sizeof vs);
            int t;
            while(!q.empty())
            {
                t = q.front();
                q.pop();
                if( t == las)
                {
                    l = m;
                    while(!q.empty())
                    {
                        q.pop();
                    }
                    break;
                }
                int sz = g[t].size();
                for(int i = 0; i < sz; i++)
                {
                    int as = g[t][i];
                    if(vs[as])
                        continue;
                    vs[as] = true;
                    q.push(as);
                }
            }
            if(t != las)
                r = m;
            
        }
        printf("%.3lf\n", m);
        
        
    }
    
    return 0;
}

