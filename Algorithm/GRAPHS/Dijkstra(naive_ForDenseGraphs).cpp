/* 
Roopam Mishra
RESOURCES: https://cp-algorithms.com/graph/dijkstra.html
           https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
           */
*****************************************************************************************

/*
Naive-Algorithm
Used for Dense Graphs
Complexity: O(n*n+m)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1000000000
vector<ll> dijkstra(ll s,vector<vector<pair<ll, ll>>> adj)
{
    ll n=adj.size();
    vector<ll> d(n,INF);
    vector<ll> p(n,-1);
    vector<bool> u(n, false);
    d[s]=0;
    for(ll i=0;i<n;i++)
    {
        ll min_distance=LLONG_MAX;
        ll min_distance_unvisited_vertex=-1;
        for(ll j=0;j<n;j++)
        {
            if((d[j]<min_distance) && !u[j])
            {
                min_distance_unvisited_vertex=j;
                min_distance=d[j];
            }
        }
        if(d[min_distance_unvisited_vertex]==INF)
        break;
        u[min_distance_unvisited_vertex]=true;
        for(auto edge: adj[min_distance_unvisited_vertex])
        {
            ll to=edge.first;
            ll len=edge.second;
            if((d[min_distance_unvisited_vertex]+len)<d[to])
            {
                d[to]=d[min_distance_unvisited_vertex]+len;
                p[to]=min_distance_unvisited_vertex;
            }
        }
    }
    return d;
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
}
