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
vector<pll> adj[maxn][2];
vector<int> dag[maxn];
vector<vector<ll>> dists(maxn,vector<ll>(2,inf));
vector<tuple<int,int,ll>> el;
ll nway[maxn];
int minlen[maxn];
int maxlen[maxn];
int filld[maxn];
int deg[maxn];
bool vis[maxn];
 
void dfs1(int node){
	deg[node]++;
	if (!vis[node]) {
		vis[node] = true;
		for(int c : dag[node]){
			dfs1(c);
		}
	}
}
 
void search(int node,int parent){
	//we already processed the parent
	if (node!=0) {
		nway[node] += nway[parent];
		nway[node] %= 1000000007LL;
		minlen[node] = min(minlen[node],minlen[parent]+1);
		maxlen[node] = max(maxlen[node],maxlen[parent]+1);
	}
	if (deg[node]==filld[node]+1||node==0) {
		filld[node]++;
		for(int c : dag[node]){
			search(c,node);
		}
	}else {
		filld[node]++;
	}
}
 
void dijkstra(int src,int dir){
 
	priority_queue< pll, vector <pll> , greater<pll> > pq;
	
	pq.push(make_pair(0,src));
	dists[src][dir] = 0;
	ll v,w;
	while(!pq.empty()){
		pll up = pq.top();
		ll u = up.second;
		pq.pop();
		if (up.first>dists[u][dir]) {
			continue;
		}
		for (auto pv: adj[u][dir]) {
			v = pv.first;
			w = pv.second;
			
			if (dists[v][dir]>dists[u][dir]+w) {
				dists[v][dir] = dists[u][dir]+w;
				pq.push(make_pair(dists[v][dir],v));
			}
		}
	}
}
 
 
void solve(){
	cin >> n >> m;
	ll u,v,w;
	for (int i = 0; i < m ; i++) {
		cin >> u >> v >> w;
		u--;
		v--;
		el.pb({u,v,w});
		adj[u][0].push_back({v,w});
		adj[v][1].push_back({u,w});
	}
 
	dijkstra(0,0);
	dijkstra(n-1,1);
	ll finald = dists[n-1][0];
	cout << finald << " " ;
	for (int i = 0; i < el.size() ; i++) {
		int u,v;
		ll w;
		tie(u,v,w) = el[i];
		if (finald == dists[u][0]+dists[v][1]+w) {
			dag[u].pb(v);
		}
	}
	
	dfs1(0);
	nway[0] = 1;
	for (int i = 1; i < n ; i++) {
		minlen[i] = INF;
	}
	search(0,0);
	cout << nway[n-1] << " " << minlen[n-1] << " " << maxlen[n-1] << "\n";
	
	//paths in the dag
	//longest and shortest path in dag
//	cout << dp[n-1][0] << " " << dp[n-1][1]+1 << " " << dp[n-1][2]+1 << "\n";
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
////	
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
