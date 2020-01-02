/* Question link: https://www.spoj.com/problems/PPATH/  */
**********************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[100001]={0};
vector<ll> sieve(vector<ll> b)
{
    ll i,j;
    a[0]=1;
    a[1]=1;
    for(i=2;i<=100;i++)
    {
        if(a[i]==0)
        {
            for(j=i;j<=10000;j+=i)
            {
                a[j]=1;
            }
        }
    }
    for(i=0;i<=100000;i++)
    {
        if(a[i]==0 && i>1000 && i<10000)
        b.push_back(i);
    }
    return b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> b;
    b=sieve(b);
    ll i,c,j,aa,bb,query,x;
    vector<ll> adj[10010];
    //cout<<b.size()<<endl;
    //for(i=0;i<b.size();i++)
    //cout<<b[i]<<" ";
    //cout<<endl;
    for(i=0;i<b.size();i++)
    {
        for(j=0;j<=b.size();j++)
        {
            //cout<<(b[i]%10)<<" "<<(b[j]%10)<<endl;
            c=0;
            if((b[i]%10)!=(b[j]%10))
            c++;
            if(((b[i]/10)%10)!=((b[j]/10)%10))
            c++;
            if((((b[i]/100)%10))!=((b[j]/100)%10))
            c++;
            if(((b[i]/1000)%10)!=((b[j]/1000)%10))
            c++;
            //cout<<c<<" ";
            if(c==1)
            {
                adj[b[i]].push_back(b[j]);
                adj[b[j]].push_back(b[i]);
            }
        }
    }
    cin>>query;
    while(query--)
    {
        cin>>aa>>bb;
        ll visited[10001];
        ll level[10001];
        for(i=0;i<=10001;i++)
        {
            visited[i]=0;
            level[i]=-1;
        }
        queue<ll> q;
        q.push(aa);
        visited[aa]=1;
        level[aa]=0;
        while(!q.empty())
        {
            x=q.front();
            for(i=0;i<adj[x].size();i++)
            {
                if(visited[adj[x][i]]==0)
                {
                    visited[adj[x][i]]=1;
                    q.push(adj[x][i]);
                    level[adj[x][i]]=level[x]+1;
                }
            }
            q.pop();
        }
        if(level[bb]==-1)
        cout<<"Impossible"<<endl;
        else
        cout<<level[bb]<<endl;
    }
} 
