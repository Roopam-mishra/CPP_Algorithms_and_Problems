#include<iostream>
using namespace std;
typedef long long int ll;
ll dp[61][100003];
ll gcd(ll a,ll b)
{
    if(b == 0)return a;
    return gcd(b,a%b);
}
ll power(ll a,ll b)
{
    ll res = 1;
    while(b>0)
    {
        if(b&1)res = res*a;
        b = b>>1;
        a = a*a;
    }
    return res;
}
ll func(ll a[],ll pos,ll current_gcd,ll n)
{
    if(pos==n && current_gcd==1)
    {
        //cout<<"a"<<" ";
        return dp[n][current_gcd]= 1;
    }
    if(pos==n)
    {
        //cout<<"b"<<" ";
        return dp[pos][current_gcd]= 0;
    }
    if(current_gcd==1)
    {
        //cout<<"c ";
        dp[pos][current_gcd]=power(2,n-pos);
    }
    if(dp[pos][current_gcd]!=-1)return dp[pos][current_gcd];
    return dp[pos][current_gcd]=func(a,pos+1,current_gcd,n)+func(a,pos+1,gcd(current_gcd,a[pos]),n);
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,i,sum,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n];
        
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=10002;j++)
            dp[i][j]=-1;
        }
        sum=0;
        for(i=0;i<n;i++)
        {
            sum+=func(a,i+1,a[i],n);
            //cout<<sum<<" ";
        }
        cout<<sum<<endl;
    }
    return 0;
}
