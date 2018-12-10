#ifndef __binarytree_h__
#define __binarytree_h__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define maxsize 15
typedef int Datatype;
typedef struct BinaryTreeNode
{
	Datatype data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
	int flag;
}BTNode;

BTNode* BTCreate(Datatype* a, int n, int* pi);//创建一颗二叉树
void BTDestory(BTNode* root);//销毁一节二叉树

int BTSize(BTNode* root);//求该二叉树的所有节点
int BTLeafSize(BTNode* root);//求叶子节点
int BTLevelKSize(BTNode* root, int k);//求第k层的节点

// 遍历  递归&非递归  前中后序求二叉树

typedef struct stack
{
	BTNode* r[maxsize];
	int top;
}Stack;
typedef struct queue
{
	BTNode* r[maxsize];
	int  tail;
	int  head;

}Queue;
void BTPrevOrder(BTNode* root);
void BTInOrder(BTNode* root);
void BTPostOrder(BTNode* root);
int BTLevelOrder(BTNode* root);

void BTPrevOrderNonR(BTNode* root);
void BTInOrderNonR(BTNode* root);
void BTPostOrderNonR(BTNode* root);

BTNode* BTFind(BTNode** pptre, Datatype x);

void TestBinaryTree(); 
void BTChange(BTNode* root);





#endif