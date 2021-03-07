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
vector<int> adj[maxn];
ll nway[maxn];
int deg[maxn];
int filld[maxn];
bool processed[maxn];
bool vis[maxn];
 
void dfs(int node){
	deg[node]++;
	if (!vis[node]) {
		vis[node] = true;
		for(int c : adj[node]){
			dfs(c);
		}
	}
}
 
void search(int node,int parent){
	//we already processed the parent
	if (node!=0) {
		nway[node] += nway[parent];
		nway[node] %= 1000000007LL;
	}
	if (deg[node]==filld[node]+1||node==0) {
		filld[node]++;
		for(int c : adj[node]){
			search(c,node);
		}
	}else {
		filld[node]++;
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
 
	nway[0] = 1;
	dfs(0);
	search(0,0);
	
	cout << nway[n-1] << "\n";
	
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
