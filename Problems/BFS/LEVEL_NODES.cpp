/* question link: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/bfs/  */
**********************************************************************************************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,a,b,i,j;
    cin>>n;
    vector<ll> adj[n+1];
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<ll> q;
    q.push(1);
    ll visited[n+1];
    for(i=0;i<=n;i++)
    visited[i]=0;
    ll level[n+1];
    level[1]=1;
    visited[1]=1;
    while(!q.empty())
    {
        ll x=q.front();
        for(i=0;i<adj[x].size();i++)
        {
            if(visited[adj[x][i]]==0)
            {
                level[adj[x][i]]=level[x]+1;
                visited[adj[x][i]]=1;
                q.push(adj[x][i]);
            }
        }
        q.pop();
    }
    ll c=0;
    ll l;
    cin>>l;
    for( i=1;i<=n;i++)
    {
        //cout<<level[i]<<" ";
        if(level[i]==l)
        c++;
    }
    cout<<c<<endl;
}
