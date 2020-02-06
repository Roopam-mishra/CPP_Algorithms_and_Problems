/*
   Question link: https://www.codechef.com/problems/BIGOF01
   */
************************************************************

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000000000000000000
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll stack<ll>
#define qll queue<ll>
#define mp make_pair
#define f first
#define s second
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
ll find(ll x,ll parent[])
{
    if(x==parent[x])
    return x;
    return parent[x]=find(parent[x],parent);
}
void unioni(ll x,ll y,ll parent[],ll size[])
{
    ll first=find(x,parent);
    ll second=find(y,parent);
    if(first==second)
    return;
    else
    {
        if(size[first]>size[second])
        {
            parent[second]=first;
            size[first]+=size[second];
        }
        else
        {
            parent[first]=second;
            size[second]+=size[first];
        }
    }
}
int main() 
{
	fast_io;
	Test
	{
	    ll n,i,a,b,x,y,m,q;
	    cin>>n>>m;
	    ll parent[n+1],size[n+1];
	    for(i=0;i<=n;i++)
	    {
	        parent[i]=i;
	        size[i]=1;
	    }
	    for(i=0;i<m;i++)
	    {
	        cin>>a>>b;
	        unioni(a,b,parent,size);
	    }
	    cin>>q;
	    for(i=0;i<q;i++)
	    {
	        cin>>a>>b;
	        x=find(a,parent);
	        y=find(b,parent);
	        if(x==y)
	        cout<<"Yes"<<endl;
	        else
	        cout<<"No"<<endl;
	    }
	}
	return 0;
}
