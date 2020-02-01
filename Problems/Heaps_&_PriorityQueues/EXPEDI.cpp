/*
  question link: https://www.spoj.com/problems/EXPEDI/
    */
*******************************************************

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
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
struct roop
{
    ll a,b;
};
bool ss(roop r1,roop r2)
{
    return r1.b<r2.b;
}
int main() 
{
	fast_io;
	Test
	{
	    ll n,i,l,p,dist,answer,ff,fuel,flag;
	    cin>>n;
	    struct roop r[n+1];
	    for(i=0;i<n;i++)
	    {
	        cin>>r[i].b>>r[i].a;
	    }
	    cin>>l>>fuel;
	    for(i=0;i<n;i++)
	    {
	        r[i].b=l-r[i].b;
	    }
	    sort(r,r+n,ss);
	    //for(i=0;i<n;i++)
	    //cout<<r[i].a<<' '<<r[i].b<<endl;
	    r[n].a=0LL;
	    r[n].b=l;
	    priority_queue<pair<ll,ll>> pq;
	    answer=0;
	    dist=0;
	    for(i=0;i<=n;i++)
	    {
	        flag=0;
	        while(1)
	        {
	            ff=fuel-(r[i].b-dist);
	            //cout<<fuel<<" "<<ff<<" "<<dist<<"***"<<endl;
	            if(ff<0)
	            {
	                //cout<<"b"<<endl;
	                if(pq.empty())
	                {
	                    //cout<<"e"<<endl;
	                    answer=-1;
	                    flag=1;
	                    break;
	                }
	                answer++;
	                fuel+=pq.top().first;
	                //cout<<fuel<<"((";
	                //dist=pq.top().second;
	                pq.pop();
	            }
	            /*else
	            if((ff+r[i].a)>=(l-r[i].b))
	            {
	                cout<<"a"<<endl;
	                answer++;
	                flag=1;
	                break;
	            }
	            /*else
	            if(ff==0)
	            {
	                cout<<"c"<<endl;
	                fuel=r[i].a;
	                dist=r[i].b;
	                answer++;
	            }*/
	            else
	            {
	                //cout<<"d"<<endl;
	                fuel=fuel-(r[i].b-dist);
	                //cout<<fuel;
	                dist=r[i].b;
	                pq.push({r[i].a,r[i].b});
	                break;
	            }
	        }
	        
	        if(flag==1)
	        break;
	    }
	    cout<<answer<<endl;
	}
	return 0;
} 
