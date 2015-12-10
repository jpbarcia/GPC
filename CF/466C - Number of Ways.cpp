#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
ll a[1000000];


int main()
{
    int n;
    scanf("%d", &n);
    scanf("%lld", &a[0]);
    for(int i = 1; i < n; i++)
    {
        scanf("%lld", &a[i]);
        a[i]+=a[i-1];
    }
    if(a[n-1]%3 != 0 || n < 3)
    {
        printf("0");
        return 0;
    }
    ll primero = a[n-1]/3;
    ll segundo = primero*2;
    vii dp;
    dp.push_back(ii(a[0]== primero ? 1 : 0,a[0]== segundo ? 1 : 0));
    for(int i = 1; i < n-1; i++)
    {
        int tempa =0, tempb=0;
        if(primero == a[i])
            tempa++;
        if(segundo== a[i])
            tempb++;
        dp.push_back(ii(dp[i-1].first + tempa,dp[i-1].second + tempb));
    }
    
    int sizet = dp.size();
    int ultimodp = sizet-1;
    int ult = -1;
    ll ans = 0;
    //printf("%d - %d -", sizet, dp[0].second);
    for(int i = 0; i < sizet; i++)
    {
        //printf("%lld ", a[i]);
        if(a[i] == primero)
        {
            //ult= dp[i].first;
            
            ans+=( dp[ultimodp].second -((primero==0) ? dp[i].second : ((i-1>=0) ? dp[i-1].second : 0)) );
            //printf("ANS: %d - %d = %lld\n", dp[ultimodp].second , dp[i].second ,ans);
        }
    }
    printf("%lld", ans);
    return 0;
}
