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
    if (k%2 == 1) {
        for(int i=0;i<k;i++) {
            cout << n << " ";
        }
        cout << "\n";
        return;
    }
    vector<int> arr(k,0);
    int tb=30;
    while(((n>>tb)&1) == 0)
        tb--;
    int numsetbits = 0;
    for(int i=tb;i>=0;i--) {
        if (((n>>i)&1) == 1) {
            for(int j=0;j<k;j++) {
                if (j!=numsetbits) {
                    arr[j]|=(1<<i);
                }
            }
            if (numsetbits>=k)
                arr[k-1]=(arr[k-1]^(1<<i));
            numsetbits++;
        } else {
            int times = numsetbits;
            if (times%2 == 1)
                times--;
            for(int j=0;j<min(k,times);j++) {
                arr[j]|=(1<<i);
            }
        }
    }

    for(int num:arr) {
        cout << num << " ";
    }
    cout << "\n";

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
