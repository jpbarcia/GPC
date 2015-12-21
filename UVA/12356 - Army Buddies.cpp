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

int l[100110], r[100110];
void init()
{
	for(int i = 0; i < 100100; i++)
	{
		l[i] = i-1;
		r[i] = i+1;
	}
}


int main()
{
	int s,b;
	while(scanf("%d %d", &s, &b) != EOF && (s || b))
	{
		init();
		
		for(int i = 0; i < b; i++)
		{
			int t1,t2;
			scanf("%d %d", &t1, &t2);
			l[r[t2]] = l[t1];
			r[l[t1]] = r[t2];
			
			if(l[t1] <= 0)
				printf("* ");
			else
				printf("%d ", l[t1]);
			
			if(r[t2] >= s+1)
				printf("*");
			else
				printf("%d", r[t2]);
			
			
			
			printf("\n");
		}
		printf("-\n");
	
	
	}
	
	return 0;
}