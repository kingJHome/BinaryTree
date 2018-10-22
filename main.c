#include <stdio.h>
#include "biTree.h"

//访问二叉树结点
void visitBTree(BiTree *node);

int main(int argc,char *argv[]){
	int btDeep = 0;
	BiTree *header = NULL;

	CreateBiTree(&header, "bitree.txt");
	VisitBiTree(header, visitBTree);
	//获取二叉树深度
	btDeep = DeepBiTree(header);
	printf("二叉树深度为%d\n", btDeep);

	return 0;
}
