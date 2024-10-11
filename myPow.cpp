// 今天在做力扣题爬楼梯，其中快速矩阵幂的解法让我想到普通整数快速幂
// 所以，在这里实现快速幂算法
#include<iostream>
using namespace std;

int myPow(int a, int n){
    int res = 1;
    while(n > 0){
        if((n & 1) == 1){
            res = res * a;
        }
        n >>= 1;
        a = a * a;
    }

    return res;
}

int main(){
    int a, n;
    cout << "请先输入底数a和幂n：" << endl;
    cin >> a >> n;
    cout << myPow(a, n) << endl;
    return 0;
}