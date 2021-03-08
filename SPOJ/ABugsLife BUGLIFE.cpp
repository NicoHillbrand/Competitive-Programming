#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <iostream>
//#include <vector>
//#include <string>
using namespace std;
//using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 2e3;
int n,m;
bool vis[maxn];
vector<int> adj[maxn];
bool col[maxn];
bool conflict;
 
 
void dfs(int node, int color){
	if (conflict) {
		return;
	}
	if (!vis[node]) {
		vis[node] = true;
		col[node] = color;
		for(int c : adj[node]){
			dfs(c,1-color);
		}
	}else if(col[node]!=color){
		conflict = true;
	}
}
 
 
void solve(){
	cin >> n >> m;
	conflict = 0;
	for (int i = 0; i < n ; i++) {
		adj[i].clear();
		vis[i] = 0;
	}
	for (int i = 0; i < m ; i++) {
		int u,v;
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
	if (conflict) {
		cout << "Suspicious bugs found!" << "\n";
	}else {
		cout << "No suspicious bugs found!" << "\n";
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
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ti++){
		cout << "Scenario #" << ti  << ":" << endl;
		solve();
	}
	
//	solve();
	
    return 0;
}
