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
    vector<ll> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(all(arr));
    if (arr[0]==arr[1]) {
        cout << "Yes\n";
        return;
    }
    ll minn=arr[0];
    vector<ll> a;
    for(int i=1;i<n;i++) {
        if (arr[i]%minn==0)
            a.push_back(arr[i]/minn); 
    }
    if (a.size()<2) {
        cout << "No\n";
        return;
    }
    ll gcdd = a[0];
    for(int i=1;i<a.size();i++) {
        gcdd=__gcd(gcdd,a[i]);
    }
    if (gcdd==1) {
        cout << "Yes" << "\n";
    } else {
        cout << "No\n";
    }



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
