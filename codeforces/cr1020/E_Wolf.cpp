#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n,q;
    cin >> n >> q;
    vector<int>arr(n);
    vector<int> ind(n+1);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        ind[arr[i]]=i;
    }
    while (q--) {
        int l,r,x;
        cin >> l >> r >> x;
        l--,r--;
        int indx = ind[x];
        if (indx<l || r<indx) {
            cout << -1 << " ";
            continue;
        }
        int leftt = l,rightt = r;
        int numgr=0,numls=0;
        int numacgr=0,numacls=0;
        int smls = 0, smgr = 0;
        while(leftt<rightt) {
            int mid = leftt+(rightt-leftt)/2;
            if (arr[mid]==x) {
                break;
            } else if (indx<mid) {
                rightt=mid-1;
                if (arr[mid]<x)
                    numgr++,numacls++;
                else
                    smgr++;
            } else {
                leftt=mid+1;
                if (arr[mid]>x)
                    numls++,numacgr++;
                else
                    smls++;
                
            }
        }
        int ans = numgr+numls;
        if (numacls<numls) {
            if (smls+numls>=x) {
                cout << -1 << " ";
                continue;
            }
            ans+=numls-numacls;
        }
        if (numacgr<numgr) {
            if (smgr+numgr>n-x) {
                cout << -1 << " ";
                continue;
            }
            ans+=numgr-numacgr;
        }
        if (ans==n)
            cout << -1 << " ";
        else
            cout << ans << " ";
    }
    cout << "\n";


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
