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
 
 
void solve(){
	int n;
	cin >> n;
 
	int a[n];
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	
	int mlen = 1;
	set<int> v;
	v.insert(a[0]);
	int lp = 0, rp = 1;
	while(rp<n){
		if (v.find(a[rp])!=v.end()) {
			while(a[lp]!=a[rp]){
				v.erase(a[lp]);
				lp++;
			}
			lp++;
		}else {
			v.insert(a[rp]);
		}
		mlen = max(mlen,rp-lp+1);
		rp++;
	}
	cout << mlen << "\n";
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("text.in", "r", stdin);
	solve();
	
    return 0;
}
