#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


int dfs(int l, int r, vector<int>&arr, vector<int>&nge) {
    if (r==l)
        return 0;
    if (r==l+1)
        return 1;
    int maxlen = 0;
    int i=l;
    int pi = -1;
    while(i<r) {
        if (pi!=-1 && arr[pi]!=arr[i])
            maxlen++;
        int j=nge[i];
        int maxlensub = dfs(i+1,j,arr,nge);
        maxlen = max(maxlen, maxlensub+1);
        pi=i;
        i=j;
    }
    return maxlen;
}


void solve() {
	int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int> nge(n);
    stack<int> stk;
    for(int i=n-1;i>=0;i--) {
        while (!stk.empty() && arr[stk.top()]<arr[i]){
            stk.pop();
        }
        if (stk.empty()) {
            nge[i]=n;
        } else {
            nge[i]=stk.top();
        }
        stk.push(i);
    }
    int maxlen = dfs(0,n,arr,nge);
    cout << maxlen << "\n";
}


int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
