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
double absd(double a)
{
    return (a < 0) ? a * -1 : a;
}

int main()
{
    //int x[6] = { 0, 0, 1, -1, 0, 0};
    //int y[6] = { 1, -1, 0, 0, 0, 0};
    //int z[6] = { 0, 0, 0, 0, 1, -1};
    //int x[8] = { 0, 0, 1, -1, -1, 1, -1, 1};
    //int y[8] = { 1, -1, 0, 0, -1, 1, 1, -1};
    
    double l, r, m;
    int casos;
    int ap, n;
    double vec[100010];
    bool debug = true;
    scanf("%d", &casos);
    while(casos--)
    {
        scanf("%d %d", &ap, &n);
        for(int i= 0; i < n; i++)
        {
            scanf("%lf", &vec[i]);
            //printf("%lf ", vec[i]);
        }
        sort(vec, vec + n);
        l = 0; r = vec[n-1] - vec[0] + 1;
        //if(debug)
            //printf("deb ap: %d\n", ap);
        while(true)
        {
            m = (l + r)/2;
            double dist = m * 2;
            int cont = 0;
            
            for(int i = 0; i < n; i++)
            {
                double disttemp = vec[i] + dist;
                cont++;
                if(cont > ap)
                    break;
                for(int k = i+1; k < n; k++)
                {
                    if(vec[k] > disttemp)
                    {
                        //if(debug)
                            //printf("deb2: k: %d\n", k);
                        i = k-1;
                        break;
                    }
                    if(k == n-1)
                        i = n-1;
                }
                //if(debug)
                    //printf("deb1 i: %d, disttemp: %lf\n", i, disttemp);
            }
            if(debug)
                //printf("deb l: %lf, r: %lf, m: %lf, cont: %d\n", l, r, m,cont);
            if(cont > ap)
            {
                l = m;
            }
            else
            {
                r = m;
            }
            if(absd(l-r) < 0.01)
                break;
        }
        printf("%.1lf\n", m);
    }
    
    return 0;
}

