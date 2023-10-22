#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	string test[] = {"Welcome", "Hue", "University", "of", "Sciences"};
	vector<int> arr(5);
	while (cin >> s)
	{
		for (int i = 0; i<5; ++i)
		{
			if (test[i]==s)
			{
				arr[i] = 1;
			}
		}
	}
	for (int i = 0; i<5; ++i)
	{
		if (arr[i]==0)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
    return 0;
}

