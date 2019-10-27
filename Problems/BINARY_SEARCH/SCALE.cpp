/* question link: https://www.spoj.com/problems/SCALE/ */
*********************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,x,i,z;
    cin>>n>>x;
    z=(pow(3,n)-1)/2;
    if(x>z)
    cout<<"-1";
    else
    {
        vector<ll> v;
        while(x>=1)
        {
            v.push_back(x%3);
            x=x/3;
        }
        v.push_back(0);
        for(i=0;i<v.size()-1;i++)
        {
            if(v[i]==2)
            {
                v[i+1]=v[i+1]+1;
                v[i]=-1;
            }
            if(v[i]==3)
            {
                v[i+1]=v[i+1]+1;
                v[i]=0;
            }
        }
        for(i=0;i<v.size();i++)
        {
            if(v[i]==-1)
            {
                cout<<i+1<<" ";
            }
            
        }
        cout<<endl;
        for(i=0;i<v.size();i++)
        {
            if(v[i]==1)
            {
                cout<<i+1<<" ";
            }
        }
    }
    return 0;
} 
