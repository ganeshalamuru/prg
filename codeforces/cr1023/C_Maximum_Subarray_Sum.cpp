#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;

ll NINF = -1e18l;
void solve() {
	ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll>arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int>uind{-1};
    for(int i=0;i<n;i++) {
        if (s[i]=='0')
            arr[i]=NINF,uind.push_back(i);
    }
    uind.push_back(n);
    ll maxmaxsum=LLONG_MIN;
    for(int i=0;i<uind.size()-1;i++) {
        int l=uind[i]+1,r=uind[i+1]-1;
        if (r<l)
            continue;
        ll maxsum = LLONG_MIN;
        ll tsum = 0;
        while(l<=r) {
            if (tsum+arr[l]>0) {
                tsum+=arr[l];
                maxsum=max(maxsum,tsum);
            } else {
                tsum=0;
            }
            l++;
        }
        maxmaxsum=max(maxmaxsum,maxsum);
        if (maxsum>k) {
            cout << "No\n";
            return;
        }
    }
    if (maxmaxsum==k) {
        cout << "Yes\n";
        for(int i=0;i<n;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    bool found = false;
    for(int i=1;i<uind.size()-1;i++) {
        ll maxlsum = 0,tsum=0;
        int l=uind[i]+1,r=uind[i]-1;
        l=uind[i-1]+1;
        tsum=0;
        for(int j=uind[i]-1;j>uind[i-1];j--) {
            tsum+=arr[j];
            maxlsum=max(maxlsum,tsum);
        }
        ll maxrsum = 0;
        r=uind[i+1]-1;
        tsum=0;
        for(int j=uind[i]+1;j<uind[i+1];j++) {
            tsum+=arr[j];
            maxrsum=max(maxrsum, tsum); 
        }
        
        arr[uind[i]] = k-maxlsum-maxrsum;
        ll maxsum = LLONG_MIN;
        tsum = 0;
        while(l<=r) {
            if (tsum+arr[l]>0) {
                tsum+=arr[l];
                maxsum=max(maxsum,tsum);
            } else {
                tsum=0;
            }
            l++;
        }
        if (maxsum==k) {
            found=true;
            break;
        } else {
            arr[uind[i]]=NINF;
        }
    }
    if (found) {
        cout << "Yes\n";
        for(int i=0;i<n;i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "No\n";
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
