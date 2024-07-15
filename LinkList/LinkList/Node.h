//链表声明
typedef struct Node {
	int data;
	struct Node* next;
}LNode, * LinkList;//其中LNode为结点，LNode*为指针变量
//函数声明
void init(LinkList&L);
void Head_insert(LNode*& L);
void Tail_Insert(LNode*& L);
void ListVisit(LinkList L);
int Locatelem(LinkList L, int e);
int GetElem(LinkList L, int i);
int Length(LinkList L);
bool Insert(LinkList L, int i, int e);
void Reverse(LinkList& L);
int Delet(LinkList& L,int i);
LinkList Getelem(LinkList L, int i);



