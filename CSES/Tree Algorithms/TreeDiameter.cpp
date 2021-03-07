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
vi adj[200005];
bool seen[200005];
int furthest, len;
 
void dfsfurthest(int node,int d){
	if (len<d) {
		len = d;
		furthest = node;
	}
	seen[node] = true;
	for(int c:adj[node]){
		if (!seen[c]) {
			dfsfurthest(c, d+1);
		}
	}
}
 
void solve(){
	cin >> n;
	int u,v;
	for (int i = 0; i < n-1 ; i++) {
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	len = -1;
	dfsfurthest(0, 0);
	for (int i = 0; i < n ; i++) {
		seen[i] = 0;
	}
	len = -1;
	dfsfurthest(furthest, 0);
	cout << len << "\n";
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
