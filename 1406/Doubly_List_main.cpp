#include "D_Linked_List.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	
	List l;
	char str[100001];
	cin >> str; //문자열을 받기
	int count;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		l.LInsert(str[i]);
	}
	l.DumInsert();
	
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		char command;
		char ch;
		cin >> command;

		switch (command)
		{
		case 'L': //커서를 왼쪽으로
			l.MoveL();
			break;

		case 'D': //커서를 오른쪽으로
			l.MoveR();
			break;

		case 'B': // 커서 왼쪽 문자를 삭제
			l.MoveRemove();
			break;

		case 'P': // 커서 왼쪽에 문자를 추가
			cin >> ch;
			l.MoveInsert(ch);
			break;

		default:
			break;
		}
	}
	l.Lprintf();
	return 0;
}