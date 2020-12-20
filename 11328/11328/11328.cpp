#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

bool w_strfry(char str1[], char str2[], int len1, int len2)
{
	char alpha1[26] = { 0, };
	char alpha2[26] = { 0, };
	int i, count = 0;

	if (len1 != len2)//문자열 길이가 다르다면
		return false;

	for (i = 0; i < len1; i++)
		alpha1[str1[i] - 'a']++; //알파벳 개수마다 배열에 저장
	for (i = 0; i < len2; i++)
		alpha2[str2[i] - 'a']++;
	for (i = 0; i < 26; i++)
	{
		if (alpha1[i] == alpha2[i])
			count++;
		if (count == 26)
			return true;
	}
	return false;
}

int main(void)
{
	char str1[1001], str2[1001];
	bool res[1001];
	int count;
	int len1, len2;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> str1 >> str2;
		len1 = strlen(str1); len2 = strlen(str2);
		res[i] = w_strfry(str1, str2, len1, len2);
	}

	for (int i = 0; i < count; i++)
	{
		if (res[i])
			cout << "Possible" << endl;
		else
			cout << "Impossible" << endl;
	}
	return 0;
}