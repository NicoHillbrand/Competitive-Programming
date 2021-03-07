#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
int n;
 
void solve(){
	cin >> n;
	vi dp;
	int x;
	for (int i = 0; i < n ; i++) {
		cin >> x;
		auto it = lower_bound(dp.begin(),dp.end(),x);
		if (it==dp.end()) {
			dp.push_back(x);
		}else {
			*it=x;
		}
	}
	cout << dp.size() << "\n";
	
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
