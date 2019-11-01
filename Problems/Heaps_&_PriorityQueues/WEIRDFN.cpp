/*  question link: https://www.spoj.com/problems/WEIRDFN/  */
*************************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mod 1000000007
void print_medians(ll a,ll b,ll c,ll n)
{
    priority_queue<ld> s;
    priority_queue<ld,vector<ld>,greater<ld>> r;
    ld median=1.0;
    s.push(1);
    vector<ll>v;
    v.push_back(1);
    vector<ll>med;
    med.push_back(1);
    for(ll i=1;i<n;i++)
    {
        ll w=(((a*med[i-1])%mod)+((b*(i+1))%mod)+c)%mod;
        v.push_back(w);
        //cout<<v[i]<<" ";
        ld x=1.0*v[i];
        if(s.size()>r.size())
        {
            if(x<median)
            {
                ld y=1.0*s.top();
                s.pop();
                r.push(y);
                s.push(x);
            }
            else
            r.push(x);
            median=(s.top()+r.top())/2.0;
        }
        else
        if(s.size()==r.size())
        {
            if(x<median)
            {
                s.push(x);
                median=1.0*s.top();
            }
            else
            {
                r.push(x);
                median=1.0*r.top();
            }
        }
        else
        {
            if(x>median)
            {
                ld y=1.0*r.top();
                r.pop();
                s.push(y);
                r.push(x);
            }
            else
            s.push(x);
            median=(s.top()+r.top())/2.0;
        }
        if(s.size()==r.size())
        {
            med.push_back((ll)s.top());
        }
        else
        if(s.size()>r.size())
        {
            med.push_back((ll)s.top());
        }
        else
        {
            med.push_back((ll)r.top());
        }
    }
    //cout<<med[0]<<" "<<endl;
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        //cout<<v[i]<<" ";
        sum=(sum+v[i]);
    }
    //cout<<endl;
    cout<<sum<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x,a,b,c,n;
    ll i,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>n;
        print_medians(a,b,c,n);
    }
    return 0;
}  
