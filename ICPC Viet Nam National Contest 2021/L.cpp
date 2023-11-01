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

const int mx=3170;

void solve() {

    ll n, ans=0;
    cin >> n;
    vector<ll> a(n);
    for_(n) cin >> a[i];

    unordered_map<ll,ll> cnt;
    vector<ll> p;
    vector<bool> isp(mx,true);

    for(int i=2; i<mx; i++) {
        if(isp[i]) {
            p.pb(i);
            for(int j=2; j*i<mx; j++) isp[i*j]=false;
        }
    }

    for_(n) {
        ll ta=a[i], val=1;
        for(auto it: p) {
            if(ta%it==0) {
                val*=it;
                while(ta%it==0) ta/=it;
            }
            else if(it>ta) break;
        }
        if(ta>1) val*=ta;
        cnt[val]++;
    }

    for(auto it: cnt) ans+=it.se*(it.se-1)/2;
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
