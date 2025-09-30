#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> arr(m);
    set<int> blackcells;
    for(int i=0;i<m;i++) {
        cin >> arr[i];
        blackcells.insert(arr[i]);
    }
    int stcell = 1;
    for(int i=0;i<n;i++) {
        if (s[i]=='A') {
            stcell++;
            blackcells.insert(stcell);
        } else {
            stcell++;
            while (blackcells.find(stcell)!=blackcells.end()) {
                stcell++;
            }
            blackcells.insert(stcell);
            while (blackcells.find(stcell)!=blackcells.end()) {
                stcell++;
            }
        }
    }
    cout << blackcells.size() << "\n";
    for(int num:blackcells) {
        cout << num << " ";
    }
    cout << "\n";


}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
