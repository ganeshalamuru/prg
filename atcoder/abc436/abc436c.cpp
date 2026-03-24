#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;



void solve() {
	int n,m;
    cin >> n >> m;
    set<pii> ss;
    int ans = 0;
    for(int i=0,a,b;i<m;i++) {
        cin >> a >> b;
        bool placable = true;
        auto cells = {pii{a,b},{a,b+1},{a+1,b},{a+1,b+1}};
        for(auto [x,y]:cells) {
            if(x<1 || x>n || y<1 || y>n) {
                placable = false;
                break;
            }
            if (ss.find({x,y})!=ss.end()) {
                placable = false;
                break;
            }
        }
        if (placable) {
            ans++;
            for(auto [x,y]:cells) {
                ss.insert({x,y});
            }
        }
    }
    cout << ans << "\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
