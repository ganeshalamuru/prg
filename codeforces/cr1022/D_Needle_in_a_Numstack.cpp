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
    if (n==2*k) {
        cout << "! "<< k << " " << k << "\n" << flush;
        return; 
    }
    vector<int>left(k),right(k);
    vector<int> numindl(k+1,0),numindr(k+1,0);
    for(int i=1,x;i<=k;i++) {
        cout << "? " << i << "\n" << flush;
        cin >> x;
        left[i-1]=x;
        numindl[x]=i;
    }
    for(int j=n-k+1,x;j<=n;j++) {
        cout << "? " << j << "\n" << flush;
        cin >> x;
        right[j-(n-k+1)]=x;
        numindr[x]=j;
    }
    int diffindnum = -1;
    for(int i=1;i<=k;i++) {
        if (abs(numindl[i]-numindr[i])%k!=0) {
            diffindnum=i;
            break;
        }
    }
    if (diffindnum == -1) {
        cout << "! -1\n" << flush;
        return;
    }
    int l=numindl[diffindnum],r=l+((n-k-l)/k)*k;
    while(l<r) {
        int len = (r-l)/k;
        int mid = l + ((len+1)/2)*k;
        cout << "? " << mid << "\n"<<flush;
        int val;
        cin >> val;
        if (val!=diffindnum) {
            r=mid-k;
        } else {
            l=mid;
        }
    }
    int ind1 = l,lnumind = numindl[diffindnum]-1,numlval=diffindnum;
    while(ind1<=n-k && numlval==left[lnumind]) {
        ind1++;
        cout << "? " << ind1 << "\n" << flush;
        cin >> numlval;
        lnumind=(lnumind+1)%k;
    }
    ind1--;
    r=numindr[diffindnum],l=r-((r-(k+1))/k)*k;
    while(l<r) {
        int len = (r-l)/k;
        int mid = r - ((len+1)/2)*k;
        cout << "? " << mid << "\n" << flush;
        int val;
        cin >> val;
        if (val!=diffindnum) {
            l=mid+k;
        } else {
            r=mid;
        }
    }
    int ind2 = l,rnumind = numindr[diffindnum]-(n-(k-1)),numrval=diffindnum;
    while(ind2>=k+1 && numrval==right[rnumind]) {
        ind2--;
        cout << "? " << ind2 << "\n" << flush;
        cin >> numrval;
        rnumind=(rnumind-1+k)%k;
    }
    ind2++;
    if (ind2<=ind1 || ind2!=ind1+1) {
        cout << "! -1\n" << flush;
    } else {
        cout << "! " << ind1 << " " << n-ind1 << "\n" << flush; 
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
