#include <bits/stdc++.h>
using namespace std;

long long distinctInSubarrays(vector<int> &nums, int k)
{
	unordered_map<int, int> freq;
	long long result = 0;
	int distinctCount = 0;

	for (int i = 0; i < k; i++)
	{
		if (++freq[nums[i]] == 1)
		{
			distinctCount++;
		}
	}
	result += distinctCount;

	for (int i = k; i < nums.size(); i++)
	{
		// remove the element going out of the window
		if (--freq[nums[i - k]] == 0)
		{
			distinctCount--;
		}
		// add the new element to the window
		if (++freq[nums[i]] == 1)
		{
			distinctCount++;
		}
		result += distinctCount;
	}

	return result;
}

int main()
{
	
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}

		cout << distinctInSubarrays(nums, k) << endl;
	
}
