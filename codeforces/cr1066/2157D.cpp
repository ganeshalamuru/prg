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
	int n,l,r;
    cin >> n >> l >> r;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    vector<int> left,middle,right;
    for(int i=0;i<n;i++) {
        if (arr[i]<l) {
            left.push_back(arr[i]);
        } else if (arr[i]<=r) {
            middle.push_back(arr[i]);
        } else {
            right.push_back(arr[i]);
        }
    }
    reverse(all(left));
    ll ans = 0;
    while(!left.empty() && !right.empty()) {
        ans+=right.back() - left.back();
        left.pop_back(),right.pop_back();
    }
    
    if (!left.empty()) {
        while(!left.empty() && !middle.empty()) {
            ans+=middle.back() - left.back();
            left.pop_back(),middle.pop_back();
        }
        if (!middle.empty()) {
            int i=0,j=int(middle.size())-1;
            while(i<j) {
                ans+=middle[j]-middle[i];
                i++,j--;
            }
        } else {
            while(!left.empty()) {
                ans+=l-left.back();
                left.pop_back();
            }
        }
        
    } else if (!right.empty()) {
        reverse(all(middle));
        while(!right.empty() && !middle.empty()) {
            ans+=right.back() - middle.back();
            right.pop_back(), middle.pop_back();
        }
        if (!middle.empty()) {
            reverse(all(middle));
            int i=0,j=int(middle.size())-1;
            while(i<j) {
                ans+=middle[j]-middle[i];
                i++,j--;
            }
        } else {
            while(!right.empty()) {
                ans+=right.back() - r;
                right.pop_back();
            }
        }
    } else {
        int i=0,j=int(middle.size())-1;
        while(i<j) {
            ans+=middle[j]-middle[i];
            i++,j--;
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
