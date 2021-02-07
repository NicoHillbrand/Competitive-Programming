#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
const int INF = 5e8+1;
const ll inf = 1e16;
const double infy = -1e8;

const int maxn = 101;
int n,m;
map<string,int> mpp;
ii pos[maxn];
bool shooter[maxn];
bool already[maxn];
string revmp[maxn];

double dists[maxn][maxn];

double distance(string s1, string s2){
	return sqrt(pow((double)(pos[mpp[s1]].first-pos[mpp[s2]].first),2.0)+pow((double)(pos[mpp[s1]].second-pos[mpp[s2]].second),2.0));
}

void solve(){
	cin >> n >> m;
	mpp.clear();
	int index = 0;
	for (int i = 0; i < n ; i++) {
		string name;
		cin >> name;
		mpp[name] = index;
		revmp[index] = name;
		int x, y;
		cin >> x >> y;
		pos[index].first = x;
		pos[index].second = y;
		index++;
	}

	//reset
	for (int i = 0; i < n ; i++) {
		shooter[i] = 0;
		already[i] = 0;
		for(int j = 0; j < n; j++){
			dists[i][j] = infy;
			if (i==j) {
				dists[i][j] = 0;
			}
		}
	}
	int shooters = 0;
	for (int i = 0; i < m ; i++) {
		string useless;
		string who, bef, after;
		cin >> who >> useless >> bef >> useless >> useless >> after;
		//implied timing
		dists[mpp[bef]][mpp[after]] = max(dists[mpp[bef]][mpp[after]],distance(who,bef)-distance(who,after));
		if (!shooter[mpp[bef]]) {
			shooters++;
		}
		if (!shooter[mpp[after]]) {
			shooters++;
		}
		shooter[mpp[bef]] = 1;
		shooter[mpp[after]] = 1;
	}

	for(int k = 0; k < n; k++){
		for (int i = 0; i < n ; i++) {
			for(int j = 0; j < n; j++){
				if (dists[i][k]!=infy&&dists[k][j]!=infy&&dists[i][k]+dists[k][j]>dists[i][j]) {
					dists[i][j] = dists[i][k]+dists[k][j];
				}
			}
		}
	}
	for (int i = 0; i < n ; i++) {
		if (dists[i][i]>0) {
			//positive cycle, impossible
			cout << "impossible" << "\n";
			return;
		}
	}
	
	//find one guy such that for all others he fires before them, at every step
	vs res;
	for (int i = 0; i < shooters ; i++) {
		int next = -1;
		for(int j = 0; j < n; j++){
			if (!shooter[j]||already[j]) {
				continue;
			}
			bool ok = true;
			for(int k = 0; k < n; k++){
				if (!shooter[k]||already[k]||j==k) {
					continue;
				}
				if (dists[k][j]>0) {
					ok = false;
					break;
				}
				
			}
			if (ok) {
				if (next!=-1) {
					cout << "unknown" << "\n";
					return;
				}
				next = j;
			}
		}
		res.pb(revmp[next]);
		already[next] = true;
	}
	
	for (int i = 0; i < res.size() ; i++) {
		if (i==res.size()-1) {
			cout << res[i] << "\n";
		}else {
			cout << res[i] << " " ;
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ti++){
		cout << "Case #" << ti  << ": ";
		solve();
	}
	
    return 0;
}
