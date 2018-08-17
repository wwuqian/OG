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
