#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


bool pos(vector<int> &arr,int k, int minmex) {
    int numsubarrays = 0;
    int i=0;
    vector<int> mexid(minmex,0);
    int j=0;
    while(i<arr.size()) {
        if (arr[i]<minmex)
            mexid[arr[i]]=1;
        while(j<minmex && mexid[j]==1)
            j++;
        if (j==minmex) {
            for(int z=0;z<minmex;z++)
                mexid[z]=0;
            numsubarrays++;
            j=0;
        }
        i++;
    }
    return numsubarrays>=k;
}

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int l=0,r=n/k + (n%k!=0);
    while(l<r) {
        int mid = l+(r-l+1)/2;
        if (pos(arr,k,mid)) {
            l=mid;
        } else {
            r=mid-1;
        }
    }
    cout << l << "\n";

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
