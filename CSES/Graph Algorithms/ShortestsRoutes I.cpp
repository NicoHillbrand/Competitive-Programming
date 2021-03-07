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
 
const int maxn = 1e5+1;
int n, m;
vector<pll> adj[maxn];
vector<ll> dists(maxn,inf);
 
void dijkstra(int src){
 
	priority_queue< pll, vector <pll> , greater<pll> > pq;
	
	pq.push(make_pair(0,src));
	dists[src] = 0;
	ll v,w;
	while(!pq.empty()){
		pll up = pq.top();
		ll u = up.second;
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
}
 
 
void solve(){
	cin >> n >> m;
	ll u,v,w;
	for (int i = 0; i < m ; i++) {
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].push_back(make_pair(v,w));
	}
	dijkstra(0);
	for (int i = 0; i < n ; i++) {
		cout << dists[i] << " ";
	}
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
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
