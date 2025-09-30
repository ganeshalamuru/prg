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
	int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int>pmed(n),smed(n);
    multiset<int,greater<int>> leftt;
    multiset<int> rightt;
    leftt.insert(arr[0]);
    pmed[0]=*leftt.begin();
    for(int i=1;i<n;i++) {
        int lsz = (i+1)/2 + (i+1)%2;
        if (arr[i]<=*leftt.begin()) {
            leftt.insert(arr[i]);
            if (leftt.size()>lsz) {
                auto itr = leftt.begin();
                rightt.insert(*itr);
                leftt.erase(itr);
            }
        } else {
            rightt.insert(arr[i]);
            if (leftt.size()<lsz) {
                auto itr = rightt.begin();
                leftt.insert(*itr);
                rightt.erase(itr);
            }
        }
        pmed[i]=*leftt.begin();
    }

    leftt = multiset<int,greater<int>>();
    rightt = multiset<int>();
    leftt.insert(arr[n-1]);
    smed[n-1]=*leftt.begin();
    for(int i=n-2,szz=2;i>=0;i--,szz++) {
        int lsz = (szz)/2 + (szz)%2;
        if (arr[i]<=*leftt.begin()) {
            leftt.insert(arr[i]);
            if (leftt.size()>lsz) {
                auto itr = leftt.begin();
                rightt.insert(*itr);
                leftt.erase(itr);
            }
        } else {
            rightt.insert(arr[i]);
            if (leftt.size()<lsz) {
                auto itr = rightt.begin();
                leftt.insert(*itr);
                rightt.erase(itr);
            }
        }
        smed[i]=*leftt.begin();
    }
    int firstpmedk=n;
    for(int i=0;i<n;i++) {
        if (pmed[i]<=k) {
            firstpmedk=i;
            break;
        }
    }
    for(int i=firstpmedk+1;i<n-1;i++) {
        if (pmed[i]<=k && arr[i]<=k) {
            cout << "YES\n";
            return;
        }
    }
    int firstsmedk=-1;
    for(int i=n-1;i>=0;i--) {
        if(smed[i]<=k) {
            firstsmedk=i;
            break;
        }
    }
    for(int i=firstsmedk-1;i>=1;i--) {
        if (smed[i]<=k && arr[i]<=k) {
            cout << "YES\n";
            return;
        }
    }

    if (firstpmedk+1 < firstsmedk) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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
