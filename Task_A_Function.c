#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void deleterec();
void modify();


struct student
{
    char name_in_full[20];
    char date_of_birth[20];
    int birth_year;
    int current_year;
    int grade;
    char class_name[5];
    char gender[20];
    char guardian_name[20];
    char address[30];
    char mobile_number[10];


};

int task_a()
{
    printf("\n--------------------------------------------------------------------------------");
    printf("   New Admission\n");
    printf("--------------------------------------------------------------------------------\n");

    menu();

    return 0;
}
void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("<--:                        MENU                              :-->");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.\n");
    gotoxy(10,6);
    printf("_____________________________________________________");
    gotoxy(10,8);
    printf("1 : Add Record.");
    gotoxy(10,9);
    printf("2 : View All Student Information");
    gotoxy(10,10);
    printf("3 : Search Student Record.");
    gotoxy(10,11);
    printf("4 : Modify Student Record.");
     gotoxy(10,12);
    printf("5 : Delete.");
    gotoxy(10,13);
    printf("6 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;


    case 6:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("student_admission_detail.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {

        gotoxy(10,3);
        printf("<--:                        ADD RECORD                         :-->");
        gotoxy(10,5);
        printf("Enter details of student.");
        gotoxy(10,6);
        printf("_________________________");

        gotoxy(10,7);
        printf("Enter Name_in_full : ");
        gets(std.name_in_full);

        gotoxy(10,8);
        printf("Enter date_of_birth : ");
        gets(std.date_of_birth);

        gotoxy(10,9);
        printf("Enter birth_year : ");
        scanf("%d",&std.birth_year);

        gotoxy(10,10);
        printf("Enter current_year : ");
        scanf("%d",&std.current_year);

        gotoxy(10,11);
        printf("Enter grade : ");
        scanf("%d",&std.grade);
        fflush(stdin);

        gotoxy(10,12);
        printf("Enter class name : ");
        gets(std.class_name);

        gotoxy(10,13);
        printf("Enter gender: ");
        gets(std.gender);

        gotoxy(10,14);
        printf("Enter guardian_name: ");
        gets(std.guardian_name);


        gotoxy(10,15);
        printf("Enter address : ");
        gets(std.address);

        gotoxy(10,16);
        printf("Enter Mobile Number : ");
        gets(std.mobile_number);


        fwrite(&std,sizeof(std),1,fp);
        gotoxy(10,20);
        printf("Successful Added Details\n");
        gotoxy(10,21);
        printf("press enter\n");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);

    }
    fclose(fp);
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:               VIEW ALL STUDENT INFORMATION                  :-->");
    gotoxy(10,5);
    printf("Index_no  |student_name                     |DOB           |age    |grade -class    |gender    |guardian     |address                             |mobile_no  ");
    gotoxy(10,6);
    printf("==========|=================================|==============|=======|================|==========|=============|====================================|===========");
    fp = fopen("student_admission_detail.txt","rb+");
    if(fp == NULL){
        gotoxy(10,9);
        printf("Error opening file.");
        exit(1);
    }
    j=7;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(7,j);
        printf("   %.4d      |%-30s   |%-11s   |%2d     |%2d    -%s        |%-7s   |%-10s   |%-30s      |%-10s  ",i,std.name_in_full,std.date_of_birth,std.current_year-std.birth_year,std.grade,std.class_name,std.gender,std.guardian_name,std.address,std.mobile_number);
        printf("\n");
        i++;
        j++;

    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press enter key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname_in_full[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:   SEARCH RECORD     :-->");
    gotoxy(10,5);
    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname_in_full);
    fp = fopen("student_admission_detail.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname_in_full,std.name_in_full) == 0){
            gotoxy(10,8);
            printf("Name : %s",std.name_in_full);

            gotoxy(10,9);
            printf("date_of_birth : %s",std.date_of_birth);

            gotoxy(10,10);
            printf("age : %d",std.current_year-std.birth_year);

            gotoxy(10,11);
            printf("grade : %d",std.grade);

            gotoxy(10,12);
            printf("class : %s",std.class_name);

            gotoxy(10,13);
            printf("gender : %s",std.gender);

            gotoxy(10,14);
            printf("guardian_name : %s",std.guardian_name);

            gotoxy(10,15);
            printf("address : %s",std.address);


            gotoxy(10,16);
            printf("Mobile Number : %s",std.mobile_number);

        }
    }
    fclose(fp);
    gotoxy(10,20);
    printf("Press enter  key to continue.");
    getch();
    menu();
}
void modify()
{
    char stname_in_full[20];
    FILE *fp;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:          MODIFY RECORD            :-->");
    gotoxy(10,5);
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname_in_full);
    fp = fopen("student_admission_detail.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname_in_full,std.name_in_full) == 0){
            gotoxy(10,7);
            printf("Enter name_in_full: ");
            gets(std.name_in_full);

            gotoxy(10,8);
            printf("Enter date_of_birth : ");
            fflush(stdin);
            gets(std.date_of_birth);

            gotoxy(10,9);
            printf("Enter birth_year : ");
            scanf("%d",&std.birth_year);

            gotoxy(10,10);
            printf("Enter current_year : ");
            scanf("%d",&std.current_year);

            gotoxy(10,11);
            printf("Enter grade : ");
            scanf("%d",&std.grade);

            gotoxy(10,12);
            printf("Enter class name : ");
            fflush(stdin);
            gets(std.class_name);

             gotoxy(10,13);
            printf("Enter gender : ");
            fflush(stdin);
            gets(std.gender);

             gotoxy(10,14);
            printf("Enter guardian_name : ");
            fflush(stdin);
            gets(std.guardian_name);


             gotoxy(10,15);
            printf("Enter address : ");
            fflush(stdin);
            gets(std.address);


            gotoxy(10,16);
            printf("Enter mobile number : ");
            gets(std.mobile_number);


            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,19);
    printf("Press enter key to continue.");
    getch();
    menu();
}
void deleterec()
{
    char stname_in_full[20];
    FILE *fp,*ft;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname_in_full);
    fp = fopen("student_admission_detail.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname_in_full,std.name_in_full)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("student_admission_detail.txt");
    rename("temp.txt","student_admission_detail.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}

void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


