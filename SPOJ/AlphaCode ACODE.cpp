#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
const ll inf = 1e17;
 
const int maxn = 5001;
 
string in;
 
void solve(){
	while(true){
		cin >> in;
		if (in=="0") {
			break;
		}
 
		vector<ll> dp(in.length()+1,0);
		
		dp[0] = 1;
		for (int i = 1; i <= in.length() ; i++) {
			//up to i
			if (in.at(i-1)!='0') {
				dp[i]=dp[i-1];
			}
			//account for 0s
			
			if ((i-2>=0)&&(in.at(i-2)=='1'||(in.at(i-2)=='2'&&in.at(i-1)<'7'))) {
				//if we have a 2 digit number
				dp[i]+=dp[i-2];
			}
			
		}
		
		
		cout << dp[in.length()] << "\n";
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
//		cout << "Case #" << ti  << ": ";
//		solve();
//	}
	
	solve();
	
    return 0;
}
