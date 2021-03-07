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
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 2500;
int n, m, q;
vector<ll> adj[maxn];
vector<tuple<int,int,ll>> el;
bool vis[maxn];
 
bool dfs(int node, int goal){
	if (vis[node]) {
		return false;
	}
	vis[node] = true;
	if (node==goal) {
		return true;
	}
	bool res = false;
	for(int c : adj[node]){
		if (!vis[c]) {
			res|=dfs(c,goal);
		}
	}
	return res;
}
 
bool check(int node){
	if (dfs(0,node)) {
		for (int i = 0; i < n ; i++) {
			vis[i]=0;
		}
		if (dfs(node,n-1)) {
			return true;
		}
	}
	return false;
}
 
void solve(){
	cin >> n >> m;
	int u,v,w;
	for (int i = 0; i < m ; i++) {
		cin >> u >> v >> w;
		u--;
		v--;
		el.pb({u,v,-w});
		adj[u].push_back(v);
	}
	vector<ll> dists(n,inf);
	dists[0] = 0;
	for (int i = 0; i < n-1 ; i++) {
		for(int j = 0; j < m; j++){
			int u,v;
			ll w;
			tie(u,v,w) = el[j];
			if (dists[v]>dists[u]+w) {
				dists[v]=dists[u]+w;
			}
		}
	}
	
	for(int j = 0; j < m; j++){
		int u,v;
		ll w;
		tie(u,v,w) = el[j];
		if (dists[v]>dists[u]+w) {
			//found negative cycle
			//check if on the path
			if (check(u)) {
				cout << -1 << "\n";
				exit(0);
			}
		}
	}
	
	cout << -1*dists[n-1] << "\n";
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
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
