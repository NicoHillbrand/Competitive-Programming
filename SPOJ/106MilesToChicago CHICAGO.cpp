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
 
 
const int maxn = 100;
int n,m;
vector<pair<int,double>> adj[maxn];
 
double dijkstra(int src){
 
	vector<double> dists(maxn,0);
	
	priority_queue< pair<double,int>, vector <pair<double,int>> > pq;
	
	pq.push(make_pair(100,src));
	dists[src] = 100;
	int v;
	double w;
	while(!pq.empty()){
		pair<double,int> up = pq.top();
		int u = up.second;
		pq.pop();
		if (up.first<dists[u]) {
			continue;
		}
		for (auto pv: adj[u]) {
			v = pv.first;
			w = pv.second;
			
			if (dists[v]<dists[u]*w) {
				dists[v] = dists[u]*w;
				pq.push(make_pair(dists[v],v));
			}
		}
	}
	
	return dists[n-1];
}
 
void solve(){
	while(true){
		cin >> n;
		if (n==0) {
			break;
		}
		for (int i = 0; i < n ; i++) {
			adj[i].clear();
		}
		
		cin >> m;
		int u,v;
		double w;
		for (int i = 0; i < m ; i++) {
			cin >> u >> v >> w;
			w/=100;
			u--;
			v--;
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back(make_pair(u,w));
		}
		
		cout << setprecision(6);
		cout << fixed;
		cout << dijkstra(0) << " percent\n";
		
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
