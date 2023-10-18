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

const long long MOD=123456789;

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

/*
    *** Idea for this problem ****
    Assume that n<m => n<=16, look at this number, we may think about bit mask.
    We denote a binary number with '1' repesenting the black cell.
    Then we can preprocess to generate all suitable mask with legnth n ( e.g 1010010 is suitable, 1100000 isn't )
    We store all those numbers in inUse, the inUse size is not exceed 2600.

    Then with each mask in inUse, we can determine which cell in the next column is available
    e.g     col i:      01000100
            col i+1:    xxx_xxx_   -> 'x' is the cell that cann't be colored black because of the way we color column i-th.

    Turn this to binary number as well: 'x'->0,'_' -> 1 ( xxx_xxx_ -> 00010001 )
    Vector canUse take the mask in inUse and return the mask that let us know which cell is available, we call this mask_can_use

    With each mask_can_use, we check all elements in inUse, the toUse[ mask_can_use ] is a vector stores all elements M in inUse such as M is subset of mask_in_use
    ( it means we know all the ways to color cell with each mask_can_use )

    Now we will use dp with 3 states: dp[mask_can_use][i][k] = number of ways to color with availbe cells as mask_can_use in i-th column and k black cells need coloring left.
    To update dp[mask_can_use][i][k], we iretate all elements M inUse[mask_can_use] and for each M, dp[mask_can_use][i][k]+=dp[canUse[M]][i+1][k-numBIT(M)]

    max( mask_can_use * i * k ) ~ 5.10^6 - good enough

    Of course mask_can_use may have large value so we actually use dp[id_mask_can_use][i][k]

*/

vector<int> inUse;
vector<int> canUse(70000,-1), recu(70000,-1), cnB(70000,0);
vector<vector<int>> toUse(70000);
vector<vector<vector<int>>> dp;

void ini( int i, int n, int num ) {
    if(i==n) {
        for(int j=0; j<n; j++) if( ((num&(1<<j))!=0) && ( (num&(1<<(j+1)))!=0) ) return;
        inUse.pb(num);
        return;
    }
    ini(i+1,n,num+(1<<i));
    ini(i+1,n,num);
}

int cntBit(int num) {
    int res=0;
    while(num>0) {
        res+=(num%2==1);
        num/=2;
    }
    return res;
}

ll cnt( int cUse, int i, int k, int m ) {
    int id=recu[cUse];

    if(k>=0 && dp[id][i][k]!=-1) return dp[id][i][k];
    if(k==0) return dp[id][i][k]=1;
    if(i==m) return dp[id][i][k]=0;

    dp[id][i][k]=0;
    for(auto it: toUse[cUse] ) {
        if(k>=cnB[it]) dp[id][i][k]+=cnt( canUse[it], i+1, k-cnB[it], m );
        dp[id][i][k]%=MOD;
    }

    return dp[id][i][k];
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    if(n>m) swap(n,m);
    if(k>130) {
        cout << "0\n";
        return;
    }

    ini(0,n,0);

    int mask=(1<<n)-1;
    for(auto it: inUse) {
        int v=it;
        int free=0;

        for(int i=0; i<n; i++) {
            if(v&(1<<i)) {
                free |= (1<<i);
                if(i>0) free |= (1<<(i-1));
                if(i<n-1) free |= (1<<(i+1));
            }
        }

        free= free^mask;
        canUse[v]=free;
    }

    dp.assign( (int)inUse.size()+2, vector<vector<int>>( m+3, vector<int>(k+7,-1) ) );

    int ii=0;
    for(auto it: canUse) {
        if(it==-1) continue;
        int v=it;
        recu[v]=ii;
        ii++;
    }

    for(auto it: inUse) {
        int cUse=canUse[it];
        for(auto it2: inUse) if( (it2&cUse)==it2 ) toUse[cUse].pb(it2);
    }

    for(auto it: inUse) cnB[it]=cntBit(it);

    for(auto it: canUse) {
        if(it==-1) continue;

        if(toUse[it].size()==0) continue;
        sort(toUse[it].begin(),toUse[it].end());
        auto uit=unique( toUse[it].begin(),toUse[it].end());
        toUse[it].resize(distance(toUse[it].begin(),uit));
    }

    cout << cnt( canUse[0],0,k,m )%MOD;

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

