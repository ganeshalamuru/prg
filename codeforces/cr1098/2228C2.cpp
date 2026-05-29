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


ll findabsdiff(ll mid, ll a, vector<int>digits) {
    ll numdigits = ll(digits.size());
    string strval;
    ll tmp=0, numdigitsreq = 18;
    if (digits[0]==0) {
        tmp = mid;
        while (tmp>=0 && int(strval.size())<numdigitsreq){
            strval.push_back(char('0'+(tmp%numdigits)));
            tmp/=numdigits;
        }
    } else {
        ll curval = 0,val = ll(digits.size());
        numdigitsreq = 1;
        while (curval+val<=mid) {
            curval+=val;
            numdigitsreq++;
            val*=numdigits;
        }
        tmp = mid-curval;
        while (tmp>=0 && int(strval.size())<numdigitsreq){
            strval.push_back(char('0'+(tmp%numdigits)));
            tmp/=numdigits;
        }
    }
    reverse(all(strval));
    ll midval=0;
    for(int i=0;i<numdigitsreq;i++) {
        midval = midval*10+digits[strval[i]-'0'];
    }
    return abs(a-midval);
}

void solve() {
	ll a,n;
    cin >> a >> n;
    vector<int> digits(n);
    for(int i=0;i<n;i++)
        cin >> digits[i];
    if (n==1 && digits[0]==0) {
        cout << a << "\n";
        return;
    }
    if (n==10) {
        cout << 0 << "\n";
        return;
    }
    ll maxperms=0,val = n;
    for(int numd=1;numd<=17;numd++,val*=n)
        maxperms+=val;
    ll l=0,r=maxperms+val-1;
    if (digits[0] == 0)
        l=0,r=val-1;
    while (l<r) {
        ll mid = l+(r-l)/2;
        ll f_mid = findabsdiff(mid,a,digits);
        ll f_midp1 = findabsdiff(mid+1,a,digits);
        // cout << "l " << " r" << l << " " << r << " " << f_mid << " " << f_midp1 << "\n"<<flush;
        if (f_midp1<f_mid) {
            l=mid+1;
        } else if (f_midp1 == f_mid) {
            cout << f_mid << "\n";
            return;
        } else {
            r=mid;
        }
    }
    cout << findabsdiff(l,a,digits) << "\n";
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
