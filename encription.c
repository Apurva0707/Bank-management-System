#include<stdio.h>
#include<conio.h>
#include<string.h>
void encrypt(int password[],int no)
{
    unsigned int i;
    for(i=0;i<strlen(password);i++)
    {
        password[i]=password[i]-no;
    }
}
void decrypt(int password[],int no)
{
    unsigned int i;
    for(i=0;strlen(password);i++)
    {
        password[i]=password[i]+no;
    }
}
void main()
{
    int password[10];
    printf("\n enter password:");
    scanf("%d",password);
    printf("\n password=%d",password);
    encrypt(password,0xFACE);
    printf("\n encrypted value=%dn",password);
    decrypt(password,0xFACE);
    printf("\n decrypted value=%dn",password);
    return;
}
