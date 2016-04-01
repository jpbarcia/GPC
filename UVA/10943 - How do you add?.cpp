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
int n,t,p;
ll dp[110][110];
ll rec(int pos, int suma)
{
    if(suma < 0)
        return 0;
    if(pos == 1)
    {
        if(suma >= 0)
            return 1;
        else
            return 0;

    }
    if(dp[pos][suma] != -1)
        return dp[pos][suma];
        
    if(pos > n)
        return 0;
        
    
    ll ans = 0;
    for(int i = p; i <= t; i++)
    {
        ans += rec(pos-1, suma-i);
    }
    return dp[pos][suma] = ans%1000000;
}


int main()
{
   
    
    while(scanf("%d%d", &t, &n) != EOF && (n || t))
    {
        memset(dp, -1, sizeof dp);
        p=0;
        ll ans2 = rec(n,t);
        printf("%lld\n", ans2);
    }
    
    return 0;
}

