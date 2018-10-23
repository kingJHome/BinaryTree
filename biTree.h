#ifndef _MYBINARY_TREE
#define _MYBINARY_TREE

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct bitree{
	char flag;
	struct bitree *parent,*lchild,*rchild;
}BiTree;

typedef void (*VisitNode)(BiTree*);

//通过文件构建二叉树
void CreateBiTree(BiTree **header,char *content);

//获取二叉树深度
int DeepBiTree(BiTree *bt);

//获取二叉树上的某个结点
BiTree* GetANode(BiTree *header,char flag);

//插入结点
void InsertANode(BiTree *header,char flag);

//删除某个结点
BiTree* DeleteANode(BiTree *header,char flag);

//访问二叉树
void VisitBiTree(BiTree *header,VisitNode vtNode);
#endif
