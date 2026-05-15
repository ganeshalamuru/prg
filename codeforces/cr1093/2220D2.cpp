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



int query(int n, int l, int r) {
    int ans=0;
    cout << "? " << r-l+1 << " ";
    for(int i=l;i<=r;i++)
        cout << (i%(2*n+1)) + 1 << " ";
    cout << "\n" << flush;
    cin >> ans;
    assert(ans!=-1);
    return ans;
}

int findlastextranum(int n,int st) {
    int l=st,r=st+2*n;
    while (l<r) {
        int mid = l+(r-l)/2;
        int res = query(n,st,mid);
        if (res%2 == (mid-st+1)%2) {
            l=mid+1;
        } else {
            r=mid;
        }
    }
    return l;
}


void solve() {
	int n;
    cin >> n;

    vector<int> ans;
    ans.push_back(findlastextranum(n,0));
    ans.push_back(findlastextranum(n,ans.back()));
    ans.push_back(findlastextranum(n,ans.back()));
    cout << "! ";
    for(int ind:ans)
        cout << ind%(2*n+1)+1 << " ";
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
