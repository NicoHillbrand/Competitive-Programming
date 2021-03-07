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
int n,m,k,c;
vector<pll> adj[maxn];
int used[maxn];
 
void dijkstra(int src){
 
	priority_queue< pll, vector <pll> , greater<pll> > pq;
	
	pq.push(make_pair(0,src));
	ll v,w;
	while(!pq.empty()){
		pll up = pq.top();
		ll u = up.second;
		pq.pop();
		used[u]++;
		if (k<used[u]) {
			continue;
		}
		if (u==n-1) {
			if (c==0) {
				return;
			}
			cout << up.first << " ";
			c--;
		}
		for (auto pv: adj[u]) {
			v = pv.first;
			w = pv.second;
			if (k>used[v]) {
				pq.push(make_pair(w+up.first,v));
			}
		}
	}
}
 
void solve(){
	cin >> n >> m >> k;
	c = k;
	for (int i = 0; i < m ; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].pb({v,w});
	}
	dijkstra(0);
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
