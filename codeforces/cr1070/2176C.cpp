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
    vector<vector<int>> arr(2);
    for(int i=0,x;i<n;i++) {
        cin >> x;
        arr[x%2].push_back(x);
    }
    sort(rall(arr[0]));
    sort(rall(arr[1]));
    if (arr[1].empty()) {
        for(int i=0;i<n;i++) {
            cout << 0 << " ";
        }
        cout << "\n";
        return;
    }
    if (arr[0].empty()) {
        for(int i=0;i<n;i++) {
            if (i%2==0)
                cout << arr[1][0] << " ";
            else
                cout << 0 << " ";
        }
        cout << "\n";
        return;
    }
    int evensz = int(arr[0].size());
    vector<ll> ans(n);
    ans[0]=arr[1][0];
    for(int i=1;i<=evensz;i++) {
        ans[i]=ans[i-1]+arr[0][i-1];
    }
    for(int i=evensz+1,j=0;i<n;i++,j++) {
        if (j%2 == 0) {
            if (i<n-1)
                ans[i]=ans[evensz-1];
            else
                ans[i] = 0;
        } else {
            ans[i]=ans[evensz];
        }
    }
    for(int i=0;i<n;i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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
