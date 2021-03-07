#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;

 
void solve(){
 
	long long x, y;
	cin >> y >> x;
	long long z;
	if (x>=y) {
		z = x*x;
		if (x%2==0) {
			z-=2*(x-1);
			z+=(y-1);
		}else {
			z-=(y-1);
		}
	}else {
		z = y * y;
		if (y%2==0) {
			z-=(x-1);
		}else {
			z-=2*(y-1);
			z+=(x-1);
		}
	}
	cout << z << "\n";
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
//	
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ti++){
		solve();
	}
	
    return 0;
}
