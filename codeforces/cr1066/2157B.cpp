#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;



void solve() {
	int n,x,y;
    cin >> n >> x >> y;
    x=abs(x),y=abs(y);
    string s;
    cin >> s;
    int fourcnt=0,eightcnt=0;
    for(char ch:s) {
        if (ch=='4')
            fourcnt++;
        else
            eightcnt++;
    }
    if (x>eightcnt+fourcnt) {
        cout << "NO\n";
        return;
    }
    if (x<=eightcnt) {
        if (y<=eightcnt+fourcnt) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        int maxy = eightcnt+fourcnt - (x-eightcnt);
        if (y<=maxy) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
