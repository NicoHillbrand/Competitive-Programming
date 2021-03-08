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
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX
const ll inf = 1e16;
 
 
const int maxn = 1e5;
int n,m;
vector<ii> adj[maxn];
int furthest;
int maxlen;
bool vis[maxn];
 
int dfs2(int node){
	int res = 0;
	if (!vis[node]) {
		vis[node] = true;
		for(ii c : adj[node]){
			if (!vis[c.first]) {
				res = max(res,dfs2(c.first)+c.second);
			}
		}
	}
	return res;
}
 
void dfs(int node, int d){
	if (!vis[node]) {
		vis[node] = true;
		if (d>maxlen) {
			furthest = node;
			maxlen = d;
		}
		for(ii c : adj[node]){
			dfs(c.first,d+c.second);
		}
	}
}
 
void solve(){
	cin >> n;
	furthest = 0;
	maxlen = 0;
	for (int i = 0; i < n ; i++) {
		adj[i].clear();
		vis[i] = 0;
	}
	
	for (int i = 0; i < n-1 ; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	dfs(0,0);
	for (int i = 0; i < n ; i++) {
		vis[i] = 0;
	}
	cout << dfs2(furthest) << "\n";
	
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
