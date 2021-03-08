    #include <bits/stdc++.h>
    using namespace std;
    #define long long ll;
     
    int n, c;
    int stallpos[100000];
     
    bool ok(int dist){
    	int pos = stallpos[0];
    	int nextpos = stallpos[0]+dist;
    	int laststall = 0;
    	bool ok = true;
    	for(int i = 1; i < c; ++i) {
    //		cout << "hi " << pos  << " " <<  nextpos<< "\n";
    		if (laststall == n) {
    			ok = false;
    			break;
    		}
    		while(pos<nextpos&&laststall<n){
    			if (laststall==n-1&&i<c) {
    				ok = false;
    				break;
    			}
    			laststall++;
    			pos=stallpos[laststall];
    			
    //			cout << "hi2 " << pos  << " " <<  nextpos<< "\n";
    		}
    		nextpos = pos+dist;
    	}
    	return ok;
    }
     
     
    void solve(){
    	cin >> n >> c;
    	for(int i = 0; i < n; ++i) {
    		cin >> stallpos[i];
    	}
     
    	sort(stallpos,stallpos+n);
     
     
    	int start = 0;
    	int end = 100000000;
    	int middle;
    	while(start<=end){
    		middle = (start+end)/2;
    		bool ok2 = ok(middle);
    		if (ok2) {
    			start = middle+1;
    		}else{
    			end = middle-1;
    		}
    	}
    	if (ok(middle)) {
    		cout << middle << "\n";
    	}else {
    		cout << middle-1 << "\n";
    	}
    	
    }
     
     
     
    int main(){
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	
    //	freopen("text.in","r",stdin);
    	int t;
    	cin >> t;
    	for(int i = 0; i < t; ++i) {
    		solve();
    	}
    //	freopen("task.in","r",stdin);
    //	freopen("task.out","w",stdout);
     
    	
    	return 0;
    }
     
