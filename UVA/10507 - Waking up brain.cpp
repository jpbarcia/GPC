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

vi pset; // pset[i]: Jefe del nodo i
vi sset; // sset[i]: Tamaño del set del nodo i
int numSets; // Número de componentes conexas
// Inicializa la estructura de datos
void init(int n) // n: Número de nodos
{
    numSets = n; // Al inicio hay N sets
    sset = vi(n, 1); // El tamaño de cada set es 1
    pset = vi(n, 0); // Asignar n casilleros al vector
    for (int i = 0; i < n; i++) // Para cada nodo i..
        pset[i] = i; // El nodo i es su propio jefe
}
// Devuelve el jefe del nodo i
int findSet(int i) // i: Nodo
{
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
// Determina si dos nodos son del mismo set
bool isSameSet(int i, int j) // i,j: Nodos
{
    return findSet(i) == findSet(j);
}
// Une los sets de los nodos i y j
void unionSet(int i, int j) // i,j: Nodos
{
    if (!isSameSet(i, j)) // Si los nodos son de diferentes sets..
    {
        numSets--; // Al unir dos sets, el total disminuye en uno
         // El jefe del nodo j se impondrá
        sset[findSet(j)] += sset[findSet(i)]; // El set j incrementa
        pset[findSet(i)] = findSet(j); // El set i tiene nuevo jefe
    }
}
// Tamaño del set al que pertenece el nodo i
int sizeOfSet(int i) // i: Nodo
{
    return sset[findSet(i)];
}

int main()
{
    char pal[100];
    int n, cone;
    bool ex[35];
    int ye[35];
    int con[35];
    int PA = 29;
    vii ari;
    while(gets(pal))
    {
        memset(ex, 0, sizeof ex);
        memset(ye, -1, sizeof ye);
        ari.clear();
        //init(30);
        
        sscanf(pal, "%d", &n);
        gets(pal);
        sscanf(pal, "%d", &cone);
        gets(pal);
        for(int i = 0; i < 3; i++)
        {
            //unionSet(PA, pal[i] - 'A');
            ye[pal[i] - 'A'] = 0;
            ex[pal[i] - 'A'] = true;
        }
        
        int a, b;
        while(gets(pal))
        {
            if(strlen(pal) == 0)
                break;
            a = pal[0] - 'A';
            b = pal[1] - 'A';
            
            ari.push_back(ii(a, b));
            ex[a] = true;
            ex[b] = true;
            
        }
        
        int sz = ari.size();
        for(int i = 1; i < 40; i++)
        {
            memset(con, 0, sizeof con);
            for(int k = 0; k < sz; k++)
            {
                ii temp = ari[k];
                if(ye[temp.first] == -1 && ye[temp.second] == -1)
                    continue;
                    
                if(ye[temp.first] == -1)
                    con[temp.first]++;
                if(ye[temp.second] == -1)
                    con[temp.second]++;
            }
            for(int k = 0; k < 30; k++)
            {
                if(ex[k] && con[k] >= 3)
                    ye[k] = i;
            }
        }
        int ans= 0;
        int helper = 0;
        for(int i = 0; i < 30; i++)
        {
            if(!ex[i])
                continue;
            if(ye[i] == -1)
            {
                ans = -1;
                break;
            }
            helper++;
            ans = max(ans, ye[i]);
        }
        if(ans == -1 || helper != n)
        {
            printf("THIS BRAIN NEVER WAKES UP\n");
        }
        else
        {
            printf("WAKE UP IN, %d, YEARS\n",ans);
        }
    }
    
    return 0;
}

