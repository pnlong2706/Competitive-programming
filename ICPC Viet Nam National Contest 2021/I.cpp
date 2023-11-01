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
#define FOR(i,a,b)  for(int i=a; i<=b; i++)

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

const int MX=1048576;
ll dp[16][16][16][16][16][51];



void solve() {
    int n;
    ll ans=0;
    cin >> n;
    vector<vector<int>> ar(n,vector<int> (5,0));
    map<string,int> id;
    id["dp"]=0;
    id["graph"]=1;
    id["mathgeo"]=2;
    id["ds"]=3;
    id["adhoc"]=4;

    for_(n) {
        int v;
        string s;
        cin >> v;
        while(v--) {
            cin >> s;
            ar[i][id[s]]=1;
        }
    }

    //for(auto it: ar) cout << it << el;



    vector<vector<int>> rg(5, vector<int> (2) );
    for_(5) cin >> rg[i][0] >> rg[i][1];


    dp[0][0][0][0][0][0]=1;
    for_(n) {
        FOR(a,0,15) FOR(b,0,15) FOR(c,0,15) FOR(d,0,15) FOR(e,0,15) {
            dp[a][b][c][d][e][i+1]=dp[a][b][c][d][e][i];
            if( a>=ar[i][0] && b>=ar[i][1] && c>=ar[i][2] && d>=ar[i][3] && e>=ar[i][4] ) {
                dp[a][b][c][d][e][i+1]+=dp[a-ar[i][0]][b-ar[i][1]][c-ar[i][2]][d-ar[i][3]][e-ar[i][4]][i];
            }
        }
    }


    FOR(i1,rg[0][0],rg[0][1]) FOR(i2,rg[1][0],rg[1][1]) FOR(i3,rg[2][0],rg[2][1]) FOR(i4,rg[3][0],rg[3][1]) FOR(i5,rg[4][0],rg[4][1]) {
        ans+=dp[i1][i2][i3][i4][i5][n];
    }
    
    if( rg[0][0]==0 && rg[1][0]==0 && rg[2][0]==0 && rg[3][0]==0 && rg[4][0]==0  ) ans--;

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
