#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
//typedef vector<bool> vb;
typedef vector<string> vstr;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define EPS 1e-09
#define PI (2*acos(0.0))
#define INF 99999999
//struct Point { int x, y; Point(){} Point(int dx, int dy) : x(dx), y(dy) {}};

//funciones
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
// a > b si comparar(a, b) > 0
// a < b si comparar(a, b) < 0
// a == b si comparar (a, b) == 0

double dabs(double a)
{
	return (a < 0) ? (a * -1) : a;
}

int dcomp (double a, double b) {
	if (a - b > EPS) return 1;// a > b
	else if (b - a > EPS) return -1; // a < b
	return 0; // a == b
}
int vec[1010][1010];
ll dp[1010][1010];
ll dp2[1010][1010];
int n;

int main()
{
	IOS

	
	while(true)
	{
		cin >> n;
		if(n == 0)
			break;
		
		//memset(dp, 0, sizeof dp);
		//memset(dp2, -1, sizeof dp2);
		for(int i = 0; i < n; i++)
			for(int k = 0; k <= i; k++)
				cin >> vec[i-k][k];

		dp[0][0] = vec[0][0];
		
		for(int i = 0; i < n; i++)
		{
			dp[i][0] = vec[i][0];
			dp2[i][0] = -1LL;
			for(int k = 1; k < n - i; k++)
			{
				dp[i][k] = vec[i][k] + dp[i][k-1];
				dp2[i][k] = -1LL;
			}
		}

		ll ans = 0;
		dp2[n-1][0] = dp[n-1][0];
		//ans = max(ans, dp2[n-1][0]);
		for(int i = n-2; i >= 0; i--)
		{
			ll t1 = 0;

			for(int k = 0; k < n-i-1; k++)
			{
				t1 = max(t1, dp2[i+1][k]);
				dp2[i][k] = t1 + dp[i][k];
			}
			dp2[i][n-i-1] = t1 + dp[i][n-i-1];
		}

		
		for(int i = 0; i < n; i++)
			ans = max(ans, dp2[0][i]);

		//debug();
		cout << ans << "\n";
		
	}

	return 0;

}
















