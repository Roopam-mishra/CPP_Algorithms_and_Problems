/* Dijkstra using Priority Queue is somewhat faster than that using sets *

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1000000000000000000
vector<ll> dijkstra(ll s,vector<vector<pair<ll, ll>>> adj)
{
    ll n=adj.size();
    vector<ll> dist(n+1,INF);
    vector<ll> prev(n+1,-1);
    dist[s]=0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, s});
    while(!pq.empty())
    {
        ll v = pq.top().second;
        ll dist_v=pq.top().first;
        pq.pop();
        if(dist_v!= dist[v])
        continue;
        for (auto edge : adj[v]) 
        {
            ll to = edge.first;
            ll len = edge.second;
            if (dist[v] + len < dist[to]) 
            {
                dist[to] = dist[v] + len;
                prev[to] = v;
                pq.push({dist[to], to});
            }
        }
    }
    vector<ll> ans;
    ll pos;
    ll mini=LLONG_MAX;
    for(ll i=0;i<dist.size();i++)
    {
        if(i==s)
        continue;
        else
        if(dist[i]<mini)
        {
            mini=dist[i];
            pos=i;
        }
    }
    cout<<pos<<" "<<endl; //minimum distance node from s
    for(ll i=pos;i!=-1;i=prev[i])
    {
        ans.push_back(i);
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans)
    {
        cout<<i<<' '; //path to the minimum distance node
    }
    cout<<endl;
    return dist;
}
int main() 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n,m,i;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+5);
    for(i=0;i<m;i++)
    {
        ll v,u,w;
        cin>>v>>u>>w;
        adj[v].push_back({u,w});
        adj[u].push_back({v,w});
    }
    for(i=1;i<=n;i++)
    {
        vector<ll> distance=dijkstra(i,adj);
        for(ll j=1;j<=n;j++)
        {
            cout<<distance[j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
