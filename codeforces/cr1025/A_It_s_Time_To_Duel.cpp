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
    vector<int> arr2;
    int i=0;
    while(i<n) {
        int val = arr[i];
        int cnt = 0;
        while(i<n && arr[i]==val) {
            i++,cnt++;
        }
        arr2.push_back(cnt);
    }
    if (arr2.size()==1) {
        cout << "YES\n";
        return;
    }
    int curval = arr[0];
    for(int j=0;j<arr2.size();j++,curval^=1) {
        if (curval==0 && arr2[j]>1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
