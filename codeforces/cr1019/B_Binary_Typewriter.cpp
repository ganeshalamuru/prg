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
    string s;
    cin >> s;
    s = "0"+s;
    int cost = 0;
    for(int i=1;i<=n;i++) {
        if (s[i]!=s[i-1])
            cost+=2;
        else
            cost++;
    }
    string s1="";
    int i=0;
    while (i<=n) {
        char ch = s[i];
        while(i<=n && s[i]==ch)
            i++;
        s1.push_back(ch);
    }
    if (s1.size()>3) {
        cout << cost - 2 << "\n";
    } else if (s1.size()>2) {
        cout << cost - 1 << "\n";
    } else {
        cout << cost << "\n";
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
