#include <stdio.h>
#include "biTree.h"

//读取文件内容
char* fileContent(FILE *fp);
//去除换行或制表符
char* removeNewLineFlag(char *content);
//访问二叉树结点
void visitBTree(BiTree *node);

int main(int argc,char *argv[]){
	FILE *fp = fopen("bitree.txt", "r");
	
	if( fp ){
		int btDeep = 0;
		BiTree *header = NULL;
		char *content = fileContent(fp);
		
		content = removeNewLineFlag(content);
		CreateBiTree(&header, content);
		VisitBiTree(header, visitBTree);
		printf("\n");
		//获取二叉树深度
		btDeep = DeepBiTree(header);
		printf("二叉树深度为%d\n", btDeep);
	}

	return 0;
}

//读取文件内容
char* fileContent(FILE *fp){
	char *ct = NULL,*rt = NULL;
	size_t glen = 0;
	
	if( getline(&ct, &glen, fp) != -1 ){
		glen = 0;
		rt = strdup(ct);

		while( getline(&ct, &glen, fp) != -1 ){
			glen = 0;
			strcat(rt, ct);
		}
	}

	return rt;
}

//去除换行或制表符
char* removeNewLineFlag(char *content){
	char sepes[] = "\r\n\t";
	size_t cur = 0;

	while( cur < strlen(content) ){
		if( strchr(sepes, content[cur]) ){//为换行或制表符
			size_t curlen = strlen(content);

			for(size_t i = cur; i < curlen; ++i){
				content[i] = content[i+1];
			}
		}else{
			cur++;
		}
	}

	return content;
}

void visitBTree(BiTree *node){
	printf("%c\t", node->flag);
}
