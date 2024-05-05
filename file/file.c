#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "datastruct.h"
#include "operate.h"
#include "extgraph.h"
#include "graphics.h"
#include "imgui.h"
#include "file.h"
//保存文件 
void save(char *p)
{

	char path[100]={0};
	char *data=(char *)calloc(1024,sizeof(char));
	data=DataSpace->word;
    int i=0,k=0,l=0;
	bool e=SaveFileDialog("C++\0.cpp\0C\0*.C",path);
	   	if(e){
	   		printf("save ok");
		   }
    

    while(p[i]){
    	int j=0;
    	while(data[l]&&data[l]!='0')
    	{
			if(data[l]=='1'){
    			i++;
			}
    		if(data[l]=='2'){
    			i=i+2;
			}
			l++;

		}

    	char *temp=(char*)calloc((i-k),sizeof(char));
    	for(j=0;j<(i-k);j++){
    		temp[j]=p[k+j];
		}

      SaveYourFileAdd(path, temp);
    	
    	free(temp);
    	k=i;
    	l++;
	
	} 
	    
 
 } 
void SaveYourFileAdd(char *path, char *s)
{
    FILE *fp;
    char *t="\n";
    if ((fp = fopen(path, "a")) == NULL) {
                        printf("Open the file failure...\n");
                        exit(-1);
                }
    fputs(s,fp);
     fputs(t,fp);
    fclose(fp);
    printf("\n");
    return 0;
}



//打开文件 
void openfile()
{	
	char *main=(char* )calloc(1024,sizeof(char));
	FILE *fp;
	int i=0;
	char path[256]={0};

	bool e=OpenFileDialog(NULL,path);
	if((fp=fopen(path,"r"))==NULL){
		 printf("Can not open the file..\n");
        exit(-1);
	}
	char c;	
	do{
		c=fgetc(fp);
		if(feof(fp)){
			break;
		}
		main[i]=c;

		i++;
	}	while(1);

	fclose(fp);
	printf("mainspace in open:%s\n",main);
int len=strlen(main); 
	char *data =(char*)calloc(len,sizeof(char));
	write_dataspace(main,data);
	correct_dataspace(data);
	main=delchar(main);
	printf("data:%s\nmain:%s\n",data,main);
	int lenmain=strlen(main);
	int lendata=strlen(data);
	int j=0;
	for(j=0;j<lenmain;j++){
		GB_insert(MainSpace, main[j]);
		
	}
	
		for(j=0;j<lendata;j++){
		GB_insert(DataSpace, data[j]);
		
	}			
}

int is_chinese(char p)
{

	if (~(p >> 8) == 0)  //将p字节进行移位运算，右移8位，这样，如果移位后是0，则说明原来的字节最高位为0，不是1那么也就不是汉字的一个字节。
	{
	 return 1;  //代表是汉字
	}

	return 0;
}

char* delchar(char* str) {//去掉换行 
	int i, j, cnt =0;
	int len = strlen(str);
	for (i = len - 1; i >= 0; i--) {
		if (str[i] == '\n') {
			for (j = i; j < len- cnt; j++) {
				str[j] = str[j + 1];
			}
			cnt++;
		}

	}
	return str;

}

int Is_Chinese(char p)
{

	if (~(p >> 8) == 0)  //将p字节进行移位运算，右移8位，这样，如果移位后是0，则说明原来的字节最高位为0，不是1那么也就不是汉字的一个字节。
	{
		return 1;  //代表是汉字
	}

	return 0;
}
void write_dataspace(char* s,char *t) {
	int i = 0;

	while (s[i]) {
		if (s[i] == '\n') {
			t[i] = '0'; i++;
		}
		else if (is_chinese(s[i])) {
			t[i] = '2'; i = i + 1;
		}
		else {
			t[i] = '1'; i++;
		}
		printf("t[%d]:%s\n", i, t);


	}

}
char * correct_dataspace(char* str) {
	int i, j, cnt = 0;
	int len = strlen(str);
	for (i = len - 1; i >= 0; i--) {
		if (str[i] == '2') {
			for (j = i; j < len - cnt; j++) {
				str[j] = str[j + 1];
			}
			cnt++;
			i--;
		}

	}
	return str;
}

