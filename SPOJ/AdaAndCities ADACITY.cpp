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
 
const int maxn = 501;
 
ll n,m,f,timer;
int fr[501];
ll dists[501][501];
vector<int> adj[maxn];
bool vis[maxn];
int assigned[maxn];
 
 
bool matching(int fri){
	for(int c : adj[fri]){
		if (vis[c]) {
			continue;
		}
		vis[c] = true;
		if (assigned[c]<0) {
			assigned[c] = fri;
			return true;
		}else if(matching(assigned[c])){
			assigned[c] = fri;
			return true;
		}
	}
	return false;
}
 
 
 
void solve(){
	cin >> n >> m >> f >> timer;
	for (int i = 0; i < f ; i++) {
		cin >> fr[i];
		fr[i]--;
	}
	for (int i = 0; i < 500 ; i++) {
		adj[i].clear();
	}
	
	for (int i = 0; i < n ; i++) {
		for(int j = 0; j < n; j++){
			dists[i][j] = inf;
			if (i==j) {
				dists[i][j] = 0;
			}
		}
	}
	
	for (int i = 0; i < m ; i++) {
		ll u,v,w;
		cin >> u >> v >> w;
		u--;
		v--;
		dists[u][v] = min(dists[u][v],w);
		dists[v][u] = min(dists[v][u],w);
	}
	
	for(int k = 0; k < n; k++){
		for (int i = 0; i < n ; i++) {
			for(int j = 0; j < n; j++){
				dists[i][j] = min(dists[i][j],dists[i][k]+dists[k][j]);
			}
		}
	}
	
	//split the graph into friends and cities connected to each friend
	for (int i = 0; i < n ; i++) {
		for(int j = 0; j < f; j++){
			if (dists[fr[j]][i]<= timer) {
				adj[j].pb(i);
				//backedge too? no need
			}
		}
	}
	
	//maximum matching
	int res = 0;
	for (int i = 0; i < n ; i++) {
		assigned[i] = -1;
	}
	
	for (int i = 0; i < f ; i++) {
		for(int j = 0; j < n; j++){
			vis[j] = 0;
		}
		if (matching(i)) {
			res++;
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
//	
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ti++){
//		cout << "Case " << ti  << ":\n";
		solve();
	}
//	solve();
    return 0;
}
