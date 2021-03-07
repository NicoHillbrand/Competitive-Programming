#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
int n , m , k;
int s[200001], r[200001];
 
 
 
void solve(){
 
	cin >> n >> m >> k;
	
	for (int i = 0; i < n ; i++) {
		cin >> s[i];
		s[i]-=k;
	}
	sort(s,s+n);
	for (int i = 0; i < m ; i++) {
		cin >> r[i];
	}
	sort(r,r+m);
	int res = 0;
	int used = 0;
	int start;
	for (int i = 0; i < n ; i++) {
		start = s[i];
		if (start+2*k<r[used]) {
			continue;
		}
		while(r[used]<start&&used<m){
			used++;
		}
		if (used==m) {
			break;
		}
		if (r[used]<=start+2*k) {
			res++;
			used++;
		}
	}
	
	cout << res << "\n";
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
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
