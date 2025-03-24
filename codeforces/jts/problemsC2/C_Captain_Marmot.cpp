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


vector<pair<int,int>> allpos(int x, int y, int a, int b) {
    vector<pair<int,int>> ans;
    ans.push_back({x,y});
    ans.push_back({-y+a+b,x-a+b});
    ans.push_back({-x+2*a,-y+2*b});
    ans.push_back({y-b+a,-x+a+b});
    return ans;
}

ll calcdis(pair<int,int> &p1, pair<int,int> &p2) {
    return 1ll*(p1.F-p2.F)*(p1.F-p2.F) + 1ll*(p1.S-p2.S)*(p1.S-p2.S);
}

bool issquare(pair<int,int> &p1, pair<int,int> &p2,pair<int,int> &p3, pair<int,int> &p4) {
    map<ll,int> mp;
    mp[calcdis(p1,p2)]++;
    mp[calcdis(p1,p3)]++;
    mp[calcdis(p1,p4)]++;
    mp[calcdis(p2,p3)]++;
    mp[calcdis(p2,p4)]++;
    mp[calcdis(p3,p4)]++;
    if (mp.size() ==2) {
        auto itr = mp.begin();
        if (itr->second==4) {
            itr++;
            if (itr->second==2)
                return true;
        }
    }
    return false;
}

int minmoves(vector<vector<pair<int,int>>> &arrs) {
    int ans = INT_MAX;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            for(int k=0;k<4;k++) {
                for(int z=0;z<4;z++) {
                    if (issquare(arrs[0][i],arrs[1][j],arrs[2][k],arrs[3][z])) {
                        ans = min(ans, i+j+k+z);
                    }
                }
            }
        }
    }
    if (ans == INT_MAX)
        return -1;
    return ans;
}

void solve() {
	int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        vector<vector<pair<int,int>>> arrs(4);
        for(int j=0;j<4;j++) {
            int x,y,a,b;
            cin >> x >> y >> a >> b;
            arrs[j] = allpos(x,y,a,b);
        }
        cout << minmoves(arrs) << "\n";
    }
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
