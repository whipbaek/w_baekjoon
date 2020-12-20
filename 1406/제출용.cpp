#include <string>
#include <iostream>
#include <cstring>

using namespace std;

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
	if (ptr->prev->cdata != 'F')
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

void List::MoveRemove()
{
	Node* bptr = ptr->prev;
	Node* bbptr = bptr->prev;
	if (bptr->cdata == 'F') // 왼쪽노드가 f라면 (삭제할 수 없는 상황)
		return;


	//서로 연결
	bbptr->next = ptr;
	ptr->prev = bbptr;

	if (bbptr->cdata == 'F')
		front = ptr;

	delete bptr;
}

void List::Lprintf()
{
	Node* temp = front;
	if (temp->cdata == NULL)
	{
		cout << "No Data to print" << endl;
		return;
	}

	cout << temp->cdata;
	while (temp->next->cdata != 'R') //마지막 더미노드출력 방지
	{
		temp = temp->next;
		cout << temp->cdata;
	}
	cout << '\n';
}

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