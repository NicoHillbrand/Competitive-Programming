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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 2e5;
int n;
const int modd = 1e8;
 
void print(int tp){
	string s = to_string(tp);
	for (int i = 0; i < 8-s.length() ; i++) {
		cout << 0;
	}
	cout << s << "\n";
}
 
void solve(){
	cin >> n;
	if (n==-1) {
		exit(0);
	}
	vii a(n);
	for (int i = 0; i < n ; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a.begin(),a.end());
	map<int,int> et;
	for (int i = 0; i < n ; i++) {
		if (et.find(a[i].first)!=et.end()) {
			et.erase(et.find(a[i].first));
		}
		et.insert(mp(a[i].first,i+1));
	}
	
	vi dp(n+1,0);
	dp[0] =1;
	for (int i = 1; i <= n; i++) {
		//not include
		dp[i] = dp[i-1];
		//include
		int w = 0;
		auto it = et.upper_bound(a[i-1].second);
		if (it!=et.begin()) {
			it--;
			w = (*it).second;
		}
		//use binary search to determine where a[i-1].second
		dp[i]+= dp[w];
		dp[i]%=modd;
	}
	if (dp[n]==0) {
		print(modd-1);
		
	}else {
		print(dp[n]-1);
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
	while(true){
		solve();
	}
	
	
    return 0;
}
