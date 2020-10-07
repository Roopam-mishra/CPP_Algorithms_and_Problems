pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<stack>
#include <sstream>      //contains 'istringstream'
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define  vpi vector<pair<int,int>>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ppb pop_back
# define ln cout << "\n" ;
#define fabl(i,a,b) for(i=a;i<b;i++)
#define fabe(i,a,b) for(i=a;i<=b;i++)
#define fre(i,a,b) for(i=b;i>=a;i--)
# include <cstdio> 
# include <string> 
# include <vector> 
#include<math.h>
#define cases cout << "Case " << i << ": "; 
#define tests ll t,i; cin >> t; for(i=1;i<=t;i++)
#define block 555
 
// MO'S ALGO
ll frq[1000006]={0};
ll n, q, ML, MR, cnt=0;
ll a[30004];
ll ans[1000006]={0};
 
 
struct qry{
    ll ind, l,r;
};
 
bool cmp(qry i1, qry i2){
    if((i1.l/block) != (i2.l/block)){
        return i1.l/block < i2.l/block;
    }
    return i1.r < i2.r;
}
 
void add(ll index){
    if(frq[a[index]] ==0){
        cnt++;
    }
    frq[a[index]]++;
}
void Remove(ll index){
    frq[a[index]]--;
    //cout << index << ":" << a[index] << " " << frq[a[index]] << ",     ";
    if(frq[a[index]] ==0){
        cnt--;
    }
}
 
void solve(){
    ll i,j,x,y;
    cnt =0;
    for(i=0;i<1000006;i++){
        frq[i]=0;
    }
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> q;
    qry query[q];
    for(i=0;i<q;i++){
        ll left, right;
        cin >> left >> right;
        query[i].ind =i; query[i].l = left; query[i].r = right;
    }
    sort(query,query+q, cmp);
    ML = MR =0;
    frq[a[0]]++;
    cnt = 1;
 
    for(i=0;i<q;i++){
        ll left=query[i].l -1, right=query[i].r -1;
        ll index = query[i].ind;
        while(ML > left){
            ML--;
            add(ML);
        }
        while(MR < right){
            MR++;
            add(MR);
        }
        while(ML < left){
            Remove(ML);
            ML++;
        }
        while(MR > right){
            Remove(MR);
            MR--;
            if(MR == right) break;
        }
        ans[index] = cnt;
    }
    for(i=0;i<q;i++){
        cout << ans[i]; ln;
    }
}
 
int main()
{
    fastio  
    //tests{
        //cases
        solve();
    //}
    return 0;
} 
