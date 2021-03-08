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
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 1e5;
int n;
vector<int> adj[maxn];
bool vis[maxn];
int furthest;
int md;
 
void dfs(int node, int d){
	if (!vis[node]) {
		vis[node] = true;
		if (md<d) {
			md=d;
			furthest =node;
		}
		for(int c : adj[node]){
			dfs(c,d+1);
		}
	}
}
 
void solve(){
	cin >> n;
	md = 0;
	for (int i = 0; i < n ; i++) {
		adj[i].clear();
		vis[i]=0;
	}
	
	int u,v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(0,0);
	for (int i = 0; i < n ; i++) {
		vis[i] = 0;
	}
	dfs(furthest,0);
	cout << (md+1)/2 << "\n";
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
//		cout << "Case #" << ti  << ": ";
		solve();
	}
	
//	solve();
	
    return 0;
}
