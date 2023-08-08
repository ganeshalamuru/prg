#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	long long n;
    cin >> n;
    vector<long long>arr(n);
    map<long long, long long>mp;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    vector<pair<long long, long long>> freqarr;
    for (auto &keyval : mp)
        freqarr.push_back(keyval);
    long long distinctN = freqarr.size();
    vector<long long> psum(distinctN),ssum(distinctN);
    for(long long i=0;i<freqarr.size();i++) {
        long long count = freqarr[i].second;
        if (i==0) {
            psum[i]=count;
            continue;
        }
        psum[i] = psum[i-1] + count;
    }
    for(long long i=freqarr.size() - 1;i>=0;i--) {
        long long count = freqarr[i].second;
        if (i==freqarr.size() - 1) {
            ssum[i]=count;
            continue;
        }
        ssum[i] = ssum[i+1] + count;
    }


    vector<long long> ppsum(distinctN),sssum(distinctN);
    for(long long i = 0; i< distinctN; i++) {
        long long count = 0;
        if (i+1 < distinctN) {
            count = psum[i]*(freqarr[i+1].first - freqarr[i].first);
        } else {
            count = psum[i];
        }
        if (i==0) {
            ppsum[i]=count;
            continue;
        }
        ppsum[i] = ppsum[i-1] + count;
    }
    for(long long i = distinctN - 1; i>=0; i--) {
        long long count = 0;
        if (i-1>=0) {
            count = ssum[i]*(freqarr[i].first - freqarr[i-1].first);
        } else {
            count = ssum[i];
        }
        if (i==distinctN - 1) {
            sssum[i]=count;
            continue;
        }
        sssum[i] = sssum[i+1] + count;
    }

    map<long long, long long> ans;
    for(long long i =0; i<distinctN;i++){
        long long res = 0;
        if (i-1>=0) {
            res += ppsum[i-1];
        }
        if (i+1 < distinctN) {
            res += sssum[i+1];
        }
        res += psum[i] + ssum[i] - freqarr[i].second;
        ans[freqarr[i].first] = res;
    }
    for (long long arrval : arr) {
        cout << ans[arrval] << " ";
    }
    cout << "\n";
}




signed main(){
    fast;
    long long t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
