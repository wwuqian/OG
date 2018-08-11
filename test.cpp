////#include <iostream>
////#include <vector>
////using namespace std;
////int main() {
////	int a,b;
////	while(cin >> a >> b)//注意while处理多个case
////		cout << a+b << endl;
////}
//
////#include <iostream>
////#include <cstdio>
////
////using namespace std;
////
////int main(){
////	//freopen("1.in","r",stdin);
////	int n,ans = 0;
////	cin >> n;
////	for(int i = 0; i < n; i++){
////		for(int j = 0; j < n; j++){
////			int x; scanf("%d",&x);
////			ans += x;
////		}
////	}
////	cout << ans << endl;
////	return 0;
////}
//
////#include<iostream>
////#include <string>
////using namespace std;
////
////class Replacement {
////public:
////	string replaceSpace(string initString, int length) {
////		if( length <= 0)
////			return NULL;
////		int oldlength = 0;
////		int blank = 0;
////		int i = 0;
////		while(initString[i] != '\0')
////		{
////			++oldlength;
////			if(initString[i] == ' ')
////				++blank;
////
////			++i;
////		}
////		int newlength = oldlength + blank*2;
////		if(newlength > length)
////			return NULL;
////
////		int p1 = oldlength;  //指向源串的末尾
////		int p2 = newlength;   //指向新串的末尾
////		while(p1 >= 0 && p1 > p2)
////		{
////			if(initString[p1] == ' ')
////			{
////				initString[p2--] = '0';
////				initString[p2--] = '2';
////				initString[p2--] = '%';
////			}
////			else
////			{
////				initString[p2--] = initString[p1];
////			}
////			--p1;
////		}
////		return initString;
////	}
////};
////int main()
////{
////	Replacement blank;
////	string s;
////	int len;
////	string result;
////	cin >> s;
////	cin >> len;
////	cout<<endl;
////	result = blank.replaceSpace(s,len);
////	cout<<result<<endl;
////	return 0;
////}
//
////
////#include <iostream>
////#include <string>
////using namespace std;
////class Solution {
////	enum STATE
////	{
////		VALID,
////		INVALID
////	};
////public:
////	int StrToInt(string str) {
////		STATE state = VALID;
////		int flag = 1;  //符号位 ,正数
////		long long ret = 0;
////		const char* newstr = str.c_str();
////		while(isspace(*newstr))
////			++newstr;
////		if(*newstr == '+')
////			newstr++;
////		if(*newstr == '-'){
////			flag = -flag;
////			newstr++;
////		}
////		while(*newstr){
////			if(isdigit(*newstr))
////			{
////				ret = ret*10+(*newstr-'0')*flag;
////				//考虑溢出
////				if(ret > INT_MAX || ret < INT_MIN)
////				{
////					ret = 0;
////					break;
////				}
////				newstr++;
////			}
////			else
////			{
////				state = INVALID;
////				ret = 0;
////				break;
////			}
////		}
////		return (int)ret;
////	}
////};
////
////int main()
////{
////	string str;
////	int ret = 0;
////	cin >> str;
////	Solution sol;
////	ret = sol.StrToInt(str);
////	cout << str <<endl;
////	return 0;
////}
//
//////左旋字符串。
////class StringRotation {
////public:
////	string rotateString(string A, int n, int p) {
////		// write code here
////		p %= n;
////		while(p--)
////		{
////			string tmp;
////
////			for(int i = 0;i <= p;++i)
////			{
////				for(int j = 0;j < p;++j)
////				{
////					tmp[j] = A[i];
////				}    
////				A[i] = A[i+1];
////			}
////			for(int i = p;i < n;++i)
////			{
////				A[i]
////			}
////
////
////		}
////	}
////};
////
//////使用字符串的函数实现，获取子串和拼接字符串。
////#include <iostream>
////#include<string>
////using namespace std;
////class StringRotation {
////public:
////	string rotateString(string A, int n, int p) {
////		// write code here
////		A = A.substr(p+1,n-p-1)+A.substr(0,p+1);
////		return A;
////	}
////};
//
////数组中出现次数超过一半的数字。
////解法一：利用数组特点，使用vector
//
////#include <vector>
////
////class Solution {
////public:
////	int MoreThanHalfNum_Solution(vector<int> numbers) {
////		int i;
////		int result, time=0;
////		for(i = 0;i < numbers.size();++i)
////		{
////			if(time == 0)
////			{
////				result = numbers[i];
////				time = 1;
////			}
////			else if(result == numbers[i])
////				time++;
////			else
////				time--;
////		}
////		int times = 0;
////		for(i = 0;i < numbers.size();++i)
////		{
////			if(result == numbers[i])
////				times++;
////		}
////
////		if(times*2 > numbers.size())
////			return result;
////		
////		return 0;
////	}
////};
////
////int main()
////{
////	Solution s;
////	int ret;
////	vector<int> numbers;
////	numbers.push_back(1);
////	numbers.push_back(2);
////	numbers.push_back(3);
////	numbers.push_back(2);
////	numbers.push_back(2);
////	numbers.push_back(2);
////	numbers.push_back(5);
////	numbers.push_back(4);
////	numbers.push_back(2);
////	
////	ret = s.MoreThanHalfNum_Solution(numbers);
////	cout << ret <<endl;
////}
//
////class Solution
////{
////public:
////	int MoreThanHalfNum(int* numbers,int length)
////	{
////		if(numbers == NULL || length <= 0)
////			return 0;
////		int result = 0;
////		int times = 0;
////		for(int i = 0; i < length; ++i)
////		{
////			if(times == 0)
////			{
////				result = numbers[i];
////				times++;
////			}
////			else if(result == numbers[i])
////				times++;
////			else
////				times--;
////		}
////		//此时result已经是数组中出现次数最多的数字
////		//下面进行检验，result是否超过数组元素的一半。
////		int c_times = 0;
////		for(int i = 0; i < length; ++i)
////		{
////			if(result == numbers[i])
////				c_times++;
////		}
////		if(c_times*2 > length)
////			return result;
////
////		return 0;
////	}
////};
////
//////由快排算法找出中位数，返回中位数。
////class Solution2
////{
////public:
////	int RandomInRange(int a,int b)
////	{
////		int c;
////		c = a + rand()%(b-a+1);
////		return c;
////	}
////
////	void Swap(int* a,int* b)
////	{
////		int tmp = *a;
////		*a = *b;
////		*b = tmp;
////	}
////
////	int Partition(int data[],int length,int start,int end)
////	{
////		if(data == NULL || length <= 0 || start < 0 || end >= length)
////			throw new std::exception("Invalid Parameters");
////
////		int index = RandomInRange(start,end);
////		Swap(&data[index],&data[end]);
////
////		int small = start - 1;
////		for(index = start; index < end; ++index)
////		{
////			if(data[index] < data[end])
////			{
////				++small;
////				if(small != index)//说明small此时比data[end]的值大
////					Swap(&data[small],&data[index]); 
////			}
////		}
////		++small;
////		Swap(&data[small],&data[end]);
////		//此时small左边的值比它小，small右边的值比它大
////		return small;
////	}
////	int Partition2(int data[],int length,int start,int end)
////	{
////		if(data == NULL || length <= 0 || start < 0 || end >= length)
////			throw new std::exception("Invalid Parameters");
////		int index = RandomInRange(start,end);
////		while(start < end)
////		{
////			while(start < end && index < data[end])
////				end--; //end找比index小的数
////			Swap(&data[start],&data[end]);  //将小的数放到start处
////
////			while(start < end && index >= data[start])
////				start++;  //start找比index大的数
////			Swap(&data[start],&data[end]); //将大的数放到end处
////		}
////		return start;
////	}
////
////	int MoreThanHalfNum(int* numbers,int length)
////	{
////		if(numbers == NULL || length <= 0)
////			return 0;
////		int middle = length >> 1;
////		int start = 0;
////		int end = length-1;
////		int index = Partition2(numbers,length,start,end);
////		while(index != middle)
////		{
////			if(index > middle)
////			{
////				end = index-1;
////				index = Partition2(numbers,length,start,end);
////			}
////			else
////			{
////				start = index+1;
////				index = Partition2(numbers,length,start,end);
////			}
////		}
////		int result = numbers[middle];
////		//检测该数字的次数是不是超过数组元素的一半
////		int times = 0;
////		for(int i = 0; i < length; ++i)
////		{
////			if(result == numbers[i])
////				++times;
////		}
////		if(times * 2 > length)
////			return result;
////
////		return 0;
////	}
////
////};
////
////class Solution3 {  
////public:
////	int MoreThanHalfNum(int* numbers,int length) 
////	{  
////		if(numbers == NULL || length <= 0)
////			return -1;  
////		  
////		//使用哈希表:缺点-浪费空间  
////		int hashtable[256]; 
////		for(int i = 0;i < length; i++){  
////			hashtable[i] = 0;  
////		}  
////		for(int i = 0;i < length; i++){  
////			hashtable[numbers[i]]++;  
////		}  
////		for(int i = 0;i < length; i++){  
////			if(hashtable[i]*2 > length)  
////				return i;  
////		}  
////		//没有找到这样的数字  
////		return 0;  
////	}  
////};
////
////int main()
////{
////	int num[] = {1,2,3,2,2,2,5,4,2};
////	int ret = 0;
////	Solution3 sol;
////	ret = sol.MoreThanHalfNum(num, sizeof(num)/sizeof(num[0]));
////	cout << "数组中出现次数超过一半的数字是： ";
////	cout << ret <<endl;
////	return 0;
////}
//
//
//
////#include <iostream>
////#include <string.h>
////using namespace std;
////
////void WordReverse(char* str)
////{
////	int i = 0;
////	int j = strlen(str)-1;
////	int length = strlen(str);
////	char tmp;
////	//第一步：将整个字符串进行逆置
////	while(i < j)
////	{
////		tmp = str[i];
////		str[i] = str[j];
////		str[j] = tmp;
////		i++;
////		j--;
////	}
////
////	//第二步：翻转单词
////	int begin = 0,end = 0;
////	i = 0;
////	while(i < length)
////	{
////		if(str[i] != ' ')
////			end++;
////		else  //此时end指向空格的位置
////		{
////			int m = begin;
////			int n = end-1;
////			while(m < n)
////			{
////				tmp = str[m];
////				str[m] = str[n];
////				str[n] = tmp;
////				m++;
////				n--;
////			}
////			begin = end+1; //下一个单词开始的地方
////			end++;
////		}
////		i++;
////	} 
////}
////int main()
////{
////	char str[] = "I like beijing.";
////	cout << "源字符串为：" <<endl;
////	cout << str << endl;
////	WordReverse(str);
////	cout << str <<endl;    
////}
//
////求数组中的逆序对
////class Solution {
////public:
////	//int InversePairs(vector<int> data) {
////	//	int i = 0, j = 0;
////	//	int count = 0;
////	//	for(i = 0; i < data.size(); ++i)
////	//	{
////	//		for(j = 1; j < data.size();++j)
////	//		{
////	//			if(data[i] > data[j])
////	//				count++;
////	//		}
////	//	}
////	//	count = count % 1000000007;
////	//	return count;
////	//}
////	int InversePairs(vector<int> data) {
////		int length = data.size();
////		vector<int> copy(length);
////		for(int i = 0; i < length; ++i)
////		{
////			copy[i] = data[i];
////		}
////		int count = InversePairsCode(data,copy,0,length-1);
////
////		count = count % 100000007;
////		return count;
////	}
////	int InversePairsCode(vector<int> data,vector<int> copy,int start,int end)
////	{
////		if(start == end)
////		{
////			copy[start] = data[start];
////			return 0;
////		}
////		int length = (end-start)/2;
////		int left = InversePairsCode(copy,data,start,start+length);
////		int right = InversePairsCode(copy,data,start+length+1,end);
////
////		int i = start + length;
////		int j = end;
////		int indexCopy = end;
////		int count = 0; 
////		while(i >= start && j >= start+length+1)
////		{
////			if(data[i] > data[j])
////			{
////				copy[indexCopy--] = data[i--];
////				count += j-start-length;
////			}
////			else
////			{
////				copy[indexCopy--] = data[j--];
////			}
////		}
////		for(; i >= start; --i)
////			copy[indexCopy--] = data[i];
////		for(; j >= start+length+1; --j)
////			copy[indexCopy--] = data[j];
////
////		return left + right + count;
////	}
////
////};
//
////int main()
////{
////	vector<int> v;
////}
//
////面试53：正则表达式的匹配
////class Solution {
////public:
////	bool match(char* str, char* pattern)
////	{
////		if(str == NULL || pattern == NULL)
////			return false;
////		return matchCode(str,pattern);
////	}
////
////	bool matchCode(char* str,char* pattern)
////	{
////		if(*str == '\0' && *pattern == '\0')
////			return true;
////		if(*str != '\0' && *pattern == '\0')
////			return false;
////		//也可以匹配"" 和 "a*"
////		if(*(pattern+1) == '*')
////		{
////			if(*pattern == *str || (*pattern == '.' && *str != '\0'))
////				return matchCode(str+1, pattern+2)
////				|| matchCode(str+1, pattern)
////				|| matchCode(str, pattern+2);
////			else
////				return matchCode(str,pattern+2);
////		}
////
////		if(*str == *pattern || (*pattern == '.' && *str != '\0'))
////			return matchCode(str+1, pattern+1);
////
////		return false;
////	}  
////};
//
////在二维数组中查找：vector
////class Solution {
////public:
////	//参数为vector
////	bool Find(int target, vector<vector<int>> array) {
////		int rows = array.size();
////		int columns = array[0].size();
////		bool found = false;
////		while(!array.empty() && rows > 0 && columns > 0)
////		{
////			int row = 0;
////			int column = columns - 1;
////			while(row < rows && column >= 0)
////			{
////				if(array[row][column] == target)
////				{
////					found = true;
////					return found;
////				}
////				else if(array[row][column] > target)
////					--column;
////				else
////					++row;
////			}
////		}
////		return found;
////	}
////
////	bool FindInArray(int* matrix, int rows, int columns, int target)
////	{
////		bool found = false;
////		if(matrix != NULL && rows > 0 && columns > 0)
////		{
////			int row = 0;
////			int column = columns - 1;
////			while(row < rows && column >= 0)
////			{
////				if(matrix[row * columns + column] == target)
////				{
////					found = true;
////					return found;
////				}
////				else if(matrix[row * columns + column] > target)
////					--column;
////				else
////					++row;
////			}
////		}
////		return found;
////	}
////};
////
////int main()
////{
//////	Solution sol;
//////	int ret;
//////	int target;
//////	vector<vector<int>> vec;
//////	vector<int> a;
//////	vector<int> b;
//////	vector<int> c;
//////	vector<int> d;
//////	a.push_back(1);
//////	a.push_back(2);
//////	a.push_back(8);
//////	a.push_back(9);
//////	b.push_back(2);
//////	b.push_back(4);
//////	b.push_back(9);
//////	b.push_back(12);
//////	c.push_back(4);
//////	c.push_back(7);
//////	c.push_back(10);
//////	c.push_back(13);
//////	d.push_back(6);
//////	d.push_back(8);
//////	d.push_back(11);
//////	d.push_back(15);
//////
//////	vec.push_back(a);
//////	vec.push_back(b);
//////	vec.push_back(c);
//////	vec.push_back(d);
//////	
//////	cout << "请输入要查找的数字：";
//////	cin >> target;
//////	ret = sol.Find(target,vec);
//////	cout << "是否找到该元素：";
//////	cout << ret << endl;
//////	return 0;
////
////	int a[][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
////	int ret,target;
////	Solution sol;
////	int row = sizeof(a)/sizeof(a[0]);
////	int column = sizeof(a[0])/sizeof(a[0][0]);
////	cout << "请输入要查找的数字：";
////	cin >> target;
////	ret = sol.FindInArray((int*)a,row,column,target);
////	cout << "是否找到该元素：";
////	cout << ret << endl;
////	return 0;
////}
//
//
////调整数组顺序使奇数位于偶数前面。奇数和奇数，偶数和偶数的相对位置不变。
////class Solution {
////public:
////	void reOrderArray(vector<int> &array) {
////		int length = array.size();
////		vector<int> tmp(length,0);
////		int p1 = 0;
////		int p2 = length-1;
////		int i = 0;
////		int j = length-1;
////		while(p1 < length || p2 >= 0)
////		{
////			while((p1 < length || p2 >= 0) && (array[p1] & 0x1) == 0)
////				p1++;
////			tmp[i] = array[p1];
////			i++;
////			p1++;
////
////			while((p1 < length || p2 >= 0) && (array[p2] & 0x1) != 0)
////				p2--;
////			tmp[j] = array[p2];
////			j--;
////			p2--;
////		}
////		for(i = 0; i < length; ++i)
////		{
////			array[i] = tmp[i];
////		}      
////	}
////};
//
////顺时针打印矩阵。
////#include<vector>
////class Solution {
////public:
////	vector<int> printMatrix(vector<vector<int> > matrix) {
////		int rows = matrix.size();
////		int columns = matrix[0].size();
////		int start = 0;
////		vector<int> vec;
////		vec.resize(rows*columns);
////		while(columns > start * 2 && rows > start * 2)
////		{
////			vec = PrintMatrixInCircle(matrix,columns,rows,start);
////			++start;
////		}
////		return vec;
////	}
////
////	vector<int> PrintMatrixInCircle(vector<vector<int>> matrix,int columns,int rows,int start)
////	{
////		int endX = columns -1 - start;
////		int endY = rows - 1 - start;
////		vector<int> vec;
////		vec.resize(rows*columns);
////
////		//从左到右打印一行
////		for(int i = start; i <= endX; ++i)
////		{
////			int number = matrix[start][i];
////			vec.push_back(number);
////		}
////		//从上到下打印一列
////		if(start < endY)
////		{
////			for(int i = start+1; i <= endY; ++i)
////			{
////				int number = matrix[i][endX];
////				vec.push_back(number);
////			}
////		}
////		//从右到左打印一行
////		if(start < endX && start < endY)
////		{
////			for(int i = endX-1; i >= start; --i)
////			{
////				int number = matrix[endY][i];
////				vec.push_back(number);
////			}
////		}
////		//从下到上打印一列
////		if(start < endX && start < endY-1)
////		{
////			for(int i = endY-1; i >= start+1; --i)
////			{
////				int number = matrix[i][start];
////				vec.push_back(number);
////			}
////		}
////		return vec;
////	}
////};
//
////int main()
////{
////	vector<vector<int>> matrix;
////	Solution sol;
////	vector<int> a;
////	vector<int> b;
////	vector<int> c;
////	vector<int> d;
////	a.push_back(1);
////	a.push_back(2);
////	a.push_back(3);
////	a.push_back(4);
////
////	b.push_back(5);
////	b.push_back(6);
////	b.push_back(7);
////	b.push_back(8);
////
////	c.push_back(9);
////	c.push_back(10);
////	c.push_back(11);
////	c.push_back(12);
////
////	d.push_back(13);
////	d.push_back(14);
////	d.push_back(15);
////	d.push_back(16);
////
////	matrix.push_back(a);
////	matrix.push_back(b);
////	matrix.push_back(c);
////	matrix.push_back(d);
////
////	return 0;
////}
//
////面试题33：把数组排成最小的数
//
////#include <stdio.h>
////#include <stdlib.h>
////#include <string>
////#include <algorithm>
////
////static const int MaxNumberLength = 10;
////static  char* StrCombine1 = new char[MaxNumberLength*2 + 1];
////static char* StrCombine2 = new char[MaxNumberLength*2 + 1];
////
////class Solution {
////public:
////	static int compare(const void* strNumber1,const void* strNumber2)
////	{
////		strcpy(StrCombine1, *(const char**)strNumber1);
////		strcat(StrCombine1, *(const char**)strNumber2);
////
////		strcpy(StrCombine2, *(const char**)strNumber2);
////		strcat(StrCombine2, *(const char**)strNumber1);
////
////		return strcmp(StrCombine1, StrCombine2);
////	}
////
////	string PrintMinNumber(vector<int> numbers) {
////		string str;
////		int length = numbers.size();
////		char** strNumbers = (char**)(new int[length]);
////		for(int i = 0; i < length; ++i)
////		{
////			strNumbers[i] = new char[MaxNumberLength + 1];
////			sprintf(strNumbers[i],"%d",numbers[i]);
////		}
////		qsort(strNumbers,length,sizeof(char*),compare );
////
////		for(int i = 0; i < length; ++i)
////		{
////			str = str + strNumbers[i];
////		}
////
////		for(int i = 0; i < length; ++i)
////			delete[] strNumbers[i];
////		delete[] strNumbers;
////
////		return str;
////	}
//
//
////面试题41：和为s的连续证书序列。
////class Solution {
////public:
////	vector<vector<int> > FindContinuousSequence(int sum) {
////
////		int small = 1;
////		int big = 2;
////		int middle = (1 + sum)/2;
////		int curSum = small + big;
////		vector<vector<int>> v;
////		vector<int> a;
////
////		while(small < middle)
////		{
////			if(curSum == sum)
////			{
////				for(int i = small; i <= big; ++i)
////					a.push_back(i);
////			}
////			v.push_back(a);
////
////			while(curSum > sum && small < middle)
////			{
////				curSum -= small;
////				small++;
////				if(curSum == sum)
////				{
////					for(int i = small; i <= big; ++i)
////						a.push_back(i);
////				}
////			}  
////			v.push_back(a);
////		}
////		return v;
////	}
////};
//
////链表中倒数第k个节点
//*
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};*/
////class Solution {
////public:
////    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
////        if(pListHead == NULL || k == 0)
////            return NULL;
////        ListNode* first = pListHead;
////        ListNode* second = NULL;
////        for(int i = 0; i < k-1; ++i)
////        {
////            if(first->next != NULL)
////                first = first->next;
////            else
////                return NULL;
////        }
////        second = pListHead;
////        while(first->next != NULL)
////        {
////            first = first->next;
////            second = second->next;
////        }
////        return second; 
////    }
////};
//
////面试题31：连续子数组的最大和
////#include <iostream>
////#include <vector>
////using namespace std;
////bool InvalidValue = false;
////
////int GreatestSumOfArray(vector<int> array,int length)
////{
////	if(array.empty())
////	{
////		InvalidValue = true;
////		return 0;
////	}
////	InvalidValue = true;
////
////	int sum = 0;
////	int GreatestSum = 0x80000000;
////	for(int i = 0; i < length; ++i)
////	{
////		if(sum <= 0)
////			sum = array[i];
////		else
////			sum += array[i];
////		if(sum > GreatestSum)
////			GreatestSum = sum;
////	}
////	return GreatestSum;
////}
////
////int main()
////{
////	int n;
////	int num,sum;
////	vector<int> array;
////	cin >> n;
////	while((n--) > 0)
////	{
////		cin >> num;
////		array.push_back(num);
////	}
////	sum = GreatestSumOfArray(array,array.size());
////	cout << sum << endl;
////	return 0;
////}
//
////面试题5：从尾到头打印链表
//**
//*  struct ListNode {
//*        int val;
//*        struct ListNode *next;
//*        ListNode(int x) :
//*              val(x), next(NULL) {
//*        }
//*  };
//*/
////class Solution {
////public:
////	vector<int> printListFromTailToHead(ListNode* head) {
////		std::stack<ListNode*> node;
////		vector<int> v;
////		ListNode* cur = head;
////		while(cur != NULL)
////		{
////			node.push(cur);
////			cur = cur->next;
////		}
////		while(!node.empty())
////		{
////			cur = node.top();
////			v.push_back(cur->val);
////			node.pop();
////		}
////		return v; 
////	}
////};
//
////复杂链表的复制
//
////struct RandomListNode {
////    int label;
////    struct RandomListNode *next, *random;
////    RandomListNode(int x) 
////		:label(x)
////		,next(NULL)
////		,random(NULL) 
////	{}
////};
////
////class Solution {
////public:
////    void CloneNodes(RandomListNode* pHead)
////    {
////        RandomListNode* node = pHead;
////        while(node != NULL)
////        {
////            RandomListNode* clone = new RandomListNode(node->label);
////            clone->next = node->next;
////            clone->random = NULL;
////            
////            node->next = clone;
////            node = clone->next;
////        }
////    }
////    
////    void ConnectRandomNodes(RandomListNode* pHead)
////    {
////        RandomListNode* node = pHead;
////        while(node != NULL)
////        {
////            RandomListNode* clone = node->next;
////            if(node->random != NULL)
////            {
////                clone->random = node->random->next;
////            }
////            node = clone->next;
////        }
////    }
////    
////    RandomListNode* ReconnectNodes(RandomListNode* pHead)
////    {
////        RandomListNode* node = pHead;
////        RandomListNode* clonedHead = NULL;
////        RandomListNode* clonedNode = NULL;
////        if(node != NULL)
////        {
////            clonedHead = clonedNode = node->next;
////            node->next = clonedNode->next;
////            node = node->next;
////        }
////        while(node != NULL)
////        {
////            clonedNode->next = node->next;
////            clonedNode = clonedNode->next;
////            node->next = clonedNode->next;
////            node = node->next;
////        }
////        return clonedHead;
////    }
////    
////    RandomListNode* Clone(RandomListNode* pHead)
////    {
////        CloneNodes(pHead);
////        ConnectRandomNodes(pHead);
////        return ReconnectNodes(pHead);   
////    }
////};
//
////数组中重复的数字
////class Solution {
////public:
////	// Parameters:
////	//        numbers:     an array of integers
////	//        length:      the length of array numbers
////	//        duplication: (Output) the duplicated number in the array number
////	// Return value:       true if the input is valid, and there are some duplications in the array number
////	//                     otherwise false
////	bool duplicate(int numbers[], int length, int* duplication) {
////		if(numbers == NULL || length <= 0)
////			return false;
////		for(int i = 0;i < length; ++i)
////		{
////			if(numbers[i] < 0 || numbers[i] >= length)
////				return false;
////		}
////		for(int i = 0; i < length; ++i)
////		{
////			while(numbers[i] != i)
////			{
////				if(numbers[i] == numbers[numbers[i]])
////				{
////					*duplication = numbers[i];
////					return true;
////				}
////				//交换
////				int temp = numbers[i];
////				numbers[i] = numbers[temp];
////				numbers[temp] = temp;
////			}
////		}
////		return false;
////	}
////};
//
////两个链表的第一个公共结点
//*
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};*/
////class Solution {
////public:
////    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
////        unsigned int length1 = GetListLength(pHead1);
////        unsigned int length2 = GetListLength(pHead2);
////        int lengthDiff = length1 - length2;
////        ListNode* ListOfLong = pHead1;
////        ListNode* ListOfShort = pHead2;
////        if(length2 > length1)
////        {
////            ListOfLong = pHead2;
////            ListOfShort = pHead1;
////            lengthDiff = length2 - length1;
////        }
////        for(int i = 0;i < lengthDiff; ++i)
////            ListOfLong = ListOfLong->next;
////        
////        while((ListOfLong != NULL) && (ListOfShort != NULL)
////             && (ListOfLong != ListOfShort))
////        {
////            ListOfLong = ListOfLong->next;
////            ListOfShort = ListOfShort->next;
////        }
////        
////        return ListOfLong;
////    }
////    unsigned int GetListLength(ListNode* pHead)
////    {
////        unsigned int length = 0;
////        ListNode* cur = pHead;
////        while(cur != NULL)
////        {
////            ++length;
////            cur = cur->next;
////        }
////        return length;
////    }
////};
//
////合并两个排序的链表
//*
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};*/
////class Solution {
////public:
////    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
////    {
////        if(pHead1 == NULL)
////            return pHead2;
////        else if(pHead2 == NULL)
////            return pHead1;
////        ListNode* MergeHead = NULL;
////        
////        if(pHead1->val < pHead2->val)
////        {
////            MergeHead = pHead1;
////            MergeHead->next = Merge(pHead1->next,pHead2);
////        }
////        else
////        {
////            MergeHead = pHead2;
////            MergeHead->next = Merge(pHead1,pHead2->next);
////        }
////        return MergeHead;
////    }
////};
//
////反转链表
//*
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};*/
////class Solution {
////public:
////    ListNode* ReverseList(ListNode* pHead) {
////        ListNode* RevHead = NULL;
////        ListNode* cur = pHead;
////        ListNode* prev = NULL;
////        ListNode* next = NULL;
////        while(cur != NULL)
////        {
////            next = cur->next;
////            if(next == NULL)
////                RevHead = cur;
////                
////            cur->next = prev;
////            prev = cur;
////            cur = next;
////        }
////        return RevHead;
////    }
////};
//
//
////一个链表包含环，请找出该链表的环的入口处
//*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) :
//        val(x), next(NULL) {
//    }
//};
//*/
////class Solution {
////public:
////    ListNode* EntryNodeOfLoop(ListNode* pHead)
////    {
////        ListNode* meet = MeetingNode(pHead);
////        if(meet == NULL)
////            return NULL;
////        //环的个数
////        int numofLoop = 1;
////        ListNode* cur = meet;
////        while(cur->next != meet)
////        {
////            cur = cur->next;
////            ++numofLoop;
////        }
////        //cur向前走numofLoop步
////        cur = pHead;
////        for(int i = 0;i < numofLoop; ++i)
////        {
////            cur = cur->next;
////        }
////        
////        //cur和behind同时向前走，在环的入口处相遇
////        ListNode* behind = pHead;
////        while(cur != behind)
////        {
////            cur = cur->next;
////            behind = behind->next;
////        }
////        return cur;
////    }
////    
////    ListNode* MeetingNode(ListNode* pHead)
////    {
////        if(pHead == NULL)
////            return NULL;
////        ListNode* slow = pHead->next;
////        if(slow == NULL)
////            return NULL;
////        ListNode* fast = slow->next;
////        while(fast != NULL && slow != NULL)
////        {
////            if(slow == fast)
////                return fast;
////            slow = slow->next;
////            fast = fast->next;
////            if(fast != NULL)
////                fast = fast->next;
////        }
////        return NULL;
////    }
////};
//
////在一个排序的链表中，删除重复的节点
//*
//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) :
//        val(x), next(NULL) {
//    }
//};
//*/
////class Solution {
////public:
////    ListNode* deleteDuplication(ListNode* pHead)
////    {
////        if(pHead == NULL)
////            return NULL;
////        ListNode* prev = NULL;
////        ListNode* cur = pHead;
////        while(cur != NULL)
////        {
////            ListNode* next = cur->next;
////            bool needDel = false;
////            if(next != NULL && next->val == cur->val)
////                needDel = true;
////            if(!needDel)
////            {
////                prev = cur;
////                cur = cur->next;
////            }
////            else
////            {
////                int value = cur->val;
////                ListNode* delNode = cur;
////                while(delNode != NULL && delNode->val == value)
////                {
////                    next = delNode->next;
////                    delete delNode;
////                    delNode = NULL;
////                    
////                    delNode = next;
////                }
////                if(prev == NULL)
////                {
////                   pHead = next;
////                }
////                else
////                {
////                    prev->next = next;
////                }
////                cur = next;
////            }
////        }
////        return pHead;
////    }
////};
//
////面试题52：构建乘积数组
////class Solution {
////public:
////	vector<int> multiply(const vector<int>& A) {
////		if(A.empty())
////			return A;
////		int length = A.size();
////		vector<int> C(length,0);
////		vector<int> D(length,0);
////		C[0] = 1;
////		for(int i = 1;i < length; ++i)
////		{
////			C[i] = C[i-1] * A[i-1];
////		}
////
////		D[length-1] = 1;
////		for(int i = length-2; i >= 0; --i)
////		{
////			D[i] = D[i+1] * A[i+1];
////		}
////
////		//计算B
////		for(int i = 0; i < length; ++i)
////			C[i] = C[i] * D[i];
////
////		return C;
////	}
////};
//
////按照左右半区的方式重新组合单链表
////class Solution {
////public:
//	/**
//	 *	按照左右半区的方式重新组合单链表
//	 *	输入：一个单链表的头节点head
//	 *	将链表调整成题目要求的样子
//	 *
//	 *	后台的单链表节点类如下：
//	 *
//	 struct ListNode {
//		int val;
//		struct ListNode *next;
//		ListNode(int x) :
//				val(x), next(NULL) {
//		}
//	};
//	 */
////	void relocateList(struct ListNode* head) {
////       if(head == NULL || head->next == NULL)
////           return;
////        ListNode* mid = head;
////        ListNode* right = head->next;
////        //确定中心---mid为左半区间最右边的数
////        while(right->next != NULL && right->next->next != NULL)
////        {
////            mid = mid->next;
////            right = right->next->next;
////        }
////        right = mid->next; //此刻right为右半区间的第一个数
////        mid->next = NULL;
////        MergeLR(head,right);
////    }
////    void MergeLR(ListNode* left,ListNode* right)
////    {
////        ListNode* next = NULL;
////        while(left->next != NULL)
////        {
////            next = right->next;
////            right->next = left->next;
////            left->next = right;
////            left = right->next;
////             right = next;
////        }
////        left->next = right;
////    }
////};
//
////二叉搜索树与双向链表
//
//*
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//			val(x), left(NULL), right(NULL) {
//	}
//};*/
////class Solution {
////public:
////    TreeNode* Convert(TreeNode* pRootOfTree)
////    {
////        TreeNode* LastOfList = NULL;
////        CovertNode(pRootOfTree,&LastOfList);
////        
////        TreeNode* HeadOfList = LastOfList;
////        while(HeadOfList != NULL && HeadOfList->left != NULL)
////            HeadOfList = HeadOfList->left;
////        return HeadOfList;
////    }
////    
////    void CovertNode(TreeNode* pNode,TreeNode** LastOfList)
////    {
////        if(pNode == NULL)
////            return;
////        TreeNode* current = pNode;
////        if(current->left != NULL)
////            CovertNode(current->left,LastOfList);
////        
////        current->left = *LastOfList;
////        if(*LastOfList != NULL)
////            (*LastOfList)->right = current;
////        *LastOfList = current;
////        if(current->right != NULL)
////            CovertNode(current->right,LastOfList);
////    }
////};
//
////leetcode面试题：rotate-list :旋转链表
//**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
////class Solution {
////public:
////     ListNode *rotateRight(ListNode *head, int k) {
////        if(head == NULL || head->next == NULL || k <= 0)
////            return head;
////        ListNode* cur = head;
////        int len = 0;
////        while(cur != NULL)
////        {
////            len++;
////            cur = cur->next;
////        }
////        k = k % len;
////        if(k == 0)
////            return head;
////        ListNode* fast = head;
////        ListNode* slow = head;
////        for(int i = 0;i < k;++i)
////            fast = fast->next;
////        while(fast->next != NULL)
////        {
////            slow = slow->next;
////            fast = fast->next;
////        }
////        fast->next = head;
////        fast = slow->next;
////        slow->next = NULL;
////        return fast;
////    }
////    //一个指针的方法
////     ListNode *rotateRight_2(ListNode *head, int k) {
////         if(head == NULL || head->next == NULL || k <= 0)
////             return head;
////         int len = 1;
////         ListNode* cur = head;
////         while(cur->next != NULL)
////         {
////             len++;
////             cur = cur->next;
////         }
////         k = k % len;
////         if(k == 0)  
////             return head;
////         cur->next = head;
////         for(int i = 0;i < len-k;i++)
////             cur = cur->next;
////         head = cur->next;
////         cur->next = NULL;
////         return head;
////     }
////};
//
////leetcode面试题：covert-sorted-list-to-binary-search-tree
////将排序的单链表转化为二叉搜索树
////1-》2-》3-》4-》5-》NULL
//**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
//**
// * Definition for binary tree
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
////class Solution {
////public:
// //TreeNode *sortedListToBST(ListNode *head) {
// //       return BST(head,NULL);
// //   }
// //   TreeNode *BST(ListNode *head,ListNode *tail)
// //   {
// //       if(head == tail)
// //           return NULL;
// //       ListNode* slow = head;
// //       ListNode* fast = head;
// //       while(fast != tail && fast->next != tail)
// //       {
// //           slow = slow->next;
// //           fast = fast->next->next;
// //       }
// //       TreeNode* root = new TreeNode(slow->val);
// //       root->left = BST(head,slow);
// //       root->right = BST(slow->next,tail);
// //        
// //       return root;
// //   }
////};
//
//
//////有问题，过不去
////TreeNode *sortedListToBST(ListNode *head) {
////	if(head == NULL)
////		return NULL;
////	ListNode* tail = head;
////	TreeNode* root = NULL;
////	int len = 1;
////	if(tail->next != NULL)
////	{
////		tail = tail->next;
////		++len;
////	}
////	root = BST(head,tail,len);
////	return root;
////}
////
////TreeNode* BST(ListNode* head,ListNode* tail,int len)
////{
////	if(head == tail)  //1个节点
////	{
////		TreeNode* root = new TreeNode(head->val);
////		return root;
////	}
////	if(head->next == tail)  //2个节点
////	{
////		TreeNode* root = new TreeNode(tail->val);
////		root->left = new TreeNode(head->val);
////		return root;
////	}
////	//3个及三个以上的节点
////	ListNode* point = head;
////	int step = len/2 - 1;//左子树的最大节点，point->next为根节点
////	while(step--)
////		point = point->next;
////	TreeNode* root = new TreeNode(point->next->val);
////	BST(head,point,len/2);
////	BST(point->next->next,tail,len-len/2-1);
////
////	return root;
////}
//
////leetcode:remove-nth-node-from-end-of-list
////题目描述：
////Given a linked list, remove the n th node from the end of list and return its head.
////For example,
////Given linked list: 1->2->3->4->5, and n = 2.
////After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
////class Solution {
////public:
////    ListNode *removeNthFromEnd(ListNode *head, int n) {
////        if(head == NULL ||head->next == NULL || n <= 0)
////            return NULL;
////        ListNode* fast = head;
////        ListNode* prev = head;
////        ListNode* del = NULL;
////        for(int i = 0; i < n; i++)
////        {
////            fast = fast->next;
////        }
////        if(fast == NULL) //n> 链表的总数，删除头结点
////            return head->next;
////        while(fast->next != NULL)
////        {
////            fast = fast->next;
////            prev = prev->next;
////        }
////        del = prev->next;
////        prev->next = del->next;
////        delete del;
////        del = NULL;
////        return head;
////    }
////};
//
////leetcode:add-two-numbers
////题目描述：
////You are given two non-empty linked listsrepresenting two non-negative integers. 
////The digits are stored in reverse order and each of their nodes contain a single digit.
////Add the two numbers and return it as a linked list.
////You may assume the two numbers do not contain any leading zero, except the number 0 itself.
////
////Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) 
////Output: 7 ->0->8 
////解题思路：
////本题主要是类似数据在机器中存储的方式，我们平常所见的数据比如342，
////在链表中是逆向存储的所以就成了2->4->3这样了，同样5 -> 6 -> 4就是465，
////如果这样转换后，我们就会发现342+465=807，在十位上相加是超过10向前进一，但是链表是逆向的，所以就是向后进一。 
////因此，本题可以把链表中的元素转换为相应的数据后进行相加，得到的结果在按照相应的格式放入链表中。
////也可以直接按照链表的方式进行相加，在相加的过程中判断其是否要进位，如果需要进位是向后进位的。
////方法一：遍历两个链表，相同位置进行相加，把进位的数字计入下一组相加的数字中。
//**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
////class Solution {
////public:
////    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
////        if(l1 == NULL || l2 == NULL)
////            return NULL;
////        ListNode* tmp = new ListNode(0);
////        ListNode* result = tmp;
////        int value1 = 0; //余数
////        int value2 = 0; //进位
////        while(l1 != NULL && l2 != NULL)
////        {
////            value1 = (l1->val + l2->val + value2) % 10;
////            value2 = (l1->val + l2->val + value2) / 10;
////            tmp->next = new ListNode(value1);
////            l1 = l1->next;
////            l2 = l2->next;
////            tmp = tmp->next;
////            if(l1 == NULL && l2 == NULL)
////                break;
////            if(l1 == NULL)
////                l1 = new ListNode(0);
////            if(l2 == NULL)
////                l2 = new ListNode(0);
////        }
////        if(value2 != 0)
////            tmp->next = new ListNode(value2);
////        return result->next;
////    }
////};
//
//
////leetcode:sort-list链表排序
////Sort a linked list in O(n log n) time using constant space complexity.
////题目描述：Given 1->3->2->null, sort it to 1->2->3->null.
////常见排序方法有很多，插入排序，选择排序，堆排序，快速排序，冒泡排序，归并排序，桶排序等等。
////它们的时间复杂度不尽相同，而这里题目限定了时间必须为O(nlgn)，符合要求只有快速排序，归并排序，堆排序，
////而根据单链表的特点，最适于用归并排序。
//**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
////class Solution {
////public:
////    ListNode *sortList(ListNode *head) {
////        if(head == NULL || head->next == NULL)
////            return head;
////        ListNode* fast = head;
////        ListNode* slow = head;
////        ListNode* pre = head;
////        while(fast != NULL && fast->next != NULL)
////        {
////            pre = slow;
////            slow = slow->next;
////            fast = fast->next->next;
////        }
////        pre->next = NULL;
////        return Merge(sortList(head),sortList(slow));
////    }
////    
////    ListNode* Merge(ListNode* l1,ListNode* l2)
////    {
////        ListNode* newList = new ListNode(-1); //头结点
////        ListNode* cur = newList;
////        while(l1 && l2)
////        {
////            if(l1->val < l2->val)
////            {
////                cur->next = l1;
////                l1 = l1->next;
////            }
////            else
////            {
////                cur->next = l2;
////                l2 = l2->next;
////            }
////            cur = cur->next;
////        }
////        if(l1 != NULL)
////            cur->next = l1;
////        if(l2 != NULL)
////            cur->next = l2;
////        return newList->next;
////    }
////   //递归的方式归并
//	//ListNode* merge(ListNode* l1, ListNode* l2)
//	//{
//	//	if (!l1) return l2;
//	//	if (!l2) return l1;
//	//	if (l1->val < l2->val) {
//	//		l1->next = merge(l1->next, l2);
//	//		return l1;
//	//	} else {
//	//		l2->next = merge(l1, l2->next);
//	//		return l2;
//	//	}
//	//}
////};
//
////leetcode:partition-list分割链表
////Given a linked list and a value x, partition it such that all nodes less than x come
////before nodes greater than or equal to x.
////You should preserve the original relative order of the nodes in each of the two partitions.
////For example,
////Given1->4->3->2->5->2and x = 3,
////return1->2->2->4->3->5.
////题目描述：
////题意：给定一个单链表和一个x，把链表中小于x的放到前面，大于等于x的放到后面，每部分元素的原始相对位置不变。
////思路：新建两个节点preHead1与preHead2，分别为指向两个链表的头结点。
////节点值小于x的节点链接到链表1上，节点值大等于x的节点链接到链表2上。
////最后把两个链表相连即可
//**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
////class Solution {
////public:
////    ListNode *partition(ListNode *head, int x) {
////        if(head == NULL || head->next == NULL)
////            return head;
////        ListNode* list1 = new ListNode(0);
////        ListNode* list2 = new ListNode(0);
////        ListNode* p1 = list1;
////        ListNode* p2 = list2;
////        while(head != NULL)
////        {
////            if(head->val < x)
////            {
////                p1->next = head;
////                p1 = p1->next;
////            }
////            else
////            {
////                p2->next = head;
////                p2 = p2->next;
////            }
////            head = head->next;
////        }
////        p2->next = NULL;
////        p1->next = list2->next;
////        return list1->next;
////    }
////};
//
////面试题21：包含min函数的栈
////定义栈的数据结构，请在该类型中实现一个能够得到最小元素的min函数。
//
////#include <stack>
////#include <assert.h>
////class Solution {
////public:
////	void push(int value) {
////		m_data.push(value);
////		if(m_min.size() == 0 || value < m_min.top())
////			m_min.push(value);
////		else
////			m_min.push(m_min.top());
////	}
////	void pop() {
////		assert(m_data.size() > 0 && m_min.size() > 0);
////		m_data.pop();
////		m_min.pop();
////	}
////	int top() {
////		return m_data.top();
////	}
////	int min() {
////		assert(m_data.size() > 0 && m_min.size() > 0);
////		return m_min.top();
////	}
////private:
////	std::stack<int> m_data; //数据栈
////	std::stack<int> m_min;  //辅助栈
////};
//
////栈的压入、弹出序列
////#include <stack>
////class Solution {
////public:
////	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
////		bool Possible = false;
////		if(!pushV.empty() && !popV.empty())
////		{
////			int NextPush = 0; //数组下标，从0开始
////			int NextPop = 0;
////			int length = pushV.size();
////			std::stack<int> data;  //辅助栈
////
////			while(NextPop < length)
////			{
////				if(data.empty() || data.top() != popV[NextPop])
////				{
////					if(NextPush  == length)
////						break;
////					data.push(pushV[NextPush]);
////					NextPush++;
////				}
////				if(data.top() != popV[NextPop])
////					break;
////				data.pop();
////				NextPop++;
////			}
////			if(data.empty() && NextPop == length)
////				Possible = true;
////		}
////		return Possible;
////	}
////};
//
////栈的压入、弹出序列。
////在线OG未通过
////#include <stack>
////class Solution {
////public:
////	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
////		bool Possible = false;
////		if(!pushV.empty() && !popV.empty())
////		{
////			int NextPush = 0; //数组下标，从0开始
////			int NextPop = 0;
////			int length = pushV.size();
////			std::stack<int> data;  //辅助栈
////
////			while(NextPop < length)
////			{
////				if(data.empty() || data.top() != popV[NextPop])
////				{
////					if(NextPush  == length)
////						break;
////					data.push(pushV[NextPush]);
////					NextPush++;
////				}
////				if(data.top() != popV[NextPop])
////					break;
////				data.pop();
////				NextPop++;
////			}
////			if(data.empty() && NextPop == length)
////				Possible = true;
////		}
////		return Possible;
////	}
////};
//
//
////用两个栈实现队列
////class Solution
////{
////public:
////	void push(int node) {
////		stack1.push(node);
////	}
////
////	int pop() {
////		if(stack2.size() <= 0)
////		{
////			while(stack1.size() > 0)
////			{
////				int& data = stack1.top();
////				stack2.push(data);
////				stack1.pop();
////			}
////		}
////		if(stack2.size() == 0)
////		{
////			cout << "queue is empty" << endl;
////			return -1;
////			//throw new exception("queue is empty); //在线OG过不去
////		}
////		int head = stack2.top();
////		stack2.pop();
////		return head;
////	}
////
////private:
////	stack<int> stack1;
////	stack<int> stack2;
////};
//
////堆栈的使用
////#include <stack>
////#include <vector>
////#include <cstdio>
////#include <iostream>
////using namespace std;
////int main()
////{
////	std::stack<int> s;
////	std::vector<char> vec;
////	std::vector<int> v;
////	int n = 0,data = 0;
////	char ch;
////	while(getchar() != '\n')
////	{
////		cin >> n;
////		cout << endl;
////		for(int i = 0; i < n; ++i)
////		{
////			cin >> ch;
////			vec.push_back(ch);
////			if(ch == 'P')
////				s.push(data);
////		}
////		for(int i = 0; i < n;++i)
////		{
////			if(vec[i] == 'A')
////			{
////				if(s.size() == 0)
////					cout << "E" <<endl;
////				cout << s.top() << endl;
////			}
////			else if(vec[i] == 'P')
////			{
////				cout << endl;
////			}
////			else if(vec[i] == 'O')
////			{
////				s.pop();
////			}
////		}
////
////	}
////}
//
//
