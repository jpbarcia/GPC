#include <bits/stdc++.h>

using namespace std;

int n,m,x,y;
bool vec[1010][1010];   

int dp[3][1010];
int dp2[1010][1010][2];

long long bt(int pos, int acum, bool ind)
{
    if(pos >= m)
    {
        if(acum <= x)
            return 9999999;
        return 0;
    }
    if(acum > y)    return 9999999;
    //printf("%d - %d - %d\n",pos, (ind)?1:0, dp[(ind)?1:0][pos]);
    if(dp2[pos][acum][ind] != -1)
        return dp2[pos][acum][ind];
    if(acum < x)
    {
        return dp2[pos][acum][ind] = dp[(ind)?1:0][pos] + bt(pos+1, acum+1, ind);
    }
    return dp2[pos][acum][ind] = dp[(ind)?1:0][pos] + min(bt(pos+1, acum+1, ind),bt(pos+1, 1, !ind));
}

int main()
{


    scanf("%d %d %d %d\n", &n,&m,&x,&y);
    memset(dp2, -1, sizeof dp2);
    //int contador=0;   
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char temp;
            scanf("%c",&temp);
            vec[i][j] = (temp == '.') ? true : false;
        }
        scanf("\n");
    }


    for(int j = 0; j < m; j++)
    {
        int contador=0;
        for(int i = 0; i < n; i++)
        {
            contador += (vec[i][j]) ? 1 : 0;
        }
        scanf("\n");
        //printf("%d: %d - %d\n",j, contador, n - contador);
        dp[1][j] = contador;
        dp[0][j] = n - contador;
    }
    
    printf("%lld", min(bt(0,1,true),bt(0,1,false)));

    return 0;
}
