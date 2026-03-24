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
	int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<vector<int>> dp(n+1,vector<int>(17));
    for(int i=0;i<17;i++)
        dp[n][i]=n;
    stack<int> stk;
    for(int i=n-1;i>=0;i--) {
        while (!stk.empty() && arr[stk.top()]<=arr[i]) {
            stk.pop();
        }
        if (stk.empty())
            dp[i][0]=n;
        else
            dp[i][0]=stk.top();
        stk.push(i);
    }
    for(int i=1;i<17;i++) {
        for(int j=n-1;j>=0;j--) {
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    while (q--) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        int numvis = 1, l=a, r=b,i=16;
        while (l<r) {
            while (i>=0 && dp[l][i]>r)
                i--;
            if (i<0)
                break;
            numvis += 1<<i;
            l=dp[l][i];
        }
        cout << numvis << "\n";
        
    }
    

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
