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



void solve() {
    int c;
    cin >> c;
    vector<int> st(10);
    for__(1,10) cin >> st[i];

    cout << "YES\n";
    vector<string> ans;
    if(st[8]!=st[6]) {
        int t=(st[6]-st[8]+c)%c;
        ans.pb("0 0 1 0 7 " + to_string(t) );
        st[4]=(st[4]+t)%c;
        st[5]=(st[5]+t)%c;
        st[7]=(st[7]+t)%c;
        st[8]=(st[8]+t)%c;
    }
    if(st[5]!=st[6]) {
        int t=(st[6]-st[5]+c)%c;
        ans.pb("1 0 0 0 1 " + to_string(t) );
        st[1]=(st[1]+t)%c;
        st[2]=(st[2]+t)%c;
        st[4]=(st[4]+t)%c;
        st[5]=(st[5]+t)%c;
    }
    if(st[5]!=st[2]) {
        int t=(st[2]-st[5]+c)%c;
        ans.pb("0 0 1 1 7 " + to_string(t) );
        st[4]=(st[4]+t)%c;
        st[5]=(st[5]+t)%c;
        st[6]=(st[6]+t)%c;
        st[7]=(st[7]+t)%c;
        st[8]=(st[8]+t)%c;
        st[9]=(st[9]+t)%c;
    }
    if(st[5]!=st[4]) {
        int t=(st[4]-st[5]+c)%c;
        ans.pb("0 1 0 1 3 " + to_string(t) );
        st[2]=(st[2]+t)%c;
        st[3]=(st[3]+t)%c;
        st[5]=(st[5]+t)%c;
        st[6]=(st[6]+t)%c;
        st[8]=(st[8]+t)%c;
        st[9]=(st[9]+t)%c;
    }
    if(st[1]!=st[5]) ans.pb("0 0 0 0 1 " +to_string( (st[5]-st[1]+c)%c) );
    if(st[3]!=st[5]) ans.pb("0 0 0 0 3 " +to_string( (st[5]-st[3]+c)%c) );
    if(st[7]!=st[5]) ans.pb("0 0 0 0 7 " +to_string( (st[5]-st[7]+c)%c) );
    if(st[9]!=st[5]) ans.pb("0 0 0 0 9 " +to_string( (st[5]-st[9]+c)%c) );
    if(st[5]!=0) ans.pb("1 1 1 1 1 "+ to_string(  (0-st[5]+c)%c ) );

    cout << ans.size() << el;
    for(auto it: ans) cout << it << el;


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
