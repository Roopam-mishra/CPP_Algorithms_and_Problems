/* question link: https://www.spoj.com/problems/RMID2/
   Concept Used: Median of Stream of Running Integers using STL(https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/)
   */
***********************************************************************************************************************************************

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
typedef long double ld;
void print_medians(vector<ll> v)
{
    priority_queue<ld> s;
    priority_queue<ld,vector<ld>,greater<ld>> r;
    ld median=v[0];
    s.push(1.0*v[0]);
    for(ll i=1;i<v.size();i++)
    {
        ld x=1.0*v[i];
        if(x!=-1)
        {
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
        }
        else
        if(x==-1)
        {
            if(s.size()==r.size())
            {
                cout<<(ll)s.top()<<"\n";
                s.pop();
                ld a=(s.size()>0)?s.top():0;
                ld b=(r.size()>0)?r.top():0;
                if(s.size()>r.size())
                median=s.top();
                else
                if(r.size()>s.size())
                median=r.top();
                else
                median=(a+b)/2.0;
            }
            else
            if(s.size()>r.size())
            {
                cout<<(ll)s.top()<<"\n";
                s.pop();
                ld a=(s.size()>0)?s.top():0;
                ld b=(r.size()>0)?r.top():0;
                if(s.size()>r.size())
                median=s.top();
                else
                if(r.size()>s.size())
                median=r.top();
                else
                median=(a+b)/2.0;
            }
            else
            {
                cout<<(ll)r.top()<<"\n";
                r.pop();
                ld a=(s.size()>0)?s.top():0;
                ld b=(r.size()>0)?r.top():0;
                if(s.size()>r.size())
                median=s.top();
                else
                if(r.size()>s.size())
                median=r.top();
                else
                median=(a+b)/2.0;
            }
        }
    }
}
int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x;
    ll i,t;
    scanf("%lld",&t);
    while(t--)
    {
        vector<ll> v;
        while(1)
        {
            scanf("%lld",&x);
            if(x==0)
            break;
            else
            v.push_back(x);
        }
        print_medians(v);
        cout<<"\n";
    }
    return 0;
} 
