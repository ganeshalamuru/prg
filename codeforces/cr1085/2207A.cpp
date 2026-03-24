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
    string str;
    cin >> str;
    string s1 = str, s2 = str;
    for(int i=1;i<n-1;i++) {
        if (s1[i-1]=='1' && s1[i+1]=='1')
            s1[i]='1';
    }
    int ansmax = 0;
    for(int i=0;i<n;i++) {
        if (s1[i]=='1')
            ansmax++;
    }
    s2=s1;
    for(int i=1;i<n-1;i++) {
        if (s2[i-1]=='1' && s2[i+1]=='1')
            s2[i]='0';
    }
    int ansmin = 0;
    for(int i=0;i<n;i++) {
        if (s2[i]=='1')
            ansmin++;
    }
    cout << ansmin << " " << ansmax << "\n";

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
