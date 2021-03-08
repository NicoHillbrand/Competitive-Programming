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
 
const int maxn = 1e6+1;
int dists[maxn];
bool vis[maxn];
int n,s,g,u,d;
 
void bfs( int snode){
	queue<int> q;
	q.push(snode);
	dists[snode] = 0;
	vis[snode] = true;
	int node;
	while(!q.empty()){
		node=q.front();q.pop();
		int c = node-d;
		if (!vis[c]&&c>=1) {
			dists[c] = dists[node]+1;
			vis[c] = true;
			q.push(c);
		}
		c = node+u;
		if (!vis[c]&&c<=n) {
			dists[c] = dists[node]+1;
			vis[c] = true;
			q.push(c);
		}
	}
}
 
void solve(){
	cin >> n >> s >> g >> u >> d;
	for (int i = 0; i <=n ; i++) {
		vis[i] = 0;
		dists[i] = INF;
	}
	bfs(s);
	if (dists[g] == INF) {
		cout << "use the stairs" << "\n";	
	}else {
		cout << dists[g] << "\n";
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
////	
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
////		cout << "Case #" << ti  << ": ";
//		solve();
//	}
 
	solve();
	
	
	
    return 0;
}
