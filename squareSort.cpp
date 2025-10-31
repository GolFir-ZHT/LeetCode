/*
 有序数组按平方值排序，要求空间复杂度 O(1)，时间复杂度 O(n)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> squareSort(vector<int>& nums){
    // 双指针，如果不使用数组 ans，该如何做？
    // 如果只是简单的交换，没办法做，因为交换的同时，会破坏 l,r 的递进关系
    // 问了 gemini，似乎也没有不使用 ans 的标准解决办法，而且一般是不会把答案数组计入空间复杂的
    int n = nums.size();
    int l = 0, r = n - 1;
    vector<int> ans;
    while(l <= r){
        if(abs(nums[l]) > abs(nums[r])){
            ans.emplace_back(nums[l]);
            ++l;
        }else{
            ans.emplace_back(nums[r]);
            --r;
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {-100, -99, -7, -5, 0, 0, 100};
    vector<int> ans;
    ans =  squareSort(nums);
    reverse(ans.begin(), ans.end());
    for(int a : ans){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}