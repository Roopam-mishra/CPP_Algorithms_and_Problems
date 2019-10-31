/*
Author: Roopam Mishra
*/
**********************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[10000000],n;
void swap(ll *x, ll *y) 
{ 
    ll temp = *x; 
    *x = *y; 
    *y = temp; 
}
ll parent(ll i)
{
    return (i-1)/2;
}
ll leftchild(ll i)
{
    return 2*i+1;
}
ll rightchild(ll i)
{
    return 2*i+2;
}
void sift_down(ll m,ll i)
{
    ll min_index=i;
    ll l =leftchild(i);
    ll r=rightchild(i);
    if(l<m && a[l]<a[i])
    min_index=l;
    if(r<m && a[r]<a[min_index])
    min_index=r;
    if(i!=min_index)
    {
        swap(&a[min_index],&a[i]);
        sift_down(m,min_index);
    }
}
void build_heap()
{
    for(ll i=n/2-1;i>=0;i--)
    sift_down(n,i);
}
void heapsort()
{
    build_heap();
    for(ll i=n-1;i>=0;i--)
    {
        swap(&a[0],&a[i]);
        sift_down(i,0);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,m;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    heapsort();
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
