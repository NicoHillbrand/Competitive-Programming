#include <bits/stdc++.h>
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
#define INF INT_MAX;
const ll inf = 1e17;
 
int n,m;
const int maxn = 1e5;
vector<pll> adj1[maxn];
vector<pll> adj2[maxn];
ll d1[maxn], d2[maxn];
bool vis[maxn];
 
 
void dijkstra(int src, vector<pll> adj[maxn], ll d[maxn]){
	memset(d, 0x3f,sizeof(d1));
	priority_queue< pll, vector <pll> , greater<pll> > pq;
	pq.push(make_pair(0,src));
	d[src] = 0;
	int v,w;
	while(!pq.empty()){
		ii up = pq.top();
		int u = up.second;
		pq.pop();
		if (up.first>d[u]) {
			continue;
		}
		for (auto pv: adj[u]) {
			v = pv.first;
			w = pv.second;
			
			if (d[v]>d[u]+w) {
				d[v] = d[u]+w;
				pq.push(make_pair(d[v],v));
			}
		}
	}
}
 
 
void solve(){
	cin >> n >> m;
	for (int i = 0; i < m ; i++) {
		ll u,v,w;
		cin >> u >> v >> w;
		u--;
		v--;
		adj1[u].push_back(make_pair(v,w));
		adj2[v].push_back(make_pair(u,w));
	}
	dijkstra(0,adj1,d1);
	dijkstra(n-1,adj2,d2);
 
	ll res = 1e18;
	for (int i = 0; i < n ; i++) {
		for(ii c : adj1[i]){
			res = min(res,d1[i]+d2[c.first]+c.second/2);
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
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
//		cout << "Case #" << ti  << ": ";
//		solve();
//	}
	
	solve();
	
    return 0;
}
