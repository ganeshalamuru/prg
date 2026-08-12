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
    vector<vector<int>> a(n,vector<int>(2)),b(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin >> a[i][0];
        a[i][1]=i;
    }
    for(int i=0;i<n;i++) {
        cin >> b[i][0];
        b[i][1]=i;
    }
    sort(all(a)),sort(all(b));
    for(int i=0;i<n;i++) {
        if (a[i][0]>b[i][0]) {
            cout << -1 << "\n";
            return;
        }
    }
    auto cmp = [](const vector<int>&l,const vector<int>&r) {
        return l[1]<r[1];
    };
    sort(all(a),cmp),sort(all(b),cmp);
    int ans = 0;
    for(int i=0;i<n;i++) {
        int j=i;
        while (j<n && a[j][0]>b[i][0]) {
            j++;
        }
        while (j>i) {
            swap(a[j],a[j-1]);
            j--;
            ans++;
        }
    }
    cout << ans << "\n" << flush;


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
