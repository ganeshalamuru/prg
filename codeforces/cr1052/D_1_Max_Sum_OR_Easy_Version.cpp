#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const ll mod = 1e9+7;



ll sumbet(int a, int b) {
    return (1ll*b*(b+1)) - (1ll*a*(a-1));
}


void solve() {
	int l,r;
    cin >> l >> r;
    ll ans = 0;
    int num = r;
    vector<int> a(r+1);
    for(int i=0;i<=r;i++)
        a[i]=i;
    int ind = r;
    while(num > 0) {
        bitset<31> bs(num);
        int j=30;
        while(bs[j]==0)
            j--;
        int rem = num-(1<<j);
        if (rem+1==(1<<j)) {
            ans+=sumbet(1,num);
            reverse(a.begin()+ind-num,a.begin()+ind+1);
            ind = ind-num-1;
            break;
        } else {
            int szz = 2*(rem+1);
            ans+=sumbet((1<<j)-rem-1,num);
            reverse(a.begin()+ind-szz+1,a.begin()+ind+1);
            ind = ind-szz;
            num=(1<<j)-rem-2;
        }
    }
    cout << ans << "\n";
    for(int i=0;i<=r;i++) {
        cout << a[i] << " ";
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
