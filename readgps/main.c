#include<stdio.h>
int main(int argc, const char* argv[])
{
    char a[100];
    FILE *fr;
    fr = fopen("//Users//a20161104616//Desktop//readgps//GPS170510.log", "r+");
    fscanf(fr, "%s",a);
    printf("%s\n",a);
    fclose(fr);
    return 0;
}
