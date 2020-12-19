#include "D_Linked_List.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	List l;
	char str[1000];
	cin >> str; //문자열을 받기
	int len = strlen(str);
	
	for (int i = 0; i < len; i++)
	{
		l.LInsert(str[i]);
	}
	l.DumInsert();
	l.Lprintf();

	l.MoveInsert('x');
	l.MoveL();
	l.MoveInsert('y');
	l.MoveInsert('n');
	l.Lprintf();

	return 0;
}