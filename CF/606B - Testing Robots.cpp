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
	bool mat[600][600];
	memset(mat, false, sizeof mat);
	int x,y,x0,y0;
	scanf("%d %d %d %d\n", &y, &x, &y0, &x0);
	x0--;
	y0--;
	char proc[100100];
	gets(proc);
	int len = strlen(proc);

	mat[y0][x0] = true;
	printf("1");
	for(int i = 0; i < len; i++)
	{
		char temp = proc[i];
		if(temp == 'U')
			y0= (y0 > 0) ? y0 - 1 : 0;
		else if(temp == 'D')
			y0= (y0 < y - 1) ? y0 + 1 : y - 1;
		else if(temp == 'R')
			x0= (x0 < x - 1) ? x0 + 1 : x - 1;
		else if(temp == 'L')
			x0= (x0 > 0) ? x0 - 1 : 0;
		
		if(i != len - 1)
		{
			if(mat[y0][x0])
				printf(" 0");
			else
				printf(" 1");
			mat[y0][x0] = true;
		}
		else
		{
			int cont = 0;
			for(int i = 0 ; i < y; i++)
				for(int j = 0; j < x; j++)
					cont += mat[i][j] ? 0 : 1;
			printf(" %d", cont);
			
		}
	}


	return 0;
}