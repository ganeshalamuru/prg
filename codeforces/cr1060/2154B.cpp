#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    
    int prefmax = arr[1];
    ll ans = 0;
    for(int i=2;i<=n;i++) {
        prefmax=max(prefmax, arr[i]);
        if (i%2==0) {
            arr[i]=max(arr[i],prefmax);
            if (arr[i-1]>=arr[i]) {
                ans++;
                arr[i-1]--;
            }
        } else if (arr[i-1]<=arr[i]) {
            ans+=(arr[i]-arr[i-1]+1);
            arr[i]=arr[i-1]-1;
        }
    }
    cout << ans << "\n";

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
