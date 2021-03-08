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
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 1e5+1;
int n,m;
int dp[maxn];
int a[maxn];
 
void solve(){
	cin >> n;
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	dp[0] = 1;
	for (int i = 1; i < n ; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if ((a[i] > 0 && a[j] < 0 && a[i] > -a[j]) || (a[i] < 0 && a[j] > 0 && -a[i] > a[j])) {
				dp[i] = max(dp[i],1+dp[j]);
			}
//			if (a[i]<a[j]||a[i]>a[j]) {
//				if (abs(a[j])<abs(a[i])) {
//					dp[i] = max(dp[i],1+dp[j]);
//				}
//			}
		}
	}
	int maxi = 0;
	for (int i = 0; i < n ; i++) {
		maxi = max(dp[i],maxi);
	}
	cout << maxi << "\n";
	
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
////	
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
////		cout << "Case #" << ti  << ": ";
//		solve();
//	}
//	
	solve();
	
    return 0;
}
