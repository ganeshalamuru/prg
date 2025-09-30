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
	int n,k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    if (n==1) {
        cout << 1 << "\n";
        return;
    }
    sort(arr.begin(),arr.end());
    int maxmed = arr[k + (n-k)/2];
    int minmed = arr[(n-1-k)/2];
    cout << maxmed-minmed+1 << "\n";

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
