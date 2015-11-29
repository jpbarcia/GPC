#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>

using namespace std;


typedef vector<int> vi;
typedef map<int, vi> mivi;



int main()
{
	//freopen("in.txt", "r", stdin);

	mivi oc;

	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		oc.clear();
		for (int i = 0; i < n; i++)
		{
			int temp;
			scanf("%d", &temp);
			oc[temp].push_back(i + 1);

		}

		for (int i = 0; i < k; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);

			if (oc.find(b) != oc.end())
			{
				if (oc[b].size() >= a)
				{
					printf("%d\n", oc[b][a - 1]);
				}
				else
					printf("0\n");
			}
			else
				printf("0\n");

		}
	}
	return 0;
}