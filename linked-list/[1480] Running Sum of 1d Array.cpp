#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int sum = 0;
    for (int i=1; i<nums.size(); i++)
    {
        sum = nums[i];
        nums[i] = nums[i-1] + sum;
    }
    return nums;
}
