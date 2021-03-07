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
#define ts to_string
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const int INF = 5e8+1;
const ll inf = 1e16;
 
 
 
const int maxn = 2e5;
int n,m;
 
multiset<int> adj[maxn];
vi circuit;
int ec[maxn];
 
void euler(int start){
	stack<int> curpath;
	int curnode = start;
	curpath.push(start);
	while(curpath.size()){
		if (ec[curnode]!=0) {
			curpath.push(curnode);
			int next = *adj[curnode].begin();
			ec[curnode]--;
			ec[next]--;
			adj[curnode].erase(adj[curnode].begin());
			adj[next].erase(adj[next].find(curnode));
			curnode = next;
		}else {
			circuit.push_back(curnode);
			curnode = curpath.top();
			curpath.pop();
		}
	}
}
bool vis[maxn];
 
void dfs(int node){
	if (!vis[node]) {
		vis[node] = true;
		for(int c : adj[node]){
			dfs(c);
		}
	}
}
 
bool connected(){
	bool al=0;
	for (int i = 0; i < n ; i++) {
		if (!vis[i]&&(ec[i]>0||i==0)) {
			if (al) {
				return false;
			}
			dfs(i);
			al = 1;
		}
	}
	return true;
}
 
void solve(){
	cin >> n >> m;
	for (int i = 0; i < m ; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].insert(v);
		adj[v].insert(u);
		ec[u]++;
		ec[v]++;
	}
	
	if (!connected()) {
		cout << "IMPOSSIBLE" << "\n";
		return;
	}
	
	for (int i = 0; i < n ; i++) {
		if (adj[i].size()%2==1) {
			cout << "IMPOSSIBLE" << "\n";
			return;
		}
	}
	euler(0);
	for(int i = circuit.size()-1; i>0 ; i--){
		cout << circuit[i]+1 << " ";
		
	}
	cout << 1 << "\n";
	
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
