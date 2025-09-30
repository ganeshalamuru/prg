#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<int> arr(2*n);
    for(int i=0;i<2*n;i++) {
        cin >> arr[i];
    }
    ll evnsum = 0;
    ll oddsum = 0;
    for(int i=0;i<2*n;i+=2) {
        evnsum+=arr[i+1]-arr[i];
    }
    if (n==1) {
        cout << evnsum << "\n";
        return;
    }
    for(int i=1;i+1<2*n;i+=2) {
        oddsum+=arr[i+1]-arr[i];
    }
    int i=0,j=2*n-1;
    vector<ll>ans;
    ll outermatch = 0;
    for(int k=0;k<n;k++,i++,j--) {
        if (k%2==0) {
            ans.push_back(outermatch+evnsum);
            evnsum-=(arr[i+1]-arr[i])+(arr[j]-arr[j-1]);
        } else {
            ans.push_back(outermatch+oddsum);
            oddsum-=(arr[i+1]-arr[i])+(arr[j]-arr[j-1]);
        }
        outermatch+=arr[j]-arr[i];
    }
    for(int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
