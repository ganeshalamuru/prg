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
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    int ind;
    cin >> ind;
    int rightops = 0, leftops = 0;
    int j=n;
    while (j>ind && arr[j]==arr[ind])
        j--;
    while (j>ind) {
        int val = arr[j];
        while (j>ind && val==arr[j]) {
            j--;
        }
        rightops++;
    }
    j=1;
    while (j<ind && arr[j]==arr[ind])
        j++;
    while (j<ind) {
        int val = arr[j];
        while (j<ind && val==arr[j]) {
            j++;
        }
        leftops++;
    }

    int tmp = max(leftops, rightops);
    if (tmp == 0) {
        cout << 0 << "\n";
    } else {
        if (tmp%2!=0) tmp++;
        cout << tmp << "\n";
    }


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
