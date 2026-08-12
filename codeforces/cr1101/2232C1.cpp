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

void solve2(int n,int x,int s,string str) {
    set<pii> introvertss,ambivertss;
    int numocc = 0;
    for(int i=0;i<n;i++) {
        char ch = str[i];
        if (ch=='I') {
            if (int(introvertss.size())+int(ambivertss.size())<x) {
                introvertss.insert({1,i});
                numocc++;
            } else if (ambivertss.size()>0 && (ambivertss.begin()->F)<s){
                auto [numpeeps,ind] = *ambivertss.begin();
                if ((x-1)*s-numocc>=0) {
                    ambivertss.erase(ambivertss.begin());
                    while (numpeeps>0 && introvertss.size()>0 && (introvertss.begin()->F)<s && (introvertss.begin()->S<ind)) {
                        auto [pp,ind1]=*introvertss.begin();
                        introvertss.erase(introvertss.begin());
                        introvertss.insert({pp+1,ind1});
                        numpeeps--;
                    }
                    while (numpeeps>0 && ambivertss.size()>0 && (ambivertss.begin()->F)<s && (ambivertss.begin()->S<ind)) {
                        auto [pp,ind1]=*ambivertss.begin();
                        ambivertss.erase(ambivertss.begin());
                        ambivertss.insert({pp+1,ind1});
                        numpeeps--;
                    }
                    if (numpeeps>0) {
                        ambivertss.insert({numpeeps,ind});
                    } else {
                        introvertss.insert({1,i});
                        numocc++;                    
                    }
                }
            }
        } else if (str[i]=='A' && int(introvertss.size())+int(ambivertss.size())<x) {
            ambivertss.insert({1,i});
            numocc++;
        } else {
            if (introvertss.size()>0 && (introvertss.begin()->F)<s) {
                    auto [numpeeps,ind]=*introvertss.begin();
                    introvertss.erase(introvertss.begin());
                    introvertss.insert({numpeeps+1,ind});
                    numocc++;
            } else if (ambivertss.size()>0 && (ambivertss.begin()->F)<s) {
                    auto [numpeeps,ind]=*ambivertss.begin();
                    ambivertss.erase(ambivertss.begin());
                    ambivertss.insert({numpeeps+1,ind});
                    numocc++;
            }
        }
    }
    cout << "greedy: " <<numocc << "\n";
}



void solve(	int n,int x,int s,string str) {
    vector<vector<int>> dp(n,vector<int>(x+1,INT_MIN));
    for(int i=0;i<n;i++)
        dp[i][0]=0;
    if (str[0]=='A' || str[0]=='I')
        dp[0][1]=1;
    for(int i=1;i<n;i++) {
        for(int j=0;j<=x;j++)
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        if (str[i]=='I') {
            for(int j=0;j<x;j++) {
                if (dp[i-1][j]!=INT_MIN)
                    dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+1);
            }
        } else if (str[i]=='E') {
            for(int j=1;j<=x;j++) {
                if (dp[i-1][j]!=INT_MIN && j*s-dp[i-1][j]>0) {
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
                }
            }
        } else {
            for(int j=0;j<=x;j++) {
                if (dp[i-1][j]!=INT_MIN && j<x) {
                    dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+1);
                }
                if (j>0) {
                    if (dp[i-1][j]!=INT_MIN && j*s-dp[i-1][j]>0) {
                        dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
                    }
                }
            }
        }
    }
    int ans = INT_MIN;
    for(int j=0;j<=x;j++) {
        ans = max(ans, dp[n-1][j]);
    }
    cout << "dp: " <<ans << " ";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    // 11 3 3
    //EAEEEAIAEEI
    //
    while(t--) {
        int n=11,s=3,x=3;
        cin >> n >> x >> s;
        string str;
        cin >> str;
        cout << str << "\n";
    	solve(n,x,s,str);
        solve2(n,x,s,str);
    }
    
    return 0;
}
