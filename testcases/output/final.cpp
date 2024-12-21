#include <bits/stdc++.h> 
using namespace std; 
 
int countSetBits(int num) { 
	return __builtin_popcount(num); // built-in function for counting set bits 
} 
 
// Custom comparator function for stable sorting 
bool comparator(const int& a, const int& b) { 
	int setBitsA = countSetBits(a); 
	int setBitsB = countSetBits(b); 
	// sort by descending order of set bits 
	// if set bits are the same, maintain relative order (stable sort) 
	return setBitsA > setBitsB; 
} 
 
vector<int> sortBySetBits(vector<int>& nums) { 
	stable_sort(nums.begin(), nums.end(), comparator); 
	return nums; 
} 
 
int main() { 
	int n; 
	cin >> n; 
	vector<int> nums(n); 
	for (int i = 0; i < n; i++) { 
    	cin >> nums[i]; 
	} 
 
	nums = sortBySetBits(nums); 
 
	for (int num : nums) { 
    	cout << num << " "; 
	} 
	cout << endl; 
} 