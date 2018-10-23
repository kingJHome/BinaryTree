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

//获取树结点数目
int GetTreeNodeNum(BiTree *bt){
	if( bt ){
		int lnum = GetTreeNodeNum(bt->lchild),
			rnum = GetTreeNodeNum(bt->rchild);

		return (1 + lnum + rnum);
	}else{
		return 0;
	}
}

//获取二叉树深度(递归)
int DeepBiTree(BiTree *bt){
	if( bt ){
		int lnum = DeepBiTree(bt->lchild),
			rnum = DeepBiTree(bt->rchild);

		return (1 + Maxi(lnum,rnum));
	}else{
		return 0;
	}	
}

//访问二叉树(中序遍历)
void VisitBiTree(BiTree *header,VisitNode vtNode){
	if( header ){
		VisitBiTree(header->lchild,vtNode);
		vtNode(header);
		VisitBiTree(header->rchild,vtNode);
	}
}
