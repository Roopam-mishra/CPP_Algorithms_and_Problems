/* -->Implementation of Fenwick tree
   */
   
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll read(ll idx,ll bit[])   //to get the sum from numbers from 1 to idx
{
    ll sum=0;
    for(;idx>0;idx-=(idx&(-idx)))
    {
        sum+=bit[idx];
    }
    return sum;
}
void update(ll idx,ll value,ll n,ll bit[])   // updating the BIT
{
    for(;idx<=n;idx+=(idx&(-idx)))
    {
        bit[idx]+=value;
    }
}
ll read_single(ll idx,ll bit[])   // to get the value at the index
{
    ll sum=bit[idx];
    if(idx>0)
    {
        ll z=idx-(idx&-idx);
        idx--;
        while(idx!=z)
        {
            sum-=bit[idx];
            idx-=(idx&-idx);
        }
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,j;
    cin>>n;
    ll a[n+10];
    ll bit[n+10]={0};
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i],n,bit);
    }
    cout<<read_single(2,bit)<<endl;
}
