#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i=0;i<n;i++) cin>>a[i];
	int maxx = INT_MIN;
	int sum = 0;
	int sum2 = 0;
	int ans = 0;
	for (int i = 0; i<n; ++i)
	{
		if (sum<0)
		{
			sum = 0;
			sum2 = 0;
			maxx = INT_MIN;
		}
		sum += a[i];
		maxx = max(a[i], maxx);
		sum2 = sum - maxx;
		ans = max(ans, sum2);
	}
	cout << ans;
}

