/*
Roopam Mishra

RESOURCES: https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/
           https://cp-algorithms.com/data_structures/disjoint_set_union.html
           https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
           */
************************************************************************************

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll nn,m,parent[100001],ranki[100001];
void makeset()
{
    for(ll i=0;i<=nn;i++)
    {
        parent[i]=i;
        ranki[i]=0;
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
        }
        else
        {
            parent[second]=first;
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
    ll a,b,i,t;
    cin>>nn>>m;
    makeset();
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        --a;
        --b;
        unioni(a,b);
    }
    for(i=0;i<nn;i++)
    {
        cout<<"Node-->"<<i+1<<" "<<"Parent-->"<<parent[i]+1<<" "<<"Rank-->"<<ranki[i]<<endl;
    }
} 
