#pragma once
#include <string>
#include <iostream>
typedef char Ldata;
class Node
{
private:
	Node* prev;
	Node* next;
	Ldata cdata; //char ���ھ� ����
public:
	Node()
	{
		prev = NULL;
		next = NULL;
		cdata = NULL;
	}
	~Node() {}

	friend class List; // ListŬ���������� ������ ���
};

class List
{
private:
	Node* ptr; // ���Ḯ��Ʈ������ ������ ����
	Node* front;
public:
	List();
	~List();
	void MoveL(); //�����͸� �������� �ű�
	void MoveR(); //�����͸� ���������� �ű�
	void LInsert(Ldata ndata); //�ʱⰪ ����
	void DumInsert(); //���̰� �߰�
	void MoveInsert(Ldata ndata);
	void MoveRemove(); //���ʰ� ����
	void Lprintf();
};