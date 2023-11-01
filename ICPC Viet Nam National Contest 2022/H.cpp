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
ostream& operator<<(ostream& os, const set<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
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

vector<vector<ll>> mul_mod(const vector<vector<ll>> &a,const vector<vector<ll>> &b, ll mod) {
    int r1=a.size(), c1=a[0].size(), r2=b.size(), c2=b[0].size();
    vector<vector<ll>> res(r1, vector<ll> (c2,0) );
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            for(int k=0; k<c1; k++) { res[i][j]+=a[i][k]*b[k][j]%mod; res[i][j]%=mod; }
        }
    }
    return res;
}

vector<vector<ll>> pow_mod(vector<vector<ll>> a, ll k, ll mod) {
    int r=a.size();
    vector<vector<ll>> res(r, vector<ll> (r,0) );
    for(int i=0; i<r; i++) res[i][i]=1;
    while(k>0) {
        if(k%2==1) res=mul_mod(res,a,mod);
        a=mul_mod(a,a,mod);
        k=(k>>1);
    }
    return res;
}

int main() {
    //clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INP.inp","r",stdin);

    vector<vector<ll>> m({
        {1,1,1,0,0,0},
        {2,0,0,0,0,0},
        {2,1,0,0,0,0},
        {0,0,0,1,1,1},
        {6,0,0,2,0,0},
        {6,3,0,2,1,0}  });
    vector<vector<ll>> ini(6, vector<ll>(1)), ans(6, vector<ll>(1));
    ini[0][0]=1;
    ini[1][0]=2;
    ini[2][0]=2;
    ini[3][0]=0;
    ini[4][0]=6;
    ini[5][0]=6;

    ll n;
    cin >> n;
    ans=mul_mod(pow_mod(m,n-2,MOD),ini,MOD);
    cout << (ans[3][0]+ans[4][0]+ans[5][0])%MOD;


    //cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}
