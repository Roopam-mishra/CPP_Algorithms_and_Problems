/*
   Question link: https://www.spoj.com/problems/LAZYPROG/
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
struct roop
{
    ll a,b,d;
};
bool ss(roop r1,roop r2)
{
    if(r1.d==r2.d)
    {
        /*if(r1.b==r2.b)
        {
            return r1.a>r2.a;
        }
        else
        return r1.b<r2.b;*/
        return r1.a>r2.a;
    }
    else
    return r1.d<r2.d;
}
int main() 
{
	fast_io;
	ll k=1;
	Test
	{
	    //cout<<k<<" ";
	    ll n,i,y1,t1,timer,tt;
	    long double answer=0;
	    cin>>n;
	    struct roop r[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>r[i].a>>r[i].b>>r[i].d;
	    }
	    sort(r,r+n,ss);
	    //for(i=0;i<n;i++)
	    //cout<<r[i].a<<" "<<r[i].b<<" "<<r[i].d<<endl;
	    timer=0;
	    priority_queue<pair<ll,ll>> pq;
	    pair<ll,ll> x1;
	    for(i=0;i<n;i++)
	    {
	        pq.push({r[i].a,r[i].b});
	        t1=r[i].d-timer;
	        if(r[i].b<t1)
	        timer=timer+r[i].b;
	        else
	        timer=r[i].d;
	        if(t1<r[i].b)
	        {
	            t1=r[i].b-t1;
	            //cout<<t1<<endl;
	            while(t1)
	            {
	                x1=pq.top();
	                y1=x1.second;
	                if(y1==0)
	                {
	                    pq.pop();
	                }
	                else
	                if(y1>t1)
	                {
	                    pq.pop();
	                    answer+=((1.0*t1/x1.first));
	                    pq.push({x1.first,y1-t1});
	                    t1=0;
	                }
	                else
	                {
	                    pq.pop();
	                    answer+=((1.0*y1/x1.first));
	                    t1-=y1;
	                }
	                //cout<<answer<<endl;
	            }
	        }
	    }
	    cout<<fixed<<setprecision(2)<<answer<<" ";
	    //k++;
	}
	return 0;
}  
