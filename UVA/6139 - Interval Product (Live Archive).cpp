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
struct Valo { int p, n, z; Valo(){ p = n = z = 0;} Valo(int dp, int dn, int dz) : p(dp), n(dn), z(dz) {}};
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

const int MAX = 1e6; // Max number of elements
Valo t[MAX*2]; // Segment Tree (Root is t[1])
int n; // Number of elements of the array
void build() // Builds the segment tree
{
	for(int i = n - 1; i > 0; i--) // For each non-leaf node..
	{
		t[i].p = t[i << 1].p + t[i << 1 | 1].p;
		t[i].n = t[i << 1].n + t[i << 1 | 1].n;
		t[i].z = t[i << 1].z + t[i << 1 | 1].z;
	}
}
void update(int i, int val) // Sets array[i] to val (i in range [0, N-1])
{
	t[i+n].p = t[i+n].n = t[i+n].z = 0;
	if(val > 0)
		t[i+n].p = 1;
	else if (val == 0)
		t[i+n].z = 1;
	else
		t[i+n].n = 1;
	for(t[i += n]; i >>= 1; ) // Update leaf node, then go up..
	{
		t[i].p = t[i << 1].p + t[i << 1 | 1].p;
		t[i].n = t[i << 1].n + t[i << 1 | 1].n;
		t[i].z = t[i << 1].z + t[i << 1 | 1].z;
	}
}
int query(int l, int r) // Range Sum Query in range [l,r]
{
	Valo ans;
	for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1)
	{
		if( l & 1 )
		{
			ans.z = ans.z + t[l].z; // For left pointer, odd nodes matter
			ans.n = ans.n + t[l].n; // For left pointer, odd nodes matter
			ans.p = ans.p + t[l].p; // For left pointer, odd nodes matter
		}
		if(!(r & 1))
		{
			ans.z = t[r].z + ans.z; // For right pointer, even nodes matter
			ans.n = t[r].n + ans.n; // For right pointer, even nodes matter
			ans.p = t[r].p + ans.p; // For right pointer, even nodes matter
		}
	}
	return ans.z > 0 ? 0 : (ans.n % 2 == 1 ? -1 : 1);
}

int main()
{
	IOS

	int q;
	while(cin >> n >> q)
	{
		int t1,t2;
		for(int i = 0; i < n; i++)
		{
			cin >> t1;
			t[i+n].p = t[i+n].n = t[i+n].z = 0;
			if(t1 > 0)
				t[i+n].p = 1;
			else if (t1 == 0)
				t[i+n].z = 1;
			else
				t[i+n].n = 1;
		}
		build();
		string s1;

		for(int i = 0; i < q; i++)
		{
			// cout << " P , N , Z \n";
			// for(int k = 0; k < n; k++)
			// {
			// 	for(int m = 0; m < (1<<k); m++)
			// 	{
			// 		cout << t[(1<<k)+m].p << ", " << t[(1<<k)+m].n << ", " << t[(1<<k)+m].z << " | ";
			// 	}
			// 	cout << "\n";
			// }
			cin >> s1 >> t1 >> t2;
			if(s1[0] == 'C')
			{
				update(t1-1, t2);
			}
			else
			{
				int ans = query(t1-1,t2-1);
				cout << (ans > 0 ? '+' : (ans == 0 ? '0' : '-'));
			}
		}
		cout << "\n";
	}

	return 0;
}
















