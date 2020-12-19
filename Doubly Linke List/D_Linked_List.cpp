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
	if (front == NULL) // 첫 노드라면
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
	fdum->cdata = 'F'; //앞쪽 더미노드를 나타냄
	rdum->cdata = 'R'; //뒷쪽 더미노드를 나타냄

	//앞 더미노드 연결작업
	fdum->next = front;
	front->prev = fdum;

	//뒷 더미노드 연결작업 및 ptr갱신 
	ptr->next = rdum;
	rdum->prev = ptr;
	ptr = rdum;
}

void List::MoveL() //ptr의 왼쪽 이동및 한계체크
{
	if(ptr->prev->cdata != 'F') 
	ptr = ptr->prev; 
}

void List::MoveR()
{
	if (ptr->next != NULL)
		ptr = ptr->next;
}

//삽입은 항상 노드기준 좌측에 이루어짐
//첫노드에 추가시 front값도 갱신필요

void List::MoveInsert(Ldata ndata) 
{
	Node* bptr = ptr->prev; //그 전 노드와의 연결을 위한 포인터
	Node* newNode = new Node;
	newNode->cdata = ndata;

	if (ptr->prev->cdata == 'F') //왼쪽 노드가 f더미노드이면
	{
		newNode->next = ptr;
		newNode->prev = bptr;
		bptr->next = newNode;
		ptr->prev = newNode;

		front = front->prev; //첫노드이기에 front값 갱신
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
	while (temp->next->cdata != 'R') //마지막 더미노드출력 방지
	{
		temp = temp->next;
		cout << temp->cdata << ' ';
	}
	cout << '\n';
}