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
 
 
const int maxn = 2e5;
 
 
void solve(){
	int n;
	cin >> n;
	vector<tuple<int,int,int>> sim;
	for (int i = 0; i < n ; i++) {
		int a,b;
		cin >> a >> b;
		sim.pb({a,0,i});
		sim.pb({b,1,i});
	}
	sort(sim.begin(),sim.end());
	int k = 0;
	vi room(n);
	stack<int> av;
	for (int i = 0; i < sim.size() ; i++) {
		int time, id;
		bool leaves;
		tie(time,leaves,id) = sim[i];
		if (leaves) {
			av.push(room[id]);
		}else {
			if (av.empty()) {
				k++;
				room[id] = k;
			}else {
				room[id] = av.top();
				av.pop();
			}
		}
	}
	cout << k << "\n";
	for (int i = 0; i < n ; i++) {
		cout << room[i] << " ";
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
 
	
	solve();
	
    return 0;
}
