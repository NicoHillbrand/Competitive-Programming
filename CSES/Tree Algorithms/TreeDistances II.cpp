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
ll nsub[200005], subsum[200005], dist[200005];
vi adj[200005];
 
void dfs1(int node, int parent){
	nsub[node] = 1;
	for(int c:adj[node]){
		if (c!=parent) {
			dfs1(c,node);
			nsub[node]+=nsub[c];
		}
	}
}
 
void dfs2(int node,int parent){
	for(int c:adj[node]){
		if (c!=parent) {
			dfs2(c,node);
			subsum[node]+=subsum[c]+nsub[c];
		}
	}
}
 
void dfs3(int node,int parent){
	if (node==0) {
		dist[node] = subsum[0];
	}else {
		dist[node] = dist[parent]+(n-nsub[node])-nsub[node];
	}
	
	for(int c:adj[node]){
		if (c!=parent) {
			dfs3(c,node);
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
	
	dfs1(0,0);
	dfs2(0,0);
	dfs3(0,0);
	
	for (int i = 0; i < n ; i++) {
		cout << dist[i] << " ";
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
