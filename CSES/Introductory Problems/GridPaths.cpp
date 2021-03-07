#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
string s;
bool vis[7][7];
int ans;
 
bool empty(int x, int y){
	return x>=0&&x<7&&y>=0&&y<7&&!vis[x][y];
}
 
void dfs(int x, int y, int depth){
 
	if (x == 0 && y == 6) {
		if (depth == 48) {		
			ans++;
		}
		return;
	}
 
	
	vis[x][y] = 1;
	if (s[depth]=='?'||s[depth]=='L') {
		
			if (empty(x-1,y)&&!(!empty(x-2,y)&&empty(x-1,y+1)&&empty(x-1,y-1))) {	
				dfs(x-1,y,depth+1);
			}
		
	}
	if (s[depth]=='?'||s[depth]=='R') {
		
			if (empty(x+1,y)&&!(!empty(x+2,y)&&empty(x+1,y+1)&&empty(x+1,y-1))) {
				dfs(x+1,y,depth+1);
			}
		
	}
	if (s[depth]=='?'||s[depth]=='U') {
		
			if (empty(x,y-1)&&!(!empty(x,y-2)&&empty(x-1,y-1)&&empty(x+1,y-1))) {
				dfs(x,y-1,depth+1);
			}
		
	}
	if (s[depth]=='?'||s[depth]=='D') {
		
			if (empty(x,y+1)&&!(!empty(x,y+2)&&empty(x-1,y+1)&&empty(x+1,y+1))) {
				dfs(x,y+1,depth+1);
			}
		
	}
	vis[x][y] = 0;
	
}
 
 
 
void solve(){
	cin >> s;
	dfs(0,0,0);
	cout << ans << "\n";
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
