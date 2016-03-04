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


int main()
{
    int n, d;
    int din[30];
    
    while(scanf("%d%d", &n, &d) != EOF && (n || d))
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &din[i]);
        
        int a,b,c;
        for(int i = 0; i < d; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            a--;b--;
            din[a] -= c;
            din[b] += c;
        }
        
        bool fai = false;
        for(int i = 0; i < n; i++)
            if(din[i] < 0)
            {
                fai = true;
                break;
            }
        
        if(fai)
            printf("N\n");
        else
            printf("S\n");
        
    }
    
    return 0;
}

