// Written By Dheeraj Maurya
// Btech student IET CSE (2018 - 2022)
// segment tree with range query and range update

#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const int N = 10005;
ll seg[4*N] , lazy[4*N];

void check(ll v,ll l,ll r){
    if(lazy[v]!=-1){
        seg[v] = lazy[v]*(r-l+1);
        if(l!=r) lazy[2*v] = lazy[2*v+1] = lazy[v]; lazy[v] =-1;
    }
}

void rupdate(ll v,ll s,ll e,ll l,ll r,ll val){
    check(v,s,e);
    if(s>r || e<l)return ;
    if(s>=l && e<=r){
       seg[v] = (e - s + 1)*val;
       if(s!=e) lazy[2*v] = lazy[2*v+1] = val;
       return ;
    } 
    ll mid = (s+e)>>1;
    rupdate(2*v,s,mid,l,r,val);    rupdate(2*v+1,mid+1,e,l,r,val);
    seg[v] = seg[2*v] + seg[2*v+1];
}

ll query(ll v,ll s,ll e,ll l,ll r){
    check(v,s,e);
    if(s>r || e<l)return 0;
    if(s>=l && e<=r)return seg[v];
    ll mid = (s+e)>>1;
    return  query(2*v,s,mid,l,r) +  query(2*v+1,mid+1,e,l,r);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n,i,l,r,val;
    // here we take range of 10000
    n = 10000;   
    memset(lazy,-1,sizeof(lazy));

    // initially all elements have initialize with zero

    // add 5 to range 4 to 11
    l = 4, r= 11,val=5;
    rupdate(1,1,n,l,r,val);   
    
    // output the sum of range 3 to 7
    l = 3, r =7; 
    cout<< query(1,1,n,l,r)<<"\n";
     
}
