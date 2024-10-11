// 力扣239：滑动窗口最大值
// 通过这个题目来总结单调队列的基本用法
/*
 * for(int i = 0; i < n; ++i){
 *      while(!q.empty() && checkWindow(i, q.back())){
 *          q.pop_back();
 *      }
 *      q.push_back(i);
 *      while(!q.empty() && check(i, q.front())){
 *          q.pop_front();
 *      }
 *      // 输出或者将其加入答案中
 * }
*/

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    int n = nums.size();
    deque<int> q; // 单调队列可以是双端队列，双端队列的好处是可以两端都进行push或pop操作
    for(int i = 0; i < k; ++i){
        while(!q.empty() && nums[i] >= nums[q.front()]){
            // 尾部弹出
            q.pop_back();
        }
        q.push_back(i);
    }

    vector<int> ans = {nums[q.front()]};
    for(int i = k; i < n; ++i){
        while(!q.empty() && nums[i] >= nums[q.front()]){
            q.pop_back();
        }
        q.push_back(i);
        while(q.front() <= i - k){
            q.pop_front(); // 不在窗口内的队头元素弹出
        }
        ans.push_back(nums[q.front()]);
    }

    return ans;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for(const int& num: nums){
        cout << num << endl;
    }

    return 0;
}