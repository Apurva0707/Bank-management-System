#include<time.h>
#include<windows.h>
#include<unistd.h>
typedef struct account
{
    char phone[10];
    int age;
    char name[20];
    char addhar[40];
    char address[60];
    int state;
    int acno;
    int opnbal;

}ACCT;
typedef struct balance
{
     int money;
    int n_o;

}BAL;
typedef struct pin//6 bytes
{
    char pin[4];
    int acnum;
    int state;

}PIN;
PIN sec;
FILE *fc,*fa,*op;
ACCT ac;
BAL bal;


void add()
{   system("cls");
    fseek(op,0,SEEK_END);
    int i=0;
    int no,pos=0;
    while(1)
    {
    printf("\nEnter account no: ");
    scanf("%d",&no);
    pos=search_(no);
    if(pos>=0)
    {   system("cls");
        printf("\nAccount already exists!!");

    }
    else
        break;
    }
     if(pos==-1)
     {



     ac.acno=no;
    printf("_______________ACCOUNT_____________\n\n\n");
    printf("\nEnter account holder's name: ");
    fflush(stdin);
    scanf("%[^\n]s",ac.name);
   do{
            i=0;
        printf("\nEnter phone number: ");
       fflush(stdin);
       scanf("%s",ac.phone);
        if(strlen(ac.phone)<10||strlen(ac.phone)>10)
        printf("\nInvalid phone no!!");
        else
        {
            while(i<10)
            {
                if(ac.phone[i]>=48&&ac.phone[i]<=57)
                    i++;
                else
                    break;

            }
            if(i==10)
                break;
            else
                printf("\nInvalid phone number");

        }

    }while(1);
       do{
    printf("\nEnter age: ");
    fflush(stdin);
    scanf("%d",&ac.age);
    if(ac.age<18)
    printf("\nInvalid!!");
    else
        break;
       }while(1);
    printf("\nEnter address(address should not be greater than twenty characters) : ");
    fflush(stdin);
    scanf("%[^\n]s",ac.address);

    do{
            i=0;
        printf("\nEnter addhar number: ");
       fflush(stdin);
       scanf("%s",ac.addhar);
        if(strlen(ac.addhar)<12||strlen(ac.addhar)>12)
        printf("\nInvalid addhar no!!");
        else
        {
            while(i<12)
            {
                if(ac.addhar[i]>=48&&ac.addhar[i]<=57)
                    i++;
                else
                    break;

            }
            if(i==12)
                break;
            else
                printf("\nInvalid addhar number");

        }

    }
       while(1);
    do
    {
        bal.n_o=ac.acno;
        printf("\nOpening Balance:");
        scanf("%d",&ac.opnbal);
        bal.money=ac.opnbal;
        if(ac.opnbal<500)
            printf("\nInvalid Amount");
        else break;
    }while(1);
    ac.state=1;
    printf("\n\n____________________________________________\n\n");
    fwrite(&ac,sizeof(ACCT),1,fa);
    fwrite(&bal,sizeof(BAL),1,op);
    //fprintf(op,"%d\n%d\n",bal.n_o,bal.money);
    printf("\nACCOUNT ADDED SUCCESSFULLY!!!.....DEAR CUSTOMER ,REMEMBER YOUR ACCOUNT NUMBER,\n Your Account Number is : %d ",ac.acno);

     }
     //withdraw_(no);
}
void withdraw_()
{   int no=0,tmp,cnt=0;
    int money,flg=0;
    rewind(op);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter Account Number: ");
    scanf("%d",&no);
    while(1)
    {
        //fscanf(op,"%d\n%d",&bal.n_o,&bal.money);
        fread(&bal,sizeof(BAL),1,op);

        if(bal.n_o==no)
            break;
    }
    printf("\nAvailable balance %d\n",bal.money);
    tmp=bal.money;
    while(tmp>0)
    {
        tmp/=10;
        cnt++;

    }
    while(1)
    {
    printf("\nEnter amount: ");
    fflush(stdin);
    scanf("%d",&money);
    if(money>=bal.money)
    {
        printf("\nInsufficient balance\n");
        continue;
    }
    else
        {
            flg=1;
            break;
        }

    }
    if(flg==1)

    {     fseek(op,-sizeof(BAL),SEEK_CUR);

          bal.money=bal.money-money;
    printf("\nRemaining balance : %d",bal.money);

    fwrite(&bal,sizeof(BAL),1,op);
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tWITHDRAWAL PROCESS SUCCESSFULL\n");
    }


}
void deposit_()
{   int no=0,tmp,cnt=0;
    int money,flg=0;
    rewind(op);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter Account Number: ");
    scanf("%d",&no);
    while(1)
    {
        //fscanf(op,"%d\n%d",&bal.n_o,&bal.money);
        fread(&bal,sizeof(BAL),1,op);

        if(bal.n_o==no)
            break;
    }
    printf("\nAvailable balance %d\n",bal.money);


    printf("\nEnter amount: ");
    fflush(stdin);
    scanf("%d",&money);

    fseek(op,-sizeof(BAL),SEEK_CUR);

          bal.money=bal.money+money;
    printf("\nupdated balance : %d",bal.money);

    fwrite(&bal,sizeof(BAL),1,op);
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tDEPOSIT PROCESS SUCCESSFULL\n");
    }










int search_(int no)
{

    int pos=0;
    rewind(fa);//this is a library fn .the fn call shifts the file pointer fa to the byte 0 from begin of the file
    //(SEEK_SET the function allows to use 3 cont SEEK_SET=begin position
       //SEEK_cur=current position ,SEEK_END = end position.

       while(1)
       {
           fread(&ac,sizeof(ACCT),1,fa);
           if(feof(fa))
           {

               pos=-1;
               break;

           }
           if(ac.acno==no)
            break;
            pos=ftell(fa);//library returns present file pointer position in bytes from begin of the file


       }
       return pos;


}
void update(int no)
{
     int i=0;
     printf("_______________ACCOUNT_____________\n\n\n");
    printf("\nEnter account holder's name: ");
    fflush(stdin);
    scanf("%[^\n]s",ac.name);
   do{
            i=0;
        printf("\nEnter phone number: ");
       fflush(stdin);
       scanf("%s",ac.phone);
        if(strlen(ac.phone)<10||strlen(ac.phone)>10)
        printf("\nInvalid phone no!!");
        else
        {
            while(i<10)
            {
                if(ac.phone[i]>=48&&ac.phone[i]<=57)
                    i++;
                else
                    break;

            }
            if(i==10)
                break;
            else
                printf("\nInvalid phone number");

        }

    }
       while(1);
       do{
    printf("\nEnter age: ");
    fflush(stdin);
    scanf("%d",&ac.age);
    if(ac.age<18)
    printf("\nInvalid!!");
    else
        break;
       }while(1);
    printf("\nEnter address(address should not be greater than twenty characters) : ");
    fflush(stdin);
    scanf("%[^\n]s",ac.address);

    do{
            i=0;
        printf("\nEnter addhar number: ");
       fflush(stdin);
       scanf("%s",ac.addhar);
        if(strlen(ac.addhar)<12||strlen(ac.addhar)>12)
        printf("\nInvalid addhar no!!");
        else
        {
            while(i<12)
            {
                if(ac.addhar[i]>=48&&ac.addhar[i]<=57)
                    i++;
                else
                    break;

            }
            if(i==12)
                break;
            else
                printf("\nInvalid addhar number");

        }

    }
       while(1);
    do
    {
        printf("\nOpening Balance:");
        scanf("%d",&ac.opnbal);
        if(ac.opnbal<500)
            printf("\nInvalid Amount");
        else break;
    }while(1);
    ac.state=1;
    printf("\n\n____________________________________________\n\n");
    fwrite(&ac,sizeof(ACCT),1,fa);
    printf("\nACCOUNT ADDED SUCESSFULLY!!!.....DEAR CUSTOMER ,REMEMBER YOUR ACCOUNT NUMBER,\n Your Account Number is : %d ",ac.acno);

}
void modify()
{
    system("cls");
    int no,pos;
    printf("\nEnter A/c No:");
    scanf("%d",&no);
    pos=search_(no);
    if(pos==-1)
    {
        printf("\nRecord Not found");
        return;
    }
    if(ac.state==0)
    {
        printf("\nRecord Deleted .....can't Modify");
        return;
    }
    update(no);
    fseek(fa,pos,SEEK_SET);
    fwrite(&ac,sizeof(ACCT),1,fa);
}
void displayall()
{
    rewind(fa);//library function shifts the file pointer to the begin position
    while(1)
    {
        fread(&ac,sizeof(ACCT),1,fa);
        if(feof(fa))
            break;
        display();
    }
    return;

}

void display()//admin
{

    printf("\nAccount details\n");
    printf("\nA/c No: %d\name :%s\nOpening Bal: %d\nphone no: %s\naddhar no: %s\nage: %d\naddress: %s\nState:%d",ac.acno,ac.name,ac.opnbal,ac.phone,ac.addhar,ac.age,ac.address,ac.state);
    return;
}
void viewbal(int no)//user
{
   printf("\n_______________VIEW ACCOUNT BALANCE_________________ \n\n");
    rewind(fa);
    while(1)
    {
        fread(&ac,sizeof(ACCT),1,fa);
        if(feof(fa))
            break;
        if(no==ac.acno)
            break;

    }
    fflush(stdout);
    printf("\n\n Account Balance : %d",ac.opnbal);


}
/*void user()
{


                while(1)
            	{
            		if(opt>4)
            		printf("\n\nINVALID CHOICE!!.....PLZ ENTER A CORRECT CHOICE");
            		printf("\n\n\n1.> VIEW ACCOUNT BALANCE\n2.> VIEW E PASSBOOK\n3.> WITHDRAW\n4.> DEPOSIT\n5.> LOGOUT\nEnter your choice:  ");
            		fflush(stdin);
            		scanf("%d",&opt);
            		if(opt>5)
            		{

            			continue;
					}
					if(opt==5)
                    break;
            		switch(opt)
            		{
            			case 1:
                        viewbal(k);

            			 break;
            			case 2:

            			 break;
            			case 3:
            			    withdraw(k);
            			 break;
            			case 4:
            			    deposit(k);
            			 break;


                    }



                }

}
else {
    printf("\nincorrect username or password");
}

}*/
/*void createpin()
{




}*/
void createpin(int no)
{
    int pos=0;char pin[4];int flg=0;
    pos=search_(no);
    if(pos>=0)
    {
        while(1)
        {
            fread(&sec,sizeof(PIN),1,fc);
            if(feof(fc))
                break;
            if(sec.state==1&&sec.acnum==no)
               {
                   flg=1;
                    break;
               }
        }
        if(flg==0)
        {
        fseek(fc,0,SEEK_END);
        sec.acnum=no;
        printf("\nCREATE PIN:: ");
        scanf("%s",sec.pin);
        sec.state=1;
        fwrite(&sec,sizeof(PIN),1,fc);

        }
        else
        {
            printf("\nYour sign in is already created\n ");

        }


    }
    else
    {
        printf("\naccount not found");
    }

}




void viewpassbook(int no)
{   int flg;
    rewind(fa);
    while(1)
    {
        fread(&ac,sizeof(ACCT),1,fa);
        if(feof(fa))
            break;
        if(no==ac.acno)
        {
            flg=1;
            break;
        }
    }
    if(flg==1)
    {   system("cls");
    printf("\n\n");
    printf("\t\t_____________________CUSTOMER'S PASSBOOK__________________\t\n");
    printf("\t\t|  ACCOUNT NUMBER: %d              DOB:dd/mm/yyyyy        \n",ac.acno);
    printf("\t\t|  ACCOUNT HOLDER's NAME: %s                              \n",ac.name);
    printf("\t\t|  AGE :%d                                                \n",ac.age);
    printf("\t\t|  ADDHAR NO:%s                                           \n",ac.addhar);
    printf("\t\t|  ADDRESS NO:%s                                          \n",ac.address);
    printf("\t\t|  IFSC CODE::%s                                          \n","BKD900765");
    printf("\t\t|  MOBILE NO:%s                                           \n",ac.phone);
    printf("\t\t|  BANK ADDRESS:%s                                        \n",":VISHARAMBHAG,SANGLI");
    printf("\t\t|_________________________________________________________\n");
    }


    return;


}
/*int  infc(int no)
{
    int pos=0;
    fseek(fc,0,SEEK_SET);//this is a library fn .the fn call shifts the file pointer fa to the byte 0 from begin of the file
    //(SEEK_SET the function allows to use 3 cont SEEK_SET=begin position
       //SEEK_cur=current position ,SEEK_END = end position.
       while(1)
       {
           fread(&cr,sizeof(CRE),1,fc);
           if(feof(fc))
           {

               pos=-1;
               break;

           }
           if(cr.num==no)
                break;
            pos=ftell(fc);//library returns present file pointer position in bytes from begin of the file


       }
       return pos;
}*/
/*void creden()
{
    rewind(fc);
        while(1)
    {
        fread(&cr,sizeof(CRE),1,fc);
        if(feof(fc))
            break;
        display_();
    }
    return;



}*/
/*void display_()
{
    printf("%s\n%s\n%d\n\n\n",cr.password,cr.username,cr.num);
    return;


}*/
/*void deposit(int n)
{
    int no,pos;

    printf("\nEnter amount: ");

    scanf("%d",&no);
    ac.opnbal+=no;
    pos=search_(n);
    fseek(fa,pos,SEEK_SET);
    fwrite(&ac,sizeof(ACCT),1,fa);
    printf("\nDeposited sucessfully:)");
    printf("\n\nYour total balance is %d",ac.opnbal);
return;



}*/
void transaction()
{
    int opt,i=1,n_o;
    while(1)
    {

        printf("\n\n\n\t\t\t\t\t\t\t\1.>DEPOSIT\n\t\t\t\t\t\t\t2.>WITHDRAW\n\t\t\t\t\t\t\t3.>BACK TO MENU\n\t\t\t\t\t\t\tOPTION: ");
        scanf("%d",&opt);
        if(opt>3)
        {
            printf("\nINVALID OPTION.....\n");
            continue;
        }
        else
            if(opt==3)
        {
            printf("\n\t\t\t\t\t\t\t\t\t\t\Wait...");
            while(i<100)
            {
                usleep(1000);
                i++;
            }
            break;

        }
        else
        {
            switch(opt)
            {
                case 1:
                    deposit_();
                    break;
                case 2:
                    withdraw_();
                    break;
            }


            }
        }

}



/*void withdraw(int n)
{

    int no;
    printf("\nEnter amount: ");
    scanf("%d",&no);
    if(no>=ac.opnbal)
        printf("\nInsuffient balance...");
    else
        printf("\nYou have succesfully withdrawn Rs %d,\nremaining balance is Rs %d",no,ac.opnbal-no);
    return ;
}*/
void Adminlogin()
{   long long int i=1;
    char name[20],password[20];
    int opt,p=0,no;
     system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t ____________ADMIN LOGIN_____________");
            printf("\n\n\n\n\t\t\t\t\t\t\t\t\t|     USERNAME : ");
            scanf("%s",name);
            printf("\n\n\t\t\t\t\t\t\t\t\t|     PASSWORD:  ");
            do
            {
                    password[p]=getch();
                    if(password[p]!='\r')
			{
                    printf("*");
            }
                    p++;
            }while(password[p-1]!='\r');
            printf("\n\n\t\t\t\t\t\t\t\t\t______________________________________");
            printf("\nLOGGING IN...............>>>>>");

            while(i<=100)
            {
                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tloading....... %d %",i);
                system("cls");
                i++;
                usleep(100000);

            }

            system("cls");

            printf("\n\n\t\t\t\t\t\t\t\t\t(:SUCCESSFULLY LOGGED IN:)\n\t\t\t\t\t\t\t\t\t\t\t\t\tTIME OF LOGGED IN: ");
time_t s, val = 1;
    struct tm* current_time;

    // time in seconds
    s = time(NULL);

    // to get current time
    current_time = localtime(&s);

    // print time in minutes,
    // hours and seconds
    printf("%02d:%02d:%02d",
           current_time->tm_hour,
           current_time->tm_min,
           current_time->tm_sec);

            while(1)
            {
                //system("cls");
                    int i=1;
            		printf("\n\n\n\t\t\t\t\t\t\t\t\t1.> ADD\n\n\t\t\t\t\t\t\t\t\t2.> MODIFY\n\n\t\t\t\t\t\t\t\t\t3.> DELETE\n\n\t\t\t\t\t\t\t\t\t4.> CREATE COUSTOMER SIGNIN\n\n\t\t\t\t\t\t\t\t\t5.> TRANSATIONS\n\n\t\t\t\t\t\t\t\t\t6.>EXIT\n\n\t\t\t\t\t\t\t\t\tEnter your choice:  ");
            		scanf("%d",&opt);
                    if(opt>6)
                    {
                            printf("\n\nINVALID CHOICE!!.....PLZ ENTER A CORRECT CHOICE");
                        continue;

                    }
					if(opt==6)
                    {
                        printf("\n\t\t\t\t\t\t\t\t\t\t\tLOGGING OUT.....\n");
                       while(i<500)
                        {
                            usleep(1000);
                            i++;
                        }
                        system("cls");
                        break;
                    }
            		switch(opt)
            		{
            			case 1:
                            add();
                        break;
            			case 2:
                            modify();
                        break;
            			case 3:
                        break;
                        case 4:
                            printf("\nENTER ACCOUNT NUMBER: ");
                            scanf("%d",&no);
                            createpin(no);
                            break;
                        case 5:
                            transaction();
                            break;




					}

}
}
