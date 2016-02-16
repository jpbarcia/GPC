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
    int vec[1010];
    bool debug = false;
    int v, n;
    while(scanf("%d%d", &v, &n) != EOF)
    {
        int l = 0, r = 0, m;
        for(int i = 0; i < v; i++)
        {
            scanf("%d", &vec[i]);
            r += vec[i];
        }
        
        while(l < r)
        {
            m = l + ((r - l ) / 2);
            if(debug)
                printf("deb m: %d, l: %d, r: %d\n", m, l, r);
            int cont = 0;
            int cant = 0;
            for(int i = 0; i < v; i++)
            {
                cont++;
                if(cont > n)
                    break;
                if(vec[i] > m)
                {
                    cont = n + 1;
                    break;
                }
                cant = 0;
                for(int k = i; k < v; k++)
                {
                    cant += vec[k];
                    if(cant > m)
                    {
                        i = k - 1;
                        break;
                    }
                    if(k == v - 1)
                        i = k;
                    
                }
            }
            if(cont > n)
                l = m+1;
            else
                r = m;
            
        }
        printf("%d\n", l);
        
    }
    
    
    return 0;
}

