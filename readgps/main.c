#include<stdio.h>
#include<stdlib.h>
int main(int argc, const char* argv[])
{
    char a[100];
    char b[100];
    char lat[9],lon[9],spe[6],course[6],day[7],time[7];//lat纬度 lon经度 spe速度 course航向 day年月日 time时间
    FILE *fr,*fw;
    int i,n,m,k,timebig,timesmile;//timebig年月日循环变量 timesmile时间循环变量
    int numbig,numsm;//年月日转换变量
    fr = fopen("//Users//a20161104616//Desktop//readgps//GPS170510.log", "r+");
    if(fr==NULL)
        printf("fr文件打开失败\n");

    fw = fopen("//Users//a20161104616//Desktop//readgps//GPS.csv", "w+");
    if(fw==NULL)
        printf("fw文件打开失败\n");

    fscanf(fr, "%s%s",a,b);
    printf("%s\n%s\n",a,b);
    for(i=0;i<8;i++)
        lat[i]=a[i+16];
    lat[8]='\0';
    printf("纬度：%s\n",lat);
    for(n=0;n<8;n++)
        lon[n]=a[n+27];
    lon[8]='\0';
    printf("经度：%s\n",lon);
    for(m=0;m<6;m++)
        spe[m]=a[m+39];
    spe[5]='\0';
    printf("速度(节):%s\n",spe);
    for(k=0;k<6;k++)
        course[k]=a[k+45];
    course[5]='\0';
    printf("航向:%s\n",course);
    for(timebig=0;timebig<6;timebig++)
        day[timebig]=a[timebig+51];
    day[6]='\0';
    printf("日期utc:%s\n",day);
    fclose(fr);
    numbig = atoi(day);//字符串转换为整数
    printf("%d\n",numbig);
    for(timesmile=0;timesmile<8;timesmile++)
        time[timesmile]=a[timesmile+7];
    time[6]='\0';
    numsm = atoi(time);
    if(numsm>=24000)
    {
        numsm=numsm-24000;
        numbig=numbig+10000;
    }
    printf("时间：%d\n",numsm+8000);
    fprintf(fw,"%s,%s,%s,%s,%d,%d\n",lat,lon,spe,course,numbig,numsm );
    fclose(fw);
    fclose(fr);
    return 0;
}
