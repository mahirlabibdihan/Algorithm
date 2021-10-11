#include <stdio.h>
#include <string.h>

int main(){
	char* s= malloc(133);
	for(int i=0;i<133;i++){
		s[i]='\0';
	}
	for(int i=0;i<133;i++){
		s[i]='0';
		printf("%s %d\n",s,i);
	}
}