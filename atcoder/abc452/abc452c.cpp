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
    vector<pii> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i].F >> arr[i].S;
    }
    int m;
    cin >> m;
    vector<vector<vector<int>>> mp(11,vector<vector<int>>(11,vector<int>(26,0)));
    vector<string> strs(m);
    for(int i=0;i<m;i++) {
        string str;
        cin >> str;
        strs[i]=str;
        int szz = int(str.size());
        for(int j=1;j<=szz;j++) {
            mp[szz][j][str[j-1]-'a']++;
        }
    }
    for(auto &str:strs) {
        if (int(str.size())!=n) {
            cout << "No\n";
            continue;;
        }
        bool possible = true;
        for(int j=0;auto &[len, pos]:arr) {
            if (mp[len][pos][str[j]-'a']==0) {
                possible = false;
                break;
            }
            j++;
        }
        if (possible)
            cout << "Yes\n";
        else
            cout << "No\n";
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
