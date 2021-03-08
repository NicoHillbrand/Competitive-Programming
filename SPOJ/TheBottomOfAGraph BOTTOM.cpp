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
int n,m;
 
int comps;
bool vis[maxn];
int comp[maxn];
bool good[maxn];
vector<int> adj[maxn][2];
stack<int> s;
 
void dfs(int node,int dir){
	if (!vis[node]) {
		vis[node] = true;
		if (dir==1) {
			comp[node] = comps;
		}
		for(int c : adj[node][dir]){
			if (!vis[c]) {
				dfs(c,dir);
			}
		}
		if (dir==0) {
			s.push(node);
		}
	}
}
 
void scc(){
	for (int i = 0; i < n ; i++) {
		if (!vis[i]) {
			dfs(i,0);
		}
	}
	for (int i = 0; i < n ; i++) {
		vis[i] = 0;
	}
	while(s.size()){
		int next = s.top();
		s.pop();
		if (!vis[next]) {
			comps++;
			good[comps] = 1;
			dfs(next,1);
		}
	}
}
 
 
void solve(){
	cin >> n;
	if (n==0) {
		exit(0);
	}
	cin >> m;
	comps = 0;
	for (int i = 0; i < n ; i++) {
		adj[i][0].clear();
		adj[i][1].clear();
		comp[i] = 0;
		vis[i] = 0;
	}
	for (int i = 0; i < m ; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		adj[u][0].pb(v);
		adj[v][1].pb(u);
	}
	
	scc();
	
	
	//we want to print all nodes in components that don't have outgoing edges
	for (int i = 0; i < n ; i++) {
		if (!good[comp[i]]) {
			continue;
		}
		for(int j = 0; j < adj[i][0].size(); j++){
			if (comp[i]!=comp[adj[i][0][j]]) {
				good[comp[i]] = 0;
			}
		}
	}
	set<int> res;
	for (int i = 1; i <= comps ; i++) {
		if (good[i]) {
			for(int j = 0; j < n; j++){
				if (comp[j] == i) {
					res.insert(j+1);
				}
			}
		}
	}
	for(int r : res){
		if (res.find(r)==--res.end()) {
			cout << r;
		}else {
			cout << r << " " ;
		}
	}
	cout << "\n";
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
//	
	while(true){
		solve();
	}
//	solve();
	
    return 0;
}
