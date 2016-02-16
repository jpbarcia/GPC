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

double dabs(double a)
{
    return (a < 0) ? (a * -1) : a;
}
int main()
{
    //int x[6] = { 0, 0, 1, -1, 0, 0};
    //int y[6] = { 1, -1, 0, 0, 0, 0};
    //int z[6] = { 0, 0, 0, 0, 1, -1};
    //int x[8] = { 0, 0, 1, -1, -1, 1, -1, 1};
    //int y[8] = { 1, -1, 0, 0, -1, 1, 1, -1};
    bool debug = false;
    int n;
    if(debug)
        printf("%d\n", (1 << 20));
    int vec[15];
    while(scanf("%d", &n) != EOF && n)
    {
        for(int i = 0; i <= n; i++)
            scanf("%d", &vec[i]);
        
        double l, r, m;
        // max possible 10k
        l = -0.99999; r = 50000;
        
        while( dabs(r-l) > 0.0001)
        {
            m = (l + r) / 2;
            
            double ans = vec[0];
            double den = 1;
            for(int i = 1; i <= n; i++)
            {
                den *= (1+m);
                ans += (vec[i] / den);
            }
            
            if(debug)
                printf("deb ans: %lf, m: %lf, l: %lf, r: %lf\n", ans, m, l, r);
            if(ans < 0)
                r = m;
            else
                l = m;
            
        }
        printf("%.2lf\n", l);
        
    }
    
    return 0;
}

