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

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    vii vec;
    vector<iii> vt,ans;
    int a,b;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        vec.push_back(ii(a,b));
        vt.push_back(iii(a,ii(b*-1, i)));
    }
    sort(vt.begin(), vt.end());
    ll nodCon = 1;
    ll arDis = 0;
    ll arCon = 0;
    //comprobacion
    int sz = vt.size();
    bool mal = false;
    int aux = 2;
    a = 2;
    b = 3;
    for(int i = 0; (i < sz) && !mal; i++)
    {
        iii temp = vt[i];
        if(temp.second.first != 0)
        {
            nodCon++;
            arDis = ((nodCon-1)*nodCon)/2;
            ans.push_back(iii(temp.second.second,ii( 1, aux)));
            aux++;
        }
        else
        {
            ans.push_back(iii(temp.second.second,ii( a, b)));
            a++;
            if(a == b)
            {
                b++;
                a = 2;
            }
        }
        arCon++;
        
        if(arDis < arCon)
            mal = true;
    }
    if(mal)
    {   
        printf("-1");
    }
    else
    {
        sort(ans.begin(), ans.end());
        sz = ans.size();
        for(int i = 0; i < sz; i++)
        {
            printf("%d %d\n", ans[i].second.first, ans[i].second.second);
        }
    }
    
    return 0;
}

