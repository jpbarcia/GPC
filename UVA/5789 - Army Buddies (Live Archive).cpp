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
	
	int n, q;

	Sol vec[100100];

	while(cin >> n >> q)
	{
		if(n == 0 && q == 0)
			break;
		for(int i = 0; i < n+5; i++)
		{
			vec[i].l = i-1;
			vec[i].r = i+1;
		}
		int left, right;
		for(int i = 0; i < q; i++)
		{
			cin >> left >> right;
			left--; right--;

			if(vec[left].l >= 0)
				vec[vec[left].l].r = vec[right].r;
			if(vec[right].r <= n-1)
				vec[vec[right].r].l = vec[left].l;

			if(vec[left].l < 0)
				cout << "* ";
			else
				cout << vec[left].l+1 << " ";

			if(vec[right].r > n-1)
				cout << "*\n";
			else
				cout << vec[right].r+1 << "\n";

		}
		cout << "-\n";
	}

	return 0;

}
















