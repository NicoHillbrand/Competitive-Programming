#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
int n,x;
ii a[5000];
 
 
void solve(){
	cin >> n >> x;
	for (int i = 0; i < n ; i++) {
		cin >> a[i].first;
		a[i].second = i+1;
	}
	sort(a,a+n);
	int s;
	for (int i = 0; i < n ; i++) {
		s = x-a[i].first;
		//two pointer
		int lp = 0;
		int rp = n-1;
		while(lp<rp){
			if (s==a[lp].first+a[rp].first&&a[i].second!=a[lp].second&&a[i].second!=a[rp].second) {
				cout << a[i].second << " " << a[lp].second << " " << a[rp].second << "\n";
				return;
			}
			if (s<a[lp].first+a[rp].first) {
				rp--;
			}else {
				lp++;
			}
		}
	}
	cout << "IMPOSSIBLE" << "\n";
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
