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
const int INF = 5e8+1;
const ll inf = 1e16;
 
const int maxn = 101;
int n;
int adj[maxn][maxn];
ii assigned[maxn][maxn];
bool vis[maxn][maxn];
 
 
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
 
bool good(int x, int y){
	if (x<0||x>=n||y<0||y>=n) {
		return false;
	}
	if(vis[x][y]){
		return false;
	}
	return true;
}
 
bool matching(int x, int y){
	
	for (int i = 0; i < 4 ; i++) {
		if (good(x+dx[i],y+dy[i])&&adj[x+dx[i]][y+dy[i]]==adj[x][y]-1) {
			vis[x+dx[i]][y+dy[i]] = true;
			if (assigned[x+dx[i]][y+dy[i]].first<0||matching(assigned[x+dx[i]][y+dy[i]].first,assigned[x+dx[i]][y+dy[i]].second)) {
				assigned[x+dx[i]][y+dy[i]].first = x;
				assigned[x+dx[i]][y+dy[i]].second = y;
				return true;
			}
		}
	}
	
	return false;
}
 
 
 
void solve(){
	cin >> n;
	for (int i = 0; i < n ; i++) {
		for(int j = 0; j < n; j++){
			cin >> adj[i][j];
			assigned[i][j] = mp(-1,-1);
		}
	}
	
	for(int k = 2; k < 10; k++){
		//reset assigned? no need
		for (int i = 0; i < n ; i++) {
			for(int j = 0; j < n; j++){
				if (adj[i][j] == k) {
					
					for (int i1 = 0; i1 < n ; i1++) {
						for (int i2 = 0; i2 < n ; i2++) {
							vis[i1][i2] = 0;
						}
					}
					
					if (!matching(i,j)) {
						cout << "NO" << "\n";
						return;
					}
					
					
				}
			}
		}
	}
	cout << "YES" << "\n";
	
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
