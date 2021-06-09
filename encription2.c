#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int password[10];
    int i,len=0;
    printf("\n Enter your password:");
    scanf("%d",&password);
    len=strlen(password);
    printf("\n your encrypted password is:");
    for(i=0;i<len;i++)
        printf("%d",password[i]+8);
    return;
}
