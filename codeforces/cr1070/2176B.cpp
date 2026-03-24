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
	int n;
    cin >> n;
    string s;
    cin >> s;
    int maxconseczeros = 0;
    int i=0;
    while(i<n) {
        if (s[i]=='1') {
            i++;
            continue;
        }
        int cnt = 0;
        while(i<n && s[i]=='0')
            cnt++,i++;
        maxconseczeros = max(maxconseczeros, cnt);
    }
    if (s[0]==s[n-1] && s[0]=='0') {
        int cnt = 0,j=n-1,z=0;
        while(j>=0 && s[j]=='0')
            cnt++,j--;
        while(z<n && s[z]=='0')
            cnt++,z++;
        maxconseczeros = max(maxconseczeros, cnt);        
    }
    cout << maxconseczeros << "\n";
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
