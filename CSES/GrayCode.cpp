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
 
void recfill(vs& code, int n){
	if (n==1) {
		return;
	}
	recfill(code,n-1);
	int copysize = (1<<(n-1));
	for (int i = 0; i < copysize ; i++) {
		code[copysize*2-1-i] = code[i];
	}
	for (int i = 0; i < copysize ; i++) {
		code[i] += "0";
	}
	for (int i = copysize; i < 2*copysize; i++) {
		code[i] += "1";
	}
}
 
 
void solve(){
	int n;
	cin >> n;
	vector<string> code = vs(1<<n,"");
	code[1] = "1";
	code[0] = "0";
	
	recfill(code,n);
	
	for (int i = 0; i < (1<<n) ; i++) {
		reverse(code[i].begin(),code[i].end());
		cout << code[i] << "\n";
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
////		cout << "Case #" << ti  << ": ";
//		solve();
//	}
	
	solve();
	
    return 0;
}
