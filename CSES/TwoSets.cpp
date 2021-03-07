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
 
 
void solve(){
	int n;
	cin >> n;
	
	if ((n*(n+1)/2)%2!=0) {
		cout << "NO" << "\n";
		return;
	}
	
	vi v1,v2;
	int j = 0;
	if (n%4==0) {
		j=4;
	}else {
		j=3;
	}

	for (int i = 0; i < (n-1)/4 ; i++) {
		v1.push_back(4*i+1+j);
		v1.push_back(4*i+4+j);
		v2.push_back(4*i+2+j);
		v2.push_back(4*i+3+j);
	}
	if (n%4) {
		v1.push_back(1);
		v1.push_back(2);
		v2.push_back(3);
	}else {
		v1.push_back(1);
		v1.push_back(4);
		v2.push_back(3);
		v2.push_back(2);
	}
	
	cout << "YES" << "\n";
	cout << v1.size() << "\n";
	for(int i:v1){
		cout << i << " ";
	}
	cout << "\n";
	cout << v2.size() << "\n";
	for(int i:v2){
		cout << i << " ";
	}
	cout << "\n";
	
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
//		solve();
//	}
	
	solve();
	
    return 0;
}
 
