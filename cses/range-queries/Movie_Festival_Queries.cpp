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
    vector<array<int,3>> arr(n),oarr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2]=i;
        oarr[i]=arr[i];
    }
    sort(all(arr), [](const auto &a, const auto &b){return a[1]<b[1];});
    vector<vector<int>> dp(n+1,vector<int>(18));
    for(int i=0;i<18;i++)
        dp[n][i]=n;
    set<array<int,2>> ss;
    sort(all(oarr));
    for(int i=n-1,j=n-1;i>=0;i--) {
        while (j>=0 && oarr[j][0]>=arr[i][1]) {
            ss.insert({oarr[j][1],oarr[j][2]});    
            j--;
        }
        auto itr = ss.begin();
        if (itr != ss.end()) {
            dp[arr[i][2]][0]=(*itr)[1];
        } else {
            dp[arr[i][2]][0]=n;
        }
        
    }
    sort(all(oarr),[](const auto &a, const auto &b){return a[2]<b[2];});
    for(int i=1;i<18;i++) {
        for(int j=0;j<n;j++) {
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    vector<array<int,3>> queries(q);
    for(int i=0;i<q;i++) {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][2]=i;
    }
    sort(all(queries));
    sort(all(arr));
    set<array<int,2>> ssq;
    for(int i=0;i<n;i++)
        ssq.insert({arr[i][1],arr[i][2]});
    vector<int> ans(q);
    for(int j=0;auto &[a,b,qind]:queries) {
        while (j<n && arr[j][0]<a) {
            ssq.erase({arr[j][1],arr[j][2]});
            j++;
        }
        int ind = (*ssq.begin())[1];
        int numovies = 0;
        if (oarr[ind][1]<=b)
            numovies++;
        for(int i=17;i>=0;i--) {
            if (dp[ind][i]!=n && oarr[dp[ind][i]][1]<=b) {
                ind = dp[ind][i];
                numovies+=(1<<i);
            }
        }
        ans[qind]=numovies;
    }
    for(int numovies:ans) {
        cout << numovies << "\n";
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