#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct roop
{
    ll sum,prefixsum,suffixsum,answer;
};
struct roop add_accordingly(struct roop a, struct roop b)
{
    struct roop result;
    result.sum=a.sum+b.sum;
    result.prefixsum=max(a.sum+b.prefixsum,a.prefixsum);
    result.suffixsum=max(a.suffixsum+b.sum,b.suffixsum);
    result.answer=max(max(a.answer,b.answer),a.suffixsum+b.prefixsum);
    return result;
}
struct roop set_data(ll value)
{
    struct roop result;
    result.sum=value;
    result.prefixsum=result.suffixsum=result.answer=value;
    return result;
}
void build(ll a[],ll v,ll low,ll high,struct roop t[])
{
    if(low==high)
    {
        t[v]=set_data(a[low]);
    }
    else
    {
        ll mid=(low+high)/2;
        build(a,2*v+1,low,mid,t);
        build(a,2*v+2,mid+1,high,t);
        t[v]=add_accordingly(t[v*2+1],t[2*v+2]);
    }
}
void update(ll v,ll low,ll high,ll pos,ll value,struct roop t[])
{
    if(low==high)
    {
        t[v]=set_data(value);
    }
    else
    {
        ll mid=(low+high)/2;
        if(pos<=mid)
        update(2*v+1,low,mid,pos,value,t);
        else
        update(2*v+2,mid+1,high,pos,value,t);
        t[v]=add_accordingly(t[v*2+1],t[2*v+2]);
    }
}
struct roop max_sum(ll v,ll low,ll high,ll l,ll r,struct roop t[])
{
    if(low>high || low>r || high<l)
    return set_data(LLONG_MIN);
    if(l<=low && r>=high)
    return t[v];
    ll mid=(low+high)/2;
    if(r<=mid)
    return max_sum(2*v+1,low,mid,l,r,t);
    if(l>mid)
    return max_sum(2*v+2,mid+1,high,l,r,t);
    return add_accordingly(max_sum(2*v+1,low,mid,l,min(mid,r),t),max_sum(2*v+2,mid+1,high,max(l,mid+1),r,t));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,j,q,m,pos,value,l,r,flag;
    cin>>n;
    ll a[n];
    ll size=pow(2,ceil(log2(n))+1);
    struct roop t[size];
    flag=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build(a,0,0,n-1,t);
    /*for(i=0;i<=6;i++)
    {
        cout<<t[i].answer<<" ";
    }*/
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>l>>r;
        cout<<max_sum(0,0,n-1,l-1,r-1,t).answer<<endl;
    }
}
 
