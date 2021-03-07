#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
int n,m, bx,by;
string rooms[1000];
bool vis[1000][1000];
int dists[1000][1000];
 
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
char dir[4] = {'D','L','U','R'};
 
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
 
string solution;
bool found;
 
char getchar(int i){
	if (i==0) {
		return 'U';
	}else if (i==1) {
		return 'R';
	}else if (i==2) {
		return 'D';
	}else if (i==3) {
		return 'L';
	}else {
		return 0;
	}
	
}
 
void getsolution(int x, int y){
	string res = "";
	int d = dists[x][y];
	while(d>0){
		for (int i = 0; i < 4 ; i++) {
			if (x+dx[i]>=0&&x+dx[i]<m&&y+dy[i]>=0&&y+dy[i]<n&&dists[x+dx[i]][y+dy[i]]==d-1) {
				if (d-1==0&&rooms[y+dy[i]].at(x+dx[i])!='A') {
					continue;
				}
				x+=dx[i];
				y+=dy[i];
				
				
				res+=dir[i];
				d--;
				break;
			}
		}
	}
	reverse(res.begin(),res.end());
	solution = res;
}
 
 
void bfs(int x, int y){
	
	queue<tuple<int,int,int>> q;
	q.push(make_tuple(x,y,0));
	int nx, ny,dist;
	while(!q.empty()&&!found){
		
		tie(nx,ny,dist)=q.front();q.pop();
		if (vis[nx][ny]) {
			continue;
		}
		vis[nx][ny] = true;
		dists[nx][ny] = dist;
 
		if (rooms[ny].at(nx)=='B') {
			found = true;
			getsolution(nx,ny);
			break;
		}
		for (int i = 0; i < 4 ; i++) {
			if (good(nx+dx[i],ny+dy[i])) {
				q.push(make_tuple(nx+dx[i],ny+dy[i],dist+1));
			}
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
			if (rooms[j].at(i)=='A') {
				bfs(i,j);
				i=m;
				j=n;
			}
		}
	}
	
	
	
	if (!found) {
		cout << "NO" << "\n";
	}else {
		cout << "YES" << "\n";
		cout << solution.length() << "\n";
		cout << solution << "\n";
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
