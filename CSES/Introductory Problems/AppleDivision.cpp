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
 
int n;
int nums[20];
 
void solve(){
	cin >> n;
	for (int i = 0; i < n ; i++) {
		cin >> nums[i];
	}
	
	long long mindif = INT_MAX;
	long long sum = 0;
	long long g1sum = 0;
	for (int i = 0; i < 1<<n ; i++) {
		//sum
		for(int j = 0; j < n; j++){
			sum += (long long) nums[j];
			if (!!(i&(1<<j))) {
				g1sum += (long long) nums[j];
			}
		}
		
		mindif = min(mindif,abs(sum-g1sum-g1sum));
		sum = 0;
		g1sum = 0;
	}
	
	cout << mindif << "\n";
	
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
