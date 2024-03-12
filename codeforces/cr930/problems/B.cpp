#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}




void solve(){
	int n;
    cin >> n;
    vector<vector<int>> arr(2,vector<int>(n));
    for(int i=0;i<2;i++) {
        string str;
        cin >> str;
        for(int j=0;j<n;j++)
            arr[i][j] = str[j]-'0';
    }
    set<pair<int,int>> cells;
    cells.insert({0,0});
    map<pair<int,int>,int> freq;
    freq[{0,0}] = 1;
    string path = "";
    path.push_back('0'+arr[0][0]);
    int steps = n;
    while(steps--) {
        map<char, vector<pair<int,int>>> binvalpairs;
        map<pair<int,int>,int> tfreq;
        for(auto cell:cells) {
            if (cell.first+1<2) {
                binvalpairs['0'+arr[cell.first+1][cell.second]].push_back({cell.first+1,cell.second});
                tfreq[{cell.first+1,cell.second}]+=freq[cell];
            }
            if (cell.second+1<n) {
                binvalpairs['0'+arr[cell.first][cell.second+1]].push_back({cell.first,cell.second+1});
                tfreq[{cell.first,cell.second+1}]+=freq[cell];
            }
            
        }
        cells = set<pair<int,int>>();
        path.push_back(binvalpairs.begin()->first);
        for(auto cell:binvalpairs.begin()->second)
            cells.insert(cell);
        freq = map<pair<int,int>,int>();
        for(auto cell:cells)
            freq[cell] = tfreq[cell];
    }
    cout << path << "\n";
    cout << freq.begin()->second << "\n";

}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
