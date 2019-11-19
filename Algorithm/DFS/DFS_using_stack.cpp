/*
Author: Roopam Mishra
*/
**************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,c,a,b,f,x,h,j;
    cin>>n>>m;
    vector<ll> adj[n+1];
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll visited[n+1];
    for(i=0;i<=n;i++)
    visited[i]=0;
    visited[1]=1;
    stack<ll> s;
    s.push(1);
    cout<<1<<" ";
    c=1;
    while(!s.empty())
    {
        x=s.top();
        f=0;
        for(i=0;i<adj[x].size();i++)
        {
            if(visited[adj[x][i]]==0)
            {
                f=1;
                s.push(adj[x][i]);
                cout<<adj[x][i]<<" ";
                visited[adj[x][i]]=1;
                c++;
                break;
            }
        }
        if(f==0)
        s.pop();
    }
    return 0;
}
