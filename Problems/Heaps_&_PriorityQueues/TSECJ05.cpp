/*
question link: https://www.codechef.com/problems/TSECJ05
*/
*********************************************************

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
	Test
	{
	    ll k,n,i,x;
	    cin>>k>>n;
	    ll a[n];
	    priority_queue<ll> pq1;
	    priority_queue<ll,vector<ll>,greater<ll>> pq2; 
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(pq2.size()<k)
	        {
	            pq2.push(a[i]);
	        }
	        else
	        {
	            if(pq2.top()<a[i])
	            {
	                x=pq2.top();
	                pq2.pop();
	                pq1.push(x);
	                pq2.push(a[i]);
	            }
	        }
	        if(pq2.size()<k)
	        cout<<-1<<" ";
	        else
	        cout<<pq2.top()<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
