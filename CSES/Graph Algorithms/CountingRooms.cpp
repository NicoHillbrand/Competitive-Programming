#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
int n,m, comps;
string rooms[1000];
bool vis[1000][1000];
 
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
 
bool good(int x, int y){
	if (x<0||y<0) {
		return false;
	}
	if (x>=m||y>=n) {
		return false;
	}
	if (vis[x][y]) {
		return false;
	}
	if (rooms[y].at(x)=='#') {
		return false;
	}
	return true;
}
 
 
void visit(int x,int y){
	
	vis[x][y] = true;
	
	for (int i = 0; i < 4 ; i++) {
		if (good(x+dx[i],y+dy[i])) {
			visit(x+dx[i],y+dy[i]);
		}
	}
}
 
void solve(){
	cin >> n >> m;
	for (int i = 0; i < n ; i++) {
		cin >> rooms[i];
	}
	
	for (int i = 0; i < m ; i++) {
		for(int j = 0; j < n; j++){
			if (!vis[i][j]&&rooms[j].at(i)!='#') {
				visit(i,j);
				comps++;
			}
		}
	}
	cout << comps << "\n";
	
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
