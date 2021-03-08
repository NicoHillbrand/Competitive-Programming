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
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 3e5+1;
int n;
bool vis[8][8];
int dists[8][8];
 
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
 
bool good(int x, int y){
	if (x<0||x>=8||y<0||y>=8) {
		return false;
	}
	if(vis[x][y]){
		return false;
	}
	return true;
}
 
void bfs( int sx,int sy,int gx, int gy){
	queue<ii> q;
	q.push(mp(sx,sy));
	dists[sx][sy] = 0;
	vis[sx][sy] = true;
	ii node;
	while(!q.empty()){
		node=q.front();q.pop();
		if (node.first==gx&&node.second==gy) {
			cout << dists[node.first][node.second] << "\n";
			return;
		}
		for(int i=0;i<8;i++){
			if (good(node.first+dx[i],node.second+dy[i])) {
				dists[node.first+dx[i]][node.second+dy[i]] = dists[node.first][node.second]+1;
				vis[node.first+dx[i]][node.second+dy[i]] = true;
				q.push(mp(node.first+dx[i],node.second+dy[i]));
			}
		}
	}
}
 
void solve(){
	string s1, s2;
	cin >> s1 >> s2;
	int sx = s1[0]-'a';
	int sy = s1[1]-'1';
	int gx = s2[0]-'a';
	int gy = s2[1]-'1';
	for (int i = 0; i < 8 ; i++) {
		for(int j = 0; j < 8; j++){
			vis[i][j] = 0;
		}
	}
	bfs(sx,sy,gx,gy);
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
////	
////	
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ti++){
//		cout << "Case #" << ti  << ":\n";
		solve();
	}
 
//	solve();
	
    return 0;
}
