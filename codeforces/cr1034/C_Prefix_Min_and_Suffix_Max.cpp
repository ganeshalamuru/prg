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
    for(int i=0;i<n;i++)
        cin >>arr[i];
    vector<int>pmin(n),smax(n);
    pmin[0] = arr[0];
    for(int i=1;i<n;i++) {
        pmin[i]=min(pmin[i-1],arr[i]);
    }
    smax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--) {
        smax[i]=max(smax[i+1],arr[i]);
    }
    string s = "1";
    for(int i=1;i<n-1;i++) {
        if (pmin[i-1]<arr[i] && arr[i]<smax[i+1]) {
            s.push_back('0');
        } else {
            s.push_back('1');
        }
    }
    s.push_back('1');
    cout << s << "\n";
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
