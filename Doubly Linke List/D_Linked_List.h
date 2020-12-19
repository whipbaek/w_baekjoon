#pragma once
#include <string>
#include <iostream>
typedef char Ldata;
class Node
{
private:
	Node* prev;
	Node* next;
	Ldata cdata; //char 한자씩 저장
public:
	Node()
	{
		prev = NULL;
		next = NULL;
		cdata = NULL;
	}
	~Node() {}

	friend class List; // List클래스에서의 접근을 허용
};

class List
{
private:
	Node* ptr; // 연결리스트에서의 포인팅 역할
	Node* front;
public:
	List();
	~List();
	void MoveL(); //포인터를 왼쪽으로 옮김
	void MoveR(); //포인터를 오른쪽으로 옮김
	void LInsert(Ldata ndata); //초기값 설정
	void DumInsert(); //더미값 추가
	void MoveInsert(Ldata ndata);
	void MoveRemove(); //왼쪽값 삭제
	void Lprintf();
};