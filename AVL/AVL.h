#pragma once
class Node
{
public:
	Node* Lchild;
	int data;
	int height;
	Node* Rchild;
};
class AVL
{
private:
	Node* root;
public:
	AVL() { root = nullptr; }
	int Height(Node* p);
	int BalanceFactor(Node* p);
	Node* LLRotation(Node* p);
	Node* RRRotation(Node* p);
	Node* LRRotation(Node* p);
	Node* RLRotation(Node* p);
	Node* RInsert(int key) { root = RInsert(root, key); return root; }
	Node* RInsert(Node* p,int key);
	void Inorder() { Inorder(root); }
	void Inorder(Node* p);
};

