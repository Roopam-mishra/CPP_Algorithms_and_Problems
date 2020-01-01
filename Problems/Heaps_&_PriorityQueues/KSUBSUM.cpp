/* Question link: https://www.codechef.com/problems/KSUBSUM  */
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
	ll n,k1,k2,k3,sum,i,s,j;
	Test
	{
	    cin>>n>>k1>>k2>>k3;
	    ll a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    priority_queue <ll,vector<ll>,greater<ll>> pq;
	    for(i=0;i<n;i++)
	    {
	        sum=a[i];
	        if(pq.size()<k3)
	        pq.push(sum);
	        else
	        if(pq.top()<sum)
	        {
	            pq.pop();
	            pq.push(sum);
	        }
	        for(j=i+1;j<n;j++)
	        {
	            sum+=a[j];
	            if(pq.size()<k3)
	            pq.push(sum);
	            else
	            if(pq.top()<sum)
	            {
	                pq.pop();
	                pq.push(sum);
	            }
	        }
	    }
	    ll aa[pq.size()+5];
	    j=pq.size()-1;
	    //cout<<pq.top()<<endl;
	    while(pq.size()) 
	    {
	        aa[j]=pq.top();
	        j--;
	        pq.pop();
	    }
	    cout<<aa[k1-1]<<" "<<aa[k2-1]<<" "<<aa[k3-1]<<endl;
	}
	return 0;
}
