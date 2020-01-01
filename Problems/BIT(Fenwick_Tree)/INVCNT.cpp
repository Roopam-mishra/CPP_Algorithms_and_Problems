/* Question link: https://www.spoj.com/problems/INVCNT/  */
***********************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll binary_search(ll b[],ll low,ll high,ll value)
{
    if(low<=high)
    {
        ll mid=(low+high)/2;
        if(b[mid]==value)
        {
            return mid+1;
        }
        else
        if(b[mid]>value)
        {
            return binary_search(b,low,mid-1,value);
        }
        else
        {
            return binary_search(b,mid+1,high,value);
        }
    }
}
ll read(ll idx,ll bit[])
{
    ll sum=0;
    for(;idx>0;idx-=(idx&(-idx)))
    {
        sum+=bit[idx];
    }
    return sum;
}
void update(ll idx,ll value,ll n,ll bit[])
{
    for(;idx<=n;idx+=(idx&(-idx)))
    {
        bit[idx]+=value;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,x;
        cin>>n;
        ll a[n+10],b[n+10];
        ll bit[n+10]={0};
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i-1]=a[i];
        }
        sort(b,b+n);
        ll sum=0;
        for(i=1;i<=n;i++)
        {
            x=binary_search(b,0,n-1,a[i]);
            //cout<<x<<" ";
            sum+=(read(n,bit)-read(x,bit));
            update(x,1,n,bit);
        }
        cout<<sum<<endl;
    }
    return 0;
}
