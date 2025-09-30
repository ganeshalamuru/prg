#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9;


void solve() {
	int n,k;
    cin >> n >> k;
    if (n<k) {
        cout << 1 <<"\n";
        return;
    }
    vector<int> arr(n+1);
    for(int i=0;i<k;i++)
        arr[i]=1;
    int window = k;
    for(int i=k;i<=n;i++) {
        arr[i]=window;
        window=(window+arr[i])%mod;
        window=(window-arr[i-k]+mod)%mod;
    }
    cout << arr[n] << "\n";


}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
