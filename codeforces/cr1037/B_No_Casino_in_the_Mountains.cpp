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
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int numpeaks = 0;
    int i=0;
    while(i<n) {
        int j=i,endind = i+k;
        while(j<endind && j<n && arr[j]==0) {
            j++;
        }
        if (j==endind) {
            numpeaks++;
        }
        i=j+1;
    }
    cout << numpeaks << "\n";

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
