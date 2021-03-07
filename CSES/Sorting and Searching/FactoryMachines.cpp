#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
 
int n, t, a[200005];
 
void solve(){
	
	cin >> n >> t;
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	ll lb = 1, rb = 1e18;
	while(lb<rb){
		ll mid = (lb+rb)/2, s = 0;
		for (int i = 0; i < n ; i++) {
			s+= min(mid/a[i],(ll)1e9);
		}
		if (s>=t) {
			rb = mid;
		}else {
			lb = mid+1;
		}
	}
	cout << lb << "\n";
	
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
