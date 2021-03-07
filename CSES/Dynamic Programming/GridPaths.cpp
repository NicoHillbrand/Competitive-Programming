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
 
const int maxn = 2e3+1;
int n;
string maap[maxn];
ll dp[maxn][maxn];
bool vis[maxn][maxn];
 
ll rec(int x, int y){
	ll res = 0;
	if (vis[x][y]) {
		return dp[x][y];
	}
	if (x==0&&y==0) {
		res = 1;
	}
	if (y>0) {
		res+=rec(x,y-1);
		res%=1000000007LL;
	}
	if (x>0) {
		res+=rec(x-1,y);
		res%=1000000007LL;
	}
	if (maap[y].at(x)=='*') {
		res = 0;
	}
	vis[x][y] = true;
	dp[x][y] = res;
	return res;
}
 
void solve(){
	cin >> n;
	for (int i = 0; i < n ; i++) {
		cin >> maap[i];
	}
	cout << rec(n-1,n-1) << "\n";
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
