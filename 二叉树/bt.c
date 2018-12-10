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
void BTDestory(BTNode** pptre)  //���ַ��������
{
	assert(pptre);

	if ((*pptre) == NULL)
		return;
	BTDestory(&(*pptre)->left);
	BTDestory(&(*pptre)->right);
	free(*pptre);
    *pptre= NULL;
}

int BTSize(BTNode* root)  //��ڵ����
{
	if (root != NULL)
		return BTSize(root->left) + BTSize(root->right) + 1;
	else
		return 0;
}

int BTLeafSize(BTNode* root)    //��Ҷ�ӽڵ����
{
	if (root == NULL)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	
	return BTSize(root->left) + BTSize(root->right);
}
int BTLevelKSize(BTNode* root, int k)   //���k��ڵ����
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BTLevelKSize(root->left, k - 1) + BTLevelKSize(root->right, k - 1);
}

//�ݹ����ǰ�к���
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


void BTPrevOrder(BTNode* root)   //ǰ������ǵݹ�
{
	Stack S;
	Stack* s = &S;
	Stack* t;
	s->top = -1;
	if (root == NULL)
		printf("����");
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



void BTInOrder(BTNode* root)  //��������ǵݹ�
{
	Stack S;
	Stack* s = &S;
	Stack* t;
	s->top = -1;
	if (root == NULL)
		printf("����");
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
void BTPostOrder(BTNode* root)  //�ǵݹ��������
{
	Stack S;
	Stack* s = &S;
	Stack* t;
	BTNode* tmp=NULL;
	s->top = -1;
	if (root == NULL)
		printf("����");
	while (root != NULL || s->top != -1)
	{
		while (root != NULL&&s->top < maxsize)    //�Ƚ����е���ڵ���ջ
		{
			s->top++;
			s->r[s->top] = root;
			root = root->left;
		}
		BTNode* top = s->r[s->top];    //ȡ��ջ��Ԫ��


	//�趨һ�����ָ�룬������ʹ��ҽڵ㣬��ָ��ָ��ýڵ�
			if (top->right== NULL || top->right == tmp)  //���ջ���ҽڵ�Ϊ�գ�ֱ�ӽ���һ���ڵ��ջ���ʡ������Ϊ�գ������ҽڵ��Ѿ����ʹ���������м�ڵ�
			{
			
				printf("%d ", top->data);
				tmp = top;
				s->top--;  //���ʹ��󽫽ڵ��ջ
			}
			else
			{
				root = top->right;   //����ҽڵ㲻Ϊ�գ���δ���ʹ��ͽ��ҽڵ���ջ
			}
	}
}
int BTLevelOrder(BTNode* root)   //��α�����Ҷ�ӽڵ����
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

void BTWC(BTNode* root)  //�ж��Ƿ�Ϊ��ȫ������
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
					printf("������ȫ������\n");
					return;
				}
			}
			printf("����ȫ������\n");
			return;
		}
		else
		{
			q->r[++q->tail] = q->r[q->head]->left;
			q->r[++q->tail] = q->r[q->head]->right;
		}

	}

}
BTNode* BTFind(BTNode* root,Datatype x)  //��������
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

int BTHeight(BTNode* root)  //��������߶�
{
	int lefthigh;
	int righthigh ;
	if (root == NULL)
	return 0;
	lefthigh = BTHeight(root->left) ;
	righthigh = BTHeight(root->right);

	return  lefthigh > righthigh ? lefthigh + 1 : righthigh + 1;
}

void BTChangeR(BTNode* root)   //�ݹ����������
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

void BTChange(BTNode* root)  //�ǵݹ����������
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