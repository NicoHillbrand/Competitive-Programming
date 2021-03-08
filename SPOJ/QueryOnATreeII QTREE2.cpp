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
 
const int maxn = 1e5+1;
 
int n;
 
int up[maxn][31];
ll costup[maxn][31];
vector<ii> adj[maxn];
int depth[maxn];
 
void dfs(int node, int parent, int cost){
	up[node][0] = parent;
	costup[node][0] = cost;
	for(ii c: adj[node]){
		if (c.first!=parent) {
			depth[c.first] = depth[node]+1;
			dfs(c.first,node,c.second);
		}
	}
}
 
int kthancestor(int v, int k){
	for (int i = 0; i <= ceil(log2(k))+1 ; i++) {
		if (k&(1<<i)) {
			v = up[v][i];
		}
	}
	return v;
}
 
ll kcost(int v, int k){
	ll cost = 0;
	for (int i = 0; i <= ceil(log2(k))+1 ; i++) {
		if (k&(1<<i)) {
			cost += costup[v][i];
			v = up[v][i];
		}
	}
	return cost;
}
 
 
ll dists(int u, int v){
	if (u==v) {
		return 0;
	}
	if (depth[u]<depth[v]) {
		swap(u,v);
	}
	int res = 0;
	if (depth[u]>depth[v]) {
		res = kcost(u,depth[u]-depth[v]);
		u = kthancestor(u, depth[u]-depth[v]);
	}
	if (u==v) {
		return res;
	}
	for(int i = ceil(log2(n)); i>=0 ; i--){
		if (up[u][i]!=up[v][i]) {
			res += kcost(u,(1<<i))+kcost(v,(1<<i));
			u = up[u][i];
			v = up[v][i];
		}
	}
	
	return res+kcost(u,1)+kcost(v,1);
}
 
int query(int u, int v, int k){
	k--;
	if (k==0) {
		return u;
	}
	int us=u, vs=v;
	int lca;
	if (depth[us]<depth[vs]) {
		swap(us,vs);
	}
	if (depth[us]>depth[vs]) {
		us = kthancestor(us, depth[us]-depth[vs]);
	}
	if (us==vs) {
		lca = us;
	}else {
		for(int i = ceil(log2(n))+1; i>=0 ; i--){
			if (up[us][i]!=up[vs][i]) {
				us = up[us][i];
				vs = up[vs][i];
			}
		}
		lca = up[us][0];
	}
	
	if (k==depth[u]+depth[v]-2*depth[lca]) {
		return v;
	}
	if (depth[u]-depth[lca]>=k) {
		return kthancestor(u, k);
	}else {
		k -= depth[u]-depth[lca];
		return kthancestor(v, depth[v]-depth[lca]-k);
	}
}
 
 
 
void solve(){
	cin >> n;
	for (int i = 0; i < n ; i++) {
		adj[i].clear();
		depth[i] = 0;
	}
	
	for (int i = 0; i < n-1 ; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	
	//determine root and parent
	dfs(0,0,0);
	
	for (int i = 1; i <= ceil(log2(n))+1 ; i++) {
		for(int j = 0; j < n; j++){
			up[j][i] = up[up[j][i-1]][i-1];
		}
	}
	for (int i = 1; i <= ceil(log2(n))+1 ; i++) {
		for(int j = 0; j < n; j++){
			costup[j][i] = costup[j][i-1]+costup[up[j][i-1]][i-1];
		}
	}
	
	while(true){
		string s;
		cin >> s;
		if (s[1]=='O') {
			cout  << "\n";
			return;
		}
		if (s[0]=='D') {
			int u,v;
			cin >> u >> v;
			u--;
			v--;
			cout << dists(u,v) << "\n";
		}else {
			int u,v,k;
			cin >> u >> v >> k;
			u--;
			v--;
			cout << query(u,v,k)+1 << "\n";
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
//		cout << "Caso #" << ti  << "\n";
		solve();
	}
	
    return 0;
}
