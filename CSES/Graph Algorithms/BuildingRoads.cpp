#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
int n,m,comps;
vi adj[100001];
bool vis[100001];
vi reps;
 
void visit(int node){
	if (reps[comps]==-1) {
		reps[comps]=node;
	}
	vis[node] = true;
	for(int c:adj[node]){
		if (!vis[c]) {
			visit(c);
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
		adj[v].push_back(u);
	}
	
	for (int i = 0; i < n ; i++) {
		if (!vis[i]) {
			reps.push_back(-1);
			visit(i);
			comps++;
		}
	}
	
	
	
	if (reps.size()==1) {
		cout << 0 << "\n";
	}else {
		cout << reps.size()-1 << "\n";
		for (int i = 1; i < reps.size() ; i++) {
			cout << reps[0]+1 << " " << reps[i]+1 << "\n";
		}
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
