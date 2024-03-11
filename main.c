#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

int i,j,main_exit;

void menu();
void new_entry();
void edit();
void view_list();
void erase();
void see();
void sorter();
void closer();


struct {

    char name[120];
    char sname[100];
    int age;
    char city[120];
    char mail_id[60];
    char depart[50];
    int room_no;
    char father_name[60];
    char father_phone_no[11];
    char phone_no[11];
    char hostel_name[16];
    char Gr_no[10];
    }add,upd,check,rem,sort;

int main()
{
    system("color 0b");
    menu();  // Call the menu function directly instead of pass()
    return 0;
}
void menu()
{
system("CLS");
    int choice;
    printf("\n\n\t\t\t########## TKIET HOSTEL #########");
    printf("\n\n\n\t\t\** WELCOME TO THE MAIN MENU **");
    printf("\n\n\t\t1>> Enter new Student's data\n\t\t2>> Update information of existing account\n\t\t3>> Check the details of existing account\n\t\t4>> View all Students of a particular Hostel\n\t\t5>> Deleting existing account\n\t\t6>> View all students list\n\t\t7>> Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {

        case 1:new_entry();
        break;
        case 2:edit();
        break;
        case 3:see();
        break;
        case 4:sorter();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:closer();
        break;
        default:menu();
    }
}

void sorter()
{
    system("CLS");
    int choice,test=0;

    printf("This are the following hostels :\n\n\t\t1. Phule \n\t\t2. Afpi\n\t\t3. Shivaji \n\t\t4.Bhabha\n\t\t5.Tilak\n\t\t6.Sv\n\t\t7.Bhaskar\n\t\t8.Raman\n\n");
    printf("Enter your choice :");
    scanf("%d",&choice);

    FILE *fp, *hostel;
    switch(choice)
    {
        case 1: hostel=fopen("Phule.dat","a+");break;
        case 2: hostel=fopen("Afpi.dat","a+");break;
        case 3: hostel=fopen("Shivaji.dat","a+");break;
        case 4: hostel=fopen("Bhabha.dat","a+");break;
        case 5: hostel=fopen("Tilak.dat","a+");break;
        case 6: hostel=fopen("Sv.dat","a+");break;
        case 7: hostel=fopen("Bhaskar.dat","a+");break;
        case 8: hostel=fopen("Raman.dat","a+");break;
        default: sorter();
    }
    while(fscanf(hostel,"%s\n",check.Gr_no)!=EOF)
    {
        fp=fopen("record.dat","r");
        while(fscanf(fp,"%s %s %s %d %s %s %s  %s %s %s %d %s \n",sort.Gr_no, sort.name,sort.sname, &sort.age,sort.depart, sort.city, &sort.phone_no, sort.mail_id, sort.father_name, &sort.father_phone_no, &sort.room_no, sort.hostel_name)!=EOF)
        {
            if(strcmp(check.Gr_no,sort.Gr_no)==0)
            {
                if(test==0)
                {
                    printf("\t\tFollowing is the list of requested students:");
                    printf("\n\tGr_no.\tNAME\tROOM NO.\n");
                }
                printf("\n\t%s\t %s %s\t %d", sort.Gr_no,sort.name,sort.sname, sort.room_no);
                test++;
            }
        }
    }

    fclose(fp);
    if (test==0)
        printf("\nNO RECORDS!!\n");

    sort_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1)
        menu();
    else if(main_exit==0)
        closer();
    else
    {
        printf("\nInvalid!\a");
        goto sort_list_invalid;
    }

}


void new_entry()
{
    system("CLS");
    int choice;
    FILE *ptr,*hostel;

    ptr=fopen("record.dat","a+");
    Gr_no:

    printf("\t\t\t\** ADD STUDENTS DATA **");
    printf("\nEnter your Gr_no:");
    scanf("%s",check.Gr_no);
    while(fscanf(ptr,"%s %s %s %d  %s %s %s %s %s %s %d %s\n",add.Gr_no, add.name,add.sname, &add.age,add.depart, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, &add.room_no, add.hostel_name)!=EOF)
    {
        if (strcmp(check.Gr_no,add.Gr_no)==0)
            {printf("Students Gr_no already in use!");
             goto Gr_no;
        }
    }
int in=1,an,j,flag=0;
char anu;
strcpy(add.Gr_no,check.Gr_no);
    while(in!=0){
    printf("\nEnter the name:");
    scanf("%s",add.name);
    an=strlen(add.name);
    for(j=0;j<an;j++){
            anu=add.name[j];
        if(isalpha(anu)==0){
        flag=1;
        break;}
        else
            flag=0;
    }
    if(flag==1){
            printf("Please re-enter the name\n");

        }
    else{
        in=0;

        }

    }
    in=1;
     while(in!=0){
    printf("\nEnter the surname:");
    scanf("%s",add.sname);
    an=strlen(add.sname);
    for(j=0;j<an;j++){
            anu=add.sname[j];
        if(isalpha(anu)==0){
        flag=1;
        break;}
        else
            flag=0;
    }
    if(flag==1){
            printf("Please re-enter the surname\n");

        }
    else{
        in=0;

        }
     }

int tin=1;
while(tin!=0){
        printf("\n Enter the age:");
scanf("%d",&add.age);
if(add.age>=18&&add.age<=28){
    tin=0;
    break;}
else {printf("\n Invalid");
tin=1;
}
} in=1;
     while(in!=0){
    printf("\nEnter the Department:");
    scanf("%s",add.depart);
    an=strlen(add.depart);
    for(j=0;j<an;j++){
            anu=add.depart[j];
        if(isalpha(anu)==0){
        flag=1;
        break;}
        else{
                if(strcmp(add.depart,"cse")==0){
            flag=0;
            break;

            }

            else if(strcmp(add.depart,"entc")==0){
            flag=0;
           // break;
            }
            else if(strcmp(add.depart,"mech")==0)
            {

             flag=0;
            // break;
             }
            else if(strcmp(add.depart,"civil")==0)
            {
             flag=0;

            }
            else if(strcmp(add.depart,"chemical")==0){
             flag=0;
             }
        else{
            flag=1;

        }    }
    }
    if(flag==1){
            printf("\n Please re-enter the Department");


        }
    else{
        in=0;

        }
     }



    in=1;
     while(in!=0){
    printf("\nEnter the city:");
    scanf("%s",add.city);
    an=strlen(add.city);
    for(j=0;j<an;j++){
            anu=add.city[j];
        if(isalpha(anu)==0){
        flag=1;
        break;}
        else
            flag=0;
    }
    if(flag==1){
            printf("\n please re-enter the city");

        }
    else{
        in=0;

        }
     }

int x1,y1,z1,lag=0;
    char bk;

  int im=1;
 while(im!=0)
 {
 printf("\nEnter the phone number:");
 scanf("%s",add.phone_no);
 x1=strlen(add.phone_no);
 if(x1==10)
 {
 for(y1=0;y1<x1;y1++)
 {
     bk=add.phone_no[y1];
     if(isdigit(bk)==0)
     {
       lag=1;
         break;
     }
     else
        lag=0;

 }
 }
 else
 {
     lag=1;}
 if(lag==1)
 {
     printf("\n Something went wrong");

 }
 else
 {
 im=0;
 }

}
    int x,y,z,dot=0;
    char b,c,d;
  int i=1;
 while(i!=0)
 {
 printf("\n Enter the email id :");
scanf("%s",add.mail_id);
 x=strlen(add.mail_id);
 for(y=0;y<x;y++)
 {
     b=add.mail_id[y];
     if(b=='@')
     {
         flag=1;
     }
     if(b=='.')
     {
         dot=1;
         z=y;
     }
 }
 if(flag==1&&dot==1&&x-z>3)
 {
     i=0;
 }
 else
 {
 printf("\n Email is wrong please re-enter :");
 }

}

    in=1;
     while(in!=0){
    printf("\nEnter the father name:");
    scanf("%s",add.father_name);
    an=strlen(add.father_name);
    for(j=0;j<an;j++){
            anu=add.father_name[j];
        if(isalpha(anu)==0){
        flag=1;
        break;}
        else
            flag=0;
    }
    if(flag==1){
            printf("\n Please re-enter the father name");

        }
    else{
        in=0;

        }
     }
 char ck;
 int x2,y2,z2,tag=0;
  int ip=1;
 while(ip!=0)
 {
 printf("\nEnter your Father's phone no :");
 scanf("%s",&add.father_phone_no);
 x2=strlen(add.father_phone_no);
 if(x2==10)
 {
 for(y2=0;y2<x2;y2++)
 {
     ck=add.father_phone_no[y2];
     if(isdigit(ck)==0)
     {
         tag=1;
         break;
     }
     else
        tag=0;

 }
 }
 else
 {
    tag=1;}
 if(tag==1)
 {
     printf("\n something went wrong");

 }
 else
 {
 ip=0;
 }

}

    printf("\n Enter your hostel name from Phule,Afpi,Shivaji,Bhabha,Tilak,Sv,Bhaskar,Raman:");
    scanf("%s",add.hostel_name);

    printf("\n --------------------------Each Hostel contains 33 rooms------------------------!!!!");

int bin=1;
while(bin!=0){
        printf("\n enter the room no:");
scanf("%d",&add.room_no);
if(add.room_no>=1&&add.room_no<=33){
    bin=0;
    break;}
else {printf("\n invalid");
bin=1;
}
}





        fprintf(ptr,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname,add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);


    if(strcmp(add.hostel_name,"Phule")==0)
    {
        hostel=fopen("Phule.dat","a+");
        fprintf(hostel,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname,add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);

        fclose(hostel);}
    else if(strcmp(add.hostel_name,"Afpi")==0)
    {
        hostel=fopen("Afpi.dat","a+");
        fprintf(hostel,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname,add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
        fclose(hostel);
    }
    else if(strcmp(add.hostel_name,"Shivaji")==0)
    {
        hostel=fopen("Shivaji.dat","a+");
        fprintf(hostel,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname,add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
        fclose(hostel);
    }
    else if(strcmp(add.hostel_name,"Bhabha")==0)
    {
        hostel=fopen("Bhabha.dat","a+");
        fprintf(hostel,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname,add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
        fclose(hostel);
    }
    else if(strcmp(add.hostel_name,"Tilak")==0)
    {
        hostel=fopen("Tilak.dat","a+");
        fprintf(hostel,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname,add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
        fclose(hostel);
    }
    else if(strcmp(add.hostel_name,"Sv")==0)
    {
        hostel=fopen("Sv.dat","a+");
        fprintf(hostel,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname,add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
        fclose(hostel);
    }
    else if(strcmp(add.hostel_name,"Bhaskar")==0)
    {
        hostel=fopen("Bhaskar.dat","a+");
        fprintf(hostel,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname,add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
        fclose(hostel);
    }
    else if(strcmp(add.hostel_name,"Raman")==0)
    {
        hostel=fopen("Raman.dat","a+");
        fprintf(hostel,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname,add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
        fclose(hostel);
    }


    fclose(ptr);
    printf("\n Student added successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1)

        menu();
    else if(main_exit==0)
            closer();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_list()
{
    system("CLS");
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;

    printf("\nGr_no\t\t\tNAME\t\t\tCity\t\t\tROOM ALLOTED\n");

    while(fscanf(view,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname, &add.age,add.depart, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, &add.room_no, add.hostel_name)!=EOF)
       {
           printf("\n%11s\t\t %s %s\t\t\t %s\t\t\t %d\t\t\t",add.Gr_no,add.name,add.sname,add.city,add.room_no);
           test++;
       }
    fclose(view);

    if (test==0)
        {
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            menu();
        else if(main_exit==0)
            closer();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void see()
{
    system("CLS");
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.dat","r+");
    printf("Do you want to check by\n1.Gr_no \nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("\n\nEnter the Gr_no:");
        scanf("%s",check.Gr_no);

        while (fscanf(ptr,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname, &add.age,add.depart, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, &add.room_no, add.hostel_name)!=EOF)
        {
            if(strcmp(add.Gr_no,check.Gr_no)==0)
            {
                test=1;

                printf("\nGr_no:%s\nName:%s %s  \nAge:%d \n Department: %s \ncity:%s \nPhone number:%s \nE-Mail id:%s \nFather's name:%s %s \n Father's Phone No.:%s \nRoom No:%d \nHostel:%s\n",add.Gr_no, add.name,add.sname, add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name,add.sname, add.father_phone_no, add.room_no, add.hostel_name);
            }
        }
    }


    fclose(ptr);
     if(test!=1)
        printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto see_invalid;
        }
}
void edit()
{
    system("CLS");
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r+");
    newrec=fopen("new.dat","w");

    printf("\nEnter the Gr_no of the student whose information you want to change:");
    scanf("%s",upd.Gr_no);
    while(fscanf(old,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname, &add.age,add.depart, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, &add.room_no, add.hostel_name)!=EOF)

    {
        if (strcmp(add.Gr_no,upd.Gr_no)==0)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Room no.\n2.Phone\n3. name\n4. hostel\n5. email id\n6. age\n\nEnter your choice:");
            scanf("%d",&choice);

            if(choice==1)
                {

printf("\n --------------------------Each Hostel contains 33 rooms------------------------!!!!");

int bin=1;
while(bin!=0){
        printf("\n enter the new room no:");
scanf("%d",&upd.room_no);
if(upd.room_no>=1&&upd.room_no<=33){
    bin=0;
    break;}
else {printf("\n invalid");
bin=1;
}
}fprintf(newrec,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname, add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, upd.room_no, add.hostel_name);
                printf("Changes saved!!!!");

                }
            else if(choice==2)
                { int x1,y1,z1,lag=0;
                   char bk;

                   int im=1;
 while(im!=0)
 {
 printf("\nEnter  the student new phone number:");
 scanf("%s",upd.phone_no);
 x1=strlen(upd.phone_no);
 if(x1==10)
 {
 for(y1=0;y1<x1;y1++)
 {
     bk=upd.phone_no[y1];
     if(isdigit(bk)==0)
     {
       lag=1;
         break;
     }
     else
        lag=0;

 }
 }
 else
 {
     lag=1;}
 if(lag==1)
 {
     printf("\n Something went wrong");

 }
 else
 {
 im=0;
 }

}

 fprintf(newrec,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname, add.age,add.depart, add.city, upd.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
  printf("Changes saved!");
    }


        else if(choice==3)
        {
            int in=1,an,j,flag=0;
char anu;
             while(in!=0){
    printf("\nEnter the name:");
    scanf("%s",upd.name);
    an=strlen(upd.name);
    for(j=0;j<an;j++){
            anu=upd.name[j];
        if(isalpha(anu)==0){
        flag=1;
        break;}
        else
            flag=0;
    }
    if(flag==1){
            printf("Please re-enter the name\n");

        }
    else{
        in=0;

        }

    }

 fprintf(newrec,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, upd.name,add.sname, add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
            printf("Changes saved!");
        }
        else if(choice==4){
        printf("Enter the new hostel:");
                scanf("%s",&upd.hostel_name);
                fprintf(newrec,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname, add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, upd.hostel_name);
                printf("Changes saved!");}
                 else if(choice==5){
                         int x,y,z,dot=0;
    char b,c,d;
  int i=1,flag=0;
 while(i!=0)
 {
 printf("\n Enter the new email id :");
scanf("%s",upd.mail_id);
 x=strlen(upd.mail_id);
 for(y=0;y<x;y++)
 {
     b=upd.mail_id[y];
     if(b=='@')
     {
         flag=1;
     }
     if(b=='.')
     {
         dot=1;
         z=y;
     }
 }
 if(flag==1&&dot==1&&x-z>3)
 {
     i=0;
 }
 else
 {
 printf("\n Email is wrong please re-enter :");
 }

}

                fprintf(newrec,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname, add.age,add.depart, add.city, add.phone_no, upd.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
                printf("Changes saved!");}
                 else if(choice==6){
                        int tin=1;
while(tin!=0){
        printf("\n Enter the new age:");
scanf("%d",&upd.age);
if(upd.age>=18&&upd.age<=28){
    tin=0;
    break;}
else {printf("\n Invalid");
tin=1;
}
}

fprintf(newrec,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname, upd.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
                printf("Changes saved!");}
                break;
                }
        else
            fprintf(newrec,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname, add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
        printf("\nRecord not found!!\a\a\a");

    edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            edit();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }

}

void erase()
{
    system("CLS");
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the Gr_no of student whose data you want to delete:");
    scanf("%s",rem.Gr_no);
    while (fscanf(old,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name, &add.age,add.sname,add.depart, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, &add.room_no, add.hostel_name)!=EOF)
   {
        if(strcmp(add.Gr_no,rem.Gr_no)!=0)
            fprintf(newrec,"%s %s %s %d %s %s %s %s %s %s %d %s \n",add.Gr_no, add.name,add.sname, add.age,add.depart, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, &add.room_no, add.hostel_name);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
        printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
}

void closer()
{
    system("CLS");
    printf("\n\n\n*THANK YOU*\n\n\n");
}

int pass(void)
{
   int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
    system("cls");

    printf("\n  *  LOGIN FORM  *  ");
    printf(" \n                       ENTER USERNAME:-");
    scanf("%s", &uname);
    printf(" \n                       ENTER PASSWORD:-");
    while(i<10)
    {
        pword[i]=getch();
        c=pword[i];
        if(c==13) break;
        else printf("*");
        i++;
    }
    pword[i]='\0';

    i=0;
        if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
    {
    printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
    system("PAUSE");
    break;
    }
    else
    {
        printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
        system("PAUSE");
        a++;

        getch();

    }
}
    while(a<=25);
    if (a>2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getch();

        }
        system("cls");
}