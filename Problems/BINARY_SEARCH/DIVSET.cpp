/* question link: https://www.codechef.com/problems/DIVSET  */
***************************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[1000000];
bool check(ll c,ll mid,ll k,ll n)
{
    ll nw=0;
    vector<ll> v[mid];
    for(ll i=0;i<n;i++)
    {
        if(v[nw].size() == k) 
        return true;
        if(v[nw].empty() || (v[nw].back()*c<=a[i]))
        {
            v[nw].push_back(a[i]);
            nw=(nw+1)%mid;
        }
    }
    if(v[mid-1].size()==k)
    {
        return true;
    }
    else
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll k,c,t;
    ll n,i,l,r,res,mid;
    cin>>t;
    while(t--)
    {
    cin>>n>>k>>c;
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    res=0;
    l=0;
    r=n;
    while(r-l>1)
    {
        mid=(l+r)/2;
        if(check(c,mid,k,n))
        {
            res=mid;
            l=mid;
        }
        else
        r=mid;
    }
    cout<<res<<endl;
    }
}
