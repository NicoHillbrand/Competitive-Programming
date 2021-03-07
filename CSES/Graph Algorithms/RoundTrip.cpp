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
 
 
const int maxn = 2e5;
int n,m;
vector<int> adj[maxn];
int parent[maxn];
int dists[maxn];
bool vis[maxn];
bool ins[maxn];
bool done;
 
void dfs(int node, int p, int d){
	if (done) {
		return;
	}
	if (!vis[node]) {
		parent[node] = p;
		vis[node] = true;
		dists[node] = d;
		ins[node] = true;
		for(int c : adj[node]){
			dfs(c,node,d+1);
		}
		ins[node] = false;
	}
	if (vis[node]&&ins[node]&&dists[p]-dists[node]>1) {
		//solution
		done = true;
		cout << dists[p]-dists[node]+2 << "\n";
		cout << node+1 << " ";
		int no = p;
		while(no!=node){
			cout << no+1 << " ";
			no = parent[no];
		}
		cout << node+1 << " ";
	}
}
 
 
void solve(){
	cin >> n >> m;
	int u,v;
	for (int i = 0; i < m ; i++) {
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i = 0; i < n ; i++) {
		if (!vis[i]) {
			dfs(i,i,0);
		}
	}
	if (!done) {
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
 
	
	solve();
	
    return 0;
}
