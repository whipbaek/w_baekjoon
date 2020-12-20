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
	if (ptr->prev->cdata != 'F')
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

void List::MoveRemove()
{
	Node* bptr = ptr->prev;
	Node* bbptr = bptr->prev;
	if (bptr->cdata == 'F') // ���ʳ�尡 f��� (������ �� ���� ��Ȳ)
		return;


	//���� ����
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
	while (temp->next->cdata != 'R') //������ ���̳����� ����
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