/* Question link: https://codeforces.com/contest/61/problem/E */
****************************************************************

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
    ll n,i,x1,x2;
    cin>>n;
    ll a[n+10],b[n+10];
    ll bit1[n+10]={0};
    ll bit2[n+10]={0};
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i-1]=a[i];
    }
    sort(b,b+n);
    ll sum1[n+10]={0},sum2[n+10]={0};
    ll sum=0;
    for(i=1;i<=n;i++)
    {
        x1=binary_search(b,0,n-1,a[i]);
        x2=binary_search(b,0,n-1,a[n-i+1]);
        //cout<<x1<<" "<<x2<<endl;
        sum1[i]=(read(n,bit1)-read(x1,bit1));
        sum2[n-i+1]=(read(x2-1,bit2)-read(0,bit2));
        update(x1,1,n,bit1);
        update(x2,1,n,bit2);
    }
    for(i=1;i<=n;i++)
    {
        //cout<<sum1[i]<<" "<<sum2[i]<<endl;
        sum+=(sum1[i]*sum2[i]);
    }
    cout<<sum<<endl;
    return 0;
}
