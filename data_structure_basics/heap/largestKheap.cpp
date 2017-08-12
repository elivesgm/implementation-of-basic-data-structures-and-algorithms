#include <iostream>
#include <vector>

using namespace std;

#define LEN 10

void percolateDown(vector<int>&hp, int hole)
{
	int size = hp.size();
	for (; 2*hole < size;){
		int child = 2*hole;
		int tmp = hp[hole];
		if (child < size - 1 && hp[child] < hp[child + 1]) ++child;
		if (hp[child] > hp[hole]) {
			hp[hole] = hp[child];
			hole = child;
			hp[hole] = tmp;
		}
		else break;
	}

}

void makeHeap(vector<int>&hp)
{
	for (int i = (hp.size() - 1)/2; i >=1; --i)
		percolateDown(hp, i);
}

int getSmallestK(vector<int>&nums, int k) {
	int size = nums.size();
	if (size < k) return -1;

	vector<int> hp(k + 1, 0);
	for (int i = 0; i < size; ++i) {
		if (i < k -1) hp[i + 1] = nums[i];
		else if (i == k - 1) {
			hp[i+1] = nums[i];
			makeHeap(hp);
		}
		else {
			if (nums[i] < hp[1]) {
				hp[1] = nums[i];
				percolateDown(hp, 1);
			}
		}
	}
	return hp[1];
}

int main()
{
	int k = 3;
	int arr[LEN] = {4,6,2,1,7,3,9,5,8,0};
	vector<int>nums(arr, arr + LEN);
	for(vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) 
		cout << *itr << " ";
	cout << endl;

	cout << "Result: " << getSmallestK(nums, k) << endl;
	return 0;
}