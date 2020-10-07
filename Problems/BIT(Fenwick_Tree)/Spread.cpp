#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<queue>
#include <sstream>      //contains 'istringstream'
#include<algorithm>
#include <assert.h> 
# include <cstdio> 
# include <string> 
# include <vector>
#include<stdlib.h>
#include<set> 
#include<list>
#include<math.h>
#include<iomanip>
#include <string.h> 
using namespace std;
#define ln cout << "\n";
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define  vpll vector<pair<ll,ll>>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define fab(i,a,b) for(i=a;i<b;i++)
#define fabe(i,a,b) for(i=a;i<=b;i++)
#define fre(i,a,b) for(i=b;i>=a;i--)
#define test ll t; cin >> t; while(t--)
#define log log2
#define cases cout << "Case " << i << ":\n"; 
#define tests ll t,i; cin >> t; for(i=1;i<=t;i++)

// FENWICK TREE

ll bit[1000005]={0} , n,m,c;

void update_add(ll x, ll delta)       //add "delta" at index "x"
{
    for(; x <= n; x += x&-x)
          bit[x] += delta;
}

ll query(ll x)      //returns the sum of first x elements in given array a[]
{
     ll sum = 0;
     for(; x > 0; x -= (x&-x)){
        sum += bit[x];
     }  
     return sum;
}

void solve(){
    ll q,i,j,x,ind,val,num;
    cin >> n >> m >> c;
    ll a[n+1];
    for(i=0;i<=n;i++){
        bit[i]=0;
    }
    // cout << c; ln;
    // for(i=0;i<=n; i++){
    //     cout << bit[i] << " ";
    // } ln;
    while(m--){
        char ch;
        cin >> ch;
        if(ch == 'Q'){
            ll p;
            cin >> p;
            ll ans = query(p) +c;
            cout << ans ; ln;
        }
        else if(ch == 'S'){
            ll u,v,k;
            cin >> u >> v >> k;
            update_add(u,k);
            update_add(v+1,-k);
        }
    }
}

int main()
{
    fastio  
    //tests{
    //    cases
        solve();
    //}
    return 0;
}
