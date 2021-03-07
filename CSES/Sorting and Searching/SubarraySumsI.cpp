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
ll n,x;
ll a[maxn];
 
void solve(){
	cin >> n >> x;
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	
	ll lp = 0, rp = 0;
	ll sum=a[0];
	ll res = 0;
	while(true){
		if (sum==x) {
			res++;
			if (rp<n-1) {
				rp++;
				sum+=a[rp];
			}else {
				break;
			}
		}else if (sum<x) {
			if (rp<n-1) {
				rp++;
				sum+=a[rp];
			}else {
				break;
			}
		}else if(sum>x){
			sum-=a[lp];
			lp++;
		}
	}
 
	
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
