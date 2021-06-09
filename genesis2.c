
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"features2.h"//header file.
#include<time.h>
#include<windows.h>
//#include<unistd.h>
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif


//choice variable
void main()

{   int opt; int i=1;
    fa=fopen("b_ank_d_e_t_a_i_l.dat","r+b");// bank user details
    if(fa==NULL)
    {
        fa=fopen("b_ank_d_e_t_a_i_l.dat","w");
        fclose(fa);
        fa=fopen("b_ank_d_e_t_a_i_l.dat","r+b");
    }
    fc=fopen("c_rb.dat","r+b");//login id and password
    if(fc==NULL)
    {
        fc=fopen("c_rb.dat","w");
        fclose(fc);
        fc=fopen("c_rb.dat","r+b");
    }
    op=fopen("w_i_t_h_d_rawm.dat","r+b");
    if(op==NULL)
    {
        op=fopen("w_i_t_h_d_rawm.dat","w");
        fclose(op);
        op=fopen("w_i_t_h_d_rawm.dat","r+b");

    }
    time_t s, val = 1;
    struct tm* current_time;

    // time in seconds
    s = time(NULL);

    // to get current time
    current_time = localtime(&s);

    // print time in minutes,
    // hours and seconds
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\tTIME<<%02d:%02d:%02d>>",
           current_time->tm_hour,
           current_time->tm_min,
           current_time->tm_sec);

/*int sec=0,min=0,hour=0,i,j;
while(1)
{

if(sec>59)
{
min++;
sec=0;
}
if(min>59)
{
hour++;
min=0;
}
if(hour>23)
{
hour=0;
min=0;
sec=0;
}

sec=sec+1;

printf("\t\t%d:%d:%d\n",hour,min,sec);
}
*/

   // printf("\n\n\n_________________________________________________________________________________________<<<<SYSTEM LOGIN PORTAL>>>>_______________________________________________________________________________________________________");
    while(1)
    {
            long long int i=1;
    	printf("\n\n\n_________________________________________________________________________________________<<<<SYSTEM LOGIN PORTAL>>>>_______________________________________________________________________________________________________");

    printf("\n\n\t\t\t\t\t\t\t\t\t1.) USER LOGIN\n\n\n\t\t\t\t\t\t\t\t\t2.) ADMIN LOGIN\n\n\n\t\t\t\t\t\t\t\t\t3.) USER SIGN IN\n\n\n\t\t\t\t\t\t\t\t\t4.) EXIT\n\n\n\t\t\t\t\t\t\t\t\tEnter Your Choice (1/2/3): ");
    scanf("%d",&opt);
    if(opt==4)
    {
        break;



    }
    else if(opt>3||opt<1)
    {
        printf("\n\nInvalid Choice!!!..plz enter a correct choice>>>");

    }
    else
    {
        switch(opt)
        {
            case 1:
            //user();
            break;
            case 2:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPLEASE WAIT WHILE THE SYSTEM IS LOADING........>>");
                while(i<800)
                {
                    usleep(10000);
                    i++;

                }
            Adminlogin();
            break;
            case 3:
            //createpin();
            break;



        }
		}

    fclose(fa);
    fclose(fc);
    fclose(op);
    }


}


/*
1. invalid input

2. structure of user
    (USERNAME,PWD,NAME,ADDRESS,CITY,PHONENO,ADHARNO,DOB),(IFSE))
3.
*/
/*account opening date
transation in admin->admin
details->admin
coustomer id->passbook

cfsc code->passbook
branch address->passbook
email id->passbook
    createid->admin
    encryption fn
    forgot password and userid
*/
