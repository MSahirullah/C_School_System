
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#define MAXCHAR 500

int current_year_ex_c();                        //getting current year from computer date
int stu_details_ex_c(int grd, char cls[5]);     //reading the students details from file and storing in structure(term_stu)
int menu_form();                                //menu form
int chek_grd_cls_ex_c(int grd, char cls[5]);

struct ex_c_activities
{
    char year[10];                          //structures to store extracurricular activity details
    char term[10];
    int grade;
    char cls[10];
}ex_c_d;

struct ex_c_stu
{
    char index[100];                        //structure to stores student details, marks and rank
    char name[100];
    int point;
    char comment[250];
}ex_c_stu_d[100];

int task_b ()
{
    printf("\n---- Students' Engagement in Extracurricular Activities ----");

    FILE *file_b;

    if ((file_b = fopen("File_B.txt", "a+")) == NULL)
    {
        printf("File open error");
    }

    while(1)
    {
        int num_of_stu;
        int y, z;
        int checker;
        char p[50], q[10];

        printf("\n\n--Enter The Details of The Extracurricular Activities--\n\n");
        sprintf(ex_c_d.year, "%d", current_year_ex_c());
        printf("Year          : %s\n", ex_c_d.year);

        z = 0;

        while(1)
        {
            printf("Term          : ");
            scanf(" %[^\n]", ex_c_d.term);

            strcpy(p, ex_c_d.term);

            if (strcmp(p, "First") == 0 || strcmp(p, "Second") == 0 || strcmp(p, "Third") == 0)
            {
                while (1)
                {
                    printf("Grade & Class : ");
                    scanf("%d %[^\n]", &ex_c_d.grade, &q);

                    strcpy(ex_c_d.cls, q);
                    checker = chek_grd_cls_ex_c(ex_c_d.grade, ex_c_d.cls);

                    if (checker == 1)
                    {
                        z = 1;
                        break;
                    }
                    else
                    {
                        printf("ERROR!. Grade does not exist. Please input valid Grade & Class.\n\n");
                    }
                }
            }
            else
            {
                printf("ERROR!. Your input is incorrect. Please input valid Term.\n\n");
            }
            if (z == 1)
            {
                break;
            }
        }

        num_of_stu = stu_details_ex_c(ex_c_d.grade, ex_c_d.cls);

        printf("\n\n--Enter The Students' Details of The Extracurricular Activities--\n");
        printf("\nNumber of Students : %d\n", num_of_stu);

        for (y=0; y<num_of_stu; y++)
        {
            int tr_point = 0;
            z = 0;

            while(1)
            {
                printf("\nStudent Index    : %s", ex_c_stu_d[y].index);
                printf("\nStudent Name     : %s", ex_c_stu_d[y].name);
                printf("\nStudent's Points : ");
                scanf("%d", &tr_point);

                if (tr_point <= 10)
                {
                    printf("Activities (use comma to separate) : ");
                    scanf(" %[^\n]", ex_c_stu_d[y].comment);



                    ex_c_stu_d[y].point = tr_point;


                    break;
                }
                else
                {
                        printf("ERROR!. Your input is incorrect. Please input points correctly.\n\n");
                }

            }
            if (z == num_of_stu)
            {
                break;
            }
        }

        char temp_fr[10];

        fprintf(file_b, "%s Term Test - %s \n", ex_c_d.term, ex_c_d.year );
        fprintf(file_b, "Grade : %d - %s \n\n", ex_c_d.grade, ex_c_d.cls);

        fprintf(file_b, "%-15s |%-30s |%-15s |%-250s", "Index No.", "Student Name", "Points", "Details");

        fprintf(file_b,"\n");

        fprintf(file_b, "----------------|-------------------------------|----------------|");

        for(y=0; y<250; y++)
        {
            fprintf(file_b,"-");
        }

        fprintf(file_b, "|\n");

        for(y=0; y<num_of_stu; y++)
        {
            fprintf(file_b, "%-16s", ex_c_stu_d[y].index);
            fprintf(file_b, "|%-31s", ex_c_stu_d[y].name);

            sprintf(temp_fr, "%d", ex_c_stu_d[y].point);
            fprintf(file_b, "|%-16s", temp_fr);

            fprintf(file_b, "|%-251s", ex_c_stu_d[y].comment);

            fprintf(file_b,"\n");
        }

        fprintf(file_b,"\n\n");

        fflush(file_b);
        printf("\nExtracurricular Activity details stored successfully!\n");

        char chr_1, chr_2;
        z = 0;

        while (1)
        {
            printf("\nNeed to include a another Extracurricular Activity details? (Y/N) : ");
            scanf(" %c", &chr_1);

            if (chr_1 == 'N' || chr_1 == 'n')
            {
                fclose(file_b);
                printf("\nNeed to go to the main menu?? (Y/N) : ");
                scanf(" %c", &chr_2);

                if(chr_2 == 'Y' || chr_2 == 'y')
                {
                    z = 1;
                    menu_form();
                    break;
                }
                else if (chr_2 == 'N' || chr_2 == 'n')
                {
                    exit(0);
                }
                else
                {
                    printf("Error. Your input is incorrect. Please try again.\n\n");
                }
            }
            else if (chr_1 == 'Y' || chr_1 == 'y')
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
            break;
        }
    }

	return 0;
}

int stu_details_ex_c(int grd, char cls[5])
{
    int w = 0, x = 0;
    char *spl_list;
    char *spl_text;
    char str_rcd[MAXCHAR];
    char tr_grade[5];
	char tr_index[10];
    char tr_name[100];

    FILE *file_a;

    sprintf(tr_grade, "%d", grd);

    if ((file_a = fopen("File_A.txt", "r")) != NULL)
    {
        while(fgets(str_rcd, MAXCHAR, file_a) != NULL)
        {
            if (w > 3)
			{
                spl_list = strtok(str_rcd, " |");

                strcpy(tr_index, spl_list);
                spl_list = strtok(NULL, " |");
                strcpy(tr_name, spl_list);

                spl_list = strtok(NULL, " |");
                spl_list = strtok(NULL, " |");
                spl_list = strtok(NULL, " |");

                if (strcmp(spl_list, tr_grade) == 0)
                {
                    spl_list = strtok(NULL, " |");
                    spl_text = strtok(spl_list, "\n");

                    if(strcmp(spl_text, cls) == 0)
                    {
                        strcpy(ex_c_stu_d[x].index, tr_index);

                        strcpy(ex_c_stu_d[x].name, tr_name);
                        x++;
                    }
                }                                   //increasing the structure index
            }
            w++;                                    //increasing the number of read line
        }
    }
    else
    {
        printf("File open error");
    }

    fclose(file_a);
    return x;
}

int chek_grd_cls_ex_c(int grd, char cls[5])
{
    int chk = 0, v = 0, w = 0, x = 0;
    char *spl_list;
    char *spl_text;
    char str_rcd[MAXCHAR];
    char tr_grade[5];

    FILE *file_a;

    sprintf(tr_grade, "%d", grd);

    if ((file_a = fopen("File_A.txt", "r")) != NULL)
    {
        while(fgets(str_rcd, MAXCHAR, file_a) != NULL)
        {
            if (w > 3)
			{
                spl_list = strtok(str_rcd, " |");
				spl_list = strtok(NULL, " |");
				spl_list = strtok(NULL, " |");
				spl_list = strtok(NULL, " |");
				spl_list = strtok(NULL, " |");

				if(strcmp(spl_list, tr_grade) == 0)
				{
					spl_list = strtok(NULL, " |");
					spl_text = strtok(spl_list, "\n");

					if(strcmp(spl_text,cls) == 0)
					{
						chk = 1;
						break;
					}
					x++;
				}
				v++;
			}
			w++;
		}
	}
    else
    {
        printf("File open error");
    }
    fclose(file_a);

    return chk;
}

int current_year_ex_c()
{
    int yr;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    yr = t->tm_year+1900;
    return yr ;
}
