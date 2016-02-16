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

vector<ll> dv, dv1;



int main()
{
    //int x[6] = { 0, 0, 1, -1, 0, 0};
    //int y[6] = { 1, -1, 0, 0, 0, 0};
    //int z[6] = { 0, 0, 0, 0, 1, -1};
    //int x[8] = { 0, 0, 1, -1, -1, 1, -1, 1};
    //int y[8] = { 1, -1, 0, 0, -1, 1, 1, -1};
    dv1 = vector<ll>(1000001, 0);
    dv = vector<ll>(100001, 0);
    for(int i = 1; i < 1000000; i++)
    {
        //dv[i] += dv[i-1];
        for(int k = i; k < 1000000; k+=i)
            dv1[k]++;
    }
    dv[0] = 1;
    for(int i = 1; i <= 100000; i++)
    {
        dv[i] = dv[i-1] + dv1[dv[i-1]];
    }
    int casos;
    scanf("%d", &casos);
    for(int ca = 0; ca < casos; ca++)
    {
        int a,b;
        scanf("%d %d", &a, &b);
        if(b < a)
            swap(a, b);
        int posa = int(lower_bound(dv.begin(), dv.end(), a) - dv.begin());
        int posb = int(upper_bound(dv.begin(), dv.end(), b) - dv.begin());
        posb--;
        printf("Case %d: ", ca+1);
        printf("%d\n", max(0,posb-posa+1));
        
    }
    
    return 0;
}

