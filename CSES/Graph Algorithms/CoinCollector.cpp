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
typedef vector<ll> vll;
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
 
const int maxn = 1e6;
 
int n,m;
ll coin[maxn];
ll compcoin[maxn];
vi dag[maxn];
int comps;
bool vis[maxn];
int indeg[maxn];
int comp[maxn];
vector<int> adj[maxn][2];
stack<int> s;
ll dp[maxn];
 
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
			dfs(next,1);
		}
	}
}
 
 
ll dfs2(int node){
	if (!vis[node]) {
		vis[node] = true;
		ll coins = 0;
		for(int c : dag[node]){
			coins = max(coins,dfs2(c));
		}
		dp[node] = coins+compcoin[node];
	}
	return dp[node];
}
 
void solve(){
	cin >> n >> m;
	for (int i = 0; i < n ; i++) {
		cin >> coin[i];
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
	
	for (int i = 0; i < n ; i++) {
		compcoin[comp[i]]+=coin[i];
	}
	
	for (int i = 0; i < n ; i++) {
		vis[i] = 0;
		for(int j = 0; j < adj[i][0].size(); j++){
			if (comp[i]!=comp[adj[i][0][j]]) {
				dag[comp[i]].pb(comp[adj[i][0][j]]);
			}
		}
	}
	vis[n] = 0;
	ll res = 0;
	for (int i = 1; i <=comps ; i++) {
		if (indeg[i]==0) {
			res = max(res,dfs2(i));
		}
	}
	cout << res << "\n";
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
	
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
////		cout << "Case #" << ti  << ": ";
//		solve();
//	}
//	
	solve();
	
    return 0;
}
