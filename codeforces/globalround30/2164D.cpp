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
    string s,t;
    cin >> s >> t;
    int i=n-1,j=n-1;
    vector<int> arr(n,0);
    while(j>=0 && i>=0) {
        if (s[i]==t[j]) {
            arr[j]=i;
            j--;
            if (j<i)
                i=j;
        } else {
            i--;
        }
    }
    if (!(i==-1 && j==-1)) {
        cout << -1 << "\n";
        return;
    }
    int maxop = 0;
    for(int z=0;z<n;z++) {
        if (z-arr[z]>k) {
            cout << -1 << "\n";
            return; 
        }
        maxop=max(maxop,z-arr[z]);
    }
    vector<string> ans(maxop+1);
    ans[0]=s;
    for(int z=1;z<=maxop;z++) {
        ans[z]=ans[z-1];
        for(int y=n-1;y>=0;y--) {
            if (arr[y]+z<=y) {
                ans[z][arr[y]+z]=ans[z-1][arr[y]+z-1];
            }
        }
    }
    cout << maxop << "\n";
    for(int z=1;z<=maxop;z++) {
        cout << ans[z] << "\n";
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
