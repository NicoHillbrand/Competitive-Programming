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
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int ccc = (1<<8)+1;
int n,m,c,a,b;
double dists[30][ccc];
vector<pair<int,double>> adj[30];
double coach[8];
 
void dijkstra(){
 
	priority_queue< tuple<double,int,int>, vector <tuple<double,int,int>> , greater<tuple<double,int,int>> > pq;
	
	pq.push(mt(0,a,0));
	dists[a][0] = 0;
	int v;
	int u;
	int mask;
	double w,wu;
	while(!pq.empty()){
		tie(wu,u,mask) = pq.top();
		pq.pop();
		if (wu>dists[u][mask]) {
			continue;
		}
		for (auto pv: adj[u]) {
			v = pv.first;
			w = pv.second;
//			//do nothing
//			if (dists[v][mask]>dists[u][mask]+w) {
//				dists[v][mask] = dists[u][mask]+w;
//				pq.push(mt(dists[v][mask],v,mask));
//			}
			//use coach
			for (int i = 0; i < c ; i++) {
				if (((mask&(1<<i))==0)&&dists[v][mask|(1<<i)]>dists[u][mask]+w/coach[i]) {
					dists[v][mask|(1<<i)] = dists[u][mask]+w/coach[i];
					pq.push(mt(dists[v][mask|(1<<i)],v,mask|(1<<i)));
				}
			}
		}
	}
}
 
void solve(){
	//read graph
	cin >> c >> n >> m >> a >> b;
	if (c==0&&n==0&&m==0&&a==0&&b==0) {
		exit(0);
	}
	a--;
	b--;
	//reset test case
	for (int i = 0; i < 30 ; i++) {
		adj[i].clear();
		for(int j = 0; j < ccc; j++){
			dists[i][j] = 1e16;
		}
	}
	
	for (int i = 0; i < c ; i++) {
		cin >> coach[i];
	}
	
	for (int i = 0; i < m ; i++) {
		int u,v;
		double w;
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
 
	dijkstra();
	
	double mini = 1e16;
	for (int i = 0; i < 1<<c ; i++) {
		mini = min(mini,dists[b][i]);
	}
	if (mini==1e16) {
		cout << "Impossible" << "\n";
	}else {
		cout << mini << "\n";
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
	while(true){
		solve();
	}
    return 0;
}
