/* 
question link: https://www.codechef.com/problems/CAPIMOVE
*/
*****************************

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
#define mp make_pair
#define f first
#define s second
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
int main() 
{
	fast_io;
	ll T;
	cin>>T;
	while(T--)
	{
	    ll n,i,a,b,j,x,y;
	    cin>>n;
	    ll p[n];
	    set<ll> s;
	    map<ll,ll> mp;
	    for(i=1;i<=n;i++)
	    {
	        cin>>p[i];
	        mp[p[i]]=i;
	        s.insert(p[i]);
	    }
	    vector<ll> visited[n+1];
	    for(i=0;i<n-1;i++)
	    {
	        cin>>a>>b;
	        visited[a].pb(b);
	        visited[b].pb(a);
	    }
	    for(i=1;i<=n;i++)
	    {
	        s.erase(p[i]);
	        for(auto u:visited[i])
	        s.erase(p[u]);
	        if(s.size()==0)
	        cout<<0<<" ";
	        else
	        {
	            cout<<mp[*s.rbegin()]<<" ";
	        }
	        s.insert(p[i]);
	        for(auto u:visited[i])
	        s.insert(p[u]);
	    }
	}
	return 0;
}
