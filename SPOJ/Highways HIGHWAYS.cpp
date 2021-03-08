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
 
const int maxn = 2e5;
int n,m;
vector<ii> adj[maxn];
 
 
int dijkstra(int src, int d){
 
	vector<int> dists(maxn,INF);
	priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
	
	pq.push(make_pair(0,src));
	dists[src] = 0;
	int v,w;
	while(!pq.empty()){
		ii up = pq.top();
		int u = up.second;
		pq.pop();
		if (up.first>dists[u]) {
			continue;
		}
		for (auto pv: adj[u]) {
			v = pv.first;
			w = pv.second;
			
			if (dists[v]>dists[u]+w) {
				dists[v] = dists[u]+w;
				pq.push(make_pair(dists[v],v));
			}
		}
	}
	return dists[d];
}
 
 
void solve(){
	cin >> n >> m;
	int s,d;
	cin >> s >> d;
	s--;
	d--;
	int u,v,w;
	for (int i = 0; i < m ; i++) {
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	int res = dijkstra(s,d);
	if (res==INF) {
		cout << "NONE" << "\n";
		
	}else {
		cout << res << "\n";
		
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
//		cout << "Case #" << ti  << ": ";
		solve();
	}
	
//	solve();
	
    return 0;
}
