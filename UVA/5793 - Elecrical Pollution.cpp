#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define PI (2 * acos(0.0))
#define MAX 9999999999999LL;
#define MIN -9999999999999LL;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define forabi(i, a, b) for(int i = (int)(a); i >= (int)(b); i--)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> graph;

vii g[30000];
ll val[30000];
bool valf[30000];
bool vis[30000];
ii eq[30000];
void dfs(const ll &nodo, const ll &pad, const ll &con)
{
	vis[nodo] = true;
	eq[nodo].first = pad;
	eq[nodo].second = con;
	forn(i, g[nodo].size())
	{
		ll target;
		ll weight;
		tie(target, weight) = g[nodo][i];	
		if(vis[target])
		{
			if(!valf[abs(pad)] && eq[target].first == pad)
			{
				val[abs(pad)] = ((weight - con + eq[target].second)/2 - weight + con) * (pad > 0 ? -1 : 1);
				valf[abs(pad)] = true;
			}
			continue;
		}
		dfs(target, pad * -1, weight - con);
	}
}

int main()
{
	IOS
	memset(val, 0, sizeof val);
	memset(valf, 0, sizeof valf);
	memset(vis, 0, sizeof vis);
	forn(i, 20200)
	{
		eq[i].first = i;
		eq[i].second = 0;
	}
	ll m, q;
	unordered_map< ll, ll > mp;
	while(true)
	{
		cin >> m >> q;
		if(m == 0 && q == 0) break;
		ll cont = 1;
		ll x, y, a;
		mp.clear();
		//mp[0] = 0;
		queue<ll> desc;
		forn(i, m)
		{
			cin >> x >> y >> a;
			if(mp.find(x) == mp.end())
				mp[x] = cont++;
			if(mp.find(y) == mp.end())
				mp[y] = cont++;
			x = mp[x];
			y = mp[y];
			if(x == y)
			{
				val[x] = a;
				valf[x] = true;
				desc.push(x);
				continue;
			}
			g[x].emplace_back(y, a);
			g[y].emplace_back(x, a);
		}
		
		while(!desc.empty())
		{
			ll t = desc.front();
			desc.pop();
			if(vis[t]) continue;
			dfs(t, t, 0);
		}
		forab(i, 1, mp.size())
		{
			if(vis[i]) continue;
			dfs(i, i, 0);
		}
		
		//queries
		forn(i, q)
		{
			cin >> x >> y;
			if(mp.find(x) == mp.end() || mp.find(y) == mp.end())
			{
				cout << "*\n";
				continue;
			}
			x = mp[x]; y = mp[y];
			if(x == y)
			{
				if(valf[abs(eq[x].first)])
					cout << (eq[x].second + val[abs(eq[x].first)] * (eq[x].first >= 0 ? 1 : -1)) << "\n";
				else
					cout << "*\n";
				continue;
			}
			if(valf[abs(eq[x].first)] && valf[abs(eq[y].first)])
				cout << ( eq[x].second + val[abs(eq[x].first)] * (eq[x].first >= 0 ? 1 : -1) + eq[y].second + val[abs(eq[y].first)] * (eq[y].first >= 0 ? 1 : -1)) << "\n";

			else if(valf[abs(eq[x].first)] || valf[abs(eq[y].first)])
				cout << "*\n";
			else if(eq[x].first * -1 == eq[y].first)
				cout << (eq[x].second + eq[y].second) << "\n";
			else
				cout << "*\n";
		}
		cout << "-\n";

		forn(i, mp.size() + 2)
		{
			eq[i].first = i;
			eq[i].second = 0;
			g[i].clear();
			valf[i] = false;
			val[i] = 0;
			vis[i] = 0;
		}	
	}
	return 0;
}

