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
	int n,k;
    cin >> n >> k;
    vector<int> freq(n+1);
    for(int i=0,x;i<n;i++) {
        cin >> x;
        freq[x]++;
    }
    int mex = 0,i=0;
    while(i<=n && freq[i]>0) {
        mex++,i++;
    }
    cout << min(mex,k-1) << "\n";
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
