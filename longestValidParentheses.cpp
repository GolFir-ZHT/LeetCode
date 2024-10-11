#include<iostream>
using namespace std;

// 力扣32：最长有效括号
// 做算法题最重要的是思考这个问题的核心是什么？解决它又存在哪些难点？
// 思考的过程有时比最后的答案更重要，为什么这么说呢？
// 因为我们做题并不是为了解决这道题，而是为了新问题出现时有解决的思路，任何的知识，或浅或深，
// 都有它发挥作用之处，我们的最终目的也是为了解决现实问题，这种目的从人类作为猿时就已经开始了，
// 发明工具不是为了生活便利和捕猎吗，现今大火的人工智能也是如此，只有直面现实问题，才能真正
// 解决问题，同时促进我们对知识的理解
// 如今，随着AI工具的出现，我们从原先的掌握编程知识变成了如何利用工具解决问题，这就需要人们头脑
// 中的想法，这种想法就是思考，也是人类身上最独特的地方
int longestValidParentheses(string s){
    // 采用左右遍历的方法
    // 这种思想在其他题目也见到过，从左往右遍历无法解决左括号大于右括号的子序列是否合法的判断，
    // 比如"(()"这种字符串，从左往右遍历过程中left > right，这样得到的ans=0，但答案显然应该为2，
    // 为了解决这种情况，我们选择从右往左进行再一次遍历，这样就能判断左括号大于右括号是否合法的情况了，
    // 同时也能记录正确答案，我认为根本之处在于合法的子序列可能出现在字符串的任何位置，而单个方向的遍历只能解决
    // 某一种合法子序列出现的情况，我们需要综合所有可能的子序列得出最大长度，所以需要两个方向的遍历
    int n = s.length();
    int left = 0, right = 0; // 当前遇到左右括号的数量
    int ans = 0;
    // 从左往右进行遍历
    for(int i = 0; i < n; ++i){
        if(s[i] == '('){
            ++left;
        }else{
            ++right;
        }
        if(left == right){
            ans = max(ans, 2 * right);
        }else if(left < right){
            // 左括号数小于右括号，说明出现无法匹配的情况
            left = right = 0;
        }
    }
    left = right = 0; // 将left和right置空
    // 从右往左进行遍历
    for(int i = n - 1; i >= 0; --i){
        if(s[i] == '('){
            ++left;
        }else{
            ++right;
        }

        if(left == right){
            ans = max(ans, 2 * left);
        }else if(left > right){
            // 与上面同理，出现左右括号无法匹配的情况
            left = right = 0;
        }
    }

    return ans;
}

int main(){
    string s = "(())";
    cout << longestValidParentheses(s) << endl;
    return 0;
}