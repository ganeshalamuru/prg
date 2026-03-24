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
	ll x,y;
    cin >> x >> y;
    if ((x&y) == 0) {
        cout << x << " " << y << "\n";
        return;
    }
    ll minval = LLONG_MAX,p=0,q=0,tp=0,tq=0;
    bitset<31> bsx(x),bsy(y);
    tp=0,tq=0;
    int i=30,j=30;
    while ((i>=0 && j>=0) && (bsx[i]!=1 || bsy[j]!=1)) {
        tp|=(bsx[i]<<i);
        tq|=(bsy[j]<<j);
        i--,j--;
    }
    // p<=x,q<=x
    if (minval > x-(tp+(1<<i)-1)+y-(tq+(1<<j)) ) {
        minval = x-(tp+(1<<i)-1)+y-(tq+(1<<j));
        p=tp+(1<<i)-1;
        q=tq+(1<<j);
    }
    if (minval > x-(tp+(1<<i))+y-(tq+(1<<j)-1)) {
        minval = x-(tp+(1<<i))+y-(tq+(1<<j)-1);
        p=tp+(1<<i);
        q=tq+(1<<j)-1;
    }

    // p<=x,q>=y
    ll ttp=tp,ttq=tq;
    ll ii=i,jj=j;
    ttq|=(1<<jj);
    ii--,jj--;
    while (ii>=0) {
        if (bsy[jj]==0) {
            ttp|=(1<<ii);
        } else {
            ttq|=(1<<jj);
        }
        ii--,jj--;
    }
    if (minval > x-ttp + ttq-y) {
        minval = x-ttp+ttq-y;
        p=ttp;
        q=ttq;
    }
    // p>=x,q<=y
    ttp=tp,ttq=tq;
    ii=i,jj=j;
    ttp|=(1<<ii);
    ii--,jj--;
    while (ii>=0) {
        if (bsx[ii]==0) {
            ttq|=(1<<jj);
        } else {
            ttp|=(1<<ii);
        }
        ii--,jj--;
    }
    if (minval > ttp-x +y-ttq) {
        minval = ttp-x +y-ttq;
        p=ttp;
        q=ttq;
    }
    //p>=x,q>=y
    ttp=tp,ttq=tq;
    ii=i+1,jj=j+1;
    while(bsx[ii]!=0 || bsy[jj]!=0) {
        ttp^=(bsx[ii]<<ii);
        ttq^=(bsy[jj]<<jj);
        ii++,jj++;
    }
    if (minval > ttp+(1<<ii)-x) {
        minval = ttp+(1<<ii)-x;
        p = ttp+(1<<ii);
        q=y;
    }
    if (minval > ttq+(1<<jj)-y) {
        minval = ttq+(1<<jj)-y;
        p=x;
        q=ttq+(1<<jj);
    }

    cout << p << " " << q << "\n";
    


    

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
