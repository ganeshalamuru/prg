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
    vector<int> a(n);
    vector<pii> mon(m);
    multiset<int> swords;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        swords.insert(a[i]);
    }
    for(int i=0;i<m;i++) {
        cin >> mon[i].F;
    }
    for(int i=0;i<m;i++) {
        cin >> mon[i].S;
    }
    sort(all(mon));
    multiset<pii,greater<pii>> cmon;
    int j=0,ans = 0;
    while(!swords.empty()) {
        auto itr = swords.begin();
        while(j<m && mon[j].F<=(*itr)) {
            cmon.insert({mon[j].S,mon[j].F});
            j++;
        }
        if (cmon.empty()) {
            swords.erase(itr);
            continue;
        }
        auto cmitr = cmon.begin();
        ans++;
        if (cmitr->F==0) {
            swords.erase(itr);
        } else if (cmitr->F > (*itr)) {
            swords.erase(itr);
            swords.insert(cmitr->F);
        }
        cmon.erase(cmitr);
    }
    cout << ans << "\n";


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
