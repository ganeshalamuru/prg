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
	int n,s;
    cin >> n >> s;
    vector<int>freq(3,0);
    int sum = 0;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        freq[x]++;
        sum+=x;
    }
    if (sum > s) {
        for(int j=0;j<3;j++) {
            for(int i=0;i<freq[j];i++) {
                cout << j << " ";
            }
        }
        cout << "\n";
    } else if (sum==s) {
        cout << "-1\n";
    } else if (s-sum==1) {
        for(int j:{0,2,1}) {
            for(int i=0;i<freq[j];i++) {
                cout << j << " ";
            }
        }
        cout << "\n";
    } else {
        cout << "-1\n";
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
