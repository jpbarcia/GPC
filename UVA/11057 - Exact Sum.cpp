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
    vi vec;
    int n;
    int m;
    bool debug = false;
    while(scanf("%d", &n) != EOF)
    {
        int a;
        vec.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            vec.push_back(a);
        }
        scanf("%d", &m);
        vec.push_back(1<<30);
        sort(vec.begin(), vec.end());
        
        int l = int(lower_bound(vec.begin(), vec.end(), (m)/2) - vec.begin());
        if(vec[l] == m/2)
            l++;
        int r=0;
        while(true)
        {
            if(debug)
            {
                printf("l: %d, r: %d\n", l, r);
                if(l < 0 || r > n)
             
                    break;
            }
            int temp =  m - vec[l];
            r = int(lower_bound(vec.begin(), vec.end(), temp) - vec.begin());
            if(temp == vec[r])
                break;
            else 
                l++;
            
        }
        if(debug)
            printf("---\n");
        printf("Peter should buy books whose prices are %d and %d.\n\n", vec[r], vec[l]);
    }
    
    
    return 0;
}

