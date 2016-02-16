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

double p,q,r,s,t,u;
double absd(double a)
{
    return (a < 0) ? a * -1 : a;
}
double func(double m)
{
    return ((p * exp(-1*m)) + (q * sin(m)) + (r * cos(m)) + (s * tan(m)) + (t * m * m) + u);
}
double func2(double a, double b, double c, double d, double e, double f, double m)
{
    return (a * exp(-1*m) + b * sin(m) + c * cos(m) + d * tan(m) + e * m * m + f);
}
int main()
{
    
    //int x[6] = { 0, 0, 1, -1, 0, 0};
    //int y[6] = { 1, -1, 0, 0, 0, 0};
    //int z[6] = { 0, 0, 0, 0, 1, -1};
    
    //int x[8] = { 0, 0, 1, -1, -1, 1, -1, 1};
    //int y[8] = { 1, -1, 0, 0, -1, 1, 1, -1};
    //p ∗ e−x + q ∗ sin(x) + r ∗ cos(x) + s ∗ tan(x) + t ∗ x2 + u = 0
    //: p, q, r, s, t, u
    bool debug = false;
    while(scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u) != EOF)
    {
        double l,r,m;
        l = 0; r = 1;
        bool mayorAMenor = false;
        if(func(0) > func(1))
            mayorAMenor = true;
        if(debug)
        {
            printf("MODO DEBUG\n");
            if(mayorAMenor)
                printf("De mayor a menor\n");
            else
                printf("De menor a mayor\n");
        }
        for(int i = 0; i < 30; i++)
        {
            m = (l + r)/2;
            
            double ans;
            ans = func(m);// (p * exp(m) + q * sin(m) + r * cos(m) + s * tan(m) + t * m * m + u);
            if(mayorAMenor)
            {
                if(ans > 0)
                    l = m;
                else
                    r = m;
            }
            else
            {
                if(ans < 0)
                    l = m;
                else
                    r = m;
            }
            if(debug)
            {
                printf("ans: %lf, m: %lf, l: %lf, r: %lf\n", ans, m, l, r);
            }
        }
        if(debug)
        {
            printf("func(%lf) = %lf\n", 0.7554, func2(1, -1, 1, -1, -1,1, 0.7554));
        }
        if(absd(func(m)) < 0.00004)
        {
            printf("%.4lf\n", m);
        }
        else
        {
            printf("No solution\n");
        }
        
    }
    
    return 0;
}

