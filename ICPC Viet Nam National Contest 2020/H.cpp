#include <bits/stdc++.h>

using namespace std;

#define ll          long long
#define ull         unsigned long long
#define for_(n)     for(ll i=0; i<n; i++)
#define for__(a,b)  for(ll i=a; i<b; i++)
#define _for(i,a,b) for(ll i=a; i<b; i++)
#define mp          make_pair
#define fi          first
#define se          second
#define pb          push_back
#define pii         pair<int, int>
#define pll         pair<long long, long long>
#define el          "\n"
#define debug(x)    cerr << "[debug] " << #x << " : " << x << endl;

const long long MOD=1000000007;

template<class T, class P>
ostream& operator<<(ostream& os, const pair<T,P> &a) { os << "{" << a.first << ";" << a.second << "}"; return os; }
template<class T>
ostream& operator<<(ostream& os, const vector<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
template<class T>
ostream& operator<<(ostream& os, const deque<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
template<class T>
ostream& operator<<(ostream& os, const set<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
template<class T>
ostream& operator<<(ostream& os, const multiset<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }

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
    ll n, d;
    ll bs=1000000;
    cin >> n;
    vector<ll> len(n);
    for_(n) cin >> len[i];
    cin >> d;
    vector<string> s(d);
    for_(d) cin >> s[i];

    unordered_map<ll,ll> cnt;

    for_(d) {
        cnt[((ll)s[i][0])*bs+(ll)s[i].length()]++;
    }

    ll ans=0;
    for_(d) {
        if(s[i].length()!=n) continue;
        vector<ll> rm;
        rm.pb( ((ll)s[i][0])*bs+(ll)s[i].length() );
        cnt[((ll)s[i][0])*bs+(ll)s[i].length()]--;

        ll ta=1;
        for(int j=0; j<s[i].length(); j++) {
            ta=ta%MOD*cnt[((ll)s[i][j])*bs+(ll)len[j]]%MOD;
            cnt[((ll)s[i][j])*bs+(ll)len[j]]--;
            rm.pb(((ll)s[i][j])*bs+(ll)len[j]);
        }

        for(auto it: rm) {
            cnt[it]++;
        }

        ans+=ta;
        ans%=MOD;
    }

    cout << ans << el;


}


int main() {
    //clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INP.inp","r",stdin);
    //freopen( "OUT.out", "w", stdout );
    int t=1;
    cin >> t;
    while(t--)
        solve();

    //cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";

    return 0;
}
