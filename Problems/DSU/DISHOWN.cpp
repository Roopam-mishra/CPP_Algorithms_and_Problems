/* Question link: https://www.codechef.com/problems/DISHOWN  */
***************************************************************

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
typedef long long int ll;
#define MOD 1000000007
#define MAX 1000000000000000000
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define f first
#define s second
#define TEST ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
ll find(ll i,ll parent[])
{
    if(i==parent[i])                      // sometimes this approach works better as while loop takes more time 
    return i;
    return parent[i]=find(parent[i],parent);
}
void unioni(ll x,ll y,ll parent[],ll s[])
{
    ll firsti=find(x,parent);
    ll secondi=find(y,parent);
    if(firsti==secondi)
    cout<<"Invalid query!"<<endl;
    else
    if(firsti!=secondi)
    {
        if(s[firsti]>s[secondi])
        {
            parent[secondi]=firsti;
            s[secondi]=-1;
        }
        else
        if(s[firsti]<s[secondi])
        {
            parent[firsti]=secondi;
            s[firsti]=-1;
        }
    }
}
int main() 
{
	fast_io;
	ll n,i,q,m,x,y;
	TEST
	{
	    cin>>n;
        ll parent[n];
        ll s[n];
        for(i=0;i<n;i++)
        {
            cin>>s[i];
            parent[i]=i;
        }
        cin>>q;
        for(i=0;i<q;i++)
        {
            cin>>m;
            if(m==0)
            {
                cin>>x>>y;
                --x;
                --y;
                unioni(x,y,parent,s);
            }
            else
            {
                cin>>x;
                /*for(ll j=0;j<n;j++)
                cout<<parent[j]<<" ";
                cout<<endl;*/
                cout<<find(--x,parent)+1<<endl;
            }
        }
	}
	return 0;
}
