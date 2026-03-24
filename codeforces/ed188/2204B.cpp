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
    vector<int> arr(n);
    multiset<int,greater<int>> ms;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        ms.insert(arr[i]);
    }
    int l=n-1,r=n-1,ans = 0;
    while (l>=0) {
        if ((*ms.begin())==arr[l]) {
            while (r>=l) {
                ms.erase(ms.find(arr[r]));
                r--;
            }
            ans++;
        }
        l--;
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
