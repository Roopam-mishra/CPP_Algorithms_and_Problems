/* question link: https://www.codechef.com/problems/STACKS */
*************************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[100001];
ll index(vector<ll> &v,ll left,ll right,ll key)
{
    while(left<=right)
    {
        ll mid=left+(right-left)/2;
        if(v[mid]<=key)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return left;
}
void calculate(ll n)
{
    vector<ll> v;
    v.push_back(a[0]);
    for(ll i=1;i<n;i++)
    {
        ll x=index(v,0,v.size()-1,a[i]);
        if(x==v.size())
        {
            v.push_back(a[i]);
        }
        else
        {
            v[x]=a[i];
        }
    }
    cout<<v.size()<<" ";
    for(ll i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,t,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        calculate(n);
    }
    return 0;
}
