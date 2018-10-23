#ifndef _MYBINARY_TREE
#define _MYBINARY_TREE

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define Maxi(a,b) ((a)>=(b)?(a):(b))

typedef struct bitree{
	char flag;
	struct bitree *parent,*lchild,*rchild;
}BiTree;

typedef void (*VisitNode)(BiTree*);

//通过文件构建二叉树
void CreateBiTree(BiTree **header,char *content);

//获取树结点数目(递归)
int GetTreeNodeNum(BiTree *bt);

//获取二叉树深度(递归)
int DeepBiTree(BiTree *bt);

//访问二叉树
void VisitBiTree(BiTree *header,VisitNode vtNode);
#endif
