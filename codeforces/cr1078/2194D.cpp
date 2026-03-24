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
	int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    int tot = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> arr[i][j];
            tot+=arr[i][j];
        }
    }
    int half = tot/2;
    vector<int> verticalcuts(n,0);
    int i = n-1,cursum = 0;
    while(i>=0 && cursum<half) {
        int j = 0;
        while(j<m && cursum<half) {
            cursum+=arr[i][j];
            j++;
        }
        verticalcuts[i]=j;
        i--;
    }
    cout << 1ll * half * (tot-half) << "\n";
    string ans;
    int j=0;
    for(int z=0;z<n;z++) {
        while(j<verticalcuts[z]) {
            ans.push_back('R');
            j++;
        }
        ans.push_back('D');
    }
    while(j<m) {
        ans.push_back('R');
        j++;
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
