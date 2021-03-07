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
 
const int maxn = 2e6+1;
ll dp[maxn];
int n;
 
void solve(){
	cin >> n;
	dp[0] =1;
	for (int i = 1; i <=n ; i++) {
		for(int j = 1; j < 7; j++){
			if (i-j>=0) {
				dp[i]+=dp[i-j];
				dp[i]%=1000000007LL;
			}
		}
	}
	cout << dp[n] << "\n";
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
//	
//	freopen("stamps.in", "r", stdin);
//	freopen("stamps.out", "w", stdout);
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
