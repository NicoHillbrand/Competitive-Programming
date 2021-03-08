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
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 10000;
int n,m;
int a[maxn];
int b[maxn];
 
void solve(){
	while(true){
		cin >> n;
		if (n==0) {
			return;
		}
		set<int> s;
		for (int i = 0; i < n ; i++) {
			cin >> a[i];
			s.insert(a[i]);
		}
		int fp = 0;
		cin >> m;
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < m ; i++) {
			cin >> b[i];
			if (s.find(b[i])!=s.end()) {
				while(a[fp]!=b[i]){
					sum1+=a[fp];
					fp++;
				}
				sum1=max(sum1,sum2);
				sum2=max(sum1,sum2);
				sum1+=b[i];
				sum2+=b[i];
				fp++;
			}else {
				sum2+=b[i];
			}
			
		}
		while(fp<n){
			sum1+=a[fp];
			fp++;
		}
		cout << max(sum2,sum1) << "\n";
	}
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
////	
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
////		cout << "Case #" << ti  << ": ";
//		solve();
//	}
//	
	solve();
	
    return 0;
}
