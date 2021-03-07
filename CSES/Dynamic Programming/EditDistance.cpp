#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
string a, b;
int an, bn;
int dp[5001][5001];
 
 
void solve(){
	cin >> a >> b;
	an = a.length();
	bn = b.length();
//	for (int i = 0; i <=an ; i++) {
//		for(int j = 0; j <= bn; j++){
//			dp[i][j] = 100000000;
//		}
//	}
 
	dp[0][0] = 0;
	
	
	int sc;
	for(int i = 0; i <= an; i++){
		for (int j = 0; j <= bn ; j++) {
			if (i==0) {
				dp[i][j] = j;
			}else if (j==0) {
				dp[i][j] = i;
			}else{
				if (a[i-1]==b[j-1]) {
					sc= 0;
				}else {
					sc= 1;
				}
				dp[i][j] = min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+sc));
			}
			
		}
		
	}
	cout << dp[an][bn] << "\n";
	
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
