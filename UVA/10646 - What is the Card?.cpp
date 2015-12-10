#include <bits/stdc++.h>
using namespace std;


int main()
{
	int casos;
	scanf("%d\n", &casos);
	vector<pair<char,char> > vec;
	for(int ca = 1; ca <= casos; ca++)
	{
		vec.clear();
		char a,b;
		for(int i = 0; i < 51; i++)
		{
			
			scanf("%c%c ",&a, &b);
			vec.push_back(pair<char,char>(a, b));
			//printf("%c%c - ",a,b);
		}
		scanf("%c%c\n", &a, &b);
		vec.push_back(pair<char,char>(a, b));

		int left = 26;
		int y=0;
		for(int i = 0; i < 3; i++)
		{
			char temp = vec[left].first;
			temp -= '0';
			int num = (temp > 2 && temp < 9) ? temp : 10;
			y+=num;
			//printf("y: %d - num: %d\n",y,num);
			left -= 10 - num + 1;
		}
		if(left < 0) left = 0;
		printf("Case %d: ", ca);
		if(y - 1 <= left)
		{
			printf("%c%c\n", vec[y - 1].first, vec[y - 1].second);
		}
		else
		{
			printf("%c%c\n", vec[y - 1 - left + 26].first, vec[y - 1 - left + 26].second);
		}

	}


	return 0;
}