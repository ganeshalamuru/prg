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
	int n,k;
    cin >> n >> k;
    vector<vector<int>> arr(n,vector<int>(26,0));
    for(int i=0;i<k;i++) {
        string str;
        cin >> str;
        for(int j=0;j<n;j++) {
            arr[j][str[j]-'a']=1;
        }
    }
    set<int> divs;
    for(int i=1;i<=n;i++) {
        if (n%i==0) {
            divs.insert(i);
            divs.insert(n/i);
        }
    }
    string ans(n,'a');
    for(int div:divs) {
        bool pos = true;
        for(int i=0;i<div;i++) {
            int ch = -1;
            for(int z=0;z<26;z++) {
                int fnd = 1;
                for(int j=i;j<n;j+=div) {
                    fnd=fnd&arr[j][z];
                }
                if (fnd) {
                    ch=z;
                    break;
                }
            }
            if (ch==-1) {
                pos=false;
                break;
            } else {
                ans[i]=char('a'+ch);
            }
        }
        if (pos) {
            for(int i=0;i<div;i++) {
                for(int j=i;j<n;j+=div) {
                    ans[j]=ans[i];
                }
            }
            cout << ans << "\n";
            break;
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
