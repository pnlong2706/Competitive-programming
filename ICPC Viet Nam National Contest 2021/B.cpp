#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define ull         unsigned long long
#define for_(n)     for(int i=0; i<n; i++)
#define for__(a,b)  for(int i=a; i<b; i++)
#define mp          make_pair
#define fi          first
#define se          second
#define pb          push_back
#define pii         pair<int, int>
#define pll         pair<long long, long long>
#define el          "\n"

const long long MOD=998244353;


template<class T, class P>
ostream& operator<<(ostream& os, const pair<T,P> &a) { os << "{" << a.first << ";" << a.second << "}"; return os; }
template<class T>
ostream& operator<<(ostream& os, const vector<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
template<class T>
ostream& operator<<(ostream& os, const deque<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
template<class T>
ostream& operator<<(ostream& os, const multiset<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
struct lessSet { bool operator() (const long long &a, const long long &b) { return a>b;} };


ll gcd(ll a, ll b) { return b==0? a : gcd(b,a%b); }
ll lcm(ll a, ll b) { return a/(gcd(a,b))*b; }

ll pow_mod(ll x, ll y, ll mod) { //mod<3.10^9
    ll ans=1;
    while(y>0) {
        if(y%2==1) ans=ans*x%mod;
        y=y>>1;
        x=x*x%mod;
    }
    return ans%mod;
}

int mn(char a, char b) {
    if(a<b) swap(a,b);
    return min( a-b, b+26-a );
}

void solve() {
    int lr, lc, ans=0;
    cin >> lr >> lc;
    vector<string> s(lr);
    for_(lr) cin >> s[i];

    for(int i=0; i<lr/2; i++) {
        for(int j=0; j<lc/2; j++) {

            char a=s[i][j];
            char b=s[lr-i-1][j];
            char c=s[lr-i-1][lc-j-1];
            char d=s[i][lc-j-1];

            int ta=INT_MAX;
            ta=min(ta, mn(a,b)+mn(a,c)+mn(a,d) );
            ta=min(ta, mn(b,a)+mn(b,c)+mn(b,d) );
            ta=min(ta, mn(c,a)+mn(c,b)+mn(c,d) );
            ta=min(ta, mn(d,a)+mn(d,b)+mn(d,c) );
            ans+=ta;

        }
    }

    if(lr%2==1) {
        int id=lr/2;
        for(int j=0; j<lc/2; j++) {
            char a=s[id][j];
            char b=s[id][lc-j-1];

            int ta=mn(a,b);
            ans+=ta;
        }
    }

    if(lc%2==1) {
        int id=lc/2;
        for(int i=0; i<lr/2; i++) {
            char a=s[i][id];
            char b=s[lr-i-1][id];

            int ta=mn(a,b);
            ans+=ta;
        }
    }

    cout << ans << el;


}

int main() {
    //clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INP.inp","r",stdin);
    //int t;
    //cin >> t;
    //while(t--)
        solve();

    //cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}
