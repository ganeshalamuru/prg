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
	int n, k;
    cin >> n >> k;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    map<int,int> freq;
    for(int i=1;i<k;i++) {
        freq[arr[i]]++;
    }
    for(int i=k;i<=n;i++) {
        freq[arr[i]]++;
        cout << freq.size() << " ";
        int lastele = arr[i-k+1];
        freq[lastele]--;
        if (freq[lastele]==0)
            freq.erase(lastele);
    }
    cout << "\n";
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
