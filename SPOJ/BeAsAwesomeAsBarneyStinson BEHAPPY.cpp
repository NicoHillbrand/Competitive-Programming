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
 
const int maxn = 21;
int n,m;
ii gift[maxn];
ll dp[101][maxn];
 
void solve(){
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < m ; i++) {
		cin >> gift[i].first >> gift[i].second;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= m ; i++) {
		for(int j = 0; j <= n; j++){
			for(int k = gift[i-1].first; k <= gift[i-1].second; k++){
				if (j-k>=0) {
					dp[j][i] += dp[j-k][i-1];
				}
			}
		}
	}
 
	
	cout << dp[n][m] << "\n";
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
