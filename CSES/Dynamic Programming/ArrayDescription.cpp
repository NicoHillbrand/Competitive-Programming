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
 
 
const int maxn = 1e5+1;
int n,m;
ll dp[maxn][101]; 
 
 
void solve(){
	cin >> n >> m;
	int first;
	cin >> first;
	if (first==0) {
		for (int i = 1; i <= m ; i++) {
			dp[0][i] = 1;
		}
	}else {
		dp[0][first] = 1;
	}
	
	for (int i = 1; i < n ; i++) {
		int next;
		cin >> next;
		if (next==0) {
			for (int j = 1; j <=m ; j++) {
				for(int k = j-1; k < j+2; k++){
					if (k>0&&k<=m) {
						dp[i][j]+=dp[i-1][k];
						dp[i][j]%=1000000007LL;
					}
				}
			}
		}else {
			for (int j = next-1; j < next+2 ; j++) {
				if (j>0&&j<=m) {
					dp[i][next]+=dp[i-1][j];
					dp[i][next]%=1000000007LL;
				}
			}
		}
	}
	
	ll sol=0;
	for (int i = 0; i <=m ; i++) {
		sol+=dp[n-1][i];
		sol%=1000000007LL;
	}
	cout << sol << "\n";
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
//	
 
	
	solve();
	
    return 0;
}
