/*
   CHUNK2: Popatlal ki shaadi
   question link: https://www.spoj.com/problems/CHUNK2/
   */
*******************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> vect;
ll nn,m,parent[100001],ranki[100001],size[100001];
void Sieve(ll n) 
{ 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    for (ll p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (ll i=2*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (ll p=2; p<=n; p++) 
       if (prime[p]) 
          vect.push_back(p);
} 
void makeset()
{
    for(ll i=0;i<=nn;i++)
    {
        parent[i]=i;
        ranki[i]=0;
        size[i]=1;
    }
}
ll find(ll i)
{
    while(i!=parent[i])
    i=parent[i];
    return i;
}
void unioni(ll x,ll y)
{
    ll first=find(x);
    ll second=find(y);
    if(first!=second)
    {
        if(ranki[first]<ranki[second])
        {
            parent[first]=second;
            size[second]+=size[first];
            size[first]=0;
        }
        else
        {
            parent[second]=first;
            size[first]+=size[second];
            size[second]=0;
            if(ranki[first]==ranki[second])
            ranki[first]++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Sieve(2000001); 
    //cout<<vect.size()<<" ";
    ll a,b,i,t;
    cin>>t;
    while(t--)
    {
    cin>>nn>>m;
    makeset();
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        --a;
        --b;
        unioni(a,b);
    }
    ll maxi=LLONG_MIN;
    for(i=0;i<nn;i++)
    {
        //cout<<size[i]<<" ";
        maxi=max(maxi,size[i]);
    }
    //cout<<endl;
    if(m==0)
    cout<<-1<<endl;
    else
    cout<<vect[maxi-1]<<endl;
    }
} 
