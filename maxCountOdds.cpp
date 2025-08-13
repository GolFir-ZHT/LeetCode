/*
 * 算法题：对于一个正整数数组，找出能够使得所选元素乘积为奇数的最大元素个数
 * 有点想复杂了，乘积为奇数的情况是其各个成分都是奇数，所以，只要统计数组里奇数的个数即可
 * 本题实质上是数学题
 */
#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    int res = 0;
    
    for(int i = 0; i < n; ++i){
        if(nums[i] % 2) ++res;
    }
    
    cout << "The max count of odds: " << (res < 2 ? -1 : res) << endl;

    return 0;
}