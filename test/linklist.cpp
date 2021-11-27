#include<iostream>

using namespace std;

template<class T>
class LinkedList
{
public:
	LinkedList(void) : m_pHead(nullptr), m_pTail(nullptr) {}
	LinkedList(const T& tData) : m_pHead(new Node(tData)), m_pTail(m_pHead){}
	~LinkedList(void)
	{
		DeleteAll();
	}
	LinkedList(const LinkedList &ll)
	{
		for (Node *pNode = ll.m_pHead; pNode; pNode = pNode->m_pNext)
			AddToTail(pNode->m_tData);
	}
	LinkedList& operator= (const LinkedList &ll)
	{
		if (&ll != this)
		{
			DeleteAll();
			for (Node *pNode = ll.m_pHead; pNode; pNode = pNode->m_pNext)
				AddToTail(pNode->m_tData);
		}
		return *this;
	}
	void DeleteAll(void)
	{
		for (Node* pNode = m_pHead, *pNext; pNode; pNode = pNext)
		{
			pNext = pNode->m_pNext;
			delete pNode;
		}
		m_pHead = nullptr;
		m_pTail = nullptr;
	}
	void AddToTail(const T& tData)
	{
		m_pTail = new Node(tData, m_pTail);
		if (m_pTail->m_pPrev)
			m_pTail->m_pPrev->m_pNext = m_pTail;
		else
			m_pHead = m_pTail;
	}
	bool RemoveFirst(const T& tData)
	{
		for (Node *pNode = m_pHead; pNode; pNode = pNode->m_pNext)
			if (Equal(pNode->m_tData, tData))
			{
				if (pNode->m_pPrev)
					pNode->m_pPrev->m_pNext = pNode->m_pNext;
				else
					m_pHead = pNode->m_pNext;
				if (pNode->m_pNext)
					pNode->m_pNext->m_pPrev = pNode->m_pPrev;
				else
					m_pTail = pNode->m_pPrev;
				return true;
			}
		return false;
	}
	bool Equal(const T& tData1, const T& tData2)
	{
		return tData1 == tData2;
	}
	friend ostream& operator<< (ostream &os, const LinkedList &ll)
	{
		for (Node *pNode = ll.m_pHead; pNode; pNode = pNode->m_pNext)
			os << '<' << *pNode << '>';
			return os;
	}
private:
	class Node {
	public:
		Node(const T& Data, Node* pPrev = NULL, Node* pNext = NULL)
			: m_tData(Data), m_pPrev(pPrev), m_pNext(pNext){}
		friend ostream& operator<< (ostream& os, const Node& node)
		{
			return os << node.m_tData;
		}
		T m_tData;
		Node* m_pPrev;
		Node* m_pNext;
	};
	Node *m_pHead;
	Node *m_pTail;
};

int main()
{
	string sa[] = {"北京","上海","长春","济南","天津","西安","上海","重庆","长春"};
    LinkedList<string> ll1 (sa[0]);
    for (size_t i = 1; i < sizeof(sa)/sizeof(sa[0]); i++)
        ll1.AddToTail (sa[i]);
    cout << ll1 << endl;
    LinkedList<string> ll2 (ll1);
    cout << ll2 << endl;
    LinkedList<string> ll3;
    ll3 = ll2;
    cout << ll3 << endl;
    ll3.RemoveFirst ("上海");
    cout << ll3 << endl;
    LinkedList<string> ll4;
    ll4.AddToTail ("张飞");
    ll4.AddToTail ("赵云");
    ll4.AddToTail ("关羽");
    cout << "-----------------------" << endl;
    LinkedList<LinkedList<string> > llll;
    llll.AddToTail (ll3);
    llll.AddToTail (ll4);
    cout << llll << endl;
}