// 力扣69：x的平方根的变形，要求精确到小数点后两位
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

// 二分法
double mySqrt(int x){
    double n = 1e-3; // 精确到小数点后两位，可以调整，如果是精确到小数点后10位，这里的值就改为1e-10，注意这里的类型是double
    double l = 0, r = x; // 这里最好不要将 r = x / 2; 因为在x = 0, 1, 2, 3时，会出现问题，具体要查看x/2和sqrt(x)的图像

    while(l <= r){
        double mid = (l + r) / 2;
        if(mid <= x / mid){
            l = mid + n;
        }else{
            r = mid - n;
        }
    }

    return r;
}

// 牛顿迭代法
double mySqrt2(int x){
    double x0 = x, C = x;

    while(true){
        double xi = 0.5 * (x0 + C / x0);

        if(fabs(x0 - xi) < 1e-4){
            break;
        }
        x0 = xi;
    }

    return x0; // 不能返回xi，因为while循环体外xi作为循环局部变量已经被销毁
}

int main(){
    int num;
    cin >> num;
    cout << fixed << setprecision(2) << mySqrt(num) << endl;
    cout << fixed << setprecision(2) << mySqrt2(num) << endl;
    return 0;
}