#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include <cstring> 
#include<map>
#include<queue>
#include <utility>
#include<algorithm>
#include <assert.h>
# include <cstdio> 
# include <vector> 
#include<math.h>
#include<limits>
#include<iomanip>
 
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define  vpi vector<pair<int,int>>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ppb pop_back
# define ln cout << "\n" ;
#define fab(i,a,b) for(i=a;i<b;i++)
#define fabe(i,a,b) for(i=a;i<=b;i++)
#define fre(i,a,b) for(i=b;i>=a;i--)
 
#define maxHeap priority_queue<ll>
#define minHeap priority_queue <ll, vector<ll>, greater<ll> >
 
ll getSum(ll BITree[], ll index) 
{ 
    ll sum = 0; 
    while (index > 0) 
    { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
 
void updateBIT(ll BITree[], ll n, ll index, ll val) 
{
    while (index <= n) 
    { 
       BITree[index] += val; 
       index += index & (-index); 
    } 
} 
 
ll getInvCount(ll arr[], ll n) 
{ 
    ll invcount = 0; 
    ll maxElement = 0; 
    for (ll i=0; i<n; i++) 
        if (maxElement < arr[i]) 
            maxElement = arr[i]; 
            
    ll BIT[maxElement+1]; 
    for (ll i=0; i<=maxElement; i++) 
        BIT[i] = 0; 
  
    for (ll i=n-1; i>=0; i--) 
    { 
        invcount += getSum(BIT, arr[i]-1); 
        updateBIT(BIT, maxElement, arr[i], 1); 
    } 
  
    return invcount; 
} 
void solve(){
    ll n,i,j;
    cin >> n;
    string s;
    vector<string> vs;
    ll v[n];
    map<string,ll> ms;
    for(i=0;i<n;i++){
        cin >> s;
        vs.pb(s);
    }
    for(i=0;i<n;i++){
        cin >> s;
        ms[s] = i;
    }
    for(i=0;i<n;i++){
        string temp = vs[i];
        ll ind = ms[temp];
        v[i] = ind+1;
    }
    // for(i=0;i<n;i++){
    //     cout << v[i] << " ";
    // }ln; 
    cout << getInvCount(v,n); ln;
}
 
int main() 
{
	fastio
	ll t; cin >> t; while(t--)
        solve();
	return 0;
} 
