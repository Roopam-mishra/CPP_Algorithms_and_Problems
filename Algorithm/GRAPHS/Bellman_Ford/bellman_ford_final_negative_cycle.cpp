#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 100000000
struct edge
{
    ll u,v,cost;
};
void Bellman_Ford(struct edge e[],ll n,ll m,ll v)
{
    vector<ll> dist(n+1,INF);
    d[v]=0;
    vector<ll> prev(n+1,- 1);
    ll x;
    for(ll i=0;i<n;i++)
    {
        x=-1;
        for(ll j=0;j<m;j++)
        {
            if(dist[e[j].u]<INF)
            {
                if(dist[e[j].v]>dist[e[j].u]+e[j].cost)
                {
                    dist[e[j].v]=dist[e[j].u]+e[j].cost;
                    prev[e[j].v] = e[j].u;
                    x=e[j].v;
                }
            }
        }
    }
    // to find a path from v to the vertex which has the shortest path from v
    /*vector<ll> ans;
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
    cout<<endl;*/
    if(x==-1)
    cout<<"No negative cycle from "<<v<<endl;
    else
    {
        ll y=x;
        for(ll i=0;i<n;i++)
        y=prev[y];
        vector<ll> path;
        for(ll current=y;;current=prev[current])
        {
            path.push_back(current);
            if(current==y && path.size()>1)
            break;
        }
        reverse(path.begin(),path.end());
        cout<<"Negative Cycle : ";
        for(ll j=0;j<path.size();j++)
        cout<<path[j]<<" ";
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i;
    cin>>n>>m;
    struct edge e[m+1];
    for(i=0;i<m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].cost;
    }
    for(i=1;i<=n;i++)
    {
        Bellman_Ford(e,n,m,i);
    }
}
