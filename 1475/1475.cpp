/*
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n,sc, numofset = 1;
	int set[9];

	fill(set,set+9, 1);
	set[6] = 2; //6만 2개(9포함)
	cin >> n;
	
	while (n%10 != 0)
	{
		sc = n % 10;
		n /= 10;
		if (sc == 9)
			sc = 6;
		set[sc]--;
		if (set[sc] < 0)
		{
			numofset++;
			if (sc == 6)
				set[sc] = 1;
			else
				set[sc] = 0;
		}
	}

	cout << numofset << endl;

	return 0;
}
*/


#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	char n[1000001];
	int sc, numofset = 1;
	int set[9];

	fill(set, set + 9, 1);

	set[6] = 2; //6만 2개(9포함)
	cin >> n;
	int i = 0;
	int nnm = 1;

	while (n[i] != NULL)
	{
		sc = n[i]-'0'; // 정수로 변경
	
		if (sc == 9)
			sc = 6;
	
		if (set[sc] == 0) // 카드가 부족하다는 뜻!
		{
			numofset++;
			for (int j = 0; j < 9; j++) //카드 올리필
				set[j]++;
			set[6]++;
		}
		set[sc]--;

		i++;
	}

	cout << numofset << endl;

	return 0;
}
