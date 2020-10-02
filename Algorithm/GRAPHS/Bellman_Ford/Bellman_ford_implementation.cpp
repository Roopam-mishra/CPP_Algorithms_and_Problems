#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 100000000
struct edge
{
    ll u,v,cost;
};
vector<ll> Bellman_Ford(struct edge e[],ll n,ll m,ll v,ll t)
{
    vector<ll> dist(n+1,INF);
    dist[v]=0;
    vector<ll> prev(n+1,- 1);
    for(;;)
    {
        bool any=false;
        for(ll j=0;j<m;j++)
        {
            if(dist[e[j].u]<INF)
            {
                if(dist[e[j].v]>dist[e[j].u]+e[j].cost)
                {
                    dist[e[j].v]=dist[e[j].u]+e[j].cost;
                    prev[e[j].v] = e[j].u;
                    any=true;
                }
            }
        }
        if(!any)
        break;
    }
    // to find a path from v to the vertex which has the shortest path from v
    /*vector<ll> ans;
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
    cout<<pos<<" "; //minimum distance node from s
    for(ll i=pos;i!=-1;i=prev[i])
    {
        ans.push_back(i);
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans)
    {
        cout<<i<<' ';
    }
    cout<<endl;*/
    if(dist[t]==INF)
    cout<<"No path from "<<v<<" to "<<t<<endl;
    else
    {
        vector<ll> ans;
        for(ll i=t;i!=-1;i=prev[i])
        {
            ans.push_back(i);
        }
        reverse(ans.begin(),ans.end());
        for(auto i:ans)
        {
            cout<<i<<' ';
        }
        cout<<endl;
    }
    return dist;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i;
    cin>>n>>m;
    struct edge e[2*m+1];
    for(i=0;i<2*m;i+=2)
    {
        cin>>e[i].u>>e[i].v>>e[i].cost;
        e[i+1].u=e[i].v;
        e[i+1].v=e[i].u;
        e[i+1].cost=e[i].cost;
    }
    for(i=1;i<=n;i++)
    {
        vector<ll> distance=Bellman_Ford(e,n,2*m,i,5);
        for(ll j=1;j<distance.size();j++)
        cout<<distance[j]<<" ";
        cout<<endl;
    }
}
