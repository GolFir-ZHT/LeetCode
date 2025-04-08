/**
 * @file        stl_queue.cpp
 * @author      zhtgolfir
 * @date        2025-04-08
 * 
 * @brief       STL中容器队列queue的使用，用于解决约瑟夫环等问题。
 * 
 * @details     队列的使用；
 * 
 * @copyright   (c) 2025 zhtgolfir. All rights reserved.
 */

#include<iostream>
#include<queue>
using namespace std;

int main(){
    // 1.创建队列，队列和栈一样，是不支持遍历的
    queue<int> q;

    // 2.添加元素（入队）
    q.push(10);
    q.push(20);
    q.push(30);

    // 3.删除元素（出队）
    q.pop(); // 删除10

    // 4.访问队头元素
    int frontElement = q.front(); // 此时，取出20

    // 5.访问队尾元素
    int backElement = q.back(); // 此时，取出30

    // 6.检查队列是否为空/获取队列大小
    if(q.empty()){
        cout << "队列是空的！" << endl;
    }else{
        cout << "队列非空！" << endl;
    }

    int size = q.size(); // 返回一个unsigned int数，现在，这里是2，即20和30两个元素

    return 0;
}