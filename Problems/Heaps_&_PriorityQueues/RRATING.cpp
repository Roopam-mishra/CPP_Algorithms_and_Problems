/* Question link: https://www.codechef.com/problems/RRATING  */
***************************************************************

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x;
    ll i,t,a,b,n,m;
    cin>>t;
    priority_queue<ll> pq1_max;
    priority_queue<ll,vector<ll>,greater<ll>> pq2_min; // min_heap tp store first one third elements
    ll size=0;
    ll size_of_pq2_min=0;
    while(t--)
    {
        cin>>m;
        //cout<<m;
        if(m==1)
        {
            cin>>x;
            if(size_of_pq2_min<(size+1)/3)
            {
                ll value=pq1_max.top();
                if(x>value)
                {
                    pq2_min.push(x);
                }
                else
                {
                    pq1_max.pop();
                    pq2_min.push(value);
                    pq1_max.push(x);
                }
                size_of_pq2_min++;
            }
            else
            if((size_of_pq2_min) && (x>pq2_min.top()))
            {
                ll value=pq2_min.top();
                pq2_min.pop();
                pq1_max.push(value);
                pq2_min.push(x);
            }
            else
            {
                pq1_max.push(x);
            }
            size++;
            //cout<<size_of_pq2_min<<"#"<<endl;
        }
        else
        {
            if(size_of_pq2_min==0)
            cout<<"No reviews yet"<<endl;
            else
            cout<<pq2_min.top()<<endl;
        }
    }
    return 0;
} 
