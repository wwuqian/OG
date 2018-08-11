//1.牛牛数星星
//#pragma once
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	vector<bool> v1(5,false);
//	vector<vector<bool>> starMap;
//	vector<int> numOfStar;
//	int n,i,j;
//	for(i = 0;i < v1.size(); ++i)
//		starMap.push_back(v1);
//
//	cin >> n;
//	cout << endl;
//	while(n--)
//	{
//		cin >> i >> j;
//		cout << endl;
//		if(i >= starMap.size() || j >= v1.size())
//		{
//			v1.resize(2*(v1.size()),false);
//			for(int k = 0; k < 2*(v1.size());++k)
//				starMap.push_back(v1);
//		}
//		starMap[i][j] = true;
//	}
//
//	int m,a1,b1,a2,b2;
//	cin >> m;
//	cout << endl;
//	while(m--)
//	{
//		cin >> a1 >> b1;
//		cin >> a2 >> b2;
//		cout << endl;
//		int count = 0;
//		for(i = a1;i <= a2; ++i)
//		{
//			for(j = b1; j <= b2; ++j)
//			{
//				
//				if(starMap[i][j] == true)
//					count++;
//			}
//		}
//		numOfStar.push_back(count);
//	}
//
//	//输出
//	for(i = 0;i < numOfStar.size();++i)
//	{
//		cout << numOfStar[i] << endl;
//	}
//	return 0;
//}

//2.牛牛与世界杯门票
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n = 0,m = 1,k = 1;
//	int xi = 1, yi = 2;
//	int min = 0,money = 0;
//	vector<int> v;
//	cin >> n >> m >> k;
//	while(m--)
//	{
//		cin >> xi >> yi;
//		if(n + 1 > yi)
//		{
//			n = n - yi;
//			while(n--)
//				money += k;
//			v.push_back(money);
//		}
//		v.push_back(xi);
//	}
//	min = v[0];
//	for(int i = 0;i < v.size(); ++i)
//	{
//		if(v[i] < min)
//			min = v[i];
//	}
//	cout << min << endl;
//	return 0;
//}

//3.Fibonacci数列
//#include<iostream>
//#include<vector>
//using namespace std;
//
//size_t StepOfFibonacci(size_t N)
//{
//	if(N != 0){
//		size_t first = 1;
//		size_t second = 1;
//		size_t current;
//		vector<size_t> v;
//		v.push_back(0);
//		v.push_back(first);
//		if(N == 0 || N == 1)
//			return 0;
//		size_t i = 1;
//		while(i < N)
//		{
//			current = first+second;
//			v.push_back(current);
//			first = second;
//			second = current;
//			i = current;
//		}
//		if(v.back() == N)
//			return 0;
//		if(v.back() < N){
//			int step = 1;
//			N--;
//			if(v.back() == N)
//				return step;
//			step++;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	unsigned int N = 0;
//	cin >> N;
//	int ret = StepOfFibonacci(N);
//	cout << ret <<endl;
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int N = 0;
//	int small = 0,big = 0;
//	int first = 0,second = 1,current;
//	cin >> N;
//	while(1){
//		current = first + second;
//		first = second;
//		second = current;
//		if(current < N) 
//			small = N - current;
//		else{
//			big = current - N;
//		break;
//		}
//	}
//	cout << min(small,big) << endl;
//	return 0;
//}

//4.分苹果
//#include<iostream>
//using namespace std;
//int main()
//{
//	int n = 0;
//	int count = 0,sum = 0;
//	cin >> n;
//	int a[n];
//	for(int i = 0;i < n;++i){
//		cin >> a[i];
//	}
//	for(int i = 0;i < n;++i){
//		sum += a[i];
//	}
//	//n为奇数
//	if(sum % n != 0)
//		cout << -1 <<endl;
//	else
//	{
//		int average = sum / n;
//		for(int i = 0;i < n;i++){
//			if(abs(average-a[i]) % 2 != 0)
//			{
//				cout << -1 << endl;
//				return 0;
//			}
//			count += abs(average - a[i]);
//		}
//		cout << count / 4 << endl;
//	}
//}

//5.连续子数组的最大和
//https://blog.csdn.net/jyy305/article/details/77622047
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {
//		if(array.size() == 0)
//			return -1;
//		int max = array[0];
//		int sum = array[0];
//		for(size_t i = 1;i < array.size();++i){
//			if(sum <= 0)
//				sum = array[i];
//			else
//				sum += array[i];
//			if(sum > max)
//				max = sum;
//		}
//		return max;
//	}
//};

//6.回文串
//#include<iostream>
//#include<string>
//using namespace std;
//int main(){
//	string str;
//	while(cin >> str)
//	{
//		int len = str.length();
//		int x = 2,j = len - 1;
//		for(int i = 0;i < j;i++,j--)
//		{
//			if(str[i] != str[j])
//				x--;
//			if(str[i+1] == str[j])
//				i++;
//			else if(str[i] == str[j-1])
//				j--;
//			else
//				x--;
//		}
//	}
//	if(x>0)
//		cout << "YES" <<endl;
//	else
//		cout << "NO" <<endl;
//    }
//}

//7.删除公共字符
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s1,s2;
//	getline(cin,s1);
//	getline(cin,s2);
//	for(int i = 0;i < s2.size();++i)
//	{
//		int pos;
//		while((pos=s1.find(s2[i])) != -1)
//			s1.erase(pos,1);
//	}
//	cout << s1 <<endl;
//	return 0;
//}

//8.饥饿的小易
//https://www.nowcoder.com/questionTerminal/5ee8df898312465a95553d82ad8898c3
//#include<stdio.h>
//#include<map>
//#include<queue>
//using namespace std;
//const long long mod=1000000007;
//struct node{
//	long long x,step;
//	node(long long x,long long step):x(x),step(step){}
//};
//int main(){
//	long long x;
//	while(scanf("%lld",&x)!=EOF){
//		queue<node> Q;
//		map<long long,int> book;
//		Q.push(node(x,0)),book[x]=1;
//		long long res=-1;
//		while(!Q.empty()){
//			node head=Q.front();Q.pop();
//			if(head.x%mod==0){
//				res=head.step;
//				break;
//			}
//			if(head.step>100000) 
//				break;
//			long long x1=(4*head.x+3)%mod,x2=(8*head.x+7)%mod;
//			if(book.count(x1)==0){
//				book[x1]=1;
//				Q.push(node(x1,head.step+1));
//			}
//			if(book.count(x2)==0){
//				book[x2]=1;
//    		   Q.push(node(x2,head.step+1));
//			}
//		}
//		printf("%lld\n",res);
//	}
//}//直接bfs就可以啦~
//
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <math.h>
//#include <algorithm>
//#include <map>
//#include <queue>
//using namespace std;
//typedef long long ll;
// 
//const int mod=1e9+7;
// 
//int main(){
//  int n;
//  while(~scanf("%d",&n)){
//    int times=4;
//    int ans=100001;
//    for(int i=1;i<=300000;++i){
//      int x=((long long)(n)*times+times-1)%mod;
//      if(x==0){
//        ans=(i+1)/3+((i+1)%3?1:0);
//        break;
//  			}
//  			times=times*2%mod;
//		}
//		printf("%d\n",ans>100000?-1:ans);
//   }
//   return 0;
//}



