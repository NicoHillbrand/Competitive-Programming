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
 
const int maxn = 101;
int n,m;
bool vis[maxn][maxn];
string mpp[maxn];
const string aiw = "ALLIZZWELL";
bool aliswell;
 
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
 
bool good(int x, int y, int d){
	if (x<0||x>=m||y<0||y>=n) {
		return false;
	}	
	if (d>9) {
		return false;
	}
	if(vis[x][y]){
		return false;
	}
	if (mpp[y].at(x)!=aiw.at(d)) {
		return false;
	}
	if (d==9) {
		aliswell = 1;
	}
	return true;
}
 
void dfs(int x, int y, int d){
	if (aliswell) {
		return;
	}
	if (!vis[x][y]) {
		vis[x][y] = true;
		for (int i = 0; i < 8 ; i++) {
			if (good(x+dx[i],y+dy[i],d+1)) {
				if (aliswell) {
					return;
				}
				dfs(x+dx[i],y+dy[i],d+1);
			}
		}
		vis[x][y]= false;
	}
}
 
void solve(){
	cin >> n >> m;
	aliswell = 0;
	for (int i = 0; i < n ; i++) {
		cin >> mpp[i];
		for(int j = 0; j < m; j++){
			vis[j][i] = 0;
		}
	}
 
	for (int i = 0; i < n ; i++) {
		for(int j = 0; j < m; j++){
			if (mpp[i].at(j)=='A') {
				dfs(j,i,0);
			}
		}
	}
	
    //for each guy, start dfs there
	//keep track of length, if wrong character or above length then backtrack
	
	if (aliswell) {
		cout << "YES" << "\n";
	}else {
		cout << "NO" << "\n";
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
//		cout << "Case #" << ti  << ": ";
		solve();
	}
 
//	solve();
	
	
	
    return 0;
}
