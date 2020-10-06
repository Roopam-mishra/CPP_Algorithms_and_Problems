// Problem Name: Discrete Acceleration
// Source Link: https://codeforces.com/contest/1408/problem/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define ppll pair<ll,pll>
#define vll vector<ll>
#define vs vector<string>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define vvpll vector<vpll>
#define f first
#define s second
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define Test ll T;cin>>T; while(T--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define init(x,n,v) for(ll i=0;i<=n;i++) x[i]=v;
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pi 3.14159265358979323846
#define MOD 998244353
#define MAX 2000000000000000000
#define MAXN 100005
bool valid(vector <long double> &a ,long double m , ll l) {
	long double d1 = 0.0000000000 , d2 = l * 1.000000000, s = 1.000000000 , t = m;
	ll i = 0, n = a.size();
	while(i < n) {
		long double tmp = d1 + (s * t * 1.00000000);
		if(tmp > (a[i] * 1.0)) {
			t -= ((a[i] - d1) / s);
			s += 1.000000000;
			d1 = a[i] * 1.000000000;
			i++;
		}
		else {
			d1 = tmp;
			t = 0;
			break;
		}
	}
	if(t > 0.0000000) {
		d1 += (s * t * 1.00000000);
	}
	i = n - 1;
	s = 1.000000000;
	t = m;
	while(i >= 0) {
		long double tmp = d2 - (s * t * 1.00000000);
		if(tmp < (a[i] * 1.0)) {
			t -= ((d2 - a[i]) / s);
			s += 1.000000000;
			d2 = a[i] * 1.000000000;
			i--;
		}
		else {
			d2 = tmp;
			t = 0;
			break;
		}
	}
	if(t > 0.00000000) {
		d2 -= (s * t * 1.00000000);
	}
	return d1 <= d2;
}
void solve() {
	ll n , d;
	cin>>n>>d;
	vll b(n);
	for(auto &i: b) cin>>i;
	vector <long double> a;
	for(auto i: b) a.pb(i * 1.00000000);
	long double l = 0.0000000000 , r = 1000000000000.0000000000 , m , ans;
	while(l < r) {
		m = (l + r) / 2.0;
		if(valid(a , m , d)) l = m + 0.0000000001 , ans = m;
		else r = m - 0.0000000001;
	}
	cout<<fixed<<setprecision(10)<<ans<<ln;
}
int main() {
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    #endif

    Test
    solve();

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
	#endif

    return 0;
}
