/* question link: https://www.codechef.com/JULY17/problems/IPCTRAIN  */
***********************************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
struct roop
{
    ll d,t,s;
};
bool ss(roop a,roop b)
{
    return a.d<b.d;
}
struct roop2
{
    ll t,s;
};
/*void swap(ll *x, ll *y) 
{ 
    ll temp = *x; 
    *x = *y; 
    *y = temp; 
}*/
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
void sift_up(struct roop2 r2[],ll j)
{
    while(j>0 && ((r2[parent(j)].t && r2[j].t && r2[parent(j)].s<r2[j].s) || r2[parent(j)].t==0))
    {
        swap(r2[parent(j)],r2[j]);
        j=parent(j);
    }
}
void sift_down(struct roop2 r2[],ll i,ll n)
{
    ll max_index=i;
    ll l =leftchild(i);
    ll r=rightchild(i);
    if(l<=n && ((r2[i].t && r2[l].t && r2[i].s<r2[l].s) || r2[i].t==0)) 
    max_index=l;
    if(r<=n && ((r2[max_index].t && r2[r].t && r2[max_index].s<r2[r].s) || r2[max_index].t==0)) 
    max_index=r;
    if(max_index!=i)
    {
        swap(r2[max_index],r2[i]);
        sift_down(r2,max_index,n);
    }
}
/*ll extract_max()
{
    ll x=a[0];
    a[0]=a[n-1];
    n=n-1;
    sift_down(0);
    return x;
}
void insert(ll p)
{
    a[n]=p;
    n=n+1;
    sift_up(n-1);
}
void change_priority(struct roop1 r,ll i,ll p)
{
    ll oldp=a[i];
    a[i]=p;
    if(oldp<p)
    sift_up(i);
    else
    sift_down(i);
}
void deletekey(ll i)
{
    a[i]=a[n-1];
    n=n-1;
    sift_down(i);
}
void build_heap()
{
    for(ll i=n/2-1;i>=0;i--)
    sift_down(n);
}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,i,days,sadness,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>days;
        sadness=0;
        struct roop r[n];
        for(i=0;i<n;i++)
        {
            cin>>r[i].d>>r[i].t>>r[i].s;
        }
        sort(r,r+n,ss);
        /*for(i=0;i<n;i++)
        {
            cout<<r[i].d<<" "<<r[i].t<<" "<<r[i].s<<endl;
        }*/
        roop2 r2[n];
        k=0;
        j=0;
        for(i=1;i<=days;i++)
        {
            while(r[k].d==i && k<n)
            {
                r2[j].t=r[k].t;
                r2[j].s=r[k].s;
                //cout<<rr.t<<" "<<rr.s<<endl;
                sift_up(r2,k);
                j++;
                k++;
            }
            //cout<<j<<endl;
            if(j>0)
            {
                if(r2[0].t>0)
	            {
	                r2[0].t--;
	                swap(r2[0],r2[j-1]);
	                sift_down(r2,0,j-2);
	                sift_up(r2,j-1);
	            }
	            /*else
	            if(r2[0].t==0)
	            {
	                swap(r2[0],r2[j-1]);
	                sift_down(r2,0,k-2);
	                sift_up(r2,j-1);
	            }*/
            }
        }
        for(i=0;i<j;i++) 
	    if(r2[i].t>0) 
	    sadness+=r2[i].t*r2[i].s;
	    cout<<sadness<<endl;
    }
    return 0;
}
