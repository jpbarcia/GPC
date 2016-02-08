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


int f,c;
int cx[4];//checkpoint[*x-y*][*1-2-3*];
int cy[4];
bool vs[10][10];
int cp[4];
int x[8] = { 0, 0, 1, -1, -1, 1, -1, 1};
int y[8] = { 1, -1, 0, 0, -1, 1, 1, -1};
bool debug = false;
int cont;
queue<ii> q;
bool pue(const int &px,const int &py,const int &pos)
{
    if(debug)
        printf("pue: px: %d, py: %d, w: %d\n", px,py,pos);
    for(int i = 0; i < 4; i++)
    {
        if(pos == cp[i])
        {
            if(cx[i] != px || cy[i] != py)
                return false;
        }
        else
        {
            if(cx[i] == px && cy[i] == py)
                return false;
        }
        if(pos < cp[i])
        {
            int manh = abs(cx[i] - px) + abs(cy[i] - py);
            if( pos + manh > cp[i] )
                return false;
        }
    }
    bool vis[10][10];
    ii t;
    memset(vis, 0, sizeof vis);
    
    int cont1 = 0, cont2 = 0;
    vis[py][px] = true;
    for(int i = 0; i < f; i++)
    {
        for(int k = 0; k < c; k++)
        {
            vis[i][k] = vs[i][k];
            if(!vis[i][k])
            {
                cont1++;
                if(q.empty())
                {
                    vis[i][k] = true;
                    cont2++;
                    q.push(ii(i,k));
                }
            }
            
        }
    }
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        
        for(int m = 0; m < 4; m++)
        {
            int asd = t.first + y[m];
            int bsd = t.second + x[m];
            if(asd < 0 || bsd < 0 || asd >= f || bsd >= c)
                continue;
            if(vis[asd][bsd])
                continue;
            vis[asd][bsd] = true;
            cont2++;
            q.push(ii(asd,bsd));
        }
        
    }
    if(debug)
        printf("%d == %d return\n",cont1, cont2);
    return cont1 == cont2;
    
    //return true;

}


void dfs(const int &tfi,const int &tse, const int &w)
{
    
    if(debug)
    {
        printf("debug: w: %d, x: %d, y: %d\n", w, tse, tfi);
    }
    
    if(!pue(tse, tfi, w))
        return;
    vs[tfi][tse] = true;
    
    if(w==cp[3])
    {
        cont++;
        vs[tfi][tse] = false;
        return;
    }
    int as,bs;
    int asw, bsw;
    int conttemp = 0;
    int itemp = 0;
    for(int m = 0; m < 4; m++)
    {
        as = tfi + y[m];
        bs = tse + x[m];
        int veci = 0;
        if(as < 0 || bs < 0 || as >= f || bs >= c)
            continue;
        if(vs[as][bs])
            continue;
        for(int o = 0; o < 4; o++)
        {
            asw = as + y[m];
            bsw = bs + x[m];
            int veci = 0;
            if(asw < 0 || bsw < 0 || asw >= f || bsw >= c)
                continue;
            if(!vs[asw][bsw])
                veci++;
        }
        if(veci == 1)
        {
            conttemp++;
            
            itemp = m;
        }
    }
    if(conttemp > 1)
    {
        vs[tfi][tse] = false;
        return;
    }
    if(conttemp == 1)
    {
        as = tfi + y[itemp];
        bs = tse + x[itemp];
        dfs(as,bs,w+1);
        vs[tfi][tse] = false;
        return;
    }
    for(int m = 0; m < 4; m++)
    {
        as = tfi + y[m];
        bs = tse + x[m];
        if(as < 0 || bs < 0 || as >= f || bs >= c)
            continue;
        
        if(!vs[as][bs])
        {
            dfs(as,bs, w+1);
        }
    }
    
    vs[tfi][tse] = false;
}

int main()
{
    
    //int x[6] = { 0, 0, 1, -1, 0, 0};
    //int y[6] = { 1, -1, 0, 0, 0, 0};
    //int z[6] = { 0, 0, 0, 0, 1, -1};
    int caso = 1;
    while(scanf("%d%d", &f, &c) != EOF && (f || c))
    {
        for(int i = 0; i < 3; i++)
        {
            scanf("%d%d", &cy[i], &cx[i]);
            cy[i] = (f-1) - cy[i];
        }
        memset(vs, 0, sizeof vs);
        cp[0] = (f*c)/4;
        cp[1] = (f*c)/2;
        cp[2] = ((f * c) * 3.0)/4;
        cp[3] = f*c;
        cx[3] = 1;
        cy[3] = f-1;
        if(debug)
        {
            for(int i = 0; i < 4; i++)
            {
                printf("cp[%d]: %d, cx[%d]: %d, cy[%d]: %d\n",i,cp[i],i,cx[i],i, cy[i]);
            }
        }
        cont = 0;


        dfs(f-1, 0, 1);
        
        printf("Case %d: %d\n", caso++, cont);

        
    }
    
    return 0;
}

