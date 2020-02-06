/* 
    Question link: https://www.codechef.com/problems/JABO
    */
**********************************************************    
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
ll parent[1250005];
ll b[1250005];
vector<ll> numbers(string s)
{
    ll i,num=0;
    vector<ll> v;
    for(i=1;i<s.length();i+=2)
    {
        if(s[i]>='A' && s[i]<='Z')
        num+=(s[i]-'A')*52;
        else
        num+=(s[i]-'a'+26)*52;
        if(s[i+1]>='A' && s[i+1]<='Z')
        num+=(s[i+1]-'A');
        else
        num+=(s[i+1]-'a'+26);
        v.push_back(num);
        num=0;
    }
    return v;
}
void makeset(ll r,ll c)
{
    ll i;
    for(i=0;i<=r*c;i++)
    {
        b[i]=0;
        parent[i]=i;
    }
}
ll find(ll x)
{
    if(x==parent[x])
    return x;
    return parent[x]=find(parent[x]);
}
void unioni(ll x,ll y)
{
    ll first,second;
    first=find(x);
    second=find(y);
    if(first==second)
    return;
    if(first!=second)
    {
        if(b[first]>=b[second])
        {
            parent[second]=first;
            b[first]+=b[second];
        }
        else
        {
            parent[first]=second;
            b[second]+=b[first];
        }
    }
}
int main() 
{
	fast_io;
	ll n,r,c,i,x,y,j;
    string s;
	cin>>n>>r>>c;
	//ll b[r*c+10],parent[r*c+10];
	makeset(r,c);
	for(i=0;i<n;i++)
	{
	    cin>>s;
	    vector<ll> v=numbers(s);
	    /*cout<<s[0]<<" ";
	    for(j=0;j<v.size();j++)
	    cout<<v[j]<<" ";
	    cout<<endl;*/
	    if(s[0]=='W')
	    {
	        unioni((((v[1]-1)/5)*c+(v[0]-1)),(((v[3]-1)/5)*c+(v[2]-1)));
	    }
	    else
	    if(s[0]=='V')
	    {
	        x=find((((v[1]-1)/5)*c+(v[0]-1)));
	        b[x]++;
	    }
	    else
	    if(s[0]=='R')
	    {
	        x=find((((v[1]-1)/5)*c+(v[0]-1)));
	        if(b[x])
	        b[x]--;
	    }
	    else
	    if(s[0]=='L')
	    {
	        x=find((((v[1]-1)/5)*c+(v[0]-1)));
	        y=find((((v[3]-1)/5)*c+(v[2]-1)));
	        if((b[x]==0 && b[y]>0) || (b[x]>0 && b[y]==0))
	        cout<<"ON\n";
	        else
	        cout<<"OFF\n";
	    }
	}
	return 0;
}
