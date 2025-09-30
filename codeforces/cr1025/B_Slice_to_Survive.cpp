#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;

int calcmoves(int x, int y) {
    int moves = 1;
    while(x>1 && y>1) {
        moves+=2;
        x=x/2 + x%2;
        y=y/2 + y%2;
    }
    while (x>1) {
        moves++;
        x=x/2 + x%2;
    }
    while(y>1) {
        moves++;
        y=y/2+y%2;
    }
    return moves;
}

void solve() {
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    cout << min(calcmoves(min(a,n-a+1),m),calcmoves(n,min(b,m-b+1))) << "\n";
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
