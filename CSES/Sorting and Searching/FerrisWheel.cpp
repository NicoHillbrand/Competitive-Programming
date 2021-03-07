#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
int n ,x;
int chil[200001];
 
 
void solve(){
	cin >> n >> x;
	for (int i = 0; i < n ; i++) {
		cin >> chil[i];
	}
	sort(chil,chil+n);
	int lp=0,rp=n-1;
	int total = 0;
	while(lp<=rp){
		if (chil[lp]+chil[rp]>x) {
			rp--;
		}else {
			//combine
			rp--;
			lp++;
		}
		total++;
	}
	cout << total << "\n";
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
//	freopen("test_input.txt", "r", stdin);
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
