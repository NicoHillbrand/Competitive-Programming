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
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const int INF = 5e8+1;
const ll inf = 1e16;
 
const int maxn = 5e5;
int n,timer,q,root;
 
int up[maxn][31];
int tin[maxn];
int tout[maxn];
bitset<250> sets[maxn];
vector<int> adj[maxn];
 
void dfs(int node, int p){
	tin[node] = ++timer;
	up[node][0] = p;
	for (int i = 1; i < ceil(log2(n))+1 ; i++) {
		up[node][i] = up[up[node][i-1]][i-1];
	}
	for(int c : adj[node]){
		if (c!=p) {
			dfs(c,node);
		}
	}
	tout[node] = ++timer;
}
 
bool isancestor(int u, int v){
	return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
 
int lca(int u, int v){
	if (isancestor(u, v)) {
		return u;
	}
	if (isancestor(v, u)) {
		return v;
	}
	for(int i = ceil(log2(n)); i>=0 ; i--){
		if (!isancestor(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}
 
 
void dpdfs(int node, int p){
	for(int c : adj[node]){
		if (c!=p) {
			dpdfs(c,node);
			sets[node] |= sets[c];
		}
	}
}
 
void solve(){
	cin >> n >> q >> root;
	timer = 0;
	for (int i = 0; i < n ; i++) {
		adj[i].clear();
		sets[i] = 0;
		int col;
		cin >> col;
		sets[i].set(col-1,1);
	}
	for (int i = 0; i < n-1 ; i++) {
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	//lca preprocessing
	dfs(root,root);
	
	//tree dp
	dpdfs(root,root);
	
	//answer queries
	for (int i = 0; i < q ; i++) {
		int u,v;
		cin >> u >> v;
		cout << sets[lca(u,v)].count() << "\n";
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
//		cout << "Case " << ti  << ":\n";
		solve();
	}
	
//	solve();
	
    return 0;
}
