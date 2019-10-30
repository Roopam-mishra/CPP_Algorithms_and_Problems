/* question link: https://www.spoj.com/problems/PT07Y/ */
*********************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,c,a,b,x,y,f,j;
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
    queue<ll> q;
    c=0;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            stack<ll> s;
            s.push(i);
            while(!s.empty())
            {
                y=s.top();
                f=0;
                for(j=0;j<adj[y].size();j++)
                {
                    if(visited[adj[y][j]]==0)
                    {
                        f=1;
                        s.push(adj[y][j]);
                        visited[adj[y][j]]=1;
                    }
                }
                if(f==0)
                s.pop();
            }
            c=(c+1);
        }
    }
    //cout<<c<<endl;
    if(n==m+1 && c==1)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    return 0;
} 
