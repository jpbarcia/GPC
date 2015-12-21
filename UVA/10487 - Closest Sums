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

//funciones
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

int main()
{
	int caso=0;
	int n=0, m=0;
	int vec[1100];
	while(scanf("%d", &n) != EOF && n)
	{
		//printf("%d\n", n);
		caso++;
		printf("Case %d:\n", caso);
		for(int i = 0; i < n; i++)
			scanf("%d", &vec[i]);
		
		vi ans;
		
		int cont=0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n ; j++)
				if(i!=j)
				{
					ans.push_back( vec[i]+vec[j] );
					cont++;
				}	
	
		
		
		sort(ans.begin(), ans.end());
		
		scanf("%d", &m);

		for(int i = 0; i < m; i++)
		{
			int tem=0;
			
			scanf("%d", &tem);
			int lpos = int(lower_bound(ans.begin(), ans.end(), tem) - ans.begin());
			int res=0;
			if(lpos == 0)
				res = ans[lpos];
			else if(lpos >= ans.size())
			{
				res = ans[lpos-1];
			}
			else
			{
				res = (ans[lpos] - tem < abs(ans[lpos-1] - tem)) ? ans[lpos] : ans[lpos-1];
			}
			
			printf("Closest sum to %d is %d.\n", tem, res);
			
		}
	}
	return 0;
}