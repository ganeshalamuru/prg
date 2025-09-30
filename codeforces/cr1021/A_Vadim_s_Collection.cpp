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
	string s;
    cin >> s;
    vector<int> freq(10,0);
    for(int i=0;i<s.size();i++) {
        freq[s[i]-'0']++;
    }
    string ans="";
    for(int i=0;i<10;i++) {
        int req = 10-i-1;
        for(int j=req;j<10;j++) {
            if (freq[j]>0) {
                ans.push_back('0'+j);
                freq[j]--;
                break;
            }
        }
    }
    cout << ans << "\n";


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
