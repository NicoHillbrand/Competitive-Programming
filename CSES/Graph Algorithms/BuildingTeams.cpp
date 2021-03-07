#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <string>
using namespace std;
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX
const ll inf = 1e16;
 
 
const int maxn = 1e5;
int n,m;
bool p;
vector<int> adj[maxn];
int team[maxn];
bool vis[maxn];
 
void dfs(int node, bool color){
	if (!vis[node]) {
		vis[node] = true;
		team[node] = color;
		
		for(int c:adj[node]){
			if (!vis[c]) {
				dfs(c,1-color);
			}
		}
	}
}
 
void solve(){
	cin >> n >> m;
	for (int i = 0; i < m ; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 0; i < n ; i++) {
		if (!vis[i]) {
			dfs(i,0);
		}
	}
	
	
	bool p = true;
	for (int i = 0; i < n ; i++) {
		for(int c : adj[i]){
			if (team[i]==team[c]) {
				p = false;
			}
		}
	}
	
	if (p) {
		for (int i = 0; i < n ; i++) {
			cout << team[i]+1 << " ";
		}
	}else {
		cout << "IMPOSSIBLE" << "\n";
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
 
 
