#include <bits/stdc++.h>

using namespace std;


typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair< int, ii > iii;
typedef vector< ii > vii;
typedef long long ll;
typedef vector< vii > grafo;

vi primos;
vi dp(10000011, 0);

int n;
//vi vec(10000011,0);
void calcPrimos()
{
    
    int tamanoCriba = 10000010;
    bitset<10000015> criba;
    criba.set();
    criba[0] = criba[1] = 0;
    int ultimo = 0;
    for (ll i = 2; i < tamanoCriba; i++)
    {
        int temp = ultimo;

        if (criba[i])
        {
            
            for (ll j = i; j < tamanoCriba; j += i)
            {
                temp+=dp[j];
                criba[j] = 0;
            }
            ultimo = temp;
        }
        dp[i]= temp;
    }
}

int main()
{

    
    scanf("%d", &n);
    int tempp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tempp);
        dp[tempp]++;
    }
    
    calcPrimos();

    int q;
    ll l, r;
    scanf("%d", &q);
    while (q--)
    {
        int der = 0, izq = 0;
        scanf("%lld%lld", &l, &r);

        if (l > 10000001)
        {
            printf("0\n");
            continue;
        }
        if (r > 10000001)
        {
            r = 10000001;
        }
        printf("%d\n", dp[r] - dp[l - 1]);
    }

    return 0;
}
