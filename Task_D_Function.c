#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#define MAXCHAR 500
struct Sub_Leaders{
    char leader_index[50];
    char leader_name[50];
}s1[13];

struct tot_array{

float TOT[10];
char class_monitor_name[50];
char class_monitor_index[50];

}monitor_d;

struct sub_name{

char subject_name[100];
};

struct sub_marks{
char  marks[10];
 };

struct Ave_Point{

char ave[10];
char pnt[10];
};

struct students

{
    char index[100];
    char name[100];
    struct sub_marks sub_M_d[13];
    struct sub_name sub_N_d[13];
    char total[10];
    struct Ave_Point average_d[10];
    char stu_rank[10];
    struct Ave_Point points_d[10];
}stu_details[100];

struct Grd_Cls_Yr_Trm
{
char grade[20];
char cls[20];
char year[20];
char term[20];

}term_deails;

int readfromfile_b(char i_year[20], char i_term[20], char i_grade[20], char i_class[20]);
int readfromfile_c(char i_year[20], char i_term[20], char i_grade[20], char i_class[20]);
int sub_lis(int ui_grd);
int menu_form();

void Sub_Leaders(int No_Of_stu,int ui_grd)
{
printf("\n------------Subject Leaders------------\n");
int higest_mark=0;
int var1;

if(ui_grd==5)
{
char *sub_array_1[] = {"Religion", "Language", "English", "Maths ", "Environment"};


for(int j=0;j<ui_grd;j++)

    {
    for(int k=0;k<No_Of_stu;k++)
    {
        if(higest_mark< atoi(stu_details[k].sub_M_d[j].marks))
        {
            higest_mark= atoi(stu_details[k].sub_M_d[j].marks);
            var1 = k;
        }
    }

    printf("\n\nThe highest mark of subject %s is %d",sub_array_1[j],higest_mark);
    printf("\n\nThe Leader of the subject %s is %s %s \n",sub_array_1[j],stu_details[var1].index,stu_details[var1].name);
    strcpy(s1[j].leader_index,stu_details[var1].index);
    strcpy(s1[j].leader_name,stu_details[var1].name);
    higest_mark=0;
    }

}else if(ui_grd==9)

{

char *sub_array_2[] = {"Religion", "Language", "English", "Maths  ", "Science", "History", "H.P.E", "Second. Lang.", "P.T.S", "Geography", "Civits", "Basket Sub."};

for(int j=0;j<ui_grd;j++)

    {
    for(int k=0;k<No_Of_stu;k++)
    {
        if(higest_mark<atoi(stu_details[k].sub_M_d[j].marks))
        {
            higest_mark=atoi(stu_details[k].sub_M_d[j].marks);
             var1 = k;
        }
    }

    printf("\n\nThe highest mark of subject %s is %d",sub_array_2[j],higest_mark);
    printf("\n\nThe Leader of the subject %s is %s %s \n",sub_array_2[j],stu_details[var1].index,stu_details[var1].name);
    strcpy(s1[j].leader_index,stu_details[var1].index);
    strcpy(s1[j].leader_name,stu_details[var1].name);
    higest_mark=0;
    }

}else
{
char *sub_array_3[] = {"Religion", "Language", "English", "Maths  ", "Science", "History", "Basket Sub I", "Basket Sub II", "Basket Sub III"};

for(int j=0;j<ui_grd;j++)

    {
    for(int k=0;k<No_Of_stu;k++)
    {
        if(higest_mark<atoi(stu_details[k].sub_M_d[j].marks))
        {
            higest_mark=atoi(stu_details[k].sub_M_d[j].marks);
             var1 = k;
        }
    }
    printf("\n\nThe highest mark of subject %s is %d",sub_array_3[j],higest_mark);
    printf("\n\nThe Leader of the subject %s is %s %s \n",sub_array_3[j],stu_details[var1].index,stu_details[var1].name);
    strcpy(s1[j].leader_index,stu_details[var1].index);
    strcpy(s1[j].leader_name,stu_details[var1].name);
    higest_mark=0;
    }
}
}

void Class_Monitor(int No_Of_stu)
{

printf("\n---------------Class Monitor---------------\n");
float higest_tot=0;
float AVE,TOT,EXE;
int var1;


    for(int k=0;k<No_Of_stu;k++)
        {

            AVE = atof(stu_details[k].average_d[k].ave) * 0.7;

            EXE = atof(stu_details[k].points_d[k].pnt)* 0.3;

            TOT = AVE+EXE;
            monitor_d.TOT[k] = TOT;

        }
        for(int a=0;a<No_Of_stu;a++)
            {
                if(higest_tot<monitor_d.TOT[a])
                {

                    higest_tot=monitor_d.TOT[a];
                     var1=a;

                }
            }

printf("\nThe Class Monitor Of the Class %s - %s is :  %s - %s \n",term_deails.grade,term_deails.cls ,stu_details[var1].index,stu_details[var1].name);
strcpy(monitor_d.class_monitor_index,stu_details[var1].index);
strcpy(monitor_d.class_monitor_name,stu_details[var1].name);

}

int task_d()
{
    printf("\n--------------------------------------------------------------------------------");
    printf("   Class Monitors and Subject Leaders\n");
    printf("--------------------------------------------------------------------------------\n");

    char i_grade[20];
    char i_year[20];
    char i_term[20];
    char i_class[20];

    printf("\nEnter the term:");
    scanf("%s",i_term);
    if (strcmp(i_term, "First") == 0 || strcmp(i_term, "Second") == 0 || strcmp(i_term, "Third") == 0)
        {
        printf("NEXT>>>");

        }else
        {
              printf("ERROR!. Your input is incorrect. Please input valid Term.\n\n");
              exit(0);
        }

    printf("\nEnter the Grade:");
    scanf("%s",i_grade);

  if (strcmp(i_grade, "1")==0 || strcmp(i_grade, "2")==0 ||strcmp(i_grade, "1")==0|| strcmp(i_grade, "3")==0||strcmp(i_grade, "4")==0 || strcmp(i_grade, "5")==0 ||strcmp(i_grade, "6")==0 || strcmp(i_grade, "8")==0|| strcmp(i_grade, "9")==0 ||strcmp(i_grade, "10")==0 || strcmp(i_grade, "11")==0)
        {
        printf("NEXT>>>");

        }else
        {
              printf("ERROR!. Your input is incorrect. Please input valid Term.\n\n");
              exit(0);
        }
    printf("\nEnter the Class:");
    scanf("%s",i_class);
    if (strcmp(i_class,"A")==0 || strcmp(i_class,"B")==0 || strcmp(i_class,"C")==0 || strcmp(i_class,"D")==0)
    {
        printf("NEXT>>>");

    }else
    {

    printf("ERROR!. Your input is incorrect. Please input valid Term.\n\n");
    exit(0);

    }

    printf("\nEnter the year:");
    scanf("%s",i_year);
    int No_Of_stu;
    int ui_grd;

    printf("\nEnter Number of student in the class:");
    scanf("%d",&No_Of_stu);

    printf("\nEnter Number of subjects:");
    scanf("%d",&ui_grd);

    Sub_Leaders( No_Of_stu, ui_grd);
    Class_Monitor(No_Of_stu);

FILE *file_d;

    if ((file_d = fopen("File_D.txt", "a+")) == NULL)

    {
        printf("Error in opening file");
    }

        fprintf(file_d, "\n\n~~~~~ %s Term Test - %s ~~~~~\n",term_deails.term, term_deails.year);
        fprintf(file_d, "Grade : %s - %s\n\n", term_deails.grade, term_deails.cls);

        fprintf(file_d,"\n");
        fprintf(file_d,"                 Class Monitor                 \n\n");
        fprintf(file_d,"\n");

        fprintf(file_d,"%-20s |%-20s ","Index No","Student Name");
        fprintf(file_d,"\n");
        fprintf(file_d, "---------------------|---------------------");
        fprintf(file_d,"\n");

        fprintf(file_d," %-20s|",monitor_d.class_monitor_index);
        fprintf(file_d," %-20s",monitor_d.class_monitor_name);
        fprintf(file_d,"\n\n\n\n");

       fprintf(file_d,"                 Subject Leaders                 \n\n\n");

        fprintf(file_d,"%-20s |%-20s |%-13s","Subject Name","Index No","Student Name");
        fprintf(file_d,"\n");
        fprintf(file_d, "---------------------|---------------------|-------------");
        int x;
         if (ui_grd <=5)
        {
        for (x=0; x<5; x++)
        {
             fprintf(file_d,"\n");

             fprintf(file_d," %-20s",stu_details[x].sub_N_d[x].subject_name);

             fprintf(file_d,"|%-21s",s1[x].leader_index);

             fprintf(file_d,"|%-13s",s1[x].leader_name);

        }

    }
    else if (ui_grd <= 9)
    {
        for (x=0; x<12; x++)
        {
             fprintf(file_d,"\n");


             fprintf(file_d," %-20s",stu_details[x].sub_N_d[x].subject_name);

             fprintf(file_d,"|%-21s",s1[x].leader_index);

             fprintf(file_d,"|%-13s",s1[x].leader_name);

        }

    }
    else if (ui_grd <= 11)
    {
        for (x=0; x<9; x++)
        {
             fprintf(file_d,"\n");


             fprintf(file_d," %-20s",stu_details[x].sub_N_d[x].subject_name);

             fprintf(file_d,"|%-21s",s1[x].leader_index);

             fprintf(file_d,"|%-13s",s1[x].leader_name);

        }
    }

         fclose(file_d);

    return 0;
}


int readfromfile_b(char i_year[20], char i_term[20], char i_grade[20], char i_class[20])
{
    int v = 0, x = 0;
    char *spl_list;
    char str_rcd[MAXCHAR];
    char tr_term[20];
    char tr_year[10];
    char tr_grade[10];
    char tr_class[10];

    FILE *file_b;

    if((file_b = fopen("File_B.txt", "r")) != NULL)
    {
        while(fgets(str_rcd, MAXCHAR, file_b) != NULL)
        {
            if(strcmp(str_rcd, "\n") == 0)
            {
                v++;
                continue;
            }

            if (v == 2)
            {
                spl_list = strtok(str_rcd, " -");
                strcpy(tr_term, spl_list);

                spl_list = strtok(NULL, " -");
                spl_list = strtok(NULL, " -");
                spl_list = strtok(NULL, " -");
                strcpy(tr_year, spl_list);

                if (strcmp(i_term, tr_term) == 0 && strcmp(i_year, tr_year) == 0)
                {
                    fgets(str_rcd, MAXCHAR, file_b);
                    spl_list = strtok(str_rcd, " :-");
                    spl_list = strtok(NULL, " :-");
                    strcpy(tr_grade, spl_list);

                    spl_list = strtok(NULL, " :-");
                    strcpy(tr_class, spl_list);

                    if(strcmp(i_grade, tr_grade) == 0 && strcmp(i_class, tr_class) == 0)
                    {
                        fgets(str_rcd, MAXCHAR, file_b);
                        fgets(str_rcd, MAXCHAR, file_b);
                        fgets(str_rcd, MAXCHAR, file_b);

                        while(fgets(str_rcd, MAXCHAR, file_b))
                        {
                            if(strcmp(str_rcd, "\n") == 0)
                            {
                                break;
                            }

                            spl_list = strtok(str_rcd, " |");
                            spl_list = strtok(NULL, " |");

                            spl_list = strtok(NULL, " |");
                            strcpy(stu_details[x].points_d[x].pnt, spl_list);


                            x++;
                        }
                    }
                }
            }
            v = 0;
        }
    }
    else
    {
        printf("File open error");
    }

    fclose(file_b);

         char chr_2, chr_3;
          int z = 0;
            FILE *file_d;
            file_d=fopen("File_D.txt","r");
        while (1)
        {

            printf("\n\nNeed to include an another  details? (Y/N) : ");
            scanf(" %c", &chr_2);

            if (chr_2 == 'N' || chr_2 == 'n')
            {
                fclose(file_d);
                printf("\n\nNeed to go to the main menu?? (Y/N) : ");
                scanf(" %c", &chr_3);

                if(chr_3 == 'Y' || chr_3 == 'y')
                {
                    z = 1;
                    menu_form();
                    break;
                }
                else if (chr_3 == 'N' || chr_3 == 'n')
                {
                    exit(0);
                }
                else
                {
                    printf("Error. Your input is incorrect. Please try again.\n\n");
                }
            }
            else if (chr_2 == 'Y' || chr_2 == 'y')
            {
                break;
            }
            else
            {
                printf("Error. Your input is incorrect. Please try again.\n\n");
            }
        }

        if (z == 1)
        {
          exit(0);
        }

    return 0;
}

int readfromfile_c(char i_year[20], char i_term[20], char i_grade[20], char i_class[20])
{
    int i, v = 0, x = 0;
    int sub_count;
    char *spl_list;
    char str_rcd[MAXCHAR];
    char tr_term[20];
    char tr_year[20];
    char tr_grade[20];
    int tr_grade_num;
    char tr_class[20];


    FILE *file_c;

    if((file_c = fopen("File_C.txt", "r")) != NULL)
    {
        while(fgets(str_rcd, MAXCHAR, file_c) != NULL)
        {
            if(strcmp(str_rcd, "\n") == 0)
            {
                v++;
                continue;
            }

            if (v == 2)
            {
                spl_list = strtok(str_rcd, " -");
                strcpy(tr_term, spl_list);

                spl_list = strtok(NULL, " -");
                spl_list = strtok(NULL, " -");
                spl_list = strtok(NULL, " -");
                strcpy(tr_year, spl_list);

                if (strcmp(i_term, tr_term) == 0 && strcmp(i_year, tr_year) == 0)
                {
                    fgets(str_rcd, MAXCHAR, file_c);

                    spl_list = strtok(str_rcd, " :-");
                    spl_list = strtok(NULL, " :-");
                    strcpy(tr_grade, spl_list);

                    spl_list = strtok(NULL, " :-");
                    strcpy(tr_class, spl_list);

                    if(strcmp(i_grade, tr_grade) == 0 && strcmp(i_class, tr_class) == 0)
                    {
                        strcpy(term_deails.year, tr_year);
                        strcpy(term_deails.term, tr_term);
                        strcpy(term_deails.grade, tr_grade);
                        strcpy(term_deails.cls, tr_class);

                        fgets(str_rcd, MAXCHAR, file_c);
                        fgets(str_rcd, MAXCHAR, file_c);
                        fgets(str_rcd, MAXCHAR, file_c);

                        tr_grade_num = atoi(tr_grade);

                        sub_count = sub_lis(tr_grade_num);

                        while(fgets(str_rcd, MAXCHAR, file_c))
                        {
                            if(strcmp(str_rcd, "\n") == 0)
                            {
                                break;
                            }

                            spl_list = strtok(str_rcd, " |");
                            strcpy(stu_details[x].index, spl_list);

                            spl_list = strtok(NULL, " |");
                            strcpy(stu_details[x].name, spl_list);

                            spl_list = strtok(NULL, " |");

                            for(i=0; i<sub_count; i++)
                            {
                                strcpy(stu_details[x].sub_M_d[i].marks, spl_list);
                                    spl_list = strtok(NULL, " |");
                            }

                            strcpy(stu_details[x].total, spl_list);

                            spl_list = strtok(NULL, " |");
                            strcpy(stu_details[x].average_d[x].ave, spl_list);

                            spl_list = strtok(NULL, " |");
                            strcpy(stu_details[x].stu_rank, spl_list);

                            x++;
                        }
                    }
                }
            }
            v = 0;
        }
    }
    else
    {
        printf("File open error");
    }

    fclose(file_c);

    return 0;
}

int sub_lis(int ui_grd)
{

    int x, sub_con;

    char *sub_array_1[] = {"Religion", "Language", "English", "Maths  ", "Environment"};
    char *sub_array_2[] = {"Religion", "Language", "English", "Maths  ", "Science", "History", "H.P.E", "Second. Lang.", "P.T.S", "Geography", "Civits", "Basket Sub."};
    char *sub_array_3[] = {"Religion", "Language", "English", "Maths  ", "Science", "History", "Basket Sub I", "Basket Sub II", "Basket Sub III"};

    if (ui_grd <=5)
    {
        for (x=0; x<5; x++)
        {
            strcpy(stu_details[x].sub_N_d[x].subject_name, sub_array_1[x]);
        }

        sub_con = 5;
    }
    else if (ui_grd <= 9)
    {
        for (x=0; x<12; x++)
        {
            strcpy(stu_details[x].sub_N_d[x].subject_name, sub_array_2[x]);
        }

        sub_con = 12;
    }
    else if (ui_grd <= 11)
    {
        for (x=0; x<9; x++)
        {
            strcpy(stu_details[x].sub_N_d[x].subject_name, sub_array_3[x]);
        }

        sub_con = 9;
    }
    return sub_con;
}
