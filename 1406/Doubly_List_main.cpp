#include "D_Linked_List.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	
	List l;
	char str[100001];
	cin >> str; //���ڿ��� �ޱ�
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
		case 'L': //Ŀ���� ��������
			l.MoveL();
			break;

		case 'D': //Ŀ���� ����������
			l.MoveR();
			break;

		case 'B': // Ŀ�� ���� ���ڸ� ����
			l.MoveRemove();
			break;

		case 'P': // Ŀ�� ���ʿ� ���ڸ� �߰�
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