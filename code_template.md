# 1.递归法解决子集枚举的代码框架

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
