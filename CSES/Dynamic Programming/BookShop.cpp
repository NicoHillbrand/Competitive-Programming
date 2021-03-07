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
 
const int maxn = 2e5+1;
int n,x;
ii book[maxn];
int dp[1001][maxn];
 
void solve(){
	cin >> n >> x;
	for (int i = 0; i < n ; i++) {
		cin >> book[i].first;
	}
	for (int i = 0; i < n ; i++) {
		cin >> book[i].second;
	}
	for (int i = 1; i <= n ; i++) {
		for(int j = 0; j <=x; j++){
			dp[i][j] = dp[i-1][j];
			if (j-book[i-1].first>=0) {
				dp[i][j] = max(dp[i][j],dp[i-1][j-book[i-1].first]+book[i-1].second);
			}
		}
	}
	cout << dp[n][x] << "\n";
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
    return 0;
}
