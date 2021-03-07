#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
int n,m,q;
const ll inf = 1e17;
ll dists[501][501];
 
void solve(){
	cin >> n >> m >> q;
	for (int i = 0; i < n ; i++) {
		for(int j = 0; j < n; j++){
			dists[i][j] = inf;
			if (i==j) {
				dists[i][j] = 0;
			}
		}
	}
	
	for (int i = 0; i < m ; i++) {
		ll u,v,w;
		cin >> u >> v >> w;
		u--;
		v--;
		dists[u][v] = min(dists[u][v],w);
		dists[v][u] = min(dists[v][u],w);
	}
	
	for(int k = 0; k < n; k++){
		for (int i = 0; i < n ; i++) {
			for(int j = 0; j < n; j++){
				dists[i][j] = min(dists[i][j],dists[i][k]+dists[k][j]);
			}
		}
	}
	
	for (int i = 0; i < q ; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		if (dists[u][v]==inf) {
			cout << -1 << "\n";
		}else {
			cout << dists[u][v] << "\n";
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
