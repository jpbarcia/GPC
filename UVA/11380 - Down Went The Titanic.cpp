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
#define EPS 1e-8
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

int cant = 0;
char pal[300];
int vec[300];
int pat[300];
int n;
int npa;
bool debug = false;
int dp[1000][1000];
/*
int bt(int pos, int falt)
{
    if(pos >= npa)
        return 0;
    
    int ps = n - falt;
    falt -= pat[pos];
    if(dp[pos][falt] != -1)
        return dp[pos][falt];
    int sumat = 0;
    for(int i = 0; i < pat[pos]; i++)
        sumat += vec[i + ps];
    int ans = sumat;
    
    if(falt == 0)
        return dp[pos][falt] = ans;
    if(debug)
        printf("de sumat: %d, ps: %d\n", sumat,ps);
    
    for(int i = 0; i <= n; i++)
    {
        if(pos== npa-1)
            break;
        if(falt-i-pat[pos+1] < 0)
            break;
        
        ans = max(ans, sumat + bt(pos+1, falt - i));
    }
    if(debug)
        printf("deb pos: %d, falt: %d, ans: %d\n", pos, falt, ans);
    return  dp[pos][falt] = ans;
}
*/


int main()
{
    bool t5 = true;
    while(true)
    {
        if(t5)
            if(scanf("%s", pal) == EOF)
                break;
        cant = 0;
        memset(dp, -1, sizeof dp);
        n = strlen(pal);
        for(int i = 0; i < n; i++)
        {
            vec[i] = pal[i] - '0';
            if(debug)
                printf("vec[%d] = %d\n", i, vec[i]);
        }
        scanf("%s", pal);
        if(pal[0] -'0' < 10 && pal[0] -'0' >= 0)
        {
            t5 = false;
            printf("0\n");
            continue;
        }
        t5 = true;
        //scanf("%s", pal);
        npa = strlen(pal);
        
        for(int i = 0; i < npa; i++)
        {
            pat[i] = pal[i] - 'a' + 1;
            cant += pat[i];
            if(debug)
                printf("pat[%d] = %d\n", i, pat[i]);
        }
        /*
        int ans = 0;
        for(int i = 0; i <= n; i++)
        {
            if(n-i-pat[0] < 0)
                break;
        
            ans = max(ans, bt(0, n-i));
        }*/
        int temp = 0;
        for(int i = 0; i < npa; i++)
        {
            temp += pat[i];
            temp--;
            int t2 = 0;
            
            for(int k = 0; k < n; k++)
            {
                t2 += vec[k];
                if(k >= pat[i])
                    t2 -= vec[k-pat[i]]; 
                if(k < temp)
                    continue;
                
                
                if(i == 0)
                    dp[i][k] = max(t2, dp[i][k-1]);
                else
                    dp[i][k] = max(t2 + dp[i-1][k-pat[i]], dp[i][k-1]);
                if(debug)
                    printf("%d ", dp[i][k]);
            }
            if(debug)
                printf("\n");
            temp++;
        }
        
        
        printf("%d\n", dp[npa-1][n-1]);
        
        
    }
    
    return 0;
}

