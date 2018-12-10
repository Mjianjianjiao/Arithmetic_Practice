#include "binarytree.h"
BTNode*  BuyNode(Datatype x)
{
	BTNode* node =(BTNode*)malloc(sizeof(BTNode));
	node->left = NULL;
	node->right = NULL;
	node->data = x;
	node->flag = 0;
	return node;
}
BTNode* BTCreate(Datatype* a,int n, int* pi)
{
	assert(pi);
	BTNode* root;
	if (*pi >= n)
		return NULL;
	if (a[*pi] != '#')
	{
		BTNode* root = BuyNode(a[*pi]);
		++(*pi);
		root->left = BTCreate(a, n, pi);
		++(*pi);
		root->right = BTCreate(a, n, pi);
		return root;
	}
	else return NULL;

}
void BTDestory(BTNode** pptre)  //其地址进行销毁
{
	assert(pptre);

	if ((*pptre) == NULL)
		return;
	BTDestory(&(*pptre)->left);
	BTDestory(&(*pptre)->right);
	free(*pptre);
    *pptre= NULL;
}

int BTSize(BTNode* root)  //求节点个数
{
	if (root != NULL)
		return BTSize(root->left) + BTSize(root->right) + 1;
	else
		return 0;
}

int BTLeafSize(BTNode* root)    //求叶子节点个数
{
	if (root == NULL)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	
	return BTSize(root->left) + BTSize(root->right);
}
int BTLevelKSize(BTNode* root, int k)   //求第k层节点个数
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BTLevelKSize(root->left, k - 1) + BTLevelKSize(root->right, k - 1);
}

//递归遍历前中后序
void BTPrevOrderNonR(BTNode* root)
{
	if (root == NULL)
		return 0;
	printf("%d ",root->data);
	BTPrevOrderNonR(root->left);
	BTPrevOrderNonR(root->right);
}
void BTInOrderNonR(BTNode* root)
{
	if (root == NULL)
		return 0;
	BTInOrderNonR(root->left);
	printf("%d ", root->data);
	BTInOrderNonR(root->right);

}

void BTPostOrderNonR(BTNode* root)  
{
	if (root == NULL)
		return 0;
	BTPostOrderNonR(root->left);
	BTPostOrderNonR(root->right);
	printf("%d ", root->data);

}


void BTPrevOrder(BTNode* root)   //前序遍历非递归
{
	Stack S;
	Stack* s = &S;
	Stack* t;
	s->top = -1;
	if (root == NULL)
		printf("树空");
	while (root != NULL||s->top != -1)
	{
		while (root != NULL&&s->top < maxsize)
		{
			printf("%d ", root->data);
			s->top++;
			s->r[s->top] = root;
			root = root->left;
		}
		if (s->top >= 0)
		{
			root = s->r[s->top--];
			root = root->right;
		}
	}


}



void BTInOrder(BTNode* root)  //中序遍历非递归
{
	Stack S;
	Stack* s = &S;
	Stack* t;
	s->top = -1;
	if (root == NULL)
		printf("树空");
	while (root != NULL || s->top != -1)
	{
		while (root != NULL&&s->top < maxsize)
		{
			s->top++;
			s->r[s->top] = root;
			root = root->left;
		}
		if (s->top >= 0)
		{
			root = s->r[s->top--];
			printf("%d ", root->data);
			root = root->right;
		}
	}

}
void BTPostOrder(BTNode* root)  //非递归后续遍历
{
	Stack S;
	Stack* s = &S;
	Stack* t;
	BTNode* tmp=NULL;
	s->top = -1;
	if (root == NULL)
		printf("树空");
	while (root != NULL || s->top != -1)
	{
		while (root != NULL&&s->top < maxsize)    //先将所有的左节点入栈
		{
			s->top++;
			s->r[s->top] = root;
			root = root->left;
		}
		BTNode* top = s->r[s->top];    //取出栈顶元素


	//设定一个标记指针，如果访问过右节点，则将指针指向该节点
			if (top->right== NULL || top->right == tmp)  //如果栈顶右节点为空，直接将下一个节点出栈访问。如果不为空，而且右节点已经访问过，则访问中间节点
			{
			
				printf("%d ", top->data);
				tmp = top;
				s->top--;  //访问过后将节点出栈
			}
			else
			{
				root = top->right;   //如果右节点不为空，且未访问过就将右节点入栈
			}
	}
}
int BTLevelOrder(BTNode* root)   //层次遍历求叶子节点个数
{
	assert(root);
	int size = 0;
	Queue t;
	Queue* q = &t;
	 q->tail = -1;
	 q->head = -1;

	 q->tail++;
	 q->r[q->tail] = root;
	 while (q->head != q->tail)
	 {
		 q->head++;
		 if (q->r[q->head]->left == NULL&&q->r[q->head]->right == NULL)
			 size++;
		 if (q->r[q->head]->left!=NULL)
		 q->r[++q->tail] = q->r[q->head]->left;
		 if (q->r[q->head]->right != NULL)
		 q->r[++q->tail] = q->r[q->head]->right;
	 }
	 return size;
}

void BTWC(BTNode* root)  //判断是否为完全二叉树
{
	Queue t;
	Queue* q = &t;
	if (root == NULL)
		perror("false");
	q->tail = -1;
	q->head = -1;
	q->r[++q->tail] = root;
	while (q->head != q->tail)
	{
		q->head++;
		if (q->r[q->head] == NULL)
		{
			while (q->head != q->tail)
			{
				q->head++;
				if (q->r[q->head] != NULL)
				{
					printf("不是完全二叉树\n");
					return;
				}
			}
			printf("是完全二叉树\n");
			return;
		}
		else
		{
			q->r[++q->tail] = q->r[q->head]->left;
			q->r[++q->tail] = q->r[q->head]->right;
		}

	}

}
BTNode* BTFind(BTNode* root,Datatype x)  //查找数据
{
	BTNode* ret ;

	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	ret = BTFind(root->left, x);
	if (ret)
		return ret;
	ret = BTFind(root->right, x);
	if (ret)
		return ret;

	return NULL;
}

int BTHeight(BTNode* root)  //求二叉树高度
{
	int lefthigh;
	int righthigh ;
	if (root == NULL)
	return 0;
	lefthigh = BTHeight(root->left) ;
	righthigh = BTHeight(root->right);

	return  lefthigh > righthigh ? lefthigh + 1 : righthigh + 1;
}

void BTChangeR(BTNode* root)   //递归二叉树镜像
{
	BTNode* t;
	if (root == NULL)
		return;
	if (root)
	{
		t = root->left;
		root->left = root->right;
		root->right = t;
	}
	BTChange(root->left);
	BTChange(root->right);
}

void BTChange(BTNode* root)  //非递归二叉树镜像
{
	Queue p;
	Queue* q;
	BTNode* t=NULL;
	q = &p;
	BTNode* tmp=NULL;
	q->head = -1;
	q->tail = -1;

	q->tail++;
	q->r[q->tail] = root;

	while (q->head != q->tail)
	{
		q ->head++;
		t = q->r[q->head];
		if (t)
		{
			tmp = t->right;
			t->right = t->left;
			t->left =tmp;

			q->r[++q->tail] = t->left;
			q->r[++q->tail] = t->right;
		}
		else
			break;
	}

}