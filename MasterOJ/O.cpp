/*
时间超限 == TLE(Time Limit Exceeded)
时间复杂度
O(时间复杂度)
计算机 5*10^7次/s
O(5*10^7)
*****************
O(1)
int main(){
	int i=i+1;
}
*****************
O(5)
int main(){
	int a;
	for(int i=1;i<=5;i++){ // 循环了5次
		a++;//1个操作
	}
}
*****************
O(n)
int main(){
	int n,a;
	for(int i=1;i<=n;i++){ // 循环了5次
		a++;//1个操作
	}
}
*****************
O(n^2)
int main(){
	int n,a;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a++;
		}
	}
}
*****************
O(n^2) 2 * 2 ^ 2 50000000 1s -> 0.9s
int main(){
	int n,a,b;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a++;
			b++;
		}
	}
}
*****************
O(nlog(n))
int main(){
	int n,a[100];
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);//快速排序 分治思想 +log()
}
*****************
优化常数：
1.是在读入与输出 优化常数
  cin -> scanf -> quick_read(getchar())
  cout -> printf -> quick_output(putchar())
2.算法上进行优化
3.编译选项上进行优化（考试不让用）
  洛谷交题的时候打开O2优化
  #pragma GCC optimize ("O2") O2优化 平衡性（空间和体积）
  #pragma GCC optimize ("O3") O3优化 偏向于 时间最快

*/
/*
空间超限 == MLE (Memory Limit Exceeded)
128MB=128*1024KB=128*1024*1024B(字节)
int=4 bytes || int a[100]=100*4 bytes
long long = 8 bytes
bool = 1 byte
char = 1 byte

*/
#include<iostream>
using namespace std;
int a[10000000];   //4*10000000
int b[1000][1000]; //4*1000*1000
int main(){

}
/*
例子：
暴力
O(n^2) TLE
前缀和优化
O(n)
10^5<5*10^7



*/