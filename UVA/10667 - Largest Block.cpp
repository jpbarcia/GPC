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
typedef vector<bool> vb;
typedef vector<string> vstr;
#define IOS std::ios_base::sync_with_stdio(false)
#define EPS 1e-07
#define PI (2*acos(0.0))
//struct point { double x, y; };
//struct line { double a, b, c; }; // ax + by + c = 0 
//funciones
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

void split(char *input, char *tokens, vector<string> &v)
{
	v.clear();
	char *p;
	p = strtok(input, tokens);
	while(p != NULL)
	{
		v.push_back(p);
		p = strtok(NULL, tokens);
	}
}

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
	int s;
	int casos;
	int vec[110][110];
	scanf("%d", &casos);
	while(casos--)
	{
		memset(vec, 0, sizeof vec);
		
		int n;
		scanf("%d %d", &s, &n);
		
		for(int i = 0; i < n; i++)
		{
			int r1,r2,c1,c2;
			scanf("%d%d%d%d", &r1,&c1, &r2,&c2);
			r1--;c1--;r2--;c2--;
			for(int k = c1; k<=c2; k++)
			{
				for(int m = r1; m <= r2; m++)
					vec[k][m] = 1;
			}
		}
				
		int aux[110];
		
		int ans = 0;
		int ant = 0;
		for(int i = 0; i < s; i++)
		{
			memset(aux, 0, sizeof aux);
			for(int k = i; k < s; k++)
			{
				int suma = 0;
				for(int m = 0; m < s; m++)
				{
					if(vec[k][m] == 1)
						aux[m] = 0;
					else
						aux[m]++;
				}
				ant = -1;
				for(int m = 0; m < s; m++)
				{
					if(aux[m] != ant)
					{
						suma = 0;
						ant = aux[m];
					}
					
					suma += aux[m];
					
					ans = max(ans, suma);
					
				}
			}
		}
		printf("%d\n", ans);
		
	}
	
	
	return 0;
}

