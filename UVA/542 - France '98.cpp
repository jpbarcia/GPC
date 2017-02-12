#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define PI (2 * acos(0.0))
#define MAX 9999999999999LL;
#define MIN -9999999999999LL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

string country[16];
double prob[16][16];

double dp[5][16];

int main()
{
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < 16; i++)
        dp[0][i] = 1;
    
    for(int i = 0; i < 16; i++)
        cin >> country[i];
    
    for(int i = 0; i < 16; i++)
        for(int k = 0; k < 16; k++)
            cin >> prob[i][k];
    
    
    for(int i = 1; i*i <= 16; i++) // Cada Juego de Match's
        for(int k = 0; k < 16; k++) // Cada Equipo
            for(int m = (k/(1 << i))*(1<<i); m < ((k + (1 << i))/(1 << i))*(1<<i); m++)
                if(m >= (k/(1 << (i-1)))*(1<<(i-1)) && m < ((k + (1 << (i-1)))/(1 << (i-1)))*(1<<(i-1))) continue;
                else dp[i][k] += dp[i-1][m] * prob[k][m]/100 * dp[i-1][k];
    
    for(int i = 0; i < 16; i++)
    {
        cout << country[i];
        for(int k = country[i].size(); k < 10; k++)
            cout << " ";
        cout << " p=";
        printf("%.2lf", dp[4][i]*100);
        cout << "%" << endl;
    }
    
    return 0;
}
