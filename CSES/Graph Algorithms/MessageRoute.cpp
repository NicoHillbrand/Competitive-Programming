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
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX
const ll inf = 1e16;
 
int n,m;
const int maxn = 1e5;
vector<int> adj[maxn];
int dists[maxn];
bool vis[maxn];
int parent[maxn];
 
void bfs( int snode){
	queue<int> q;
	q.push(snode);
	dists[snode] = 0;
	vis[snode] = true;
	int node;
	while(!q.empty()){
		node=q.front();q.pop();
		for(int c:adj[node]){
			if (!vis[c]) {
				dists[c] = dists[node]+1;
				parent[c] = node;
				vis[c] = true;
				q.push(c);
			}
		}
	}
}
 
void solve(){
	cin >> n >> m;
	for (int i = 0; i < m ; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dists[n-1] = INF;
	bfs(0);
	if (dists[n-1]==INF) {
		cout << "IMPOSSIBLE" << "\n";
	}else {
		cout << dists[n-1]+1 << "\n";
		stack<int> s;
		int node = n-1;
		while(node!=0){
			s.push(node);
			node = parent[node];
		}
		cout << 1 << " ";
		while(!s.empty()){
			cout << s.top()+1 << " ";
			s.pop();
		}
	}
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("text.in", "r", stdin);
	solve();
	
    return 0;
}
