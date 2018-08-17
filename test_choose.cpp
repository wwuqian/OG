#include<iostream>
#include<cstring>
using namespace std;

//1.
//int main()
//{
//	char a[] = "\t\v\\0will\n";
//	printf("%d",strlen(a));
//	return 0;
//}

//2.
//int FindSubString(char* pch)
//{
//	int count = 0;
//	char* p1 = pch;
//	while(*p1 != '\0')
//	{
//		if(*p1 == p1[1]-1)
//		{
//			p1++;
//			count++;
//		}
//		else
//			break;
//	}
//	int count2 = count;
//	while(*p1 != '\0')
//	{
//		if(*p1 == p1[1]+1)
//		{
//			p1++;
//			count2--;
//		}
//		else
//			break;
//	}
//	if(count2 == 0)
//		return(count);
//	return(0);
//}
//
//void ModifyString(char* pText)
//{
//	char* p1 = pText;
//	char* p2 = p1;
//	while(*p1 != '\0')
//	{
//		int count = FindSubString(p1);
//		if(count > 0)
//		{
//			*p2++ = *p1;
//			sprintf(p2,"%i",count);
//			while(*p2 != '\0')
//				p2++;
//			p1 += count + count + 1;
//		}
//		else
//			*p2++ = *p1++;
//	}
//}
//
//int main()
//{
//	char text[32] = "XYBCDCBABABA";
//	ModifyString(text);
//	printf(text);
//	return 0;
//}

//3.递归调用的次数
//int x(int n)
//{
//	printf("x()");
//	if(n <= 3)
//		return 1;
//	else
//		return x(n-2)+x(n-4)+1;
//	
//}
//
//int main()
//{
//	int time;
//	time = x(8);
//	cout << time << endl;
//	time = x(x(8));
//	cout << time << endl;
//	return 0;
//}

//4.内存对齐
//struct xx
//{
//	long long _x1;
//	char _x2;
//	int _x3;
//	char _x4[2];
//	static int _x5;
//};
//int xx::_x5;
//int main()
//{
//	xx res;
//	cout << sizeof(res) << endl;
//	return 0;
//}

//5.combination:
//#include<vector>
//class Solution {
//public:
//	vector<vector<int> > combine(int n, int k) {
//		vector<vector<int> > res;
//		vector<int> path;
//		DFS(res,path,n,k,1);
//		return res;
//	}
//
//	void DFS(vector<vector<int> > &res,vector<int> &path,int n,int k,int start){
//		if(path.size() == k)
//			res.push_back(path);
//		for(int i = start;i <= n; ++i)
//		{
//			path.push_back(i);
//			DFS(res,path,n,k,i+1);
//			path.pop_back();
//		}
//	}
//};
//
//int main()
//{
//	Solution sol;
//	vector<vector<int>> res;
//	res = sol.combine(4,2);
//	for(int i = 0;i < res.size();++i)
//	{
//		for(int j = 0;j < res[0].size();++j)
//			cout << res[i][j] << " ";
//		cout << endl;
//	}
//	return 0;
//}

//6.判断程序的输出结果：

//#include<stdio.h>
//
//int main(void){
//	int n;
//	char y[10] = "ntse";
//	char* x = y;
//	n = strlen(x);
//	*x = x[n];
//	x++;
//	printf("x=%s\n",x);
//	printf("y=%s\n",y);
//
//	return 0;
//}

//7.
//#include<stdio.h>
//int main()
//{
//	char *p,*q;
//	p = (char*)malloc(sizeof(char)*20);
//	q = p;
//	scanf("%s %s",p,q);
//	printf("%s %s\n",p,q);
//	return 0;
//}

//int main()
//{
//	static int x = 5;
//	x--;
//	int tmp = 0,y = 0;
//	
//	y = x++ + ++x;
//	cout << y <<endl;
//	tmp = x+y;
//	cout << tmp <<endl;
//	tmp = tmp+ ++x;
//	cout<< tmp << endl;
//	return 0;
//}

//8.
//int main()
//{
//	int a = 1,b = 0,c = -1,d = 0;
//	d = ++a || ++b && ++c;
//	cout << d << endl;
//	return 0;
//}

//9.
//int main()
//{
//
//	int** a[3][4];
//	cout << sizeof(a) << endl;
//	return 0;
//}

//10.
//#include<stdio.h>
//int main()
//{
//	int n;
//	char y[10] = "ntse";
//	char* x = y;
//	n = strlen(x);
//	*x = x[n];
//	x++;
//	printf("x=%s\n",x);
//	printf("y=%s\n",y);
//	return 0;
//}

//11.
//#include<stdio.h>
//int main()
//{
//	char* str = (char*)malloc(100);
//	strcpy(str,"hello");
//	free(str);
//	if(str != NULL)
//	{
//		strcpy(str,"world");
//		printf(str);
//	}
//	return 0;
//}

//12.求和：背包问题-动态规划
//#include<iostream>
//using namespace std;
//void BagProblem_Solution(int n, int m)
//{
//	if(n < 1|| m < 1)
//		return;
//	if(n > m)
//		n = m;
//
//	int num = 1 << n;               //枚举次数
//	for(int i = 1; i < num; i++)  //枚举所有情况
//	{
//		int sum = 0;
//		int j, k;
//		for(j = i, k = 1; j != 0; j>>=1, k++) //针对每种情况求和，判断是否满足条件
//		{
//			if(j&1)
//				sum += k;
//		}
//		if(sum == m) //如果满足，打印结果
//		{
//			for(j = i, k = 1; j != 0; j>>=1, k++)
//			{
//				if(j&1)
//					cout<<k<<' ';
//			}
//			cout<<endl;
//		}
//	}
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	BagProblem_Solution(n, m);
//	return 0;
//}

//13.有问题的选择题
//#include<stdio.h>
//int main()
//{
//	int a[5] = {2,4,6,8,10},*p,**k;
//	p = a;k = 
//	printf("%d",*(p++));
//	printf("%d\n",**k);
//	return 0;
//}

//14.
//#include<stdio.h>
//#define SUB(X,Y) (X+1)*Y
//int main()
//{
//	int a=3,b=4;
//	printf("%d\n",SUB(a++,b++));
//	return 0;
//}

//15.
//#include<stdio.h>
//int main()
//{
//	char str[] = "glad to test something";
//	char* p = str;
//	p++;
//	int *p1 = reinterpret_cast<int*>(p);
//	p1++;
//	p = reinterpret_cast<char*>(p1);
//	printf("result is %s\n",p);
//	return 0;
//}

//16.
//#include<stdio.h>
//void F1()
//{
//	b = a * 2;
//	a = b;
//}
//
//void F2()
//{
//	c = a + 1;
//	a = c;
//}
//
//int main()
//{
//	a = 5;
//	F1();
//	F2();
//	printf("a=%d\n",a);
//	return 0;
//}

//17
//#include<iostream>
//int main()
//{
//	char a[] = "ABCDEF"; //7 '\0'
//	char b[] = {'A','B','C','D','E','F'};  //6
//	cout << sizeof(a) << endl;
//	cout << sizeof(b) << endl;
//
//	return 0;
//}

//18.
//void incre();
//int x = 3;
//void main()
//{
//	int i;
//	for(i = 1;i < x;i++)
//		incre();
//}
//void incre()
//{
//	static int x = 1;
//	x *= x+1;
//	printf("%d\n",x);
//}

//19.
//#include<iostream>
//using namespace std;
//#include<stdio.h>
//int main()
//{
	//long l = 0;
	//long long ll = 0;
	//double d = 0.0;
	//long double ld = 0.0;
	//cout << sizeof(l) << endl;
	//cout << sizeof(d) << endl;
	//cout << sizeof(ld) << endl;

	//char ch = 10; //1010
	//printf("%u\n",ch); //10
	//printf("%d\n",ch); //10

	//ch = 127; //0111 1111
	//printf("%u\n",ch); //127
	//printf("%d\n",ch); //127

	//ch = 128; //1000 0000(char 最大为127)
	//printf("%u\n",ch); //4294967168
	//printf("%d\n",ch); //-128

	//ch = -1; //1000 0001
	//printf("%u\n",ch); //4294967295
	//printf("%d\n",ch); //-1

	//ch = -128; //1000 000
	//printf("%u\n",ch); //4294967168
	//printf("%d\n",ch); //-128

//	int i = 0;
//	int k = 0;
//	for(i=0,k=-1;k=0;i++,k++)
//		k++;
//
//	return 0;
//}
//
////折半查找
//int bin_search(int arr[],int left,int right,int key)
//{
//	int mid = 0;
//	while(left <= right)
//	{
//		mid = (right-left)>>2;
//		if(arr[mid] > key)
//			right = mid-1;
//		else if(arr[mid] < key)
//			left = mid+1;
//		else
//			return mid; //找到了
//	}
//	return -1;
//}

//20.不创建临时变量，实现两个数的交换
//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a=%d b=%d\n",a,b);
//	return 0;
//}

//21.sizeof和数组
//#include <stdio.h> 
//void test1(int arr[]) 
//{     
//	printf("%d\n", sizeof(arr));//(2) 4
//} 
//void test2(char ch[]) 
//{     
//	printf("%d\n", sizeof(ch));//(4) 4
//} 
//int main() 
//{     
//	int arr[10] = {0};     
//	char ch[10] = {0};     
//	printf("%d\n", sizeof(arr));//(1)  40   
//	printf("%d\n", sizeof(ch));//(3)  10   
//	test1(arr);     
//	test2(ch);     
//	return 0; 
//}

//22.逻辑与和逻辑或的特点
//#include<stdio.h>
//int main()
//{
//	int i = 0,a=1,b=2,c=3,d=4;
//	//i = a++ && ++b && d++;
//	//printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);//2 3 3 5
//	i = a++ || ++b || d++;
//	printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);//2 2 3 4
//
//	return 0;
//}

//23.
//#pragma pack(4)
//#include<stdio.h>
//#include<iostream>
//using namespace std;
//struct data
//{
//	int value;
//	double d;
//	char ch;
//};
////对齐数=min（最大的成员变量，默认对齐数）
//typedef struct list_t{
//	struct list_t* next;
//	struct list_t* prev;
//	char data[0];
//}list_t;
//
//int main()
//{
//	cout << sizeof(data) << endl;
//	//printf("%d\n",sizeof(list_t)); //8
//	return 0;
//}

//24.
//#include<iostream>
//using namespace std;
//int main()
//{
//	char str[] = "S\065AB";
//	cout << sizeof(str) << endl;
//	return 0;
//}
