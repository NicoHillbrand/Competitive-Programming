#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <iostream>
//#include <vector>
//#include <string>
using namespace std;
//using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ts to_string
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const int INF = 5e8+1;
const ll inf = 1e16;
 
const int maxn = 2e5;
int n;
int len;
vector<ll> b;
vector<ll> a;
 
void solve(){
	int q;
	cin >> n >> q;
	len = (int) sqrt(n+0.1)+1;
	b.resize(len,0);
	a.resize(n);
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n ; i++) {
		b[i/len] = b[i/len]^a[i];
	}
	
	for (int i = 0; i < q ; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		
		ll xorsum = 0;
		int bl = l/len, br = r/len;
		if (bl==br) {
			for (int i = l; i <= r ; i++) {
				xorsum = xorsum^a[i];
			}
		}else {
			for (int i = l; i < (bl+1)*len ; i++) {
				xorsum = xorsum^a[i];
			}
			for (int i = bl+1; i <=br-1 ; i++) {
				xorsum = xorsum^b[i];
			}
			for (int i = br*len; i <=r ; i++) {
				xorsum = xorsum^a[i];
			}
		}
		cout << xorsum << "\n";
	}
	
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
