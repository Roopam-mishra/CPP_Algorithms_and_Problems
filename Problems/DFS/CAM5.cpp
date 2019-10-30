/* question link : https://www.spoj.com/problems/CAM5/   */
************************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,t,i,j,x,c,d,a,b,f,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<ll> adj[n+1];
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            adj[a+1].push_back(b+1);
            adj[b+1].push_back(a+1);
        }
        ll visited[n+1];
        for(i=0;i<=n;i++)
        visited[i]=0;
        c=0;
        x=1;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                stack<ll> s;
                s.push(i);
                d=1;
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
                            d++;
                        }
                    }
                    if(f==0)
                    s.pop();
                }
                x=(x*(d)%mod)%mod;
                c=(c+1)%mod;
            }
        }
        cout<<c<<endl;
    }
    return 0;
} 
