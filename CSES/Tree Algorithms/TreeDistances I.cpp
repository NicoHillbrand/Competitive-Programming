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
 
int n;
const int maxn = 2e5;
vector<int> adj[maxn];
int dists[maxn];
int depths[maxn];
 
int dfs1(int node, int parent){
	int depth = 0;
	for(int c:adj[node]){
		if (c!=parent) {
			depth=max(depth,dfs1(c,node)+1);
		}
	}
	depths[node] = depth;
	return depth;
}
 
//depth or one up dists+1
void dfs2(int node, int parent){
	
	int max1=-1,max2=-1;
	for(int c : adj[node]){
		if (c!=parent) {
			if (depths[c]>max1) {
				max2=max1;
				max1=depths[c];
			}else if(depths[c]>max2){
				max2 = depths[c];
			}
		}
	}
	
	
	for(int c : adj[node]){
		if (c!=parent) {
			if (depths[c] == max1) {
				dists[c] = 1+max(dists[node],max2+1);
			}else {
				dists[c] = 1+max(dists[node],max1+1);
			}
			dfs2(c,node);
		}
	}
}
 
 
void solve(){
	cin >> n;
	for (int i = 0; i < n-1 ; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(0,0);
	dfs2(0,0);
	for (int i = 0; i < n ; i++) {
		if (depths[i]>dists[i]) {
			cout << depths[i] << " ";
		}else {
			cout << dists[i] << " ";
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
