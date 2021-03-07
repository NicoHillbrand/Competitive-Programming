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
#define ts to_string
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
 
 
 
const int maxn = 2e5;
int n,q;
 
int up[maxn][31];
int depth[maxn];
vector<int> adj[maxn];
 
void dfs(int node, int p){
	for(int c : adj[node]){
		if (c!=p) {
			depth[c] = depth[node]+1;
			dfs(c,node);
		}
	}
}
 
 
int kthancestor(int v, int k){
	for (int i = 0; i <= ceil(log2(k)) ; i++) {
		if (k&(1<<i)) {
			v = up[v][i];
		}
	}
	return v;
}
 
void solve(){
	cin >> n >> q;
	for (int i = 1; i < n ; i++) {
		int parent;
		cin >> parent;
		parent--;
		up[i][0] = parent;
		adj[parent].pb(i);
		adj[i].pb(parent);
	}
	up[0][0] = -1;
	for (int i = 1; i <= ceil(log2(n)) ; i++) {
		for(int j = 0; j < n; j++){
			if (up[j][i-1]!=-1) {
				up[j][i] = up[up[j][i-1]][i-1];
			}
		}
	}
	dfs(0,0);
	for (int i = 0; i < q ; i++) {
		int u,k;
		cin >> u >> k;
		u--;
		if (depth[u]<k) {
			
			cout << -1 << "\n";
			
		}else {
			cout << kthancestor(u,k)+1 << "\n";
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