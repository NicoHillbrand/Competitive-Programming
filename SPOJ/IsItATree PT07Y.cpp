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
 
const int maxn = 2e5;
int n,m;
const int modd = 1e8;
vector<int> adj[maxn];
bool vis[maxn];
 
void dfs(int node){
	if (!vis[node]) {
		vis[node] = true;
		
		for(int c : adj[node]){
			dfs(c);
		}
	}
}
 
void solve(){
	cin >> n >> m;
	for (int i = 0; i < m ; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if (n-1!=m) {
		cout << "NO" << "\n";
		return;
	}
	int c = 0;
	for (int i = 0; i < n ; i++) {
		if (!vis[i]) {
			c++;
			dfs(i);
		}
	}
	if (c>1) {
		cout << "NO" << "\n";
		
	}else {
		cout << "YES" << "\n";
		
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
