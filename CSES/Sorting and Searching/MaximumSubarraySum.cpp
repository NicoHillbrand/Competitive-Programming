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
	ll k;
	cin >> k;
	ll v = k, mv = k;
	for (int i = 1; i < n ; i++) {
		cin >> k;
		v = max(k,v+k);
		mv = max(mv,v);
	}
	cout << mv << "\n";
	
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("text.in", "r", stdin);
	solve();
	
    return 0;
}
