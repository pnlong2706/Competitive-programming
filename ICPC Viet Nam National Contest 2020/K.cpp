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

ll area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return abs((x2-x1)(y3-y1)-(x3-x1)(y2-y1));
}

bool checkInside(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &x4, int &y4) {
    ll s0=area(x1,y1,x2,y2,x3,y3);
    ll s1=area(x1,y1,x2,y2,x4,y4);
    ll s2=area(x1,y1,x4,y4,x3,y3);
    ll s3=area(x4,y4,x2,y2,x3,y3);
    if(s0==0) return true;
    if(s1==0) return true;
    if(s2==0) return true;
    if(s3==0) return true;
    if(s1+s2+s3==s0) return true;
    if(s0+s2+s3==s1) return true;
    if(s1+s0+s3==s2) return true;
    if(s1+s2+s0==s3) return true;
    return false;
}


void solve() {
    int n;
    cin >> n;
    while(n!=0) {
        vector<pii> p;
        for_(n) {
            int x, y;
            cin >> x >> y;
            p.pb(mp(x,y));
        }

        ll ans=0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++ ) {
                    for(int v=k+1; v<n; v++) {
                        int x1=p[i].fi, y1=p[i].se;
                        int x2=p[j].fi, y2=p[j].se;
                        int x3=p[k].fi, y3=p[k].se;
                        int x4=p[v].fi, y4=p[v].se;

                        if(checkInside(x1,y1,x2,y2,x3,y3,x4,y4)) continue;
                        ans++;
                    }
                }
            }
        }
        cout << ans << el;
        cin >> n;
    }
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
