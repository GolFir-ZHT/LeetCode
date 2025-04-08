/**
 * @file        stl_deque.cpp
 * @author      zhtgolfir
 * @date        2025-04-08
 * 
 * @brief       STL中容器双端队列deque的使用。
 * 
 * @details     双端队列的使用；
 * 
 * @copyright   (c) 2025 zhtgolfir. All rights reserved.
 */

#include<iostream>
#include<deque>
using namespace std;

int main(){
    // 1.声明
    deque<int> dq;

    // 2.常用操作
    dq.push_front(10);
    dq.push_front(30);
    dq.push_back(20);
    dq.push_back(40);

    dq.front();
    dq.back();

    int size = dq.size();

    if(dq.empty()){
        cout << "双端队列为空！" << endl;
    }else{
        cout << "双端队列不空！" << endl;
    }

    // 以下两个操作注意判空
    dq.pop_front();
    dq.pop_back();

    // 3.遍历deque
    // 使用迭代器
    for(auto it = dq.begin(); it != dq.end(); ++it){
        cout << *it << ' ';
    }
    cout << endl;

    // 使用基于范围的for循环
    for(const auto& val : dq){
        cout << val << ' ';
    }
    cout << endl;

    return 0;
}