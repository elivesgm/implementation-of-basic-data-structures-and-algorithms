#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>


using namespace std;


bool a_is_lexico_smaller_b(int a, int b) {
	char stra[33];
	char strb[33];
	itoa(a, stra, 10);
	itoa(b, strb, 10);
	return strcmp(stra,strb) < 0;
	//return a<b;
}

void quick_sort(vector<int>&nums, int start, int end) {
	if (start >= end) 
		return;
	int k = nums[start];
	int l = start, r = end;
	while (l < r) {
		while ( a_is_lexico_smaller_b(k, nums[r]) && l < r) --r;
		if (l < r) {nums[l] = nums[r];++l;}
		while ( !a_is_lexico_smaller_b(k, nums[l]) && l < r) ++l;
		if (l < r) {nums[r] = nums[l];--r;}
	}
	nums[l] = k;
	quick_sort(nums, start, l - 1);
	quick_sort(nums, l + 1, end);
}

void lexicographic_sort(vector<int>&nums) {
	quick_sort(nums, 0, nums.size() - 1);
}

int main()
{
	int arr[7] = {14, 1, 23, 11, 124, 32, 221};
	vector<int>nums(arr, arr+7);
	cout << "Original array: " << endl;
	for(vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) {
		cout << *itr << " ";
	} 
	cout << endl;

	lexicographic_sort(nums);

	cout << "Lexicographic sorted array: " << endl;
	for(vector<int>::iterator itr1 = nums.begin(); itr1 != nums.end(); itr1++) {
		cout << *itr1 << " ";
	} 
	cout << endl;

	return 0;
}