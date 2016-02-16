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


#define M 128
#define N 128

bool graph[M][N];
bool seen[N];
int matchL[M], matchR[N];
int n, m;

bool bpm( int u )
{
    for( int v = 0; v < n; v++ ) if( graph[u][v] )
    {
        if( seen[v] ) continue;
        seen[v] = true;

        if( matchR[v] < 0 || bpm( matchR[v] ) )
        {
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int mbm()
{
    // Read input and populate graph[][]
    // Set m, n

    memset( matchL, -1, sizeof( matchL ) );
    memset( matchR, -1, sizeof( matchR ) );
    int cnt = 0;
    for( int i = 0; i < m; i++ )
    {
        memset( seen, 0, sizeof( seen ) );
        if( bpm( i ) ) cnt++;
    }

    // cnt contains the number of happy pigeons
    // matchL[i] contains the hole of pigeon i or -1 if pigeon i is unhappy
    // matchR[j] contains the pigeon in hole j or -1 if hole j is empty

    return cnt;
}
vi match;
vb visit;
vvi g;
int augmenting(int v)
{
    if(visit[v])
        return 0;
        
    visit[v] = true;
    for(int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if(match[u] == -1 || augmenting(match[u]))
        {
            match[u] = v;
            return 1;
        }
    }
}
int MBM(int left, int tot)
{
    int ans = 0;
    match = vi(tot, -1);
    for(int i = 0; i < left; i++)
    {
        visit = vb(left, false);
        ans += augmenting(i);
    }
    return ans;
}
int comparar (double a, double b) {
    if (a - b > EPS) return 1;// a > b
    else if (b- a > EPS) return -1; // b > a
    return 0; // iguales
}


int main()
{
    //int x[6] = { 0, 0, 1, -1, 0, 0};
    //int y[6] = { 1, -1, 0, 0, 0, 0};
    //int z[6] = { 0, 0, 0, 0, 1, -1};
    //int x[8] = { 0, 0, 1, -1, -1, 1, -1, 1};
    //int y[8] = { 1, -1, 0, 0, -1, 1, 1, -1};
    int casos;
    double vx[200];
    double vy[200];
    double dist[200][200];
    scanf("%d", &casos);
    int k;
    bool debug = false;
    for(int ca = 0; ca < casos; ca++)
    {
        
        scanf("%d%d%d", &m, &n, &k);
        g = vvi(n + m);
        //n-> topos, m-> huecos, k -> muertes posibles
        for(int i = 0; i < m; i++)//de 0 a n-1 son de los topos
            scanf("%lf%lf", &vx[i], &vy[i]);//coordenadas
            
        for(int i = 0; i < n; i++)//a partir de n a m-1 son de los huecos
            scanf("%lf%lf", &vx[i+n], &vy[i+n]);
        
        printf("Case #%d:\n", ca+1);
        if((m == 0 && n == 0) || (m == k) || m == 0)//si pasa en cualquier caso
        {
            printf("0.000\n\n", ca+1);
            continue;
        }
        if(m-k > n)//si no pasa nunca
        {
            printf("Too bad.\n\n", ca+1);
            continue;
        }
        double l = 0.0;
        double r = 999999999.0;
        double mid;
        for(int i = 0; i < m; i++)
        {
            for(int k = 0; k < n; k++)
            {
                dist[i][k] = sqrt((vx[i] - vx[k+m])*(vx[i] - vx[k+m]) + (vy[i] - vy[k+m])*(vy[i] - vy[k+m]));
                if(debug)
                    printf("dist[%d][%d]: %lf\n", i, k, dist[i][k]);
            }
        }
        for(int asd = 0; asd < 100; asd++)
        {
            mid = (l+r)/2.0;
            //g = vvi(n+m);
            memset(graph, false, sizeof graph);
            for(int i = 0; i < m; i++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(comparar(dist[i][k],  mid) != 1)
                    {
                        graph[i][k] = true;
                        //graph[k+n][i] = true;
                        
                        //g[i].push_back(k+n);
                        //g[k+n].push_back(i);
                    }
                }
            }
            int ans;
            ans = mbm();//max bipar matching
            if(debug)
                printf("deb ans: %d\n", ans);
            if(ans < (n - k))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
            
        }
        printf("%.3lf\n\n", r);
        
            
    }
    
    return 0;
}

