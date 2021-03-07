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
 
const int maxn = 2e5;
int n,m;
 
bool incl[maxn];
int comps;
bool vis[maxn];
int comp[maxn];
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
	for (int i = 0; i < m ; i++) {
		comp[i] = -1;
		if (!vis[i]) {
			dfs(i,0);
		}
	}
	for (int i = 0; i < m ; i++) {
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
 
 
 
 
 
void solve(){
	cin >> n >> m;
	m*=2;
	for (int i = 0; i < n ; i++) {
		//build graph
		char c1,c2;
		bool b1,b2;
		int u,v;
		cin >> c1 >> u >> c2 >> v;
		u--;
		v--;
		u*=2;
		v*=2;
		if (c1=='+') {
			b1=true;
		}else {
			b1= 0;
		}
		if (c2=='+') {
			b2 = 1;
		}else {
			b2 = 0;
		}
		
		if (b1) {
			if (b2) {
				//+ +
				adj[u+1][0].pb(v);
				adj[v+1][0].pb(u);
				//rev
				adj[v][1].pb(u+1);
				adj[u][1].pb(v+1);
			}else {
				//+ -
				adj[u+1][0].pb(v+1);
				adj[v][0].pb(u);
				
				adj[v+1][1].pb(u+1);
				adj[u][1].pb(v);
			}
		}else {
			if (b2) {
				//- +
				adj[u][0].pb(v);
				adj[v+1][0].pb(u+1);
				
				adj[v][1].pb(u);
				adj[u+1][1].pb(v+1);
			}else {
				//- -
				adj[u][0].pb(v+1);
				adj[v][0].pb(u+1);
				
				adj[v+1][1].pb(u);
				adj[u+1][1].pb(v);
			}
			
		}
		
	}
	
	
	
	scc();
	
	
	for (int i = 0; i < m ; i+=2) {
		if (comp[i]==comp[i+1]) {
			cout << "IMPOSSIBLE" << "\n";
			return;
		}
		incl[i/2] = comp[i]>comp[i+1];
	}
	
	for (int i = 0; i < m/2 ; i++) {
		if (incl[i]) {
			cout << "+" << " " ;
		}else {
			cout << "-" << " " ;
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
