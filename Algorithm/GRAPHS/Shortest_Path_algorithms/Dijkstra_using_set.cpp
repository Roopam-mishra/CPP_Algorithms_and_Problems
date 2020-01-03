#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1000000000
vector<ll> dijkstra(ll s,vector<vector<pair<ll, ll>>> adj)
{
    ll n=adj.size();
    vector<ll> d(n+1,INF);
    vector<ll> p(n+1,-1);
    d[s]=0;
    set<pair<ll,ll>> sett;
    sett.insert({0,s});
    while(!sett.empty())
    {
        ll v=sett.begin()->second;
        sett.erase(sett.begin());
        for(auto edge:adj[v]) 
        {
            ll to=edge.first;
            ll len=edge.second;
            if (d[v]+len<d[to]) 
            {
                sett.erase({d[to],to});
                d[to]=d[v]+len;
                p[to]=v;
                sett.insert({d[to],to});
            }
        }
    }
    vector<ll> ans;
    ll pos;
    ll mini=LLONG_MAX;
    for(ll i=0;i<d.size();i++)
    {
        if(i==s)
        continue;
        else
        if(d[i]<mini)
        {
            mini=d[i];
            pos=i;
        }
    }
    cout<<pos<<" "; //minimum distance node from s
    for(ll i=pos;i!=-1;i=p[i])
    {
        ans.push_back(i);
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans)
    {
        cout<<i<<' ';
    }
    cout<<endl;
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
