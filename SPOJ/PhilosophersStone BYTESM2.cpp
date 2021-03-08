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
int h,w;
int a[maxn][maxn];
int dp[maxn][maxn];
 
 
void solve(){
	cin >> h >> w;
	for (int i = 0; i < h ; i++) {
		for(int j = 0; j < w; j++){
			cin >> a[j][i];
			dp[j][i] = 0;
		}
	}
	for (int i = 0; i < w ; i++) {
		dp[i][0] = a[i][0];
	}
	
	for (int i = 1; i < h ; i++) {
		for(int j = 0; j < w; j++){
			for(int k = -1; k < 2; k++){
				if (k+j>=0&&k+j<w) {
					dp[j][i] = max(dp[j][i],dp[j+k][i-1]+a[j][i]);
				}
			}
		}
	}
	int maxi = 0;
	for (int i = 0; i < w ; i++) {
		maxi = max(maxi,dp[i][h-1]);
	}
 
	cout << maxi << "\n";
	
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
