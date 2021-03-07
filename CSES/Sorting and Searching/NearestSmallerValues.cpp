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
	int x;
	stack<ii> s;
	for (int i = 1; i <= n ; i++) {
		cin >> x;
		while(!s.empty()&&s.top().first>=x){
			s.pop();
		}
		if (s.empty()) {
			cout << 0 << " ";
		}else {
			cout << s.top().second << " ";
		}
		s.push(make_pair(x,i));
	}
	
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
