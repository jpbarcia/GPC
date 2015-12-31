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

//SEGMENT TREE
const int MAX = 1e5 + 100;
int s[MAX*2];

void init(int n)
{
    
    for(int i = n-1; i > 0; i--)
        s[i] = max(s[i << 1],s[(i << 1) | 1]);
}
int query(int l, int r, int n)
{
    int ans = 0;
    for(l = l+n, r=r+n; l <= r; l = (l+1) >> 1, r = (r-1) >> 1)
    {
        if(l & 1)
            ans = max(ans, s[l]);
        if(!(r &1))
            ans = max(ans, s[r]);
    }
    return ans;
}

int main()
{
    int n, m;
    
    int left[MAX];
    int right[MAX];
    while( scanf("%d", &n) != EOF  && n)
    {
        scanf("%d", &m);
        
        int t1, t2;
        int cont = 0;
        memset(s, 0, sizeof s);
        //lectura
        scanf("%d", &t1);
        cont++;
        left[0] = 0;
        for(int i = 1; i < n; i++)
        {
            scanf("%d", &t2);
            if(t1 == t2)
            {
                cont++;
                left[i] = left[i-1];
            }
            else
            {
                for(int j = i-cont; j < i; j++)
                {
                    right[j] = i-1;
                    //SEGMENT TREE
                    s[n+j]=cont;
                }
                left[i] = i;
                cont = 1;
            }
            t1=t2;
        }
        for(int j = n-cont; j < n; j++)
        {
            right[j] = n-1;
            //SEGMENT TREE
            s[n+j]=cont;
        }
        //algoritmo
        init(n);

        //printf("\n");
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &t1, &t2);
            t1--;
            t2--;
            int ans =0;
            int temp;
            /// LEFT SIDE
            temp = s[n+t1] - ( t1 - left[t1] ) - (  right[t1] > t2 ? (right[t1] - t2) : 0 );
            //printf("temp1: %d  ", temp);
            ans = max(temp,ans);
            //RIGHT SIDE
            temp = s[n+t2] - ( right[t2] - t2 ) - (  left[t2] < t1 ? ( t1 - left[t2] ) : 0 );
            ans = max(temp,ans);
            //printf("temp2: %d  ", temp);
            //MIDDLE
            ans = max(ans, query(right[t1]+1, left[t2]-1,n));
            //printf("ans: %d\n", ans);
            printf("%d\n", ans);
        }
        
        
    }
    
	
	return 0;
}