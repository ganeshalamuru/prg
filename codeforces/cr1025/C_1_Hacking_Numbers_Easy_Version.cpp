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
    int jout;
    cout << "digit\n" << flush;
    cin >> jout;
    cout << "digit\n" << flush;
    cin >> jout;
    int l=1,r=16;
    while(l<r) {
        int mid = l+(r-l)/2;
        cout << "add " << -mid << "\n" << flush;
        cin >> jout;
        if (jout==0) {
            r=mid;
        } else {
            r=r-mid;
        }
    }
    cout << "mul "<< n <<"\n" << flush;
    cin >> jout;
    cout << "!\n" << flush;
    cin >> jout;
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
