// 测试vector容器中emplace_back和push_back函数的区别

#include<iostream>
#include<vector>
using namespace std;

int main(){
	cout << "开始！" << endl;
	vector<int> a;
	a.emplace_back(1);
	cout << a[0] << endl;
	a.push_back(2);
	cout << a[0] << " " << a[1] << endl;
	return 0;
}
