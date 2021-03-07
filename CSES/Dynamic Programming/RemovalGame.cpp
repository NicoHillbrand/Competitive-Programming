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
 
int n;
ll a[5001];
ll presum[5001];
ll dp[5001][5001];
bool vis[5001][5001];
 
ll sum(int x, int y){
	if (x==y) {
		return a[x];
	}else if(x==0){
		return presum[y];
	}else {
		return presum[y]-presum[x-1];
	}
}
 
 
ll score(int x, int y){
	if (vis[x][y]) {
		return dp[x][y];
	}
	ll res = 0;
	if (x==y) {
		res=a[x];
	}else {
		ll left = a[x]+sum(x+1,y)-score(x+1,y);
		ll right = a[y]+sum(x,y-1)-score(x,y-1);
		res = max(left,right);
	}
	
	vis[x][y] = true;
	dp[x][y] = res;
	return res;
}
 
void solve(){
	cin >> n;
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
		presum[i] = a[i];
		if (i>0) {
			presum[i]+=presum[i-1];
		}
	}
	cout << score(0,n-1) << "\n";
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
	
    return 0;
}
