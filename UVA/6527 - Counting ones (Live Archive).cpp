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

ll dp[100];

int main()
{
	IOS
	dp[0] = 1;
	dp[1] = 2;
	//dp[i] = (1 << i) * i + 1;
	for(int i = 2; i < 63; i++)
		dp[i] = (1LL << (i-1)) * i + 1;
	
	ll a,b;
	while(cin >> a >> b)
	{
		if(a > b)
			swap(a,b);

		a--;

		ll ans = 0;
		int t1 = 0;
		for(int i = 63; i >= 0; i--)
		{
			if((b & (1LL<<i)) != 0)
			{
				ans += dp[i] + ((1LL<<(i)) * t1); 
				t1++;
			}
		}
		t1 = 0;
		for(int i = 63; i >= 0; i--)
		{
			if((a & (1LL<<i)) != 0)
			{
				ans -= (dp[i] + ((1LL<<i) * t1)); 
				t1++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
