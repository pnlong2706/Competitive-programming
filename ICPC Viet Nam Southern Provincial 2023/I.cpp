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

int a[5000];
int dp[5001][5001];

void solve() {
    int n;
    cin >> n;
    for_(n) cin >> a[i];
    sort(a,a+n);

    int sum = 5001;
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (a[i - 1] > j) dp[i][j] = dp[i - 1][j]%MOD;
            else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - a[i - 1]])%MOD;
        }
    }

    ll ans=0;
    for(int i=2; i<n; i++) {
         ll val=0;
         for(int j=1; j<=a[i]; j++) {
            val+=dp[i][j];
            val%=MOD;
         }
         ans+= pow_mod(2,i,MOD)-1-val%MOD+MOD;
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
    //cin >> t;
    while(t--)
        solve();
    //cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}
