#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
//#define int long long, int_32main
 
 
string bo[8];
bool bord[8][8];
bool queen[8][8];
unordered_set<long long> seen;
int res;
 
long long hashi(){
	long long res = 0;
	for (int i = 0; i < 8 ; i++) {
		for(int j = 0; j < 8; j++){
			if (queen[i][j]) {
				res |= 1LL << (8*j+i);
			}
		}
	}
	return res;
}
 
void dfs(int q){
	long long h = hashi();
	if (seen.find(h)==seen.end()) {
		seen.insert(h);
	}else {
		return;
	}
	if (q==8) {
		res++;
		return;
	}
	for (int i = 0; i < 8 ; i++) {
		for(int j = 0; j < 8; j++){
			if (!bord[i][j]) {
				//place queen
				
				queen[i][j] = 1;
				
				vii new1s;
				//straight
				for(int k = 0; k < 8; k++){	
					if (!bord[i][k]) {
						new1s.push_back({i,k});
					}
					if (!bord[k][j]) {
						new1s.push_back({k,j});
					}
					bord[i][k] = 1;
					bord[k][j] = 1;
				}
				
				//diagonal
				for(int k = 0; k < 8; k++){
					if (i+k<8&&j+k<8) {
						if (!bord[i+k][j+k]) {
							new1s.push_back({i+k,j+k});
						}
						bord[i+k][j+k] = 1;
					}
					if (i-k>=0&&j-k>=0) {
						if (!bord[i-k][j-k]) {
							new1s.push_back({i-k,j-k});
						}
						bord[i-k][j-k] = 1;
					}
					if (i+k<8&&j-k>=0) {
						if (!bord[i+k][j-k]) {
							new1s.push_back({i+k,j-k});
						}
						bord[i+k][j-k] = 1;
					}
					if (i-k>=0&&j+k<8) {
						if (!bord[i-k][j+k]) {
							new1s.push_back({i-k,j+k});
						}
						bord[i-k][j+k] = 1;
					}
				}
				
				dfs(q+1);
				
				for(ii c:new1s){
					bord[c.first][c.second] = 0;
				}
				queen[i][j] = 0;
			}
		}
	}
}
 
 
void solve(){
	string line;
	for (int i = 0; i < 8 ; i++) {
		getline(cin,line);
		bo[i]=line;
	}
	
	for (int i = 0; i < 8 ; i++) {
		for(int j = 0; j < 8; j++){
			if (bo[i].at(j)=='*') {
				bord[j][i] = 1;
			}
		}
	}
	
	dfs(0);
	
	cout << res << "\n";
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
