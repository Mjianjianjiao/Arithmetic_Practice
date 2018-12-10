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

BTNode* BTCreate(Datatype* a, int n, int* pi);//����һ�Ŷ�����
void BTDestory(BTNode* root);//����һ�ڶ�����

int BTSize(BTNode* root);//��ö����������нڵ�
int BTLeafSize(BTNode* root);//��Ҷ�ӽڵ�
int BTLevelKSize(BTNode* root, int k);//���k��Ľڵ�

// ����  �ݹ�&�ǵݹ�  ǰ�к����������

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