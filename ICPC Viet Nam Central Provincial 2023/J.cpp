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
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> a(n), b(n);
    for_(n) cin >> a[i];
    for_(n) cin >> b[i];

    string s;
    cin >> s;

    string ss="x";
    for(int i=m-1; i>0; i--) {
        if(s.substr(0,i)==s.substr(m-i,i)) {
            ss=s.substr(i,m-i);
            break;
        }
    }
    if(ss=="x") ss=s;

    string ans="";
    ll valans=-1e18;
    for(int va=0; va<=n; va++) {
        ll vb=n-va, Cost=0;

        if(va==0) Cost=-b[vb-1];
        else if(vb==0) Cost=-a[va-1];
        else Cost=-b[vb-1]-a[va-1];

        string ta="";
        ll nr=va, nb=vb, i=0;

        ll sz=s.length(), szm=ss.length();
        for( i=0; i<s.length(); i++) {
            if(s[i]=='R' && nr>0) { ta+=s[i]; nr--; }
            else if(s[i]=='R' && nr==0) break;
            if(s[i]=='B' && nb>0) { ta+=s[i]; nb--; }
            else if(s[i]=='B' && nb==0) break;
        }

        if(i!=s.length()) goto endprocess;

        Cost+=d;
        for( ; i<n; i++ ) {
            if(ss[(i-sz)%szm]=='R' && nr>0) { ta+=ss[(i-sz)%szm]; nr--; }
            else if(ss[(i-sz)%szm]=='R' && nr==0) break;
            if( ss[(i-sz)%szm]=='B' && nb>0 ) { ta+=ss[(i-sz)%szm]; nb--; }
            else if(ss[(i-sz)%szm]=='B' && nb==0) break;
            if ((i-sz+1)%szm==0) Cost+=d;
        }

        endprocess:
        while(i<n) {
            if(nr>0) { ta+='R'; nr--; }
            else { ta+='B'; nb--; }
            i++;
        }
        if(Cost>valans) {
            valans=Cost;
            ans=ta;
        }
    }
    cout << valans << "\n" << ans << el;
}


int main() {
    //clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INP.inp","r",stdin);
    //freopen( "OUT.out", "w", stdout );
    int t=1;
    //cin >> t;
    while(t--)
        solve();
    //cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}

