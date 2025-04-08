/**
 * @file        stl_priority_queue.cpp
 * @author      zhtgolfir
 * @date        2025-04-08
 * 
 * @brief       优先队列，也叫堆
 * 
 * @details     详细说明该文件的功能、逻辑等
 * 
 * @copyright   (c) 2025 zhtgolfir. All rights reserved.
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 自定义比较函数常用方法
// 方法一：全局函数，传入函数指针用decltype转换
bool cmp1(const int &u, const int &v){
    return u < v; // 大根堆
}

// 方法三：strcut重载()运算符
struct cmp3
{
    bool operator()(const int &u, const int &v){
        return u < v; // 大根堆
    }
};

int main(){
    // 1.声明
    priority_queue<int> pq1; // 默认为大根堆
    priority_queue<int, vector<int>, greater<int>> pq2; // 小根堆

    priority_queue<int, vector<int>, decltype(&cmp1)> pq3(cmp1);

    // 方法二：匿名函数用cmp变量存储，传入变量
    auto cmp2 = [](const int &u, const int &v){
        return u < v; // 大根堆
    };
    priority_queue<int, vector<int>, decltype(cmp2)> pq4(cmp2);

    priority_queue<int, vector<int>, cmp3> pq5; // 使用方法三


    // 2.常规操作
    pq1.push(10); // 入堆，时间复杂度为O(logn)，n为堆内元素个数
    pq1.push(20);
    pq1.push(30);

    cout << pq1.top() << endl; // 取出堆顶元素，时间复杂度为O(1)，注意保证堆非空

    pq1.pop(); // 出堆，时间复杂度为O(logn)，n为堆内元素个数，注意保证堆非空

    cout << pq1.size() << '\n'; // 获取堆内元素个数，即堆的大小

    return 0;
}