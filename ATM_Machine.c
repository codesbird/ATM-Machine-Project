#include<stdio.h>
#include<encryption.h>
#include<decryption.h>
#include<stringcomp.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
int valid=0;
int ok,ko;
int c=14;
int ch;
char pass;

void creadit_amount();

void view_record();
void option();
void balance();
int main();
void list();
void edit_record();
void delete_record();
void debit_amount();
void search_reco();
void new_login();
void operation(int ch);
void Add_rec(void);
void main_menu(void);
void title();
// void change(char user[10], char password[10]);
// void log_in(char name[10],char pass[10]);
void gotoxy(short x, short y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef struct p{
    char First_Name[10];
    char Last_Name[10];
    int age;
    char contact[10];
    char user_name[10];
    char password[10];
    char email[25];
    char gender;
    char address[20];

}p;
void title()
{
    system("cls");
    printf("\n\t\t\t\t\t######################################################################\n");
    printf("\n\t\t\t\t\t\t\t\tTENALI ATM MACHINE\n\t\t\t\t\t\t\t\t      DAUSA");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t(Monu Saini)");
    printf("\n\t\t\t\t\t######################################################################\n");

}

void  creadit_amount()
{ 
    title();
    p na;
    int x=10,y;
    FILE *ptr;
    FILE *str;
    FILE *read,*write;
    write = fopen("temp.txt","w+");
    char *file;
    char txt[] = ".txt";
    int g,row=14,total=0;
    str= fopen("c.txt","r");
    fscanf(str,"%d",&g);
    ptr = fopen("local.txt","r");
    char more;
    char name[10];
    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Search User Record Data!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n\nUser Name-:");
    scanf("%s",name);
    fflush(stdin);
    // title();
    while (row!=g)
    {
        fscanf(ptr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,&na.age,na.contact,na.email,&na.gender,na.address,na.user_name,na.password);
        if(compare(name,na.user_name)==0)
        {
            total=1;
            file = strcat(name,txt);
            read = fopen(file,"r");
            fscanf(read,"%d",&x);
            printf("Enter your ammount-:");
            scanf("%d",&y);
            x=x+y;
            fprintf(write,"%d",x);
            fclose(read);
            fclose(write);
            remove(file);
            rename("temp.txt",file);
            remove("temp.txt");
            printf("\n%d",x);
          
            break;
        }
        row++;
        
    }
    if (!total)
    {
        // gotoxy(5,10);
        printf("\nInvailid user and password");
    }
    fclose(ptr);
    fclose(str);
    X:
    printf("\n\n\n\t\t..Do You Want To Search More..[Y/N]");
    scanf("%s",&more);
    fflush(stdin);
    if (toupper(more)=='Y')
    {
        creadit_amount();

    }
    else{
        if(toupper(more)=='N')
        {
        title();
        printf("\n\n\t\t\t\t\t\t\t\t**Thank You**\n\n");
        ////
        printf("\n\n\n\t\t..Press'Y' For main_menu And 'N' For Exit..[Y/N]");
        scanf("%s",&more);
        fflush(stdin);
            if (toupper(more)=='Y')
            {
                main_menu();
            }
            else{
                exit(0);
            }

        ////////
        }
        else{
            printf("\n\n\n\t\t^^^Invailid containt charactor^^^");
            goto X;
        }
         
            
    }
}

void  debit_amount()
{ 
    title();
    p na;
    int x=10,y;
    FILE *ptr;
    FILE *str;
    FILE *read,*write;
    write = fopen("temp.txt","w+");
    char *file;
    char txt[] = ".txt";
    int g,row=14,total=0;
    str= fopen("c.txt","r");
    fscanf(str,"%d",&g);
    ptr = fopen("local.txt","r");
    char more;
    char name[10];
    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Search User Record Data!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n\nUser Name-:");
    scanf("%s",name);
    fflush(stdin);
    // title();
    while (row!=g)
    {
        fscanf(ptr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,&na.age,na.contact,na.email,&na.gender,na.address,na.user_name,na.password);
        if(compare(name,na.user_name)==0)
        {
            A:
            total=1;
            printf("\n\nEnter your ammount-:");
            scanf("%d",&y);
            file = strcat(name,txt);
            read = fopen(file,"r");
            fscanf(read,"%d",&x);
            if(y>x)
            {
                printf("\n\n\n\t\t\t\t#Please.. Enter Valid Amount#");
                printf("\n\n\t\t\t\t\t#Please Check your Balance.#");
                getch();
                goto A;
            }
            else
            {
            x=x-y;
            fprintf(write,"%d",x);
            fclose(read);
            fclose(write);
            remove(file);
            rename("temp.txt",file);
            remove("temp.txt");
            printf("\n%d",x);
            }
            break;
        }
        row++;
        
    }
    if (!total)
    {
     
        printf("\nInvailid user and password");
    }
    fclose(ptr);
    fclose(str);
    X:
    printf("\n\n\n\t\t..Do You Want To Search More..[Y/N]");
    scanf("%s",&more);
    fflush(stdin);
    if (toupper(more)=='Y')
    {
        debit_amount();

    }
    else{
        if(toupper(more)=='N')
        {
        title();
        printf("\n\n\t\t\t\t\t\t\t\t**Thank You**\n\n");
        //////
        printf("\n\n\n\t\t..Press'Y' For main_menu And 'N' For Exit..[Y/N]");
        scanf("%s",&more);
        fflush(stdin);
            if (toupper(more)=='Y')
            {
                main_menu();
            }
            else{
                exit(0);
            }

        ////////
        }
        else{
            printf("\n\n\n\t\t^^^Invailid containt charactor^^^");
            goto X;
        }
         
            
    }
}



void operation(int ch)
{    
   
    switch (ch)
    {
        case 1:
        {
            creadit_amount();
            break;
        }
        case 3:
        {
            search_reco();
            break;
        }
        case 4:
            {
            fflush(stdin);
            balance();
            break;
            }
        case 2:
            {
                debit_amount();
                break;
            }   
            case 5:
            {
                main();
                break;
            }  
            
        default:
        {
            printf("\n\n\t\t\t\tInvalid Input");
            getch();
            main_menu();
            break;
        }
    }

}


void main_menu(void)
{   title();
   int ch;
   
    printf("\n\t\t\t\t\t1. For Credit"); ////complete
    printf("\n\t\t\t\t\t2. For Debit");  ///complete
    printf("\n\t\t\t\t\t3. View your record data");
    printf("\n\t\t\t\t\t4. For Check balance "); //complete
    printf("\n\t\t\t\t\t5. For Lock your account");  ///complete
    printf("\n\n\t\t\t\t\tChoose option operetion-:");
    scanf("\n%d",&ch);       
    operation(ch); 
       
}

void new_login()
{   
    p na;
    title();
    char again[0][0];
    char newuser[10];
    char password[10];
    FILE *utr;
    int row=14;
    utr = fopen("local.txt","r");
    FILE *str;
    str = fopen("c.txt","r");
    fscanf(str,"%d",&c);
    // A:
    printf("\n\n\t\t\t\t\tuser_name-:");
    scanf("%s",newuser);
    fflush(stdin);
    printf("\n\n\t\t\t\t\tpassword");
    scanf("%s",password);
    fflush(stdin);

   
    fclose(str);     
    while (row!=c)
    {
      
        fscanf(utr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,&na.age,na.contact,na.email,&na.gender,na.address,na.user_name,na.password);
        // printf("%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,na.age,na.contact,na.email,na.gender,na.address,na.user_name,na.password);
        int u = compare(newuser,na.user_name);
        int l = compare(password,na.password);
        // printf("\n%d===%d",u,l);
        if(u==0 && l==0)
        {
            title();
            printf("\n\n\t\t\t\t\tWELCOME # #");
            printf("\n\n\t\t\t...press any key to continue...\n");
            getch();
            main_menu();
            
        }
       
        row++;    
    }
    
    printf("\n\n\t\t\t\t\tthere is no user account");
    printf("\n\n\t\t\t...If you want to try again...[Y/N]\n");
    scanf("%s",again);
    char option = again[0][0];


    if (toupper(option)=='Y')
    {
        title(0);
        new_login();
        /* code */
    }
    else{
        exit(0);
    }
    


}

void search_reco()
{   title();
    p na;
    FILE *ptr;
    FILE *str;
    int g,row=14;
    str= fopen("c.txt","r");
    fscanf(str,"%d",&g);
    ptr = fopen("local.txt","r");
    char more;
    char name[10];
    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Search User Record Data!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("\n\nUser Name-:");
    scanf("%s",name);
    fflush(stdin);
    title();
    while (row!=g)
    {
        fscanf(ptr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,&na.age,na.contact,na.email,&na.gender,na.address,na.user_name,na.password);
        if(compare(name,na.user_name)==0)
        {
            gotoxy(1,12);
            printf("Full Name");
            gotoxy(20,12);
            printf("Gender");
            gotoxy(32,12);
            printf("Age");
            gotoxy(37,12);
            printf("Address");
            gotoxy(49,12);
            printf("Contact");
            gotoxy(68,12);
            printf("Email");
            gotoxy(88,12);
            printf("Username");
            gotoxy(98,12);
            printf("Password");
            printf("\n================================================================================================================");

            gotoxy(1,row);
            printf("%s %s",na.First_Name,na.Last_Name);
            gotoxy(20,row);
            printf("%c",na.gender);
            gotoxy(32,row);
            printf("%d",na.age);
            gotoxy(37,row);
            printf("%s",na.address);
            gotoxy(49,row);
            printf("%s",na.contact);
            gotoxy(68,row);
            printf("%s",na.email);
            gotoxy(88,row);
            printf("%s",na.user_name);
            gotoxy(98,row);
            printf("%s",na.password);
            break;
        }
        row++;
        
    }
    if (compare(na.user_name,name)!=0)
    {
        gotoxy(5,10);
        printf("Rcord Not Found");
    }
    fclose(ptr);
    fclose(str);
    X:
    printf("\n\n\n\t\t..Do You Want To Search More..[Y/N]");
    scanf("%s",&more);
    fflush(stdin);
    if (toupper(more)=='Y')
    {
        search_reco();
    }
    else{
        if(toupper(more)=='N')
        {
        title();
        printf("\n\n\t\t\t\t\t\t\t\t**Thank You**\n\n");
        ////////
        printf("\n\n\n\t\t..Press'Y' For main_menu And 'N' For Exit..[Y/N]");
        scanf("%s",&more);
        fflush(stdin);
            if (toupper(more)=='Y')
            {
               main_menu();
            }
            else{
                exit(0);
            }
        //////////
        }
        else{
            printf("\n\n\n\t\t^^^Invailid containt charactor^^^");
            goto X;
        }
         
            
    }
}


void exits()
{
    title();
    printf("\n\n\n\t\t\t\t\t\t\t\t<<<< !! Thanks For Visiting !! >>>\n\n\n\n\n");
    exit(0);
}

void Add_rec(void)
{   
    p na;
    title();
    char txt[] = ".txt";
    char *file;
    FILE *itr;
    
    char name[1][1];

    
    
    // fclose(atm);
    printf("\n\n\t\t\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!New User Rajistration!!!!!!!!!!!!!!!!!!!!");
    
    /************************************************"First_Name"**********************************************/

    B:
    printf("\n\n\t\t\t\t\tFirst_Name-:");
    scanf("%s",na.First_Name);
    na.First_Name[0] = toupper(na.First_Name[0]);
    if (strlen(na.First_Name)>8 || strlen(na.First_Name)<2)
    {
        printf("\n\n\t\t\t\t\t.....The arange of first_name maximu is 8 and minimum is 2.....\n");
        goto B;
    }
    else
    {
        for (int i = 0; i < strlen(na.First_Name); i++)
        {
            if (isalpha(na.First_Name[i]))
            {
                valid =1;
            }
            else{
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\n\t\t\t\t\t.....first_name containt unvailid charactor......\n\n");
            goto B;
        }
        
    }
    
    /************************************************"Last_Name"**********************************************/

    C:
    printf("\n\n\t\t\t\t\tLast_Name-:");
    scanf("%s",na.Last_Name);
    na.Last_Name[0] = toupper(na.Last_Name[0]);
    if (strlen(na.Last_Name)>8 || strlen(na.Last_Name)<2)
    {
        printf("\n\n\t\t\t\t\t.....The arange of Last_Name maximu is 8 and minimum is 2.....\n");
        goto C;
    }
    else
    {
        for (int i = 0; i < strlen(na.Last_Name); i++)
        {
            if (isalpha(na.Last_Name[i]))
            {
                valid =1;
            }
            else{
                valid = 0;
                break;
            }
        }
        if (!valid)
        {
            printf("\n\n\t\t\t\t\t.....Last_Name containt unvailid charactor......\n\n");
            goto C;
        }
        
    }
    /************************************************"Age"**********************************************/
    printf("\n\n\t\t\t\t\tEnter Age-:");
    scanf("%d",&na.age);

    /************************************************"gender"**********************************************/

    do
    {
        fflush(stdin);
        printf("\n\n\t\t\t\t\tGender(F/M)-:");
        scanf("%c",&na.gender);
        na.gender = toupper(na.gender);
        if (na.gender=='M' || na.gender=='F')
        {
            ok =1;
        }
        else{
            ok=0;
        }
        if (!ok)
        {
            printf("\n\n\t\t\t\t\t!!Gender cantain invailid charactor:(Enter Either F or M):!!");
        }
        
        

    } while (!ok);

    /************************************************"address"**********************************************/
    
    do
    {   
        printf("\n\n\t\t\t\t\tEnter Address-:");
        scanf("%s",na.address);
        na.address[0] = toupper(na.address[0]);
        if (strlen(na.address)<20 || strlen(na.address)>3)
        {
            ko= 1;
        }
        else{
            ko=0;
        }
        if(!ko)
        {
            printf("\n\n\t\t\t\tAddress containt invailid charactor") ; 
                       
        }
        
    } while (!ko);
    
    /************************************************"contact Number"**********************************************/
    do
    {   D:
    printf("\n\n\t\t\t\t\tEnter contact-:");
    scanf("%s",na.contact);
    if (strlen(na.contact)>10|| strlen(na.contact)!=10){
        printf("\n\n\t\t\t\t\tinvailid contact number!!(Enter Again..)!!");
        goto D;
    }
    else
    {for (int i = 0; i < strlen(na.contact); i++)
        {   if (!isalpha(na.contact[i]))
            {
                valid =1;
            }
            else
            {
                valid=0;
            }
            if (!valid)
            {
                printf("\n\n\t\t\t\t\tinvailid contact number!!(Enter Again..)!!\n\n");
                goto D;
            }
        }
    }
    }while (!valid);   

    /************************************************"Email_I'd"**********************************************/
    do
    {   
    printf("\n\n\t\t\t\t\tEnter Email_I'd-:");
    scanf("%s",na.email);
    if (strlen(na.email)>12 || strlen(na.email)<5)
    {
        printf("\n\n\t\t\t\tEmail containt invailid charactor") ; 
                       
    }
        
    } while(strlen(na.email)>12 || strlen(na.email)<5);

    /************************************************"User_Name"**********************************************/
    do
    {   
        printf("\n\n\t\t\t\t\tuser_name-:");
        scanf("%s",na.user_name);
        if (strlen(na.user_name)>10 || strlen(na.user_name)<3)
        {
            printf("\n\n\t\t\t\tuser_name containt invailid charactor") ; 
                       
        }
        
    } while (strlen(na.user_name)>10 || strlen(na.user_name)<3);

    /************************************************"Password"**********************************************/

    do
    {   
        printf("\n\n\t\t\t\t\tPasswod-:");
        scanf("%s",na.password);
        if (strlen(na.password)>6|| strlen(na.password)!=6)
        {
            printf("\n\n\t\t\t\tpassword containt invailid charactor") ; 
        }
        
    } while (strlen(na.password)>6 || strlen(na.password)!=6);


    /************************************************"Finishing"**********************************************/

    FILE *atm;
    atm = fopen("local.txt", "a");
    fprintf(atm,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,na.age,na.contact,na.email,na.gender,na.address,na.user_name,na.password);
    fclose(atm);
    file = strcat(na.user_name,txt);
    itr = fopen(file,"a+");
    fprintf(itr,"%d",10);
    fclose(itr);
    FILE *ohh;
    ohh = fopen("c.txt","r");
    fscanf(ohh,"%d",&c);
    fclose(ohh);
    c++;
    FILE *ls;
    ls = fopen("c.txt","w");
    fprintf(ls,"%d",c);
    fclose(ls);
    title();
    printf("\t\t\t\t\t...press any key to continue...\n");
   
    sd:
    getch();
    printf("\n\n\t\t\t\t\t!!Do you want to more rajistation!![Y/N]");
    scanf("%s",name);
    char option = name[0][0];
    
    if (toupper(option)=='Y')
    {
        Add_rec();
    }
    else
    {
        printf("\n\n\t.......ThankYou........");
        printf("\n\n\n\t\t\t\t\t...press any key to continue...\n");
        getch();
        title();
        list();
    }
}

void edit_record()
{   title();
    p na;
    int i,b,crass=0;
    FILE *utr;
    FILE *ptr,*otr;
    FILE *str;
    int g,row=14;
    utr = fopen("temp.txt","w+");
    str= fopen("c.txt","r");
    fscanf(str,"%d",&g);
    ptr = fopen("local.txt","r");
    char more;
    char name[10];
    if (ptr==NULL)
    {   
        printf("\n\n\t\t\t\t):Can Not Open File:(");
        printf("\n\n\t\t\t\t......press any key to continue........");
        getch();
        
    }
    
    printf("\n\t\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!# :(   ):# # :(   ):# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    gotoxy(12,13);
    printf("Enter User Name-:");
    scanf("%s",name);
    fflush(stdin);
    // name[0] = toupper(na.First_Name);
    if (utr==NULL)
    {
        printf("\n\n\t\t\t\t):Can Not Open File:(");
        printf("......press any key to continue........");
        getch();

    }

    
    title();
    while (row!=g)
    {
        fscanf(ptr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,&na.age,na.contact,na.email,&na.gender,na.address,na.user_name,na.password);
        if(compare(name,na.user_name)==0)
        {
            crass=1;
            gotoxy(1,13);
            printf("Full Name");
            gotoxy(20,13);
            printf("Gender");
            gotoxy(32,13);
            printf("Age");
            gotoxy(37,13);
            printf("Address");
            gotoxy(49,13);
            printf("Contact");
            gotoxy(68,13);
            printf("Email");
            gotoxy(88,13);
            printf("Username");
            gotoxy(98,13);
            printf("Password");
            printf("\n================================================================================================================");

            gotoxy(1,row);
            printf("%s %s",na.First_Name,na.Last_Name);
            gotoxy(20,row);
            printf("%c",na.gender);
            gotoxy(32,row);
            printf("%d",na.age);
            gotoxy(37,row);
            printf("%s",na.address);
            gotoxy(49,row);
            printf("%s",na.contact);
            gotoxy(68,row);
            printf("%s",na.email);
            gotoxy(88,row);
            printf("%s",na.user_name);
            gotoxy(98,row);//***************///***************
            printf("%s",na.password);
            printf("\n\n\n*********************88888888888888888888888888 ):Enter New Record:( 888888888888888888888888888888********************");

//-----------------------------------------------------------------------------------------------------------------------------------------------------
/************************************************"First_Name"**********************************************/
            B:
            printf("\n\n\t\t\t\t\tFirst_Name-:");
            scanf("%s",na.First_Name);
            na.First_Name[0] = toupper(na.First_Name[0]);
            if (strlen(na.First_Name)>8 || strlen(na.First_Name)<2)
            {
                printf("\n\n\t\t\t\t\t.....The arange of first_name maximu is 8 and minimum is 2.....\n");
                goto B;
            }
            else
            {
                for (int i = 0; i < strlen(na.First_Name); i++)
                {
                    if (isalpha(na.First_Name[i]))
                    {
                        valid =1;
                    }
                    else{
                        valid = 0;
                        break;
                    }
                }
                if (!valid)
                {
                    printf("\n\n\t\t\t\t\t.....first_name containt unvailid charactor......\n\n");
                    goto B;
                }
                
            }
            
            /************************************************"Last_Name"**********************************************/

            C:
            printf("\n\n\t\t\t\t\tLast_Name-:");
            scanf("%s",na.Last_Name);
            na.Last_Name[0] = toupper(na.Last_Name[0]);
            if (strlen(na.Last_Name)>8 || strlen(na.Last_Name)<2)
            {
                printf("\n\n\t\t\t\t\t.....The arange of Last_Name maximu is 8 and minimum is 2.....\n");
                goto C;
            }
            else
            {
                for (int i = 0; i < strlen(na.Last_Name); i++)
                {
                    if (isalpha(na.Last_Name[i]))
                    {
                        valid =1;
                    }
                    else{
                        valid = 0;
                        break;
                    }
                }
                if (!valid)
                {
                    printf("\n\n\t\t\t\t\t.....Last_Name containt unvailid charactor......\n\n");
                    goto C;
                }
                
            }
            /************************************************"Age"**********************************************/
            printf("\n\n\t\t\t\t\tEnter Age-:");
            scanf("%d",&na.age);

            /************************************************"gender"**********************************************/

            do
            {
                fflush(stdin);
                printf("\n\n\t\t\t\t\tGender(F/M)-:");
                scanf("%c",&na.gender);
                na.gender = toupper(na.gender);
                if (na.gender=='M' || na.gender=='F')
                {
                    ok =1;
                }
                else{
                    ok=0;
                }
                if (!ok)
                {
                    printf("\n\n\t\t\t\t\t!!Gender cantain invailid charactor:(Enter Either F or M):!!");
                }
                
                

            } while (!ok);

            /************************************************"address"**********************************************/
            
            do
            {   
                printf("\n\n\t\t\t\t\tEnter Address-:");
                scanf("%s",na.address);
                na.address[0] = toupper(na.address[0]);
                if (strlen(na.address)<20 || strlen(na.address)>3)
                {
                    ko= 1;
                }
                else{
                    ko=0;
                }
                if(!ko)
                {
                    printf("\n\n\t\t\t\tAddress containt invailid charactor") ; 
                            
                }
                
            } while (!ko);
            
            /************************************************"contact Number"**********************************************/
            do
            {   D:
            printf("\n\n\t\t\t\t\tEnter contact-:");
            scanf("%s",na.contact);
            if (strlen(na.contact)>10|| strlen(na.contact)!=10){
                printf("\n\n\t\t\t\t\tinvailid contact number!!(Enter Again..)!!");
                goto D;
            }
            else
            {for (int i = 0; i < strlen(na.contact); i++)
                {   if (!isalpha(na.contact[i]))
                    {
                        valid =1;
                    }
                    else
                    {
                        valid=0;
                    }
                    if (!valid)
                    {
                        printf("\n\n\t\t\t\t\tinvailid contact number!!(Enter Again..)!!\n\n");
                        goto D;
                    }
                }
            }
            }while (!valid);   

            /************************************************"Email_I'd"**********************************************/
            do
            {   
            printf("\n\n\t\t\t\t\tEnter Email_I'd-:");
            scanf("%s",na.email);
            if (strlen(na.email)>12 || strlen(na.email)<5)
            {
                printf("\n\n\t\t\t\tEmail containt invailid charactor") ; 
                            
            }
                
            } while(strlen(na.email)>12 || strlen(na.email)<5);

            /************************************************"User_Name"**********************************************/
            do
            {   
                printf("\n\n\t\t\t\t\tuser_name-:");
                scanf("%s",na.user_name);
                if (strlen(na.user_name)>10 || strlen(na.user_name)<3)
                {
                    printf("\n\n\t\t\t\tuser_name containt invailid charactor") ; 
                            
                }
                
            } while (strlen(na.user_name)>10 || strlen(na.user_name)<3);

            /************************************************"Password"**********************************************/

            do
            {   
                printf("\n\n\t\t\t\t\tPasswod-:");
                scanf("%s",na.password);
                if (strlen(na.password)>6|| strlen(na.password)!=6)
                {
                    printf("\n\n\t\t\t\tpassword containt invailid charactor") ; 
                }
                
            } while (strlen(na.password)>6 || strlen(na.password)!=6);


            /************************************************"Finishing"**********************************************/

           /**************"Clossing"**********************************************/



//-----------------------------------------------------------------------------------------------------------------------------------------------------

            
            printf(")): Press 'U' to confirm updatw :((");
            char ch=getche();
            if (ch=='u' || ch=='U')
            {
                fprintf(utr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,na.age,na.contact,na.email,na.gender,na.address,na.user_name,na.password);
                printf("\n\n\t\t!!!!!!!! ): Update Successfuly :( !!!!!!!!!");
            }
            
        }
        else
        {
            fprintf(utr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,na.age,na.contact,na.email,na.gender,na.address,na.user_name,na.password);

        }
    row++;
        
    }
    if (!crass)
    {
        
        printf("\n\n\t\t\t#____##___Rcord Not Found____##___#");
    }
    
    fclose(ptr);
    fclose(str);
    fclose(utr);
    remove("local.txt");
    rename("temp.txt","local.txt");
    remove("temp.txt");
    X:
    printf("\n\n\n\t\t..Do You Want To Update More..[Y/N]");
    scanf("%s",&more);
    fflush(stdin);
    if (toupper(more)=='Y')
    {
        edit_record();
    }
    else if(toupper(more)=='N')
    {
        title();
        printf("\n\n\t\t\t\t\t\t\t\t**Thank You**\n\n");
        printf("\n\n\n\t\t..Press'Y' For main_menu And 'N' For Exit..[Y/N]");
        scanf("%s",&more);
        fflush(stdin);
            if (toupper(more)=='Y')
            {
                list();
            }
            else{
                exit(0);
            }
    }
    else{
        printf("*-*-*-*-*-**-*- ): INVAILID-INPUT :( -*-*-*-*-*-*-*-*");
        printf("\t\t\t\t\t...press any key to continue...\n");

        getch();
        goto X;
    }
}
  

void view_record()
{   int  row;
    p na;
    title();
    FILE *ptr;
    FILE *str;
    str = fopen("c.txt","r");
    ptr = fopen("local.txt","r");
   
    fscanf(str,"%d",&c);
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!view User Record Data!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    gotoxy(1,10);
    printf("Full Name");
    gotoxy(20,10);
    printf("Gender");
    gotoxy(32,10);
    printf("Age");
    gotoxy(37,10);
    printf("Address");
    gotoxy(49,10);
    printf("Contact");
    gotoxy(68,10);
    printf("Email");
    gotoxy(88,10);
    printf("Username");
    gotoxy(98,10);
    printf("Password");
    printf("\n================================================================================================================");
    row =14;
    while (row!=c)
    {
        fscanf(ptr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,&na.age,na.contact,na.email,&na.gender,na.address,na.user_name,na.password);
        gotoxy(3,row);
        printf("%s %s",na.First_Name,na.Last_Name);
        gotoxy(20,row);
        printf("%c",na.gender);
        gotoxy(32,row);
        printf("%d",na.age);
        gotoxy(37,row);
        printf("%s",na.address);
        gotoxy(49,row);
        printf("%s",na.contact);
        gotoxy(68,row);
        printf("%s",na.email);
        gotoxy(88,row);
        printf("%s",na.user_name);
        gotoxy(98,row);
        printf("%s",na.password);
        row++;
    }
    fclose(ptr);
    printf("\n\n\t\t\t\t\t...press any key to continue...\n");
    getch();
    list();

}

void login()
{   title();
    int mount =0;
    char user[10],name[10];
    char pas[10],pass[10];
    printf("\n\n\t\t\t\tUsername-:");
    gets(user);
    printf("\n\n\t\t\t\tPassword-: ");
    gets(pas);
    FILE *ptr;
    ptr = fopen("owner.txt","r");
    fscanf(ptr,"%s%s",name,pass);
    decryption(name);
    fclose(ptr);
    decryp(pass);
    // printf("\n\n%s\n\n",name);
    // printf("%s",pass);kalidas
    int a = compare(user,name);
    int b = compare(pas,pass);
    // printf("\n%d\n%d",a,b);

    if(a==0 && b==0)
    {
        mount=1;
        printf("\n\n\t\t\t\t\tLog-in Successful");
        printf("\n\n\t\t\t\t..............Press any key to continue.................\n");
        getch();
        list();


    }
    else
    {
        printf("\n\n\t\t\t\tInvailid username & password");
        printf("\n\n\t\t\t\t..............Press any key to continue.................\n");
        getch();
        login();
    }
}

void list()
{   
    title();
    int num;
    printf("\n\n\t\t\t\t\t1. View Record Data of all Users.");
    printf("\n\n\t\t\t\t\t2. Delete Users Data using username.");
    printf("\n\n\t\t\t\t\t3. Add New User Data.");
    printf("\n\n\t\t\t\t\t4. Edit Any User Record");
    printf("\n\n\t\t\t\t\t5. Lock your Account.");
    printf("\n\n\t\t\t\t\t6. Power Off The ATM Machine.");
    
    printf("\n\n\t\t\t\t\tChoose a Option-:");
    scanf("%d",&num);
    option(num);
   
}

void delete_record()
{   title();
    p na;
    int a=14,c,delete=0;
    char name[10],more;
    title();
    FILE *ptr,*str,*ctr,*otr;
    str = fopen("temp.txt","w+");
    ptr = fopen("local.txt","r");
    ctr  = fopen("c.txt","r");
    fscanf(ctr,"%d",&c);
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!! ): Delete user Record :( !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    gotoxy(12,8);
    printf("\n\n\t\t\tEnter username-:");
    scanf("%s",name);
    while (a!=c)
    {
        fscanf(ptr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,&na.age,na.contact,na.email,&na.gender,na.address,na.user_name,na.password);
        if (strcmp(name,na.user_name)!=0)
        {
            fprintf(str,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,na.age,na.contact,na.email,na.gender,na.address,na.user_name,na.password);
        }
        else{
            delete=1;
            printf("%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,na.age,na.contact,na.email,na.gender,na.address,na.user_name,na.password);
        }
        a++;
    }

    if (delete==0)
    {
        printf("\n\n\t\t\t______Record not found________");
        printf("\n\n\n\n\t\t,,.........press any key to continue......,,");
        getch();
        delete_record();
    }
    else{
        otr = fopen("c.txt","w");
        c--;
        fprintf(otr,"%d",c);
        fclose(ptr);
        fclose(str);
        fclose(otr);
        fclose(ctr);
        remove("local.txt");
        rename("temp.txt","local.txt");
        remove("temp.txt");
        printf("\n\n\t\t........Record Delete Successfully..........");
    }
    
    
        
    X:
    printf("\n\n\n\t\t..Do You Want To Delete More..[Y/N]");
    scanf("%s",&more);
    fflush(stdin);
    if (toupper(more)=='Y')
    {
        delete_record();
    }
    else
    {
        title();
        printf("\n\n\t\t\t\t\t\t\t\t**Thank You**\n\n");
        printf("\n\n\n\t\t..Press'Y' For main_menu And 'N' For Exit..[Y/N]");
        scanf("%c",&more);
        fflush(stdin);
        if (toupper(more)=='Y')
        {
           list();
        }
        else
        {   
            printf("\n\n\n\t\t\t\t\t\t\t\t<<<< !! Thanks For Visiting !! >>>\n\n\n\n\n");

            exit(0);
        }
    }
}

void option(int num){
    switch(num){
        case 1:
        {
            fflush(stdin);

            view_record();

            break;
        }
        case 2: 
        {
            fflush(stdin);

            delete_record();

            break;
        }

        case 3:
        {
            fflush(stdin);

            Add_rec();
            break;
        }
        case 4:
        {
            fflush(stdin);
            edit_record();
            break;
        }
        case 5:
        {
            fflush(stdin);
            main();
            break;
        }
        case 6:
        {
            exits();
        }
        default:
        {
            printf("Invalid Input");
            printf("\n\n\t\t\t\t..............Press any key to continue.................\n");
            getch();
           list();
        }
    }

}

void balance()
{
    p na;
    int das=0,d,salary,c,a=14;
    char name[10];
    char b;
    title();
    FILE *ptr,*str,*otr;
    ptr = fopen("local.txt","r");
    char *file;
    char txt[] = ".txt";
    str = fopen("c.txt","r");
    fscanf(str,"%d",&c);
    fclose(str);
    gotoxy(50,20);
    printf("\n\n\t\t\tEnter username-:");
    gets(name);
    while (a!=c)
    {
        fscanf(ptr,"%s %s %d %s %s %c %s %s %s\n",na.First_Name,na.Last_Name,&na.age,na.contact,na.email,&na.gender,na.address,na.user_name,na.password);
        if (strcmp(name,na.user_name)==0)
        {
            das=1;
            file = strcat(name,txt);
            otr = fopen(file,"r");
            fscanf(otr,"%d",&salary);
            fclose(otr);
            printf("\n\n\t\t\tTotal Balance-:%d\n\n",salary);
            V:
            printf("Main_Menu[Y] & Exit[N]\n");
            scanf("%c",&b);
            fflush(stdin);
            b = toupper(b);
            if (b=='Y')
            {
                main_menu();
            }
            else if (b=='N')
            {
                exit(0);
            }
            else {
                printf("\n\n\t\t\tInavalid Input");
                goto V;
            }            
            
            break;
        }
    a++;
    }
if (das==0)
{
    A:
    printf("\n\n\t\t\tRecord Not Found");
    printf("\n\n\t\t\tPress [Enter] to Continue");   
    scanf("%c",&pass); 
    if (pass=='\n')
    {
        balance();
        
    }
    else{
        printf("\n\n\t\t\tPlease.. Press [Enter]");
        goto A;
    }

    
}
else
{  
    exit(0);

}
  

    
}

int main()
{  
    int ME;
    title();
    gotoxy(50,20);
    printf("* * * * * * * * * * * *");
    // gotoxy(50,20);
    // printf("*");
    gotoxy(50,21);
    printf("*");
    gotoxy(50,22);
    printf("*");
    gotoxy(50,23);
    printf("*");
    gotoxy(50,24);
    printf("*");
    gotoxy(50,25);
    printf("*");
    gotoxy(50,26);
    printf("*");
    gotoxy(50,27);
    printf("*");

    /////////////////////////////////////////////////////////
    gotoxy(50,28);
    printf("* * * * * * * * * * * *");
   
    
    gotoxy(72,21);
    printf("*");
    gotoxy(72,22);
    printf("*");
    gotoxy(72,23);
    printf("*");
    gotoxy(72,24);
    printf("*");
    gotoxy(72,25);
    printf("*");
    gotoxy(72,26);
    printf("*");
    gotoxy(72,27);
    printf("*");
    /////////////////////////////////////////

    gotoxy(56,23);
    printf("1. Manager");
    gotoxy(56,25);

    printf("2. Employee");
    gotoxy(54,31);

    printf("!!!-->");
    scanf("%d",&ME);
    gotoxy(58,20);
    printf("**********************");
    fflush(stdin);
    switch(ME)
    {
        case 1:
        {
            login();
        }
        case 2:
        {
            new_login();
        }
        default:
        {
            B:
            fflush(stdin);
            title();
            printf("\n\n\n\t\t\t\tInvalid Input");
            printf("\n\n\n\t\t\t\tPress Enter.....");
            scanf("%c",&pass);
            
            if (pass=='\n')
            {
                main();
            }
            else
            {
               goto B;
            }
        }
    }

    balance();
    return 0;


}
