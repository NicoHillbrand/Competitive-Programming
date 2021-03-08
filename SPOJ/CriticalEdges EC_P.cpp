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
 
const int maxn = 1e6+1;
 
int n, m;
vector<int> adj[maxn];
vii bridges;
int low[maxn];
int disc[maxn];
int timer;
 
void dfs(int node, int parent){
	low[node] = disc[node] = ++timer;
	for(int c : adj[node]){
		if (c==parent) {
			continue;
		}
		if (!disc[c]) {
			dfs(c,node);
			if (!(low[c]<=disc[node])) {
				bridges.pb(mp(min(node,c)+1,max(node,c)+1));
			}
			low[node] = min(low[node],low[c]);
		}else {
			low[node] = min(low[node],disc[c]);
		}
	}
}
 
 
void solve(){
	cin >> n >> m;
	timer = 0 ;
	bridges.clear();
	for (int i = 0; i < n ; i++) {
		adj[i].clear();
		low[i] = 0;
		disc[i] = 0;
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
		if (disc[i]==0) {
			dfs(i,i);
		}
	}
	
	sort(bridges.begin(),bridges.end());
	if (bridges.size()==0) {
		cout << "Sin bloqueos" << "\n";		
	}else {
		cout << bridges.size() << "\n";
		for (int i = 0; i < bridges.size() ; i++) {
			cout << bridges[i].first << " " << bridges[i].second << "\n";
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
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ti++){
		cout << "Caso #" << ti  << "\n";
		solve();
	}
//	solve();
    return 0;
}
