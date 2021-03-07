#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <string>
using namespace std;
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX
const ll inf = 1e16;
 
 
const int maxn = 2e5+1;
ll n,a,b;
ll c[maxn];
 
void solve(){
	cin >> n >> a >> b;
	for (int i = 0; i < n ; i++) {
		cin >> c[i+1];
		c[i+1]+=c[i];
	}
	set<pair<ll,ll>> s;
	ll ans =-1e18;
	for (int i = 0; i <= n ; i++) {
		if (i>=a) {
			s.insert({c[i-a],i-a});
		}
		if (s.size()) {
			ans = max(c[i]-(*s.begin()).first,ans);
		}
		if (i>=b) {
			s.erase({c[i-b],i-b});
		}
	}
	cout << ans << "\n";
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
//	
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
//		cout << "Case #" << ti  << ": ";
//		solve();
//	}
	
	solve();
	
    return 0;
}
