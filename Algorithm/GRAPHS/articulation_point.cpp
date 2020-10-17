#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define MOD 1000000007
#define INF 1000000000000000000
#define endll "\n"
#define pb push_back
#define forn(i,n) for(i=0;i<n;i++)
#define forab(i,a,b) for(i=a;i<=b;i++)
#define vpll vector<pair<ll,ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define ff first
#define ss second
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll timer = 0;
vll visited, tin, low;
vll arti;
void dfs(ll u, ll par, vll adj[])
{
	visited[u] = 1;
	tin[u] = low[u] = timer++;
	ll children = 0;
	for (auto v : adj[u])
	{
		if (v != par)
		{
			if (visited[v])
				low[u] = min(low[u], tin[v]);
			else
			{
				dfs(v, u, adj);
				low[u] = min(low[u], low[v]);
				if (low[v] >= tin[u] && par != -1)
					arti.pb(u);
				++children;
			}
		}
	}
	if (par == -1 && children > 1)
		arti.pb(u);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, m, i, u, v;
	cin >> n >> m;
	vll adj[n + 1];
	for (i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	visited.resize(n + 1, 0);
	tin.resize(n + 1, -1);
	low.resize(n + 1, -1);
	for (i = 1; i <= n; i++)
	{
		if (!visited[i])
			dfs(i, -1, adj);
	}
	for (i = 0; i < arti.size(); i++)
		cout << arti[i] << endl;
	return 0;
}
