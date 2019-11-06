/* question link: https://www.codechef.com/problems/IPCTRAIN  */
****************************************************************

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define MAX 1000000000000000000
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define TEST ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
struct roop
{
    ll d,t,s;
};
struct roop2
{
    ll t,s;
};
bool ss(roop a,roop b)
{
    return a.d<b.d;
}
struct ss2
{
    bool operator()(roop2 const& a, roop2 const& b){
    if(a.s==b.s)
    return a.t<b.t;
    return a.s<b.s;}
};
int main()
{
    fast_io;
    ll n,i,days,k,j;
    TEST
    {
        cin>>n>>days;
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
        k=0;
        priority_queue<roop2,vector<roop2>,ss2> pq;
        for(i=1;i<=days;i++)
        {
            while(r[k].d==i && k<n)
            {
                roop2 rr;
                rr.t=r[k].t;
                rr.s=r[k].s;
                //cout<<rr.t<<" "<<rr.s<<endl;
                pq.push(rr);
                k++;
            }
            if(pq.size()>0)
            {
                roop2 ss=pq.top();
                pq.pop();
                ss.t -= 1;
                if(ss.t > 0)pq.push(ss);
            }
        }
        ll ans = 0;
        while(pq.size() > 0)
        {
            roop2 ss = pq.top();
            pq.pop();
            ans += ss.t * ss.s;
        }
        cout<<ans<<ln;
     }   
    return 0;
}
