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



pii query(int n, int mid) {
    pii ans{0,0};
    cout << "? " << mid << " ";
    for(int i=1;i<=mid;i++)
        cout << i << " ";
    cout << "\n" << flush;
    cin >> ans.F;
    assert(ans.F!=-1);
    if (mid==n)
        return ans;
    cout << "? " << n-mid << " ";
    for(int i=mid+1;i<=n;i++)
        cout << i << " ";
    cout << "\n" << flush;
    cin >> ans.S;
    assert(ans.S!=-1);
    return ans;
}

void solve() {
	int n;
    cin >> n;


    // find middle of the extra number
    int l=1,r=2*n+1;
    while (l<r) {
        int mid = l+(r-l)/2;
        pii res = query(2*n+1,mid);
        if (res.F-res.S<0) {
            r=mid;
        } else if (res.F-res.S==0) {
            if (res.F%2 == mid%2)
                l=mid+1;
            else
                r=mid-1;
        } else {
            l=mid+1;
        }
    }
    vector<int> ans;
    ans.push_back(l);
    // find first of extra number
    l=1,r=ans[0]-1;
    while (l<r) {
        int mid = l+(r-l)/2;
        pii res = query(2*n+1,mid);
        if (res.F-res.S==0) {
            l=mid+1;
        } else {
            r=mid;
        }
    }
    ans.push_back(l);
    // find last of extra number
    l=ans[0]+1,r=2*n+1;
    while (l<r) {
        int mid = l+(r-l)/2;
        pii res = query(2*n+1,mid);
        if (res.F-res.S<0) {
            l=mid+1;
        } else {
            r=mid;
        }
    }
    ans.push_back(l);

    cout << "! ";
    for(int ind:ans) {
        cout << ind << " "; 
    }
    cout << "\n" << flush;
    
    
    
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
