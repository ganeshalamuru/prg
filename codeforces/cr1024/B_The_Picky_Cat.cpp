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
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    if (arr[0] == 0) {
        cout << "Yes\n";
        return;
    }
    int pleft=0, pright=0, pmisc=0;
    for(int i=1;i<n;i++) {
        if (abs(arr[i])<abs(arr[0])) {
            if (arr[0]>0) {
                pleft++;
            } else {
                pright++;
            }
        } else {
            pmisc++;
        }
    }
    if (n%2==0) {
        if (pleft+1<=n/2 && pright<=n/2) {
            cout << "Yes\n";
        } else if (pleft<=n/2 && pright+1<=n/2){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        if (pleft<=n/2 && pright<=n/2) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
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
