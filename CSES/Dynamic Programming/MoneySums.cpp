#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
int n, sum;
int a[100];
bool dp[101][100001];
 
void solve(){
 
	cin >> n;
	
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
		sum+= a[i];
	}
	
	dp[0][0] = 1;
	int res = 0;
	for (int i = 1; i <= n ; i++) {
		//up to i
		for(int j = 0; j <= sum; j++){
			//not include
			dp[i][j]= dp[i-1][j];
			//include i?
			if (j-a[i-1]>=0&&dp[i-1][j-a[i-1]]) {
				dp[i][j] = 1;
			}
		}
	}
	
	for (int i = 1; i <= sum ; i++) {
		if (dp[n][i]) {
			res++;
		}
	}
	
	cout << res << "\n";
	
	for (int i = 1; i <= sum ; i++) {
		if (dp[n][i]) {
			cout << i << " ";
		}
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
