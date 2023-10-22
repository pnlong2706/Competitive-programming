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

bool chall=false;

bool check(int n, int m, int k, int V, vector<string> &s) {
    int num=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(s[i][j]=='#' || s[i][j]=='.' ) continue;
            if(s[i][j]=='x') {
                num++;
                //cout << "xx " << i << " " << j << endl;
                int ti=j;
                for(int kt=ti; kt<=2*V+ti; kt++) {
                    j=kt;
                    //cout << "pp " << i << el;
                    if( kt>=m || s[i][kt]=='#') {  break; }
                }
            }
        }
    }
   // cout << "* " << num << " " << k << el;
    if(num<=k) { chall=true; return true; }
    else return false;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    for(int i=0; i<n; i++) cin >> s[i];

    int lo=0, hi=m;
    int mid=(lo+hi)/2;

    while(lo<hi) {
        //cout << "** " << mid << endl;
        if(check(n,m,k,mid,s)) hi=mid;
        else lo=mid+1;
        mid=(lo+hi)/2;
    }

    if(chall) cout << lo << el;
    else cout << "-1\n";

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

