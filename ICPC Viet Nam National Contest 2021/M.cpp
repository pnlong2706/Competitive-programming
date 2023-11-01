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
    int n;
    cin >> n;
    cout << n*(n-1)+1 << el;
    for(int i=2; i<=n*(n-1)+1; i+=n-1) {
        cout << "1";
        for(int j=i; j<i+n-1; j++) cout << " " << j;
        cout << el;
    }

    vector<int> ar(n-1);
    vector<int> add(n-1,0);
    for_(n-1) ar[i]=i+1;
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=n-1; j++) {
            cout << i;
            for(int k=1; k<=n-1; k++) {
                cout << " " << k*(n-1)+1+(j+add[k-1]-1)%(n-1)+1;
            }
            cout << el;
        }
        for(int k=1; k<=n-1; k++) add[k-1]=(add[k-1]+k-1)%(n-1);
    }

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
