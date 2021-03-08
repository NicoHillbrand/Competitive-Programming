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
 
const int maxn = 2e3;
int n,m;
const int modd = 1e8;
bool vis[maxn][maxn];
string mpp[maxn];
ii furthest;
int fd;
 
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
 
bool good(int x, int y){
	if (x<0||x>=m||y<0||y>=n) {
		return false;
	}
	if(vis[x][y]){
		return false;
	}
	if (mpp[y].at(x)=='#') {
		return false;
	}
	return true;
}
 
void dfs(int x, int y, int d){
	if (!vis[x][y]) {
		vis[x][y] = true;
		if (d>fd) {
			fd=d;
			furthest.first = x;
			furthest.second = y;
		}
		for (int i = 0; i < 4 ; i++) {
			if (good(x+dx[i],y+dy[i])) {
				dfs(x+dx[i],y+dy[i],d+1);
			}
		}
	}
}
 
void solve(){
	cin >> m >> n;
	for (int i = 0; i < n ; i++) {
		cin >> mpp[i];
		for(int j = 0; j < m; j++){
			vis[j][i] = 0;
		}
	}
	fd = 0;
	bool done = false;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++){
			if (mpp[i].at(j)=='.') {
				dfs(j,i,0);
				done = true;
				break;
			}
		}
		if (done) {
			break;
		}
	}
	fd = 0;
	for (int i = 0; i < n ; i++) {
		for(int j = 0; j < m; j++){
			vis[j][i] = 0;
		}
	}
	dfs(furthest.first,furthest.second,0);
	cout << "Maximum rope length is " << fd <<"." << "\n";
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
//		cout << "Case #" << ti  << ": ";
		solve();
	}
 
//	solve();
	
	
	
    return 0;
}
