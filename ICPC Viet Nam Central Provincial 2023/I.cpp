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

const long long MOD=3000000007;

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

int timer=1;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

stack<pair<pii,pii>> S;
ll rans=0;

void dfs( vector<string> &s, vector<vector<bool>> &vis, vector<vector<ll>> &low, vector<vector<ll>> &num, int nx, int ny, int px, int py, int n, int m ) {
    vis[nx][ny]=true;
    num[nx][ny]=low[nx][ny]=timer++;
    int child=0;

    for(int i=0; i<4; i++) {
        int vx=dx[i]+nx, vy=dy[i]+ny;

        if( !(vx>=0 && vx<=n-1 && vy>=0 && vy<=m-1) ) continue;
        if( s[vx][vy]!='.' ) continue;
        if( vx==px && vy==py ) continue;

        if( vis[vx][vy] ) {
            low[nx][ny]=min( low[nx][ny], num[vx][vy] );
            if(num[vx][vy] < num[nx][ny] ) S.push(mp( mp(nx,ny),mp(vx,vy) ));
        }
        else {

            S.push(mp( mp(nx,ny),mp(vx,vy) ));

            dfs(s,vis,low,num,vx,vy,nx,ny,n,m);
            child++;

            low[nx][ny]= min( low[nx][ny], low[vx][vy] );

            if( (nx==px && ny==py && child>1) || ((nx!=px || ny!=py) && low[vx][vy] >= num[nx][ny]) ) {
                set<pii> st;
                while( S.top().fi!=mp(nx,ny) || S.top().se!=mp(vx,vy) ) {
                    st.insert(S.top().fi);
                    st.insert(S.top().se);
                    S.pop();
                }
                st.insert(S.top().fi);
                st.insert(S.top().se);
                S.pop();
                ll cnt=st.size();
                rans+=cnt*(cnt-1)/2;
            }
        }
    }
}


void solve() {
    int n, m;
    ll ttdot=0;
    cin >> n >> m;
    vector<string> s(n);
    for_(n) cin >> s[i];

    vector<vector<bool>> vis(n+1, vector<bool> (m+1,false) );
    vector<vector<ll>> low(n+1, vector<ll> (m+1,0)), num(n+1, vector<ll> (m+1,0));

    for(int x=0; x<n; x++) {
        for(int y=0; y<m; y++) {
            if( s[x][y]=='.' ) ttdot++;
            if( s[x][y]=='.' && !vis[x][y] ) {
                dfs(s,vis,low,num,x,y,x,y,n,m);
                set<pii> st;
                while(!S.empty()) {
                    st.insert(S.top().fi);
                    st.insert(S.top().se);
                    S.pop();
                }
                ll cnt=st.size();
                rans+=cnt*(cnt-1)/2;
            }
        }
    }

    cout << ttdot*(ttdot-1) - rans*2 << el;

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
