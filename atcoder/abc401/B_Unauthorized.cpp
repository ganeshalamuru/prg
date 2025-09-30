#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<string>arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int loggedin = 0,ans = 0;
    for(int i=0;i<n;i++) {
        if (arr[i]=="login") {
            loggedin=1;
        } else if (arr[i]=="logout") {
            loggedin=0;
        } else if (arr[i]=="private" && loggedin==0) {
            ans++;
        }
    }
    cout << ans << "\n";

}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
