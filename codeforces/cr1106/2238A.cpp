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
	int n,c;
    cin >> n >> c;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++) {
        cin >> b[i];
    }
    int ans1 = 0;
    bool withoutreoder = true;
    for(int i=0;i<n;i++) {
        if (b[i]>a[i]) {
            withoutreoder = false;
            break;
        }
        ans1+=a[i]-b[i];
    }
    int ans2 = c;
    sort(all(a));
    sort(all(b));
    bool withreoder = true;
    for(int i=0;i<n;i++) {
        if (b[i]>a[i]) {
            withreoder = false;
            break;
        }
        ans2+=a[i]-b[i];
    }
    int ans =  INT_MAX;
    if (withoutreoder)
        ans = min(ans,ans1);
    if (withreoder)
        ans = min(ans,ans2);
    if (ans == INT_MAX)
        cout << -1 << "\n";
    else
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
