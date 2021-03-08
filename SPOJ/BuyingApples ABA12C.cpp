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
 
const int maxn = 101;
int n,k;
int a[maxn]; 
int dp[maxn][maxn];
 
 
void solve(){
	cin >> n >> k;
	for (int i = 0; i < k ; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i <= n ; i++) {
		for(int j = 1; j <= k; j++){
			dp[j][i] = INF-1005;
		}
	}
	
 
	for (int i = 1; i <= n ; i++) {
		for(int j = 1; j <= k; j++){
			for(int c = 0; c < k; c++){
				if (c+1<=j&&a[c]!=-1) {
					dp[j][i] = min(dp[j][i],dp[j-c-1][i-1]+a[c]);
				}
			}
		}
	}
 
	if (dp[k][n]==INF-1005) {
		cout << -1 << "\n";
	}else {
		cout << dp[k][n] << "\n";
	}
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
 
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
////	
////	
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ti++){
//		cout << "Case #" << ti  << ": ";
		solve();
	}
//	
//	solve();
	
    return 0;
}
