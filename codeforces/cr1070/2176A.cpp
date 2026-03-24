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
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int j=n-1,ans = 0;
    while(j>=0) {
        int maxele = *max_element(arr.begin(),arr.begin()+j+1);
        auto itr = find(arr.begin(), arr.begin()+j+1, maxele);
        int firstmaxind = int(distance(arr.begin(), itr));
        for(int i=j;i>=firstmaxind;i--) {
            if (arr[i]!=maxele) {
                ans++;
            }
            
        }
        j=firstmaxind-1;
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
