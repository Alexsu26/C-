#include <stdio.h>
#define maxn 100
int main(int argc, char const *argv[])
{
	FILE *fp;
	fp = fopen("test.txt","r");
 	char buf[maxn];
 	fgets(buf,maxn,fp);
 	puts(buf);
 	fclose(fp);
    return 0;
}
