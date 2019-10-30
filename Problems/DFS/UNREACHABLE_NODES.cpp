/* question link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/dfs-3/  */
**********************************************************************************************************************************

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
    /*for(i=1;i<=n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    ll visited[n+1];
    for(i=0;i<=n;i++)
    visited[i]=0;
    cin>>h;
    visited[h]=1;
    stack<ll> s;
    s.push(h);
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
                visited[adj[x][i]]=1;
                c++;
            }
        }
        if(f==0)
        s.pop();
    }
    cout<<n-c<<endl;
    return 0;
}
