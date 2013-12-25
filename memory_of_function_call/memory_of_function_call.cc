// how to watch stack in memory, reference http://www.tenouk.com/Bufferoverflowc/Bufferoverflow2a.html
#include<stdio.h>

int fn(int param0, char param1){
	int local0 = 9;
	char local1 = 'Z';
	return 1;
}

int main(int argc, char *argv[]){
	int result = fn(7, 'a');
	return 0;
}

