#include "D_Linked_List.h"
#include <iostream>
using namespace std;
List::List()
{
	ptr = NULL;
	front = NULL;
}

List::~List()
{}

void List::LInsert(Ldata ndata)
{
	if (front == NULL) // ù �����
	{
		Node* newNode = new Node;
		newNode->cdata = ndata;
		front = newNode;
		ptr = newNode;

		return;
	}
	else
	{
		Node* newNode = new Node;
		newNode->cdata = ndata;
		newNode->prev = ptr;

		ptr->next = newNode;
		ptr = newNode;
	}
}

void List::DumInsert()
{
	Node* fdum = new Node;
	Node* rdum = new Node;
	fdum->cdata = 'F'; //���� ���̳�带 ��Ÿ��
	rdum->cdata = 'R'; //���� ���̳�带 ��Ÿ��

	//�� ���̳�� �����۾�
	fdum->next = front;
	front->prev = fdum;

	//�� ���̳�� �����۾� �� ptr���� 
	ptr->next = rdum;
	rdum->prev = ptr;
	ptr = rdum;
}

void List::MoveL() //ptr�� ���� �̵��� �Ѱ�üũ
{
	if(ptr->prev->cdata != 'F') 
	ptr = ptr->prev; 
}

void List::MoveR()
{
	if (ptr->next != NULL)
		ptr = ptr->next;
}

//������ �׻� ������ ������ �̷����
//ù��忡 �߰��� front���� �����ʿ�

void List::MoveInsert(Ldata ndata) 
{
	Node* bptr = ptr->prev; //�� �� ������ ������ ���� ������
	Node* newNode = new Node;
	newNode->cdata = ndata;

	if (ptr->prev->cdata == 'F') //���� ��尡 f���̳���̸�
	{
		newNode->next = ptr;
		newNode->prev = bptr;
		bptr->next = newNode;
		ptr->prev = newNode;

		front = front->prev; //ù����̱⿡ front�� ����
		return;
	}

	newNode->next = ptr;
	newNode->prev = bptr;
	bptr->next = newNode;
	ptr->prev = newNode;

}

void List::Lprintf()
{
	Node* temp = front;
	if (temp->cdata == NULL)
	{
		cout << "No Data to print" << endl;
		return;
	}

	cout << temp->cdata<<' ';
	while (temp->next->cdata != 'R') //������ ���̳����� ����
	{
		temp = temp->next;
		cout << temp->cdata << ' ';
	}
	cout << '\n';
}