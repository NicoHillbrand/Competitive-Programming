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
 
const int maxn = 1e3+1;
string mpp[maxn];
bool vis[maxn][maxn];
bool ins[maxn][maxn];
int c,n, m;
bool inccomp;
 
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
 
 
bool good(int x, int y){
	if (x<0||x>=m||y<0||y>=n) {
		return false;
	}
	return true;
}
 
int dir(char c){
	if (c=='E') {
		return 1;
	}else if(c == 'W'){
		return 3;
	}else if(c == 'N'){
		return 0;
	}else {
		return 2;
	}
}
 
void dfs(int x, int y){
	if (!vis[x][y]) {
		vis[x][y] = true;
		ins[x][y] = true;
		int i = dir(mpp[y].at(x));
		if (good(x+dx[i],y+dy[i])) {
			dfs(x+dx[i],y+dy[i]);
		}
		ins[x][y] = 0;
	}else if(!ins[x][y]){
		//vis means we found a previous component
		inccomp = false;
	}
}
 
void solve(){
	cin >> n >> m;
	c=0;
	for (int i = 0; i < n ; i++) {
		cin >> mpp[i];
		for(int j = 0; j < m; j++){
			vis[j][i] = 0;
		}
	}
	for (int i = 0; i < n ; i++) {
		for(int j = 0; j < m; j++){
			if (!vis[j][i]) {
				inccomp  = true;
				dfs(j,i);
				if (inccomp) {
					c++;
				}
			}
		}
	}
	cout << c << "\n";
	
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
