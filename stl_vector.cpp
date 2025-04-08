/*
* STL中vector容器相关操作
* 2025.3.25
*/
#include<iostream>
#include<bits/stdc++.h> // 新的知识点：之前使用一类容器一个头文件，而stdc++.h是一个头文件可以包含所有容器
using namespace std;

int main(){
    cout << "Start!" << endl;
    long long ll;
    cout << sizeof(ll) << endl; // 8，单位为字节，也就是64个比特，说明long long类型的数据占64位

    // 1.创建vector
    vector<int> v; // 创建一个空的vector，元素类型为int
    v.resize(5); // 将创建的vector扩容成下标为[0, 4]，包含5个int元素的vector
    vector<int> v1(10); // 创建一个含有10个元素的vector，所有元素默认初始化为0
    vector<int> v2(10, 42); // 创建一个含有10个元素的vector，所有元素初始化为42
    vector<int> v3 = {1, 2, 3, 4, 5}; // 使用列表初始化创建一个vector

    // 2.访问元素
    int x = v[0]; // 访问第一个元素
    int y = v.at(1); // 使用at()函数访问第二个元素，at()会进行边界检查
    
    // 3.修改元素
    v[0] = 10; // 修改第一个元素，o(1)
    v.push_back(20); // 在vector末尾添加一个元素，o(1)
    v.pop_back(); // 删除末尾元素，o(1)，请注意保证vector非空

    // 4.遍历vector
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << ' ';
    }
    cout << endl;

    // 或者使用范围for循环
    for(int elem: v){
        cout << elem << ' ';
    }
    cout << endl;

    // 如果vector存储的是pair类型或结构体，c++17以上版本可以使用结构化绑定来枚举
    vector<pair<int, int>> v_pair;
    // &表示引用枚举，不加&就是默认枚举拷贝枚举
    for(const auto &[x, y]: v_pair){
        cout << x << ' ' << y << '\n';
    }

    // 5.查询vector的大小
    // 返回vector中元素的数量，
    // size()函数的返回类型是uint(unsigned int)，
    // 这种类型的数进行减1操作时需要特别注意，如 i < v.size() - 1，
    // 如果v.size()为0，减1操作后结果为-1，由于类型提升，
    // 将被解释为一个很大的正数，像for语句可能就此陷入死循环。
    int size = v.size(); 

    // 6.判断vector是否为空
    // 为空时的操作
    if(v.empty()){}
    // 不为空时的操作
    if(v.size()){}

    // 7.清空vector
    v.clear(); // 移除所有元素，size变为0，时间复杂度为o(n)

    cout << "end!" << endl;

    return 0;
}