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
 
 
const int maxn = 1e5;
int n,m;
bool vis[maxn];
bool instack[maxn];
int dists[maxn];
int parent[maxn];
vi adj[maxn];
 
void visit(int node, int p, int dist){
	
	if (!vis[node]) {
		vis[node] = true;
		instack[node] = true;
		parent[node] = p;
		dists[node] = dist;
		
		for(int c : adj[node]){
			visit(c,node,dist+1);
		}
		instack[node] = false;
	}
	if (instack[node]&&dists[p]-dists[node]>0) {
		//found solution
		cout << dists[p]-dists[node]+2 << "\n";
		cout << node+1 << " ";
		while(p!=node){
			cout << p+1 << " ";
			p = parent[p];
		}
		cout << node+1 << " ";
 
		exit(0);
	}
}
 
 
 
 
void solve(){
	cin >> n >> m;
	int u,v;
	for (int i = 0; i < m ; i++) {
		cin >> u >> v;
		u--;
		v--;
		adj[v].push_back(u);
	}
	
	
	for (int i = 0; i < n ; i++) {
		if (!vis[i]) {
			visit(i,i,0);
		}
	}
 
	cout << "IMPOSSIBLE" << "\n";
 
	
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
