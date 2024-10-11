// 力扣70题爬楼梯扩展：不能爬到7以及7的倍数
// 问题描述：这是一个扩展版的爬楼梯问题：
// 从第1级台阶开始，每次可以选择爬1级或2级，但是你不能爬到7或7的倍数（例如7、14、21等）。
// 求在这种约束下，有多少种不同的方式可以爬到第 n 级台阶。

#include<iostream>
#include<vector>
using namespace std;

int climbStairs(int n){
    // 解决的方法是分段处理递推公式：
    // 分为7以及7的倍数和另外台阶数两种情况
    if(n <= 1) return 1;
    vector<int> dp(n + 1, 1);

    for(int i = 2; i <= n; ++i){
        if(i % 7 == 0){
            dp[i] = 0;
        }else{
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }

    return dp[n];
}

int main(){
    int n;
    cout << "请输入台阶数：" << endl;
    cin >> n;
    int res = climbStairs(n);
    cout << "结果是：" << res << endl;
    return 0;
}