#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

//TI LII, TLI LII, TILI LII, TITLI LII, TLITLI LII, TLITLITLI LII, TLITLTLITLTI LII
// a1<a2<a3
// a2-a1<a3-a1
// a3-a2<=a1
// 0102112210
void solve(string s) {
	int n;
    // cin >> n;
    // string s;
    // cin >> s;
    n = s.size();
    int ind = -1;    
    for(int i=0;i<n-1;i++) {
        if (s[i]!=s[i+1]) {
            ind = i;
            break;
        }
    }
    if (ind==-1) {
        cout << -1 << "\n";
        return;
    }
    set<char>ss{'L','I','T'};
    ss.erase(s[ind]),ss.erase(s[ind+1]);
    map<char,char> ff{{s[ind],'0'},{s[ind+1],'1'},{*ss.begin(),'2'}};
    for(auto &ch:s) ch=ff[ch];
    vector<int>cnt(3,0);
    for(int i=0;i<n;i++) cnt[s[i]-'0']++;
    for(int j=0;j<3;j++) cnt[j]=n-cnt[j];
    cnt[2]--;
    vector<int>ops{ind};
    int cnttriple = 1 + min(cnt[0],min(cnt[1],cnt[2]));
    while (cnt[0]>0 && cnt[1]>0 && cnt[2]>0){
        ops.push_back(ind),ops.push_back(ind+1),ops.push_back(ind);
        cnt[0]--,cnt[1]--,cnt[2]--;
    }
    // 020102010201 
    // 02101010101021 2222
    if (cnt[0]>0 && cnt[1]>0) {
        int tind = ind+3*(cnttriple-1);
        int indidff = 1,type=0;
        if (cnt[0]<cnt[1])
            indidff=0,type=1;
        while (cnt[0]!=cnt[1]) {
            ops.push_back(tind+indidff);
            cnt[type]--;
            tind-=3;
        }
        while (cnt[0]>0 && cnt[1]>0) {
            ops.push_back(ind+1),ops.push_back(ind+1);
            cnt[0]--,cnt[1]--;
        }
        
        // 02'1'
        // 02120212021
    } else if (cnt[0]>0 && cnt[2]>0) {
        int tind = ind+3*(cnttriple-1);
        int indidff = 1,type=0;
        if (cnt[0]<cnt[2])
            indidff=-1,type=2;
        while (cnt[0]!=cnt[2]) {
            ops.push_back(tind+indidff);
            cnt[type]--;
            tind-=3;
        }
        while (cnt[0]>0 && cnt[2]>0) {
            ops.push_back(ind+2),ops.push_back(ind+2);
            cnt[0]--,cnt[2]--;
        }
        //L LTILTITLTI III, 
    } else {
        int tind = ind+3*(cnttriple-1);
        int indidff = 0,type=1;
        if (cnt[1]<cnt[2])
            indidff=-1,type=2;
        while (cnt[1]!=cnt[2]) {
            ops.push_back(tind+indidff);
            cnt[type]--;
            tind-=3;
        }
        while (cnt[1]>0 && cnt[2]>0) {
            ops.push_back(ind),ops.push_back(ind);
            cnt[1]--,cnt[2]--;
        }
    }
    int tind = ind+3*(cnttriple-1);
    int indidff = 1,type=0;
    if (cnt[0]>0) {
        type=0,indidff=1;
    } else if (cnt[1]>0) {
        type=1,indidff=0;
    } else if (cnt[2]>0) {
        type=2,indidff=-1;
    }
    while (cnt[type]>0) {
        ops.push_back(tind+indidff);
        cnt[type]--;
        tind-=3;
    }
    assert(cnt[0]==0);
    assert(cnt[1]==0);
    assert(cnt[2]==0);
    cout << ops.size() << "\n";
    for(int i=0;i<ops.size();i++) {
        cout << ops[i]+1 << "\n";
    }
}



// 021 01, 021021021 01
signed main() {
    fast;
    int t = 10000;
    cin >> t;

    // std::random_device dev;
    // std::mt19937 rng(dev());
    // std::uniform_int_distribution<std::mt19937::result_type> dist6(1,3); // distribution in range [1, 6]
    // std::cout << dist6(rng) << std::endl;
    while(t--){
        int sz = 20;
        int n;
        cin >> n;
        string s="";
        cin >> s;
        // map<int,char>mp{{1,'L'},{2,'I'},{3,'T'}};
        // for(int i=0;i<sz;i++)
        //     s.push_back(mp[dist6(rng)]);
        // s="0121211122";
    	solve(s);
    }
    return 0;
}
