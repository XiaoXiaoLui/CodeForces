#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <string>
#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}


#define pii pair<int, int>

typedef long long ll;

template <class T>
struct Node
{
	Node()
	{
		left = right = parent = 0;
		w = rand();
		size = 1;
	}
	
	Node(const T &x)
	{
		left = right = parent = 0;
		w = rand();
		size = 1;
		value = x;
	}
	
	void recal()
	{
		size = 1;
		if (left)
		{
			size += left->size;
		}
		if (right)
		{
			size += right->size;
		}
	}
	
	Node<T>* next()
	{
		Node<T>* x = 0;
		if (right)
		{
			x = right;
			while (x->left)
			{
				x = x->left;
			}
		}
		else
		{
			x = this;
			while (x->parent && x == x->parent->right)
			{
				x = x->parent;
			}
			x = x->parent;
		}
		return x;
	}
	
	Node<T>* prev()
	{
		Node<T>* x = 0;
		if (left)
		{
			x = x->left;
			while (x->right)
			{
				x = x->right;
			}
		}
		else
		{
			x = this;
			while (x->parent && x == x->parent->left)
			{
				x = x->parent;
			}
			x = x->parent;
		}
		
		return x;
	}
	
	Node<T> *left;
	Node<T> *right;
	Node<T> *parent;
	
	T value;
	int w;
	
	int size;
};

template <class T>
Node<T>* getNode(const T &x)
{
	return new Node<T>(x);
}

template <class T>
void putNode(Node<T> *p)
{
	delete p;
}



template <class T>
struct Treap
{
public:
	Treap() : mRoot(0) {}
	~Treap()
	{
		deleteTreap(mRoot);
		mRoot = 0;
	}
	
	bool erase(const T &value)
	{
		Node<T> *x = find(value);
		if (!x)
		{
			return false;
		}
		
		erase(x);	
		return true;
	}
	
	void erase(Node<T> *x)
	{
		Node<T> *y;
		while (true)
		{
			y = x->parent;
			if (!x->right)
			{
				transplant(x, x->left);
				break;
			}
			else if (!x->left)
			{
				transplant(x, x->right);
				break;
			}
			else
			{
				if (x->left->w < x->right->w)
				{
					leftRotate(x);
				}
				else
				{
					rightRotate(x);
				}
			}
		}
		
		putNode(x);
		goUp(y);
	}
	
	pair<Node<T>*, bool> insertUnique(const T &value)
	{	
		Node<T>* x = mRoot, *y = 0, *xParent = 0;
		while (x)
		{
			xParent = x;
			if (x->value < value)
			{
				x = x->right;
			}
			else
			{
				y = x;
				x = x->left;
			}
		}
		
		if (y && !(value < y->value))
		{
			return pair<Node<T>*, bool>(y, false);
		}
		
		x = getNode(value);
		x->parent = xParent;
		if (!xParent)
		{
			mRoot = x;
		}
		else if (xParent->value < value)
		{
			xParent->right = x;
		}
		else
		{
			xParent->left = x;
		}
		
		// maintain heap
		while (x->parent && x->w > x->parent->w)
		{
			if (x == x->parent->left)
			{
				rightRotate(x->parent);
			}
			else
			{
				leftRotate(x->parent);
			}
		}
		
		goUp(x);
		
		return pair<Node<T>*, bool>(x, true);
	}
	
	Node<T>* insertEqual(const T &value)
	{
		Node<T>* x = mRoot, *xParent = 0;
		while (x)
		{
			xParent = x;
			if (x->value < value)
			{
				x = x->right;
			}
			else
			{
				x = x->left;
			}
		}
		
		x = getNode(value);
		x->parent = xParent;
		if (!xParent)
		{
			mRoot = x;
		}
		else if (xParent->value < value)
		{
			xParent->right = x;
		}
		else
		{
			xParent->left = x;
		}
		
		// maintain heap
		while (x->parent && x->w > x->parent->w)
		{
			if (x == x->parent->left)
			{
				rightRotate(x->parent);
			}
			else
			{
				leftRotate(x->parent);
			}
		}
		
		goUp(x);
		
		return x;
	}
	
	Node<T>* find(const T &value) const
	{
		return find(mRoot, value);
	}
	
	Node<T>* kth(int rank) 
	{
		return kth(mRoot, rank);
	}
	
	int lessCount(const T &value) const
	{
		if (!mRoot)
		{
			return 0;
		}
		
		Node<T> *x = mRoot;
		int res = 0, leftSize;
		while (x)
		{
			leftSize = x->left ? x->left->size : 0;
			if (x->value < value)
			{
				res += leftSize + 1;
				x = x->right;
			}
			else
			{
				x = x->left;
			}
		}
		return res;
	}
	
	int lessCount(Node<T>* x) const
	{
		if (!x)
		{
			return size();
		}
		
		int res = x->left ? x->left->size : 0;
		while (x->parent)
		{
			if (x == x->parent->right)
			{
				res += x->parent->left ? x->parent->left->size + 1 : 1;
			}
			x = x->parent;
		}
		
		return res;
	}
	
	void print() const
	{
		print(mRoot);
	}
	
	bool empty() const
	{
		return mRoot == 0;
	}
	
	int size() const
	{
		return mRoot ? mRoot->size : 0;
	}
	
	Node<T>* lower_bound(const T &value)
	{
		return lower_bound(mRoot, value);
	}
	
	Node<T>* upper_bound(const T &value)
	{
		return upper_bound(mRoot, value);
	}
	
	Node<T>* begin()
	{
		return subtreeMin(mRoot);
	}
	
	Node<T>* next(Node<T>* x)
	{
		if (x)
		{
			return x->next;
		}
		return 0;
	}
	
	Node<T>* end()
	{
		return 0;
	}
	
	Node<T>* prev(Node<T>* x)
	{
		if (x)
		{
			return x->prev;
		}
		return subtreeMax(mRoot);
	}
	
private:
	Node<T> *mRoot;
	
	// update size value
	void goUp(Node<T> *x)
	{
		while (x)
		{
			x->recal();
			x = x->parent;
		}
	}
	
	Node<T>* subtreeMin(Node<T> *x)
	{
		while (x->left)
		{
			x = x->left;
		}
		return x;
	}
	
	Node<T>* subtreeMax(Node<T> *x)
	{
		while (x->right)
		{
			x = x->right;
		}
		return x;
	}
	
	Node<T>* kth(Node<T> *p, int k) 
	{
		if (!p || k <= 0 || k > p->size)
		{
			return 0;
		}
		
		int leftSize;
		while (true)
		{
			leftSize = p->left ? p->left->size : 0;
			if (k <= leftSize)
			{
				p = p->left;
			}
			else if (k == leftSize + 1)
			{
				return p;
			}
			else
			{
				k -= leftSize + 1;
				p = p->right;
			}
		}
	}
	
	// find the first node whose data >= value
	Node<T>* lower_bound(Node<T>* p, const T &value)
	{
		Node<T> *x = p, *y = 0;
		while (x)
		{
			if (x->value < value)
			{
				x = x->right;
			}
			else 
			{
				y = x;
				x = x->left;
			}
		}
		
		return y;
	}
	
	// find the first node whose data > value
	Node<T>* upper_bound(Node<T>* p, const T &value)
	{
		Node<T> *x = p, *y = 0;
		while (x)
		{
			if (value < x->value)
			{
				y = x;
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}
		return y;
	}
	
	// find the first node whose data == value
	Node<T>* find(Node<T> *x, const T &value) const
	{
		Node<T> *y = lower_bound(x, value);
		if (y && value < y->value)
		{
			return 0;
		}
		return y;
	}
	
	void deleteTreap(Node<T> *p)
	{
		if (p)
		{
			deleteTreap(p->left);
			deleteTreap(p->right);
			putNode(p);
		}
	}
	
	void leftRotate(Node<T> *x)
	{
		Node<T> *y = x->right;
		x->right = y->left;
		if (y->left)
		{
			y->left->parent = x;
		}
		
		y->left = x;
		
		transplant(x, y);
		
		x->parent = y;
		
		x->recal();
		y->recal();
		
	}
	
	void rightRotate(Node<T> *x)
	{
		Node<T> *y = x->left;
		x->left = y->right;
		if (y->right)
		{
			y->right->parent = x;
		}
		
		y->right = x;
		transplant(x, y);
		x->parent = y;
		
		x->recal();
		y->recal();
	}
	
	void transplant(Node<T>* x, Node<T>* y)
	{
		if (y)
		{
			y->parent = x->parent;
		}
		
		if (x == mRoot)
		{
			mRoot = y;
		}
		else if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
	}
	
	void print(Node<T> *p) const
	{
		if (p)
		{
			print(p->left);
			cout << p->value << " ";
			print(p->right);
		}
	}

};

const int N = 2e5 + 100;


vector<pii> son[N];
int parent[N];
int a[N];
int ans[N];
ll h[N];
Treap<ll> setList[N];
int idx [N];

void dfs(int u)
{
	idx[u] = u;
	for (auto e : son[u])
	{
		int v = e.first;
		int w = e.second;
		h[v] = h[u] + w;
		dfs(v);
		
		if (setList[idx[u]].size() < setList[idx[v]].size())
		{
			swap(idx[u], idx[v]);
		}
		
		// now size(set of u) >= size(set of v)
		while (!setList[idx[v]].empty())
		{
			auto iter = setList[idx[v]].begin();
			setList[idx[u]].insertEqual(iter->value);
			setList[idx[v]].erase(iter);
		}
	}
	Treap<ll> &S = setList[idx[u]];
	//auto iter = S.upper_bound(h[u]);
	//ans[u] = S.lessCount(iter);
	ans[u] = S.lessCount(h[u] + 1);
		
	S.insertEqual(h[u] - a[u]);
}

int main()
{
	// USE_IOSTREAM;
	int n, u, v, i, w;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (i = 2; i <= n; i++)
	{
		scanf("%d%d", &u, &w);
		parent[i] = u;
		son[u].push_back({i, w});
	}
	
	dfs(1);
	
	for (i = 1; i <= n; i++)
	{
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}