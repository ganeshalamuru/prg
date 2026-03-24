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
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    vector<int>vis(n+1,0);
    ll ans =0;
    for(int i=1;i<=n;i++) {
        if (vis[i]!=0)
            continue;
        ll trav = i,cnt = 0;
        while(vis[trav]==0) {
            vis[trav]=1;
            cnt++;
            trav = arr[trav]; 
        }
        ans += (cnt)*(cnt-1)/2;
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
