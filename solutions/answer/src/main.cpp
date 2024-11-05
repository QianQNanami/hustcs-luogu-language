#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> v;

    for (int i = 0; i < n; ++i) {
        int a = read();
		//char t = getchar(); // x
		int b = read();
		//t = getchar(); // =
		int c = read();
        int x = (c - b) / a;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
	//for(auto i : v) cout << i << ' ';

    for (int i = 0; i < q; ++i) {
        int l = read(), r = read();
        auto left = lower_bound(v.begin(), v.end(), l);
        auto right = upper_bound(v.begin(), v.end(), r);
        cout << distance(left, right) << '\n';
    }

    return 0;
}
