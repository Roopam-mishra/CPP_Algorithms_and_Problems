/*  Question link: https://www.spoj.com/problems/SHPATH/  */
*************************************************************

#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
typedef long long int ll;
vector<ll> Dijkstra(ll s,vector<vector<pair<ll,ll>>> adj)
{
    ll n=adj.size();
    vector<ll> dist(n+1,INF);
    vector<ll> prev(n+1,0);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty())
    {
        ll v=pq.top().second;
        ll dist_v=pq.top().first;
        pq.pop();
        if(dist_v!=dist[v])
        continue;
        for(ll i=0;i<adj[v].size();i++)
        {
            ll to=adj[v][i].first;
            ll len=adj[v][i].second;
            if(dist[v]+len<dist[to])
            {
                dist[to]=dist[v]+len;
                prev[to]=v;
                pq.push({dist[to],to});
            }
        }
    }
    return dist;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,j,t,b,w,q;
    string str1,str2,str;
    cin>>t;
    while(t--)
    {
        cin>>n;
        unordered_map<string,ll> mp;
        vector<vector<pair<ll,ll>>> adj(n+1);
        for(i=1;i<=n;i++)
        {
            cin>>str;
            mp[str]=i;
            cin>>m;
            for(j=0;j<m;j++)
            {
                cin>>b>>w;
                adj[i].push_back({b,w});
                adj[b].push_back({i,w});
            }
        }
        cin>>q;
        while(q--)
        {
            vector<ll> dist;
            cin>>str1>>str2;
            dist=Dijkstra(mp[str1],adj);
            cout<<dist[mp[str2]]<<endl;
        }
    }
}
