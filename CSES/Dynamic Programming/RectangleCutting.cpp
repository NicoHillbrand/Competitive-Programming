#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <string>
using namespace std;
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX
const ll inf = 1e16;
 
int a, b;
int dp[501][501];
 
int moves(int a, int b){
	if (a==b) {
		return 0;
	}
	if (dp[a][b]!=0) {
		return dp[a][b];
	}
	int res = INF;
	
	for (int i = 1; i < a ; i++) {
		res = min(res,moves(i,b)+moves(a-i,b)+1);
	}
	for (int i = 1; i < b ; i++) {
		res = min(res,moves(a,i)+moves(a,b-i)+1);
	}
	
	dp[a][b] = res;
	return res;
}
 
void solve(){
	cin >> a >> b;
	cout << moves(a,b) << "\n";
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
    return 0;
}
