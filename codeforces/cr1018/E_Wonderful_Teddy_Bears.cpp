#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


/*
PBPPBPB
PBBPPPB +1
PBBPBPP +1
BBPPBPP +1
BBBPPPP +1

*/
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll moves = 0;
    int lastopen = n-1,i=n-1;
    queue<int> unplacedpinks;
    while(i>=0) {
        if (s[i]=='B') {
            i--;
            continue;
        }
        if (i%2==lastopen%2) {
            moves+=(lastopen-i)/2;
            lastopen--;
            if (!unplacedpinks.empty()) {
                moves+=(lastopen-unplacedpinks.front())/2;
                unplacedpinks.pop();
                lastopen--;
            }
        } else {
            unplacedpinks.push(i);
        }
        i--;
    }
    while (!unplacedpinks.empty()) {
        moves+=(lastopen-unplacedpinks.front())/2 + (lastopen-unplacedpinks.front())%2;
        lastopen--;
        unplacedpinks.pop();
    }
    cout << moves << "\n";

}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
    	solve();
    }
    return 0;
}
