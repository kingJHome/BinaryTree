#include "biTree.h"

//通过文件构建二叉树
void CreateBiTree(BiTree **header,char *content){
	if( *header == NULL ){
		*header = (BiTree*)malloc(sizeof(BiTree));	
	}

	BiTree *curHeader = *header;
	size_t clen = strlen(content);
		
	if( curHeader && clen ){
		size_t curPos = 0,stackPos = 0;
		BiTree *stack[clen];
		char flagStack[clen];
		
		for(size_t i = 0; i < clen; ++i){
			if( isalpha(content[i]) ){
				if( stackPos==0 ){
					curHeader->flag = content[i];
					curHeader->parent = curHeader->lchild = curHeader->rchild = NULL;
					stack[stackPos++] = curHeader;
				}else{
					BiTree *newTree = (BiTree*)malloc(sizeof(BiTree));
					if( newTree ){
						newTree->flag = content[i];
						newTree->lchild = newTree->rchild = NULL;
						newTree->parent = stack[stackPos-1];
						if( flagStack[curPos-1]=='{' && flagStack[curPos-2]==':' ){//左子树
							stack[stackPos-1]->lchild = newTree;
							stack[stackPos++] = newTree;
						}else if( flagStack[curPos-1]==','&&(flagStack[curPos-2]=='{' || flagStack[curPos-2]==':')){//右子树
							stack[stackPos-1]->rchild = newTree;
							stack[stackPos-1] = newTree;
						}
					}
				}
			}else{ 
				switch( content[i] ){
					case '{': case ':': case ',':
						flagStack[curPos++] = content[i];
						if( content[i]==',' ){
							--stackPos;
						}
						break;
					case '}':
						for( ; flagStack[curPos-1]!='{'; --curPos);
						--curPos;
						break;
				}
			}
		}
	}
}

//获取二叉树深度
int DeepBiTree(BiTree *bt){
}

//获取二叉树上的某个结点
BiTree* GetANode(BiTree *header,char flag){
}

//插入结点
void InsertANode(BiTree *header,char flag){
}

//删除某个结点
BiTree* DeleteANode(BiTree *header,char flag){
}

//访问二叉树(中序遍历)
void VisitBiTree(BiTree *header,VisitNode vtNode){
	if( header ){
		VisitBiTree(header->lchild,vtNode);
		vtNode(header);
		VisitBiTree(header->rchild,vtNode);
	}
}
