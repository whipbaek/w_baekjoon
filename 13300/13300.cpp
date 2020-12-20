#include <iostream>
using namespace std;

int main(void)
{
	int max, k, sex, grade;
	int boygrade[7] = { 0 }, girlgrade[7] = { 0 };
	int count = 0;
	cin >> max >> k;

	for (int i = 0; i < max; i++)
	{
		cin >> sex >> grade;
		if (sex==1) //남자라면
		{
			if(boygrade[grade] < k)
			boygrade[grade]++;
			else
			{
				boygrade[grade] = 1;
				count++;
			}
		}
		else //여자라면
		{
			if (girlgrade[grade] < k)
				girlgrade[grade]++;
			else
			{
				girlgrade[grade] = 1;
				count++;
			}

		}
	}
	for (int i = 0; i < 7; i++)
	{
		if (boygrade[i]>=1)
			count++;
		if (girlgrade[i]>=1)
			count++;
	}
	cout << count << endl;

	return 0;
}