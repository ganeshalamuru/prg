#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n,k;
    cin >> n >> k;
    string str; 
    cin >> str;
    string ans=str;
    vector<pii> seqs;
    int i=0;
    while(i<n) {
        if (str[i]!='?') {
            i++;
            continue;
        }
        char prev = '#';
        if (i-1>=0)
            prev = str[i-1];
        int j=i,cnt=0;
        while(i<n && str[i]=='?')
            i++,cnt++;
        char after = '#';
        if(i<n)
            after = str[i];
        if (prev=='#') {
            if (after=='#' || after=='.') {
                seqs.push_back({j,cnt});
            } else if (after == 'o') {
                ans[j+cnt-1]='.';
                cnt--;
                if (cnt>0)
                    seqs.push_back({j,cnt});
            }
        } else if (prev=='.') {
            if (after=='.' || after == '#') {
                seqs.push_back({j,cnt});
            } else if (after =='o') {
                ans[j+cnt-1]='.';
                cnt--;
                if (cnt>0)
                    seqs.push_back({j,cnt});
            }
        } else {
            ans[j]='.';
            j++,cnt--;
            if (cnt > 0) {
                if (after=='.' || after=='#') {
                    seqs.push_back({j,cnt});
                } else if (after=='o') {
                    ans[j+cnt-1]='.';
                    cnt--;
                    if (cnt>0)
                        seqs.push_back({j,cnt});
                }
            }

        }

    }
    if (seqs.empty()) {
        cout << ans << "\n";
        return;
    }
    int zzcnt = 0;
    for(int i=0;i<n;i++)
        zzcnt+=ans[i]=='o';
    int m = seqs.size();
    int tseqzzpow = 0;
    for(int i=0;i<m;i++) {
        tseqzzpow+=seqs[i].S/2 + seqs[i].S%2;
    }
    for(int i=0;i<m;i++) {
        int remzz = k-zzcnt;
        if (remzz==0) {
            for(int z=seqs[i].F;z<seqs[i].F+seqs[i].S;z++)
                ans[z]='.';
            continue;
        }
        int curseqzzpow = seqs[i].S/2 + seqs[i].S%2;
        int remseqzzpow = tseqzzpow-curseqzzpow;
        if (remzz>remseqzzpow && seqs[i].S%2==1 && remzz-remseqzzpow==curseqzzpow) {
            for(int z=seqs[i].F,ind=0;z<seqs[i].F+seqs[i].S;z++,ind++) {
                if (ind%2==0)
                    ans[z]='o';
                else
                    ans[z]='.';
            }
        }
    }
    cout << ans << "\n";

}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
