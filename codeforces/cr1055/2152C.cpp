#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<int> psum(n);
    for(int &num:arr)
        cin >> num;
    psum[0]=arr[0];
    for(int i=1;i<n;i++) {
        psum[i]=psum[i-1]+arr[i];
    }
    vector<int>altst,alted;
    int i=0;
    while (i+1<n) {
        if (arr[i]==arr[i+1]) {
            i++;
            continue;
        }
        int j = i,val=arr[i];
        while(j<n && arr[j]==val) {
            j++,val^=1;
        }
        altst.push_back(i);
        alted.push_back(j-1);
        i=j;
    }
    while(q--) {
        int l,r;
        cin >> l >> r;
        l--,r--;
        int sbsz = (r-l+1),numones = psum[r];
        if (l-1>=0)
            numones-=psum[l-1];
        if ((sbsz%3)!=0 || (numones%3)!=0) {
            cout << -1 << "\n";
            continue;
        }
        if (altst.empty()) {
            cout << sbsz/3 << "\n";
            continue;
        }
        auto itr = upper_bound(altst.begin(), altst.end(),l);
        if (itr==altst.begin()) {
            cout << sbsz/3 << "\n";
        } else {
            itr--;
            int index = distance(altst.begin(), itr);
            if (r<=alted[index]) {
                cout << sbsz/3 + 1 << "\n";
            } else {
                cout << sbsz/3 << "\n";
            }
        }

    }
    


}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
