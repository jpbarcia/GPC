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
struct Sol { int l, r; Sol(){} Sol(int dl, int dr) : l(dl), r(dr) {}};
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


int main()
{
	IOS
	
	ll dp[100100];
	ll dp2[100100];
	int vec[100100];
	ll vec2[100100];
	int fil, col;

	while(cin >> fil >> col)
	{
		if(fil == 0 || col == 0)
			break;

		for(int i = 0; i < fil; i++)
		{
			for(int k = 0; k < col; k++)
				cin >> vec[k];

			dp[0] = vec[0];
			dp[1] = vec[1];
			dp[2] = vec[0] + vec[2];
			for(int k = 3; k < col; k++)
				dp[k] = max(dp[k-2], dp[k-3]) + vec[k];
			if(col == 1)
				vec2[i] = dp[0];
			else
				vec2[i] = max(dp[col-1], dp[col-2]);
		}

		dp2[0] = vec2[0];
		dp2[1] = vec2[1];
		dp2[2] = vec2[0] + vec2[2];
		for(int i = 3; i < fil; i++)
			dp2[i] = max(dp2[i-2], dp2[i-3]) + vec2[i];

		ll ans = 0;
		if(fil == 1)
			ans = dp2[0];
		else
			ans = max(dp2[fil-1], dp2[fil-2]);
		cout << ans << "\n";
	}

	return 0;

}
















