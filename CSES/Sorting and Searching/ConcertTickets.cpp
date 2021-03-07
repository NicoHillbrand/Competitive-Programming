#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
int n ,m;
multiset<int> prizes;
 
void solve(){
	cin >> n >> m;
	for (int i = 0; i < n ; i++) {
		int p;
		cin >> p;
		prizes.insert(p);
	}
 
	int guy;
	for (int i = 0; i < m ; i++) {
		cin >> guy;
		auto it = prizes.upper_bound(guy);
		if (it==prizes.begin()) {
			cout << "-1" << "\n";
		}else {
			it--;
			cout << *it << "\n";
			prizes.erase(it);
		}
	}
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//freopen("text.in", "r", stdin);
//	freopen("test_input.txt", "r", stdin);
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
