#define _CRT_SECURE_NO_DEPRECATE   
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1  
 
#include<iostream> 
#include<string>
 
using namespace std;
 
int _next[256];
string dest;
string pattern;
 
/*
因为i位置处的字符可能在pattern中多处出现（如下图所示），而我们需要的是最右边的位置，这样就需要每次循环判断了，
非常麻烦，性能差。这里有个小技巧，就是使用字符作为下标而不是位置数字作为下标。这样只需要遍历一遍即可，
这貌似是空间换时间的做法，但如果是纯8位字符也只需要256个空间大小，而且对于大模式，可能本身长度就超过了256，
所以这样做是值得的（这也是为什么数据越大，BM/Sunday算法越高效的原因之一）。
*/
void GetNext()
{
	int len = pattern.size();//get the length
 
	for (int i = 0; i < 256; i++)
		_next[i] = -1;
 
	for (int i = 0; i < len; i++)
		_next[pattern[i]] = i;
}
 
int SundaySearch()
{
	GetNext();
 
	int destLen = dest.size();
	int patternLen = pattern.size();
 
	if (destLen == 0) return -1;
 
	for (int i = 0; i <= destLen - patternLen;)
	{
		int j = i;//dest[j]
		int k = 0;//pattern[k]
 
		for (; k<patternLen&&j < destLen&&dest[j] == pattern[k]; j++, k++)
			;//do nothing
 
		if (k == patternLen)//great! find it!
			return i;
		else
		{
			if (i + patternLen < destLen)
				i += (patternLen - _next[dest[i + patternLen]]);
			else
				return -1;
		}
	}
 
	return -1;
}
 
int main()
{
	dest = "This is a wonderful city";
	
	//case one(successful locating)
	pattern = "wo";
	int result = SundaySearch();
	if (result == -1)
		cout << "sorry,you do not find it!\n";
	else
		cout << "you find it at " << result << endl;
 
	//case two(unsuccessful locating)
	pattern = "wwe";
	result = SundaySearch();
	if (result == -1)
		cout << "sorry,you do not find it!\n";
	else
		cout << "you find it at" << result << endl;
 
	return 0;
}