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
ll nway[1000005];
int a[1000005];
 
 
void solve(){
	cin >> n >> x;
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	
	nway[0] = 0;
	for (int i = 1; i <= x ; i++) {
		nway[i] = INT_MAX;
		for(int j = 0; j < n; j++){
			if (i-a[j]>=0) {
				nway[i]=min(nway[i],nway[i-a[j]]+1);
			}
		}
	}
	if (x==0) {
		cout << 1 << "\n";
	}else {
		if (nway[x]==INT_MAX) {
			cout << -1 << "\n";
		}else {
			cout << nway[x] << "\n";
		}
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
