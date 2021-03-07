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
 
 
const int maxn = 2e5+1;
ll n,k;
ll a[maxn];
 
void solve(){
	cin >> n >> k;
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	ll lb = *max_element(a,a+n), rb = 1e18;
	while(lb<rb){
		ll mb = (lb+rb)/2;
		int c = 0;
		ll ls=0;
		for (int i = 0; i < n ; i++) {
			if (ls+a[i]>mb) {
				++c;
				ls =0;
			}
			ls+=a[i];
		}
		c++;
		if (c>k) {
			lb = mb+1;
		}else {
			rb=mb;
		}
		
	}
	cout << lb << "\n";
	
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
