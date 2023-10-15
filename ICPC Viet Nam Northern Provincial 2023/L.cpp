#include <bits/stdc++.h>
#define MOD 1000000007
#define FOR(i, n) for (int i = 0; i < n; ++i)

#ifdef cbaaabc
#define deb(x) cerr << "[DEBUG] "<< #x << '=' << x << endl
#else
#define deb(x) 0
#endif

using namespace std;

template<class T> ostream& operator<<(ostream& os, const vector<T> &a)
{
    for(const auto &x: a) os << x << ' ';
    return os;
}

typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
vector<int> phi(5e6 + 10);
void phi_1_to_n(int n) {
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    for (ll i = 1; i<=b; ++i)
    {
        ll d = __gcd(a, i);
        ans += (ll)phi[a] * (ll)phi[i] / phi[d] * d;
        ans %= 998244353;
    }
    cout << ans << endl;
    return;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    phi_1_to_n(5e6+5);
    solve();
    return 0;
}

