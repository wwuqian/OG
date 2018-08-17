//itoa的模拟实现

char* my_itoa(int value,char* str,int base)
{
	char* dest = str; //用来记录字符串的开始
	std::stack<char> tmp;
	if(value == 0)
	{
		*str++ = '0';
		*str = '\0';
		return dest;
	}

	//base的范围为：[2-36],36进制就是：0-9 && a-z
	if(base < 2 || base > 36)
	{
		*str = '\0';
		return str;
	}
	int num = 1;
	while(num)
	{
		num = value / base; 
		int data = value % base; //data是从低位到高位
		if(data < 10)
			tmp.push(data+'0');
		else
			tmp.push(data-10+'a'); //跳过大写字母
		value = num;
	}
	while(!tmp.empty())
	{
		*str++ = tmp.top();
		tmp.pop();
	}
	*str = '\0';
	return dest;
}

int main()
{
	char str[20];
	printf("my_itoa(0,str,10): %s\n",my_itoa(0,str,10));
	printf("my_itoa(12,str,10): %s\n",my_itoa(12,str,10));
	printf("my_itoa(20,str,2): %s\n",my_itoa(20,str,2));
	printf("my_itoa(67,str,8): %s\n",my_itoa(67,str,8));
	printf("my_itoa(78,str,16): %s\n",my_itoa(78,str,16));
	printf("my_itoa(45,str,32): %s\n",my_itoa(45,str,32));
	printf("my_itoa(90,str,39): %s\n",my_itoa(90,str,39));

	return 0;
}

////atoi的模拟实现
int my_atoi(const char* str)
{
	//long long num = 0; //用来处理溢出问题
	int num = 0;
	int flag = 1; //标志位
	if(*str == '+' || *str == '-')
	{
		if(*str == '-')
			flag = -flag;
		*str++;
	}
	//当字符串开始有空格或tab的时候，往后走。
	while(isspace(*str))
		str++;

	while(*str)
	{
		if(*str > '9' || *str < '0')
			break;
		num = num*10 + (*str - '0');
 		str++;
	}

	//考虑是否溢出
	//此时的num没有符号位，若出现负数，必出现了溢出
	//flag == 1时，num为负，就是正溢。2147483648存不下，就会变为负数。
	//flag == -1时，num为负，就是负溢，此时发生溢出，num存不下，对于负数而言，就会变大。
	//比如：-2147483649，flag==-1,此时的str="2147483649",存不下，在内存中就成了-2147483646,会变大。
	if(num < 0)
	{
		if(flag == 1)
		{
			printf("发生正溢出");
			return 0;
		}
		else if(num > (signed int)0x80000000)
		{
			printf("发生负溢出");
			return 0;
		}
	}

	//此时num 的类型要为long long ，否则无法判断
	//if(((num > 0x7fffffff) && (flag == 1))
	//	|| ((num*flag < (signed int)0x80000000) && (flag == -1)))
	//{
	//	printf("有溢出");
	//	return 0;
	//}

	return num*flag;
}

//int main()
//{
//	printf("模拟实现atoi:\n");
//	printf("my_atoi(12345): %d\n",my_atoi("12345"));
//	printf("my_atoi(-12345): %d\n",my_atoi("-12345"));
//	printf("my_atoi(abc12345): %d\n",my_atoi("abc12345"));
//	printf("my_atoi(-abc12345): %d\n",my_atoi("-abc12345"));
//	printf("my_atoi(	12345): %d\n",my_atoi("		12345"));
//	printf("my_atoi(2147483648): %d\n",my_atoi("2147483648")); //正溢出
//	printf("my_atoi(-2147483649): %d\n",my_atoi("-2147483649")); //负溢出
//	printf("my_atoi(-2147483648):%d\n",my_atoi("-2147483648"));
//
//	return 0;
//
//}
