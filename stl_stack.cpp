/**
 * @file        stl_stack.cpp
 * @author      zhtgolfir
 * @date        2025-04-01
 * 
 * @brief       STL中容器栈stack的使用
 * 
 * @details     栈的使用，常用于括号匹配，单调栈等题目；
 *              在这个程序中，还尝试了VSCode的可视化界面调试，
 *              左侧debug栏可以看到各变量在断点处的信息，而右键还可以
 *              调出汇编视图，可以查看每个语句对应的汇编过程，可说是非常
 *              好用了。这种可视化调试是对gdb功能的封装，gdb中像打断点或跳到
 *              下一步都是用命令行实现的，但这对于新人来说有些困难。
 * 
 * @copyright   (c) 2025 zhtgolfir. All rights reserved.
 */

 #include<iostream>
 #include<stack>
 using namespace std;

 int main(){
    // 1.初始化
    // 创建一个空栈，栈不允许列表初始化或填充相同元素，
    // 但是可以从已有的栈进行拷贝构造
    stack<int> stk; 
    stack<int> stk2(stk);
    stack<int> stk3 = stk2;

    // 2.入栈
    stk.push(10); // stk = [10(top)]
    stk.push(20); // stk = [10, 20(top)]
    stk.push(50); // stk = [10, 20, 50(top)]
    cout << stk.top() << '\n'; // 50, stk = [10, 20, 50(top)]
    stk.pop(); // stk = [10, 20(top)]
    cout << stk.top() << '\n'; // 20, stk = [10, 20(top)]

    // 3.取出栈顶元素：top()函数仅仅是取出栈顶元素，
    // 不会将栈顶元素pop()掉
    cout << stk.top() << '\n';

    // 4.出栈
    // 弹出栈顶元素，注意判断非空！
    // 判断条件等价于 if(!stk.empty())
    if(stk.size()) stk.pop(); // stk = [10(top)]
    cout << stk.top() << endl; // 10, stk = [10(top)]

    // 5.获取栈大小（元素个数），判空
    cout << stk.size() << '\n';
    if(stk.empty()) cout << "stack is empty!" << endl;

    // 6.清空栈：stack没有提供clear函数，需要我们一个个弹出
    while(stk.size()) stk.pop(); // 时间复杂度O(n)

    // 7.手写栈：以下标1作为栈底，可以在单调栈上二分
    int myStk[100], top = 0;
    // 入栈
    myStk[++top] = 2;
    myStk[++top] = 3;
    // 出栈
    top--;
    // 取出栈顶元素
    cout << myStk[top] << '\n';
    // 获取大小
    cout << top << '\n';
    // 判断栈是否为空
    if(top) { cout << "stack is not empty!" << '\n'; }
    // 遍历栈
    for(int i = 1; i <= top; ++i){
        cout << "元素遍历！" << '\n';
    }

    return 0;
 }