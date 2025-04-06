/**
 * @file        union_find.cpp
 * @author      zhtgolfir
 * @date        2025-04-06
 * 
 * @brief       重新简单学习并查集
 * 
 * @details     首先，并查集是高效处理集合的合并和查询，如名字一样。
 *              它主要包括Find操作和Union操作。Find操作查询元素属于
 *              哪个集合；Union操作合并两个元素所属的集合（当然，这两个元素
 *              一定分属于不同的集合）。
 *              应用：处理图论中的连通性问题；网络动态连通问题；游戏场景中的合并问题；
 *              二维平面连通性问题（如岛屿问题或水流模拟）；
 *              还有一个问题是p数组的构建，它需要根据具体问题的输入数据和约束条件进行调整，
 *              在这个程序中，就是修改Initial函数的初始化逻辑。
 * 
 * @copyright   (c) 2025 zhtgolfir. All rights reserved.
 */

#include<iostream>
using namespace std;

const int MAXN = 100; // 常量，父亲数组的最大长度
// 存储每个结点的父亲，当不用h或s数组是，
// 可以用根结点的父亲为负值来实现按秩合并（
// 负值绝对值为高度或结点数大小）
int p[MAXN]; 
int h[MAXN]; // 存储树的高度，用于按高度合并
int s[MAXN]; // 存储树的结点个数，用于按大小合并

void Initial(int n){
    for(int i = 0; i < n; ++i){
        p[i] = i; // 初始时，自己是自己的父亲，也就是每个结点是一个集合
        h[i] = 1;
        s[i] = 1;
    }
}

int Find(int x){
    if(p[x] == x) return x;
    else return p[x] = Find(p[x]); // 路径压缩，实质是边执行Find操作边修改查找路径上的结点父亲
}

void Union(int x, int y){
    int rootx = Find(x);
    int rooty = Find(y);
    if(rootx != rooty){
        // p[rootx] = rooty;
        // 按高度或大小合并可以都称为按秩合并
        // 按树的高度合并
        if(h[rootx] < h[rooty]){
            p[rootx] = rooty;
        }else if(h[rootx] > h[rooty]){
            p[rooty] = rootx;
        }else{
            p[rootx] = rooty;
            h[rooty]++;
        }
        // 按树的大小合并
        if(s[rootx] <= s[rooty]){
            p[rootx] = rooty;
            s[rooty] += s[rootx];
        }else{
            p[rooty] = rootx;
            s[rootx] += s[rooty];
        }
    }
}

int main(){
    return 0;
}