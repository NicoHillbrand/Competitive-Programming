#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
 
 
int n;
vi adj[200005];
int nsub[200003];
 
void dfs(int node){
	for(int c:adj[node]){
		dfs(c);
		nsub[node]+=nsub[c]+1;
	}
}
 
void solve(){
	cin >> n;
	int e;
	for (int i = 1; i < n ; i++) {
		cin >> e;
		adj[e-1].push_back(i);
	}
	dfs(0);
	for (int i = 0; i < n ; i++) {
		cout << nsub[i] << " ";
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
