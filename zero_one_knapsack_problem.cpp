/**
 * @file        zero_one_knapsack_problem.cpp
 * @author      zhtgolfir
 * @date        2025-04-17
 * 
 * @brief       简单01背包问题的练习
 * 
 * @details     背包问题是动态规划的典型问题，而01背包是其中最基础的类型，
 *              它的实质是在填一张二维表格，表格的行随物品数而变化，表格的列
 *              随由这些物品所构成的体积容量而变化，这是从左上角到右下角逐渐
 *              递推的过程，是一种自底向上的方法，恰好与递归相反。
 * 
 * @copyright   (c) 2025 zhtgolfir. All rights reserved.
 */

#include<iostream>
#include<algorithm>
using namespace std;

int goods[31]; // 物品的体积
int dp[32][20005]; // 动态规划状态数组

int main(){
    int v, n; // 背包的容量和物品的个数
    cin >> v >> n;
    for(int i = 1; i <= n; ++i){
        cin >> goods[i];
    }

    // 状态转移过程，这是一个填二维表的过程，在此过程中，
    // 程序状态逐步更新
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= v; ++j){
            if(goods[i] <= j){
                // 能放得下goods[i]，再选择放不放这件物品
                dp[i][j] = max(dp[i - 1][j], goods[i] + dp[i - 1][j - goods[i]]);
            }else{
                // 放不下goods[i]
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << v - dp[n][v] << endl;

    return 0;
}