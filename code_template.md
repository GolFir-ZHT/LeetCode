# 刷题过程的模板

## 1.递归法解决子集枚举的代码框架

求**子集问题**和求**组合问题**不一样，求组合问题是**收集叶子节点+剪枝**，而求子集问题是**收集所有节点**，所以不需要剪枝优化。==这里所说的叶子节点其实就是下述边界条件判定时的情况，组合问题答案的保存需要在边界条件里，而子集问题的答案保存是在之后的函数体内==。

```cpp {.line-numbers}
vector<int> t; // 临时存放子集的数组

// 深度优先搜索算法，优先深度，尽可能地deep
// curr是当前索引，n是nums中的元素个数
void dfs(const vector<int>& nums, int cur, int n) {
    if (cur == n) {
        // 到达边界，记录答案
        // ...
        return;
    }
    // 考虑选择当前位置
    t.push_back(nums[cur]);
    dfs(nums, cur + 1, n);
    t.pop_back();
    // 考虑不选择当前位置
    dfs(nums, cur + 1, n);
}
```

## 2.STL中求和、求最值的使用方法

```cpp
#include<iostream>
#include<algorithm> // STL中的算法需要引入该头文件，包含求最值函数 max_element和min_element
// #include<vector>
#include<bits/stdc++.h> // 新的知识点：之前使用一类容器一个头文件，而stdc++.h是一个头文件可以包含所有容器 
#include<numeric> // 包含求和函数accumulate
using namespace std;

int main(){
    vector<int> nums = {3, 1, 4, 1, 5, 9};

    // 求和，最后一个参数是初值，这种方法有点像是侯捷老师STL视频课所采用的方式
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // 求最大值
    int maxNum = *max_element(nums.begin(), nums.end());
    // 求最小值
    int minNum = *min_element(nums.begin(), nums.end());

    cout << sum << endl;
    cout << maxNum << endl;
    cout << minNum << endl;

    return 0;
}
```

面对一个算法题目时，解题四步骤：
1.**厘清题意，并作适当转换**，比如本题将划分问题变为求一个子集中所有元素加和为总和一半的操作；
2.**考虑实现方法**，常用方法有双指针、动态规划和滑动窗口等算法，这一步是问题解决的核心；
3.**考虑边界下的极端情况**，针对此情况可做适当剪枝；
4.**编码**，需要高效且直接，如何权衡是个难题，需要长期练习；

## 3.01背包问题的基础代码模板

```cpp
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

int goods[31]; // 物品的体积，这里体积就是价值value，有些题目可能将两者分为weights和values，要注意区分
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
```

## 4.关于C/C++中各种常用数据类型的数值范围

**bool**：32位和64位机器上都占1个字节，取值范围为 0/1；

**char**: 32位和64位机器上都占1个字节，取值范围为 -128~127；

**int/long**：32位和64位机器上都占4个字节，取值范围为 -2147483648~2147483647，大致为 $[-2\times 10^9,  2\times 10^9]$；

**long long**：32位和64位机器上都占8个字节，取值范围为 -9223372036854775808~ -9223372036854775807，大致为 $[-9\times 10^{18},  9\times 10^{18}]$；

**pointer**：32位机器上占4个字节，64位机器上占8个字节，因为指针与地址空间有关；

**float**：占4个字节，取值范围大致为 $[-3.4\times 10^{38},  3.4\times 10^{38}]$；

**double**：占8个字节，取值范围大致为 $[-1.7\times 10^{-308},  1.7\times 10^{308}]$；

**ASCII（American Standard Code for Information Interchange，美国信息互换标准代码）**：ASCII 编码于 1967 年第一次发布，最后一次更新是在 1986 年，迄今为止共收录了 128 个字符，包含了基本的拉丁字母（英文字母）、阿拉伯数字（1234567890）、标点符号（,.!等）、特殊符号（@#$%^&等）以及一些具有控制功能的字符（往往不会显示出来）， 刷题过程中可以用 int[128] 来处理常用字符的判断；

注意：各个数据类型占多少字节数是由编译器决定的

## 5.算法常用知识总结

```cpp {.line-numbers}
#include <cctype> // 包含 std::tolower 函数
#include <iostream>
using namespace std;

// 判断字母是否相同（忽略大小写）
// tolower() 函数将字母转换为小写形式
char a, b;
if(tolower(a) == tolower(b)) {}

// 计算各位数的乘积：实质是分解各个数位上的数字
// 这里采用的顺序是从低位到高位
int num, product = 1;
while(num > 0){
    int digit = num % 10;
    product *= digit; // 求和的话，product->sum，sum += digit;
    num /= 10;
}

// 判断完全平方数
int root = sqrt(num);
if(root * root == num) {}

// 输入未知个数的整数
int x;
while(scanf("%d", &x) == 1) {}

// 求n,m的方格中有多少矩形
// 这里并不理解？
// 直接套用排列组合公式也是一种解法：n*(n+1)*m*(m+1)/4
int n, m;
cin >> n >> m;
int sqrs = 0;
int recs = 0;
for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
        if(i == j) sqrs += (n - i) * (m - j);
        else recs += (n - i) * (m - j); 
    }
}

// 计算网格中 (x1, y1) 到 (x2, y2) 之间的距离
// 这里的dist应该是距离的平方
int dist = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

// 输入未知字符个数的字符串
char c;
string s;
while(cin >> c){
    s.push_back(c);
}

// 字符串加减
int ans, t;
while(cin >> t) ans += t;

// 在n个数中，找出最长连续个数
vector<int> a(n);
int max = -200; // 初值取一个非常小的数
for(int i = 1; i < n; ++i){
    if(a[i] == a[i - 1] - 1) ++ans;
    else ans = 0;
    if(ans > max) max = ans;
}

// 求0-n中2出现的次数，2可以出现在各个数位上
for(int i = 0; i <= n; ++i){
    int tmp = i;
    while(tmp > 0){
        if(tmp % 10 == 2) ++ans;
        tmp /= 10;
    }
}

// 传染病：一个人每轮传染x人，问传染n轮后，一共传染了多少人
int ans = 1;
for(int i = 0; i < n; ++i){
    ans = ans + ans * x;
}

// 判断数组中元素有无重复
map<int, int> count;
bool isDuplicate = false;
for(int i = 0; i < n; ++i){
    count[a[i]]++;
    if(count[a[i]] > 1){
        isDuplicate = true;
        break;
    }
}

if(!has) {} // 没有重复的处理

// 栈逐个元素出栈的正确写法
stack<int> stk;
while(!stk.empty()){
    cout << stk.top() << endl; // 输出栈顶元素
    stk.pop(); // 出栈，必须加上，否则会陷入死循环
}
```
