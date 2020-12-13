#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int callRecur(vector<vector<int>> &dp, vector<vector<int>> &countVal, int neglect, int n, int N)
{
	if (n >= N)
	{
		return 0;
	}
	if (neglect != -1)
	{
		switch (neglect)
		{
		case 0:
			if (dp[n][1] != -1 && dp[n][2] != -1)
				return max(dp[n][1], dp[n][2]);
			break;
		case 1:
			if (dp[n][0] != -1 && dp[n][2] != -1)
				return max(dp[n][0], dp[n][2]);
			break;
		case 2:
			if (dp[n][1] != -1 && dp[n][0] != -1)
				return max(dp[n][1], dp[n][0]);
			break;
		}
	}

	switch (neglect)
	{
	case 0:
		dp[n][1] = countVal[n][1] + callRecur(dp, countVal, 1, n + 1, N);
		dp[n][2] = countVal[n][2] + callRecur(dp, countVal, 2, n + 1, N);
		return max(dp[n][1], dp[n][2]);
	case 1:
		dp[n][0] = countVal[n][0] + callRecur(dp, countVal, 0, n + 1, N);
		dp[n][2] = countVal[n][2] + callRecur(dp, countVal, 2, n + 1, N);
		return max(dp[n][0], dp[n][2]);
	case 2:
		dp[n][0] = countVal[n][0] + callRecur(dp, countVal, 0, n + 1, N);
		dp[n][1] = countVal[n][1] + callRecur(dp, countVal, 1, n + 1, N);
		return max(dp[n][0], dp[n][1]);
	default:
		return max({countVal[n][0] + callRecur(dp, countVal, 0, n + 1, N), countVal[n][1] + callRecur(dp, countVal, 1, n + 1, N), countVal[n][2] + callRecur(dp, countVal, 2, n + 1, N)});
	}
}
int main()
{
	vector<vector<int>> countVal;
	int N;
	cin >> N;
	vector<vector<int>> dp(N, vector<int>(3, -1));
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		countVal.push_back({a, b, c});
	}
	cout << callRecur(dp, countVal, -1, 0, N);
	return 0;
}