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
	int r,x,d,n;
    cin >> r >> x >> d >> n;
    int cur = r;
    string s;
    cin >> s;
    int ans = 0;
    for(char ch:s) {
        if (ch=='1' || cur < x) {
            ans++;
            cur = max(0,cur-d);
        }
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
