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
ii tasks[200005];
 
 
void solve(){
	cin >> n;
	int a, b;
	for (int i = 0; i < n ; i++) {
		cin >> tasks[i].first;
		cin >> tasks[i].second;
	}
	sort(tasks,tasks+n);
	ll cur = 0;
	ll rew = 0;
	for (int i = 0; i < n ; i++) {
		cur+=tasks[i].first;
		rew += tasks[i].second-cur;
	}
	cout << rew << "\n";
	
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
