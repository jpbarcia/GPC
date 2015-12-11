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

int main()
{
	ll a,b;

	while(scanf("%lld %lld", &a, &b) != EOF)
	{
		printf("%lld\n", abs(a-b));
	}
	return 0;
}