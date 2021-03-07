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
vi adj[maxn];
 
bool cycle;
bool vis[maxn];
bool fin[maxn];
vi order;
 
void visit(int node){
	if (cycle) {
		return;
	}
	vis[node] = true;
	for(int c : adj[node]){
		if (!vis[c]) {
			visit(c);
		}
		if (vis[c]&&!fin[c]) {
			cycle = true;
		}
	}
	fin[node] = true;
	order.push_back(node);
}
 
void topsort(){
	for (int i = 0; i < n ; i++) {
		if (!vis[i]) {
			visit(i);
		}
	}
}
 
void solve(){
	cin >> n >> m;
	int u,v;
	for (int i = 0; i < m ; i++) {
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
	}
	topsort();
 
	if (cycle) {
		cout <<  "IMPOSSIBLE";
		return;
	}
	
	for(int i = n-1; i>=0 ; i--){
		cout << order[i]+1 << " ";
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
 
