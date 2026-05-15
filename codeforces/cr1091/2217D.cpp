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
    vector<pii> spind;
    spind.push_back({0,0});
    for(int i=1,x;i<=k;i++) {
        cin >> x;
        if (spind.size()==1) {
            spind.push_back({x,x});
        } else if (x == spind.back().S + 1) {
            spind.back().S = x;
        } else {
            spind.push_back({x,x});
        }
    }
    spind.push_back({n+1,n+1});
    k=int(spind.size())-2;
    int initval = arr[spind[1].F];
    vector<array<int,2>> consecval(k+2);
    for(int i=1;i<=k+1;i++) {
        int j = spind[i-1].S+1,csval = 0;
        while(j<spind[i].F && arr[j]==initval) j++;
        while (j<spind[i].F) {
            int val = arr[j];
            while (j<spind[i].F && val==arr[j]) {
                j++;
            }
            csval++;
        }
        consecval[i][0]=csval;
        j=spind[i].F-1,csval = 0;
        while(j>spind[i-1].S && arr[j]==initval) j--;
        while (j>spind[i-1].S) {
            int val = arr[j];
            while (j>spind[i-1].S && val==arr[j]) {
                j--;
            }
            csval++;
        }
        consecval[i][1]=csval;
    }
    vector<array<int,2>> dp(k+1);
    dp[1][0] = consecval[1][0] + (consecval[1][0]%2);
    int tmp = max(consecval[1][0],consecval[2][1]);
    dp[1][1] = tmp + (tmp%2);
    for(int i=2;i<=k;i++) {
        dp[i][0]=min(dp[i-1][1], dp[i-1][0] + consecval[i][0] + (consecval[i][0]%2));
        int tmp2 = max(consecval[i][0],consecval[i+1][1]);
        dp[i][1]=min(dp[i-1][1]+consecval[i+1][1]+(consecval[i+1][1]%2), dp[i-1][0]+tmp2+(tmp2%2));
    }
    cout << dp[k][1] << "\n";

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
