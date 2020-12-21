#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	char s1[1001], s2[1001];	
	int alpha1[26] = { 0 }, alpha2[26] = { 0 };
	int len1, len2, i, j = 0, count = 0;
	cin >> s1; cin >> s2;
	len1 = strlen(s1); 
	len2 = strlen(s2);
	
	for (i = 0; i < len1; i++)
		alpha1[s1[i] - 'a']++;
	for (i = 0; i < len2; i++)
		alpha2[s2[i] - 'a']++;

	
	for (i = 0; i < 26; i++)
	{
		while (alpha1[i] != alpha2[i])
		{
			if (alpha1[i] > alpha2[i])
			{
				alpha1[i]--;
				count++;
			}

			if (alpha1[i] < alpha2[i])
			{
				alpha1[i]++;
				count++;
			}
		}
	}

	cout << count;

	return 0;
}