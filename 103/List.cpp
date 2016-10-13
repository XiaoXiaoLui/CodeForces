#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;


#define pii pair<int, int>
#define mp make_pair<int, int>

typedef long long ll;

const int N = 1005;

template <typename T>
struct Node
{
	Node() : next(0), pre(0)
	{
	}
	
	void init(const T &data, Node<T> *left, Node<T> *right)
	{
		e = data;
		next = right;
		pre = left;
	}
	
	T e;
	Node<T> *next;
	Node<T> *pre;
};

template <typename T>
class List
{
public:
	List()
	{
		for (top = 0; top < N; top++)
		{
			S[top] = MEM + top;
		}
		top--;
		
		head = newNode();
		tail = newNode();
		
		head->next = tail;
		head->pre = 0;
		
		tail->pre = head;
		tail->next = 0;
	}
	
	Node<T>* erase(Node<T> *p)
	{
		Node<T> *res = p->next;
		
		p->pre->next = p->next;
		p->next->pre = p->pre;
		
		freeNode(p);
		return res;
	}
	
	Node<T>* insert(Node<T> *p, const T &x)
	{
		Node<T> *tmp = newNode(x, p->pre, p);
		tmp->pre->next = tmp;
		tmp->next->pre = tmp;
		
		return tmp;
	}
	
	Node<T>* begin() const
	{
		return head->next;
	}
	
	Node<T>* end() const
	{
		return tail;
	}
	
	bool empty() const
	{
		return head->next == tail;
	}
	
	void push_front(const T &x)
	{
		insert(begin(), x);
	}
	
	void pop_front()
	{
		erase(begin());
	}
	
	void push_back(const T &x)
	{
		insert(end(), x);
	}
	
	void pop_back()
	{
		erase(tail->pre);
	}

private:
	void freeNode(Node<T> *p)
	{
		S[++top] = p;
	}
	
	Node<T>* newNode()
	{
		if (top < 0)
		{
			return 0;
		}
		
		return S[top--];
	}
	
	Node<T>* newNode(const T &data, Node<T> *left, Node<T> *right)
	{
		Node<T> *res;
		if (top < 0)
		{
			return 0;
		}
		
		res = S[top--];
		res->init(data, left, right);
		return res;
	}


	Node<T> *head;
	Node<T> *tail;
	
	Node<T> MEM[N];
	int top;
	Node<T> *S[N];
};


int main()
{
	List<int> lst;
	int i, n;
	n = 20;
	for (i = 1; i <= n; i++)
	{
		lst.push_back(i);
	}
	
	Node<int> *p;
	for (p = lst.begin(); p != lst.end(); p = p->next)
	{
		if (p->e % 3 == 0)
		{
			p = lst.erase(p);
			p = p->pre;
		}
	}
	
	for (p = lst.begin(); p != lst.end(); p = p->next)
	{
		printf("%d ", p->e);
	}
	printf("\n");
	
	return 0;
}