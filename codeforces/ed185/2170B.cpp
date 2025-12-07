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
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(all(arr));
    if (find_if(all(arr),[](const auto &a) {return a>0;}) == arr.end()) {
        cout << 0 << "\n";
        return;
    }
    vector<pii> ops;
    int i=0,basenum = 0;
    while(i<n) {
        int num = arr[i],l=i;
        while(i<n && arr[i]==num)
            i++;
        int times = num-basenum;
        while (times--)
            ops.push_back({l,n-1});
        basenum=num;
    }
    sort(all(ops),[](const auto &a, const auto &b){return a.S-a.F<b.S-b.F;});
    if (int(ops.size())==n) {
        cout << ops.back().S-ops.back().F+1 << "\n";
        return;
    }
    int curops = int(ops.size()),ans = 1;
    i=0;
    while (i<int(ops.size()) && curops<n) {
        int splits = ops[i].S-ops[i].F+1;
        if (curops-1+splits>=n) {
            int actsplits=n-curops+1;
            if (i==int(ops.size())-1) {
                ans = max(ans, splits-actsplits+1);
            } else {
                ans = max(ans, ops.back().S-ops.back().F+1);
            }
            break;
        } else {
            curops+=splits-1;
            i++;
        }
    }
    cout << ans << "\n";


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
