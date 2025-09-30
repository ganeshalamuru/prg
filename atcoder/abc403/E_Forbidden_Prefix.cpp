#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


struct TrieNode{
    int end = 0;
    int pcnt = 0;
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
};

void insert(string s, TrieNode* head) {
    TrieNode* curnode = head;
    for(int i=0;i<s.size();i++) {
        int nind = s[i]-'a';
        if (curnode->children[nind]==nullptr) {
            curnode->children[nind]=new TrieNode{0,0};
        }
        curnode->children[nind]->pcnt++;
        curnode=curnode->children[nind];    
    }
    curnode->end++;
}

int deleteAllStringsWithPrefix(string s, TrieNode* head) {
    TrieNode* curnode = head;
    for(int i=0;i<s.size();i++) {
        int nind = s[i]-'a';
        if (curnode->children[nind]==nullptr || curnode->children[nind]->pcnt==0) {
            return 0;
        }
        curnode=curnode->children[nind];
    }
    int num = curnode->pcnt;
    TrieNode* trav=head;
    for(int i=0;i<s.size();i++) {
        int nind = s[i]-'a';
        trav->children[nind]->pcnt-=num;
        trav=trav->children[nind];
    }
    function<void(TrieNode*)> del=[&](TrieNode* node) {
        for(int i=0;i<26;i++) {
            if (node->children[i]==nullptr || node->children[i]->pcnt==0) {
                continue;
            }
            del(node->children[i]);
        }
        node->end=0;
        node->pcnt=0;
    };
    del(curnode);
    return num;
}


bool isPrefixOfStringPresent(string s, TrieNode* head) {
    TrieNode* curnode = head;
    for(int i=0;i<s.size();i++) {
        int nind = s[i]-'a';
        if (curnode->children[nind]==nullptr) {
            return false;
        } else if (curnode->children[nind]->end>0) {
            return true;
        }
        curnode=curnode->children[nind];
    }
    return false;
}





void solve() {
	int q;
    cin >> q;
    TrieNode* headx = new TrieNode{0,0};
    TrieNode* heady = new TrieNode{0,0};
    int ans = 0;
    while(q--) {
        int t;
        string s;
        cin >> t >> s;
        if (t==1) {
            ans-=deleteAllStringsWithPrefix(s,heady);
            insert(s,headx);
        } else {
            if (!isPrefixOfStringPresent(s,headx)) {
                ans++;
                insert(s,heady);
            }
        }
        cout << ans << "\n";
    }


}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
