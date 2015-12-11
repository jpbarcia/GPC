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
	int n;
	scanf("%d", &n);

	int pos[100100];
	int vec[100100];
	int dp[100100];
	

	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		vec[i] = temp;
		dp[temp] = 1;
		pos[temp] = i;
		//printf("%d ", temp);
	}
	//printf("\n");
	pos[0] = 9999999;
	int mayor = 0;
	for(int i = 0; i < n; i++)
	{

		
		dp[vec[i]] += ( pos[vec[i]] > pos[vec[i]-1] ) ? dp[vec[i] - 1] : 0; 
		//printf("vec[i]: %d - dp: %d\n",vec[i], dp[vec[i]]);
		mayor = max(mayor, dp[vec[i]]);
	}
	printf("%d", n - mayor);

	return 0;
}