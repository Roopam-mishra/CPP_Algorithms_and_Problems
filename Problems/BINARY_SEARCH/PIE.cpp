/* question link: https://www.spoj.com/problems/PIE/  */
*********************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool check(long double a[],long double volume,ll f,ll n)
{
    long double sum=0;
    for(ll i=0;i<n;i++)
    {
        sum+=(ll)(a[i]/volume);
    }
    if((ll)sum>=(f))
    return true;
    else
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,f,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>f;
        ll r[n];
        for(i=0;i<n;i++)
        {
            cin>>r[i];
        }
        sort(r,r+n);
        long double a[n];
        for(i=0;i<n;i++)
        {
            a[i]=r[i]*r[i]*M_PI;
        }
        long double maxi,mini,mid,req_vol;
        mini=0;
        maxi=a[n-1];
        f=f+1;
        ll temp=50;
        while(temp--)
        {
            mid=(maxi+mini)/2;
            req_vol=mid;
            if(check(a,mid,f,n)==false)
            maxi=mid;
            else
            mini=mid;
        }
        cout<<fixed<<setprecision(4)<<req_vol<<endl;
    }
} 
