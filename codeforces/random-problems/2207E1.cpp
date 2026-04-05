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
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    for(int i=1,minv=n-1;i<=n;i++,minv--) {
        if (!(minv<=arr[i] && arr[i]<=n)) {
            cout << "NO\n";
            return;
        }
    }
    for(int i=2;i<=n;i++) {
        if (!(arr[i-1]>=arr[i])) {
            cout << "NO\n";
            return;
        }
    }
    set<int,greater<int>>ss;
    for(int i=0;i<=n;i++) {
        ss.insert(i);
    }
    for(int i=1;i<=n;i++) {
        if (auto itr = ss.find(arr[i]);itr!=ss.end())
            ss.erase(arr[i]);
    }
    vector<int> ans;
    ans.push_back(*ss.begin());
    ss.erase(*ss.begin());
    for(int i=2;i<=n;i++) {
        if (arr[i]!=arr[i-1])
            ss.insert(arr[i-1]);
        ans.push_back(*ss.begin());
        ss.erase(*ss.begin());
    }
    cout << "YES\n";
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
