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
	int n;
    cin >> n;
    int minele = INT_MAX, maxele = INT_MIN;
    for(int i=0,a;i<n;i++) {
        cin >> a;
        minele = min(a,minele);
        maxele = max(a,maxele);
    }
    int ans = INT_MAX;
    for(int i=minele;i<=maxele;i++) {
        ans = min(ans, max(i-minele,maxele-i));
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
