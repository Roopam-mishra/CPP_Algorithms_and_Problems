/* question link:  https://www.codechef.com/problems/ANUMLA  */
***************************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using namespace std;
#define pb push_back
#define TEST ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
int main()
{
    fast_io;
    TEST
    {
        ll n,i,x,k,a;
        cin>>n;
        ll ans[n];
        multiset<ll> ms;
        multiset<ll> :: iterator itr;
        vector<ll> v;
        ll z=1<<n;
        for(i=0;i<z;i++)
        {
            cin>>a;
            if(a!=0)
            ms.insert(a);
        }
        x=0;
        while(x<n)
        {
            itr=ms.begin();
            ans[x]=*itr;
            v.pb(ans[x]);
            ms.erase(ms.find(ans[x]));
            ll j=v.size()-1;
            for(i=0;i<j;i++)
            {
                v.pb(ans[x]+v[i]);
                ms.erase(ms.find(ans[x]+v[i]));
            }
            x++;
        }
        for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
        cout<<endl;
    }   
    return 0;
}
