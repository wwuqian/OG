//<string.h>中的常见函数的模拟实现
//strcat
char* mystrcat(char* dest,const char* src)
{
	char* p = dest;
	assert(dest && src);
	//找dest的结尾处，最终指向'\0'
	while(*dest != '\0')
		dest++;
	while(*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return p;
}

//int main()
//{
//	//目标串中的空间一定要开够，否则指针++会出错
//	char str1[30] = "hello"; 
//	char* str2 = " world";
//	char* ret = mystrcat(str1,str2);
//	printf("%s\n",ret);
//	return 0;
//}

////strncat
char* mystrncat(char* dest,const char* src,int len)
{
	char* p = dest;
	assert(dest);
	assert(src);
	while(*dest)
		dest++;
	while(len--)
	{

		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return p;
}

//int main()
//{
//	char str1[30] = "hello ";
//	char str2[] = "the beautiful";
//	char* ret = mystrncat(str1,str2,3);
//	printf("%s\n",ret);
//	return 0;
//}

//memchr
void* mymemchr(const void* str,int value,size_t n)
{
	char* p = (char*)str;
	assert(str);
	while(n--)
	{
		if((char)value == *p)
			return p;
		else
			++p;
	}
	return NULL;
}

//int main()
//{
//	char* p;
//	char str1[] = "maybe is you!";
//	p = mymemchr((void*)str1,'i',sizeof(str1));
//	printf("value is %c, position is %d\n",*p,p-str1+1);
//	return 0;
//}

////strchr : 查找字符的位置
char* my_strchr(const char* str,int character)
{
	assert(str);
	while(*str && (*str != (char)character))
		++str;
	//包含了character和str都为0的情况
	if((char)character == *str)
		return (char*)str;
	return NULL;
}

//int main()
//{
//	char str1[] = "programming";
//	char* pch;
//	printf("There is the 'r' in \"%s\"\n",str1);
//	pch = my_strchr(str1,'r');
//	while(pch != NULL)
//	{
//		printf("found at %d\n",pch-str1+1);
//		pch = my_strchr(pch+1,'r');
//	}
//	return 0;
//}

//memcmp
int my_memcmp(const void* ptr1,const void* ptr2,size_t num)
{
	char* dest = (char*)ptr1;
	char* src = (char*)ptr2;
	assert(ptr1 && ptr2);

	while(num && *dest == * src)
	{
		num--;
		dest--;
		src--;
	}

	if(num == 0)
		return 0;
	else
		return *dest-*src-'\0';
}

//int main()
//{
//	//比较字符串
//	char str1[] = "prant";
//	char str2[] = "prant house";
//
//	//比较整型
//	int a1[] = {1,2,3,4,6,7};
//	int a2[] = {1,2,3,4,9,12};
//
//	int ret = my_memcmp(str1,str2,5);
//	printf("string is %d\n",ret);
//
//	ret = my_memcmp(a1,a2,4);
//	printf("int is %d\n",ret);
//	return 0;
//}

////memset:初始化
void* my_memset(void* ptr,int value,size_t num)
{
	char* p = (char*)ptr;
	assert(p);
	while(num--)
	{
		*p = (char)value;
		p++;
	}
	return ptr;
}

//int main()
//{
//	char str1[] = "hello world";
//	my_memset(str1,0,5);
//	printf("%s\n",str1);
//	return 0;
//}

////strcpy:字符串拷贝
char* my_strcpy(char* dest,const char* src)
{
	char* p = dest;
	assert(dest && src);
	while(*dest++ = *src++)
	{
		;
	}
	return p;
}

//int main()
//{
//	char str[30] = {0};
//	char* str2 = "hello";
//	printf("%s\n",my_strcpy(str,str2));
//	return 0;
//}

//strrchr
//从头往后找
char* my_strrchr(const char* str,int character)
{
	char* ret = NULL;
	assert(str);
	while(*str)
	{
		if(*str == (char)character)
		{
			ret = (char*)str; //ret保存出现character的位置
			++str;
		}
		else
			++str;
	}
	if((char)character == *str)
		ret = (char*)str;
	return ret;
}

////从后往头找
char* myy_strrchr(const char* str,int character)
{
	char* ret = (char*)str;
	while(*str)
		++str; //找到最后一个字符
	while(*str != (char)character && (str >= ret))
		--str;  //找到第一个等于character的位置
	if(str >= ret)
		return (char*)str;
	return NULL;
}

//int main()
//{
//	char str1[] = "programming";
//	char* pch;
//	printf("There is the 'r' in \"%s\"\n",str1);
//	pch = my_strrchr(str1,'r');
//	printf("found at %d\n",pch-str1+1);
//
//	pch = myy_strrchr(str1,'r');
//	printf("found at %d\n",pch-str1+1);
//	return 0;
//}

//strstr:寻找子串
char* my_strstr(const char* str1,const char* str2)
{
	char* start = (char*)str1; //用来记录子串的第一个出现的位置
	char* substr = (char*)str2;
	char* cur = (char*)str1; //用来记录当前的位置
	assert(str1);
	assert(str2);
	while(*start)
	{
		cur = start;
		while(*cur != '\0' && *substr != '\0' && *cur == *substr)
		{
			cur++;
			substr++;
		}
		if(*substr == '\0')
			return start;
		substr = (char*)str2;
		start++; //如果没有匹配到，就进行下一轮循环
	}
	return NULL;
}

//int main()
//{
//	char str1[] = "aaaabbbccd";
//	char str2[] = "bbc";
//	char* ret = my_strstr(str1,str2);
//	printf("%s\n",ret);
//	return 0;
//}

////strcmp
int my_strcmp(char* str1,char* str2)
{
	assert(str1 && str2);
	while(*str1 == *str2)
	{
		if(*str1 == '\0')
			return 0;
	}

	return *str1-*str2;
}

//int main()
//{
//	char str1[] = "hello";
//	char str2[] = "china";
//	int ret = my_strcmp(str1,str2);
//	printf("%d\n",ret);
//	return 0;
//}

//strncmp
int my_strncmp(const char* str1,const char* str2,size_t num)
{
	assert(str1);
	assert(str2);
	while(num--)
	{
		if(*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
		{
			return *str1-*str2;
		}
	}
	return 0;
}

//int main()
//{
//	char str1[] = "hello";
//	char str2[] = "hellings";
//	int ret = my_strncmp(str1,str2,5);
//	printf("%d\n",ret);
//	return 0;
//}
