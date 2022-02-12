#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int g_k;

bool compare(int a, int b)
{
	int r = a % g_k;
	int s = b % g_k;
	if (r == s)
	{
		if (a % 2 != 0 && b % 2 != 0)
			return a > b;
		else if (a % 2 == 0 && b % 2 == 0)
			return a < b;
		
		else
			return (a % 2 != 0);
	}
	else
		return r < s;
}


int main()
{
	int N, n, i;
	vector<int> t;

	while (scanf("%d %d", &N, &g_k), N + g_k > 0)
	{
		for(i = 0; i < N; i++)
		{
			scanf("%d", &n);
			t.push_back(n);
		}
		sort(t.begin(), t.end(), compare);
		printf("%d %d\n", N, g_k);
		for (i = 0; i < N; i++)
			printf("%d\n", t[i]);
		t.clear();
	}
	printf("%d %d\n", 0, 0);
	return 0;
}
