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
 
int n;
ll dp[500][70000];
 
 
void solve(){
	cin >> n;
	if ((n*(n+1)/2)%2!=0) {
		cout << 0 << "\n";
		return;
	}
	int sum = n*(n+1)/4;
	dp[0][0] = 1;
	for (int i = 1; i < n ; i++) {
		for(int j = 0; j <= sum; j++){
			dp[i][j] = dp[i-1][j];
			if (j-i>=0) {
				dp[i][j] += dp[i-1][j-i];
				dp[i][j] %= 1000000007LL;
			}
		}
	}
	cout << dp[n-1][sum] << "\n";
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
    return 0;
}
