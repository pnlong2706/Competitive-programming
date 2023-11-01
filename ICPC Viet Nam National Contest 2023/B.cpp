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

int r, c;
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={-1,0,1,-1,1,-1,0,1};

void extend(int x, int y, vector<string> &s, vector<pii> &b, vector<vector<int>> &vis) {
    bool trig=false;
    for(int i=0; i<8; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if(nx<0 || nx>r+1 || ny<0 || ny>c+1 ) continue;
        if( s[nx][ny]=='#' && vis[nx][ny]==-1 ) {
            vis[nx][ny]=1;
            extend(nx,ny,s,b,vis);
        }
        if(s[nx][ny]=='.') trig=true;
    }
    if(trig) b.pb(mp(x,y));
}

void solve() {
    cin >> r >> c;
    while(r!=0 && c!=0) {
        vector<string> s(r+2, string(c+2,'#') );
        s[0][0]=s[0][1]=s[1][0]='@';
        s[r+1][c+1]=s[r][c+1]=s[r+1][c]='@';

        for(int i=1; i<=r; i++) {
            char ch;
            for(int j=1; j<=c; j++) {
                cin >> ch;
                s[i][j]=ch;
            }
        }

        int ans=0;
        vector<vector<int>> vis(r+2, vector<int>(c+2,-1) );
        vector<pii> b, exb;
        vis[0][2]=1;
        extend(0,2,s,b,vis);
        while(vis[2][0]==-1) {
            ans++;
            exb.clear();
            for(auto it: b) {
                int x=it.fi, y=it.se;
                for(int i=0; i<8; i++) {
                    int nx=x+dx[i], ny=y+dy[i];
                    if(nx<0 || nx>r+1 || ny<0 || ny>c+1 ) continue;
                    if(s[nx][ny]=='.') {
                        s[nx][ny]='#';
                        vis[nx][ny]=1;
                        exb.pb(mp(nx,ny));
                    }
                }
            }

            b.clear();
            for(auto it: exb) {
                extend(it.fi,it.se,s,b,vis);
            }
            if(b.empty() && vis[2][0]==-1) {
                ans=-1;
                break;
            }
        }
        cout << ans << el;
        cin >> r >> c;
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

