#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#include <iostream>
//#include <vector>
//#include <string>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 2e5;
int n,m;
 
 
 
void solve(){
 
	cin >> n;
	map<string,int> mpp;
	for (int i = 0; i < n ; i++) {
		string s;
		cin >> s;
		mpp.insert(mp(s,i));
	}
	vi a(n);
	for (int i = 0; i < n ; i++) {
		string s;
		cin >> s;
		a[mpp[s]] = i;
	}
	//count inversions 
	ll ans = 0;
	indexed_set sett;
	for (int i = 0; i < n ; i++) {
		sett.insert(a[i]);
		ans+=i-sett.order_of_key(a[i]);
	}
	
	cout << ans << "\n";
	
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
//	cout << "hi" << "\n";
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
//	
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ti++){
//		cout << "Case #" << ti  << ": ";
		solve();
	}
	
//	solve();
	
    return 0;
}
