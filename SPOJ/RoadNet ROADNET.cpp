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
 
const int maxn = 2e2;
int n;
int dists[maxn][maxn];
int adj[maxn][maxn];
 
void solve(){
	cin >> n;
	for (int i = 0; i < n ; i++) {
		for(int j = 0; j < n; j++){
			int k;
			cin >> k;
			adj[j][i]=k;
			adj[i][j] = k;
			dists[j][i]=k;
			dists[i][j]=k;
		}
	}
	vii res;
	for(int k = 0; k < n; k++){
		for (int i = 0; i < n ; i++) {
			for(int j = 0; j < n; j++){
				if (i!=j&&k!=i&&k!=j&&dists[i][j] == dists[i][k]+dists[k][j]) {
					adj[i][j] = -1;
					adj[j][i] = -1;
				}
			}
		}
	}
 
	for (int i = 0; i < n ; i++) {
		for(int j = 0; j < n; j++){
			if (i<j&&adj[i][j]!=-1) {
				res.pb(mp(i+1,j+1));
			}
		}
	}
	sort(res.begin(),res.end());
	for (int i = 0; i < res.size() ; i++) {
		cout << res[i].first << " " << res[i].second << "\n";
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
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ti++){
		solve();
		cout << "\n";
	}
	
//	solve();
	
    return 0;
}
