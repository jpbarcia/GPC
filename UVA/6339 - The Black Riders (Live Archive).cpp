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
    else if (b- a > EPS) return -1; // a < b
    return 0; // a == b
}
//int x[6] = { 0, 0, 1, -1, 0, 0};
//int y[6] = { 1, -1, 0, 0, 0, 0};
//int z[6] = { 0, 0, 0, 0, 1, -1};
//int x[8] = { 0, 0, 1, -1, -1, 1, -1, 1};
//int y[8] = { 1, -1, 0, 0, -1, 1, 1, -1};
#define MAXN 1005 // Número máximo de nodos
#define MAXE 100005 // Número máximo de aristas
#define INF 20000000
int e, n, s, t; // n: Numero de nodos, s: Nodo source, t: Nodo sink
int dis[MAXN], head[MAXN], work[MAXN];
int cap[MAXE], flow[MAXE], point[MAXE], nxt[MAXE];
void init() { e = 0; memset(head, -1, sizeof head); }
// Inserta arista v->u con capacidad c1 y u->v con capacidad c2
void add(int v, int u, int c1, int c2 = 0)
{
    point[e] = u, cap[e] = c1, flow[e] = 0, nxt[e] = head[v], head[v] = (e++);
    point[e] = v, cap[e] = c2, flow[e] = 0, nxt[e] = head[u], head[u] = (e++);
}
bool dinic_bfs() // Arma el grafo nivelado
{
    memset(dis, -1, sizeof dis); dis[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (int i = head[v]; i >= 0; i = nxt[i])
            if (flow[i] < cap[i] && dis[point[i]] < 0)
            {
                dis[point[i]] = dis[v] + 1;
                q.push(point[i]);
            }
    }
    return (dis[t] >= 0);
}
int dinic_dfs(int v, int limit) // Encuentra flujos bloqueantes
{
    if (v == t) return limit;
    for (int &i = work[v]; i >= 0; i = nxt[i])
    {
        int u = point[i], tmp;
        if (flow[i] < cap[i] && dis[u] == dis[v] + 1 &&
        (tmp = dinic_dfs(u, min(limit, cap[i] - flow[i]))) > 0)
        {
            flow[i] += tmp;
            flow[i ^ 1] -= tmp;
            return tmp;
        }
    }
    return 0;
}
int dinic_flow()
{
    int ans = 0;
    while (dinic_bfs()) // Mientras haya un grafo nivelado..
    {
        for (int i = 0; i < n; i++) work[i] = head[i];
        while (1)
        {
            int f = dinic_dfs(s, INF); // Encontrar flujo bloqueante
            if (f == 0) break; // Si no hay mas flujo, terminar
                ans += f; // Agregar flujo
        }
    }
    return ans;
}
bool debug = false;


int main()
{
    int casos; 
    scanf("%d", &casos);
    while(casos--)
    {
        int to, hu, k, c;
        scanf("%d%d%d%d", &to, &hu, &k, &c);
        int l = 0, r=10100000, m;
        int vec[110][110];
        n = to + hu + hu + 2;
        s = n-2; t = n-1;
        for(int i = 0; i < to; i++)
            for(int k = 0; k < hu; k++)
                scanf("%d", &vec[i][k]);
                
        while(l < r)
        {
            m = (l+r)/2;
            init();
            for(int i = 0; i < to; i++)
            {
                add(n-2, i, 1);
            }
            for(int i = 0; i < hu; i++)
            {
                add(to+i, to+hu+i,1);
                add(to+hu+i, n-1, 2);
            }
            for(int i = 0; i < to; i++)
                for(int k = 0; k < hu; k++)
                {
                    if(vec[i][k] + c <= m)
                    {
                        add(i, to + hu + k,1);
                        if(debug)
                            printf("deb vec[%d][%d]: %d, c: %d, m: %d\n",i,k,vec[i][k], c, m);
                    }
                    else if(vec[i][k] <= m)
                    {
                        add(i, to + k,1);
                        if(debug)
                            printf("deb vec[%d][%d]: %d, m: %d\n",i,k,vec[i][k], m);
                    }
                    
                }
            int ans = dinic_flow();
            if(debug)
                printf("deb ans: %d, m: %d\n", ans, m);
            if(ans >= k)
                r = m;
            else 
                l = m + 1;
        }
        printf("%d\n", r);
        
    }
    return 0;
}

