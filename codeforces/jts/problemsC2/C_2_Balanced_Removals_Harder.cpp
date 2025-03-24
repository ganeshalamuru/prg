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




void solve() {
	int n;
    cin >> n;
    vector<vector<int>> points(n,vector<int>(4));
    for(int i=0;i<n;i++) {
        auto &point = points[i];
        cin >> point[0] >> point[1] >> point[2];
        point[3] = i;
    }
    vector<pair<int,int>> ans;
    sort(points.begin(), points.end());
    vector<int> picked(n,0);
    // combine points with same x and y
    map<pair<int,int>, int> mp;
    for(const auto& point:points) {
        pair<int,int> tp = {point[0], point[1]};
        int index = point[3];
        if (mp.find(tp) != mp.end() && picked[mp[tp]] == 0) {
            picked[mp[tp]] = 1, picked[index] = 1;
            ans.push_back({mp[tp], index});
        }
        mp[tp] = index;
    }
    // combine points with same x
    map<int, int> mp2;
    for(const auto &point:points) {
        int index = point[3];
        if (picked[index] == 1)
            continue;
        if (mp2.find(point[0]) != mp2.end() && picked[mp2[point[0]]] == 0) {
            picked[mp2[point[0]]] = 1, picked[index] = 1;
            ans.push_back({mp2[point[0]],index});
        }
        mp2[point[0]] = index; 
    }
    // combine poitns with different x
    int prev = -1;
    for(const auto& point:points) {
        int index = point[3];
        if (picked[index] == 1)
            continue;
        if (prev != -1 && picked[prev] == 0) {
            picked[prev] = 1, picked[index] = 1;
            ans.push_back({prev, index});
        }
        prev = index;
    }
    for(auto &pointIndPair:ans)
        cout << pointIndPair.first + 1 << " " << pointIndPair.second + 1 << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
