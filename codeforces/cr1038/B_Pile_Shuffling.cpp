#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<vector<ll>>arr(n,vector<ll>(4));
    for(int i=0;i<n;i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    ll numops = 0;
    for(int i=0;i<n;i++) {
        if (arr[i][1]>arr[i][3]) {
            numops+=arr[i][1]-arr[i][3];
            numops+=arr[i][0];
        } else {
            numops+=max(arr[i][0]-arr[i][2],0ll);
        }
    }
    cout << numops << "\n";

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
