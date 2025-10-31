// 经典动态规划问题：数塔问题
// 动态规划有四个步骤：
// 1.最小状态单元; dp[i][j]表示什么？
// 2.状态转移方程；dp[i][j]如何得到？
// 3.初始化边界；dp[n][j]为多少？
// 4.计算顺序；从上往下还是从下往上？
#include<iostream>
using namespace std;

int t[110][110];
int dp[110][110];
int n;

void d(){
    // 初始化 dp 数组
    for(int j = 1; j <= n; ++j){
        dp[n][j] = t[n][j];
    }

    for(int i = n - 1; i >= 1; --i){
        for(int j = 1; j <= i; ++j){
            dp[i][j] = t[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            cin >> t[i][j];
        }
    }
    d();
    cout << dp[1][1] << endl;

    return 0;
}