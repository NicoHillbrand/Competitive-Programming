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
 
const int maxn = 2e5;
int n,m;
vector<int> adj[maxn];
vi dag[maxn];
int parent[maxn];
int dists[maxn];
int vis[maxn];
int indeg[maxn];
bool vis1[maxn];
 
void builddag(int node){
	if (!vis1[node]) {
		vis1[node] = true;
		for(int c: adj[node]){
			dag[node].pb(c);
			indeg[c]++;
			builddag(c);
		}
	}
}
 
 
void dfs(int node, int p){
	vis[node]++;
	if (dists[node]<dists[p]+1) {
		dists[node] = dists[p]+1;
		parent[node] = p;
	}
	if (vis[node]==indeg[node]) {
		for(int c : dag[node]){
			dfs(c,node);
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
		adj[u].pb(v);
	}
	//build dag
	builddag(0);
	
	//dag dp
	vis[0] = -1;
	dfs(0,0);
	
	if (n==1) {
		cout << 0 << "\n";
		cout << 1 << "\n";
		return;
	}
	if (dists[n-1]==0) {
		cout << "IMPOSSIBLE" << "\n";
	}else {
		//output
		stack<int> s;
		int no = n-1;
		while(no!=0){
			s.push(no+1);
			no = parent[no];
		}
		s.push(1);
		cout << s.size() << "\n";
		while(s.size()){
			cout << s.top() << " " ;
			s.pop();
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
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
//		cout << "Case #" << ti  << ": ";
//		solve();
//	}
	
	solve();
	
    return 0;
}
