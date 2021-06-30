#include "AVL.h"
#include <iostream>
using namespace std;

int AVL::Height(Node* p)
{
	int hl, hr;
	hl = (p && p->Lchild) ? p -> Lchild->height : 0;
	hr = (p && p->Rchild) ? p->Rchild->height : 0;
	return (hl > hr) ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(Node* p)
{
	int hl, hr;
	hl = (p && p->Lchild) ? p->Lchild->height + 1 : 0;
	hr = (p && p->Rchild) ? p->Rchild->height + 1 : 0;
	return hl - hr;
}

Node* AVL::LLRotation(Node* p)
{
	Node* pl = p->Lchild;
	Node* plr = pl->Rchild;
	pl->Rchild = p;
	p->Lchild = plr;

	pl->height = Height(pl);
	p->height = Height(p);

	if (root = p)
		root = pl;	
	return pl;
}

Node* AVL::RRRotation(Node* p)
{
	Node* pr = p->Rchild;
	Node* prl = pr->Lchild;
	pr->Lchild = p;
	p->Rchild = prl;

	pr->height = Height(pr);
	p->height = Height(p);

	if(root == p)
		root = pr;
	return pr;
}
Node* AVL::LRRotation(Node* p)
{
	Node* pl = p->Lchild;
	Node* plr = pl->Rchild;

	pl->Rchild = plr->Lchild;
	p->Lchild = plr->Rchild;
	plr->Rchild = p;
	plr -> Lchild = pl;

	plr->height = Height(plr);
	pl->height = Height(pl);
	p->height = Height(p);

	if (root = p)
		root = plr;
	return plr;
}

Node* AVL::RLRotation(Node* p)
{
	Node* pr = p->Rchild;
	Node* prl = pr->Lchild;

	p->Rchild = prl->Lchild;
	pr->Lchild = prl->Rchild;
	prl->Lchild = p;
	prl->Rchild = pr;
	
	pr->height = Height(pr);
	p->height = Height(p);
	prl->height = Height(prl);

	if (root = p)
		root = prl;
	return prl;
}

void AVL::Inorder(Node* p)
{
	if (p)
	{
		Inorder(p->Lchild);
		cout << p->data << ",";
		Inorder(p->Rchild);
	}
}

Node* AVL:: RInsert(Node* p, int key)
{
	Node* t;
	if (p == nullptr)
	{
		t = new Node;
		t->data = key;
		t->Lchild = nullptr;
		t->Rchild = nullptr;
		t->height = 0;
		return t;
	}
	if (key < p->data)
		p->Lchild = RInsert(p->Lchild, key);
	else if(key > p->data)
		p->Rchild = RInsert(p->Rchild, key);

	//update height
	p->height = Height(p);
	
	//BalanceFactor 
	if (BalanceFactor(p) == 2 && BalanceFactor(p->Lchild) == 1)
		return LLRotation(p);
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->Rchild) == -1)
		return RRRotation(p);
	else if (BalanceFactor(p) == 2 && BalanceFactor(p->Lchild) == -1)
		return LRRotation(p);
	else if (BalanceFactor(p) == -2 && BalanceFactor(p->Rchild) == 1)
		return RLRotation(p);

	return p;
}