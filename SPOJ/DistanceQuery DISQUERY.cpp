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
int n,k;
vector<ii> adj[maxn];
 
int up[maxn][25][3];
int depth[maxn];
 
void dfs(int node, int p, int cost){
	up[node][0][0] = p;
	up[node][0][1] = cost;
	up[node][0][2] = cost;
	for(ii c : adj[node]){
		if (c.first!=p) {
			depth[c.first] = depth[node]+1;
			dfs(c.first,node,c.second);
		}
	}
}
 
int lift(int node, int k){
	for (int i = 0; i <= ceil(log2(k))+1 ; i++) {
		if (!!(k&(1<<i))) {
			node = up[node][i][0];
		}
	}
	return node;
}
 
ii lift2(int node, int k){
	int maxi=-INF,mini=INF;
	for (int i = 0; i <= ceil(log2(k))+1 ; i++) {
		if (!!(k&(1<<i))) {
			maxi = max(up[node][i][2],maxi);
			mini = min(up[node][i][1],mini);
			node = up[node][i][0];
		}
	}
	return mp(mini,maxi);
}
 
 
void process(int u, int v){
	int mini=INF,maxi=-INF;
	
	if (depth[u]<depth[v]) {
		swap(u,v);
	}
	ii res = lift2(u,depth[u]-depth[v]);
	if (depth[u]!=depth[v]) {
		mini = res.first;
		maxi = res.second;
	}
	u = lift(u,depth[u]-depth[v]);
	if (u==v) {
		cout << mini << " " << maxi << "\n";
		return;
	}
 
	for(int i2 = ceil(log2(depth[u]))+1; i2>=0 ; i2--){
		int i = 1<<i2;
		if (lift(u,i)!=lift(v,i)) {
			ii ul2 = lift2(u,i);
			ii vl2 = lift2(v,i);
			mini = min(mini,min(ul2.first,vl2.first));
			maxi = max(maxi,max(ul2.second,vl2.second));
			u = lift(u,i);
			v = lift(v,i);
		}
	}
	
	
	ii ul2 = lift2(u,1);
	ii vl2 = lift2(v,1);
	
	mini = min(mini,min(ul2.first,vl2.first));
	maxi = max(maxi,max(ul2.second,vl2.second));
	
	cout << mini << " " << maxi << "\n";
}
 
void solve(){
	cin >> n;
	for (int i = 0; i < n-1 ; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	dfs(0,0,0);
	for (int i = 1; i < ceil(log2(n))+1 ; i++) {
		for(int node = 0; node < n; node++){
			up[node][i][0] = up[up[node][i-1][0]][i-1][0];
			up[node][i][1] = min(up[node][i-1][1],up[up[node][i-1][0]][i-1][1]);
			up[node][i][2] = max(up[node][i-1][2],up[up[node][i-1][0]][i-1][2]);
		}
	}
	cin >> k;
	for (int i = 0; i < k ; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		process(u,v);
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
////		cout << "Case #" << ti  << ": ";
//		solve();
//	}
	solve();
    return 0;
}
