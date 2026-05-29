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
    vector<int>arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int> ops;
    int flip=1;
    for(int i=n-1;i>=0;i--) {
        if (arr[i]*flip>0) {
            ops.push_back(i);
            flip*=-1;
        }
    }
    cout << ops.size() << "\n";
    for(int i=0;i<int(ops.size());i++) {
        cout << ops[i]+1 << " ";
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
