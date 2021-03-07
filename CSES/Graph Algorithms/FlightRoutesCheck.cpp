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
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 1e5;
int n,m, marked;
 
bool vis[maxn];
vector<int> adj[maxn][2];
bool works;
ii example;
 
void dfs(int node, int dir){
	if (!vis[node]) {
		vis[node] = true;
		marked--;
		for(int c : adj[node][dir]){
			dfs(c,dir);
		}
	}
}
 
void solve(){
	cin >> n >> m;
	for (int i = 0; i < m ; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		adj[u][0].pb(v);
		adj[v][1].pb(u);
	}
	works = true;
	marked = n;
	dfs(0,0);
	
	
	if (marked!=0) {
		works = false;
		for (int i = 1; i < n ; i++) {
			if (!vis[i]) {
				example = mp(0,i);
				break;
			}
		}
	}else {
		for (int i = 0; i < n ; i++) {
			vis[i] = 0;
		}
		marked = n;
		dfs(0,1);
		if (marked!=0) {
			works = false;
			for (int i = 1; i < n ; i++) {
				if (!vis[i]) {	
					example = mp(i,0);
					break;
				}
			}
		}
	}
	
	if (works) {
		cout << "YES" << "\n";
	}else {
		cout << "NO" << "\n";
		cout << example.first+1 << " " << example.second+1 << "\n";
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
