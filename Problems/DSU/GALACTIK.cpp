/* question link: https://www.codechef.com/problems/GALACTIK  */
****************************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll nn,m,parent[100002],size[100002],cost[100002];
void makeset()
{
    for(ll i=0;i<=nn;i++)
    {
        parent[i]=i;
        size[i]=1;
    }
}
ll find(ll i)
{
    if(i==parent[i]) return i;
	return parent[i] = find(parent[i]);
}
void unioni(ll x,ll y)
{
    ll first=find(x);
    ll second=find(y);
    if(first!=second)
    {
        if(size[first]<size[second])
        {
            parent[first]=parent[second];
            size[second]+=size[first];
            size[first]=0;
        }
        else
        {
            parent[second]=parent[first];
            size[first]+=size[second];
            size[second]=0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,t,c,sum,flag=0;
    cin>>nn>>m;
    ll a,b;
    makeset();
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        --a;
        --b;
        unioni(a,b);
    }
    ll maxi=LLONG_MIN;
    for(i=0;i<nn;i++)
    {
        cin>>cost[i];
        if(cost[i]<0)
        cost[i]=LLONG_MAX;
    }
    for(i=0;i<nn;++i)
	  {
		ll p = find(i);
		cost[p]=min(cost[p],cost[i]);
	  }
    c=0;
    sum=0;
    ll mini=LLONG_MAX;
    vector<ll> v;
    for(i=0;i<nn;i++)
    {
        if(parent[i]==i)
        {
            c++;
            mini=min(cost[i],mini);
			if(cost[i]==LLONG_MAX)
			{
				flag=1;
			}
			sum+=cost[i];
        }
    }
    if(c==1)
    {
        cout<<0<<endl;
    }
    else 
    {
        if(flag==1)
		{
			cout<<"-1";
		}
		else
		{
			cout<<mini*(c-1) + sum-mini;
		}
    }
    return 0;
}
