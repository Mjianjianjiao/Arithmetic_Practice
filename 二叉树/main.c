#include "binarytree.h"
void TestBinaryTree()
{

	Datatype a[] = { 1, 2, 4, '#', '#', 5, '#', '#', 3, 6, '#','#',7,'#','#' }  /*  a[] = {1,2,4,'#',3,'#',5}*/;
	int* pi = 0;
	int n = sizeof(a) / sizeof(a[0]);
	int t1, t2, t3;

	BTNode* root = BTCreate(a,n, &pi);
	/*BTChange(root);*/
	/*BTDestory(&root);*/
	/*BTWC(root);*/
	/*BTPostOrder(root);
	printf("\n")*/;
	/*t1=BTSize(root);
	t2=BTLeafSize(root);
	t3=BTLevelKSize(root,3);
	printf("%d\n", t1);
	printf("%d\n", t2);
	printf("%d\n", t3);*/
	/*BTPostOrderNonR(root);*/
	/*printf("%d",BTLevelOrder(root));*/
	/*printf("%d\n", BTFind(root, 3)->data);*/
	/*t1=BTHeight(root);*/
	/*BTPrevOrder(root);*/
	/*printf("%d", t1);*/
	BTPostOrder(root);
}

int main()
{

	TestBinaryTree();

}