#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;
int N=1e6+1;
vector<int>freq(N,0),seq(N,0);
void solve(int n,int d,vector<int>&arr) {
    //fill(all(freq),0),fill(all(seq),0);
    //cout << "My: ";
    for(int i=0;i<n;i++) {
        freq[arr[i]]++;
    }
    if (d==0) {
        int dis = 0;
        for(int i=0;i<N;i++) {
            if (freq[i]>0) {
                dis++;
            }
        }
        cout << n-dis << "\n";
        return;
    }
    int ans=0,i=0;
    while(i<N) {
        if (freq[i]==0 || seq[i]!=0 || (i-d>=0 && seq[i-d]!=0) || (i+d<N && seq[i+d]!=0)) {
            i++;
            continue;
        }
        vector<pii>vv;
        int val=i;
        while(val<N && freq[val]>0) {
            seq[val]=1;
            vv.push_back({freq[val],val});
            val+=d;
        }
        vector<int> dp(vv.size(),0);
        dp[0]=vv[0].F;
        for(int z=1;z<vv.size();z++) {
            dp[z]=max(dp[z],dp[z-1]);
            int maxcntinclu = vv[z].F;
            if (z-2>=0) {
                maxcntinclu+=dp[z-2];
            }
            dp[z]=max(dp[z],maxcntinclu);
        }   
        ans+=dp[vv.size()-1];
        i++;
    }
    cout << n-ans << "\n";

}
// 0,5,10,12
void solve2(int n,int d, vector<int>&arr) {
    cout << "AC: ";
    int ans = 0;
    multiset<int> fin;
    for(int i=0;i<(1<<n);i++) {
        multiset<int>ss;
        bitset<15>bs(i);
        for(int j=0;j<15;j++) {
            if (bs[j]==1)
                ss.insert(arr[j]);
        }
        bool valid = true;
        for(auto itr=ss.begin();itr!=ss.end();itr++) {
            int val = *itr;
            if (ss.find(val-d)!=ss.end() || ss.find(val+d)!=ss.end()) {
                valid = false;
                break;
            }
        }
        if (valid) {
            if (ans<ss.size()) {
                //fin=ss;
                ans = max(ans, (int)ss.size());
            }
        }
    }
    cout << n-ans << "\n";
}

int main() {
    fast;
    int t = 1;
    // std::random_device dev;
    // std::mt19937 rng(dev());
    // std::uniform_int_distribution<std::mt19937::result_type> dist6(0,N-1); // distribution in range [1, 6]
    while(t--){
        int n=14,d=3;
        cin >> n >> d;
        vector<int>arr(n);
        for(int i=0;i<n;i++) {
            cin >> arr[i];
            // arr[i]=dist6(rng);
            // cout << arr[i] << " "; 
        }
        //cout << "\n";
    	//arr = {10, 0, 5 ,12, 12 ,12, 2, 12 ,7, 5, 9 ,10};
        solve(n,d,arr);
        //solve2(n,d,arr);
    }
    return 0;
}
