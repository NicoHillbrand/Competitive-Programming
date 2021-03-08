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
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 1e5;
int n,m;
vector<pll> adj[maxn][2];
vector<ii> dag[maxn];
vector<vector<ll>> dists(maxn,vector<ll>(2,inf));
vector<tuple<int,int,ll>> el;
 
 
 
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
 
 
 
 
void dijkstra2(int src, int dest){
 
	vector<int> dists2(maxn,INF);
	priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
	
	pq.push(make_pair(0,src));
	dists2[src] = 0;
	int v,w;
	while(!pq.empty()){
		ii up = pq.top();
		int u = up.second;
		pq.pop();
		if (up.first>dists2[u]) {
			continue;
		}
		for (auto pv: dag[u]) {
			v = pv.first;
			w = pv.second;
			
			if (dists2[v]>dists2[u]+w) {
				dists2[v] = dists2[u]+w;
				pq.push(make_pair(dists2[v],v));
			}
		}
	}
	if (dists2[dest]==INF) {
		cout << -1 << "\n";
		
	}else {
		cout << dists2[dest] << "\n";
		
	}
	
}
 
void solve(){
	cin >> n >> m;
	if (n==0&&m==0) {
		exit(0);
	}
	el.clear();
	for (int i = 0; i < n ; i++) {
		adj[i][0].clear();
		adj[i][1].clear();
		dists[i][0] = inf;
		dists[i][1] = inf;
		dag[i].clear();
	}
	
	int s, d;
	cin >> s >> d;
	ll u,v,w;
	for (int i = 0; i < m ; i++) {
		cin >> u >> v >> w;
		el.pb({u,v,w});
		adj[u][0].push_back({v,w});
		adj[v][1].push_back({u,w});
	}
 
	dijkstra(s,0);
	dijkstra(d,1);
	ll finald = dists[d][0];
	for (int i = 0; i < el.size() ; i++) {
		int u,v;
		ll w;
		tie(u,v,w) = el[i];
		if (finald != dists[u][0]+dists[v][1]+w) {
			dag[u].pb({v,w});
		}
	}
	dijkstra2(s,d);
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
 
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
//	
	int t=(int)1e8;
//	cin >> t;
	for(int ti = 1; ti <= t; ti++){
//		cout << "Case #" << ti  << ": ";
		solve();
	}
	
//	solve();
	
    return 0;
}
 
