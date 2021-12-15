#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#define MAXCHAR 1000

int current_year();                                     //getting current year from computer date
int stu_details(int grd, char cls[10]);                 //reading the students details from file and storing in structures(term_stu & temp_test)
int subject_list(int ui_grd);                           //updating the subjects in structure(subject_name) according to grade
int chek_grd_cls(int grd, char cls[10]);                //checking grade is valid or not
int check_input_num(char str[10]);                      //checking the given string is a numeric value
int check_input_marks(char mark_l[400], int st_con);    //checking the inputted marks count is equal to number of students
int menu_form();                                        //menu form


struct subject_name
{
    char sub_name[100];                                 //structure to store subject names
};

struct sub_marks
{
    int sub_marks;                                      //structure to store subject marks
};

struct term_test
{
    char year[10];                                      //structures to store term test details
    char term[10];
    int grade;
    char cls[10];
    struct subject_name sub_name_d[13];
}term_d;

struct temp_details
{
    char temp_index[100];                               //structure to temporarily store student index and average
    double temp_avg;
}temp_d[100];

struct term_stu
{
    char index[100];                                    //structure to stores student details, marks and rank
    char name[100];
    struct sub_marks sub_marks_d[13];
    int total;
    double average;
    int stu_rank;
}term_stu_d[100];

int task_c ()
{
    printf("\n\n\n--------------------------------------------------------------------------------");
    printf("   Result of Term Tests and Ranking   \n");
    printf("--------------------------------------------------------------------------------\n");

    FILE *file_c;
    if ((file_c = fopen("File_C.txt", "a+")) == NULL)
    {
        printf("File open error!");
    }

    while(1)
    {
        int num_of_stu, num_of_sub;
        int i, j, y, z;
        int checker;
        char p[50];

        //Inclusion of term examination information
        printf("\n-- Enter The Details of The Term Test --\n\n");
        sprintf(term_d.year, "%d", current_year());
        printf("Year          : %s\n", term_d.year);

        z = 0;
        checker = 0;
        while(1)
        {
            printf("Term          : ");
            scanf(" %[^\n]", term_d.term);

            strcpy(p, term_d.term);

            if (strcmp(p, "First") == 0 || strcmp(p, "Second") == 0 || strcmp(p, "Third") == 0)
            {
                while (1)
                {
                    printf("Grade & Class : ");
                    scanf("%d %[^\n]", &term_d.grade, term_d.cls);

                    checker = chek_grd_cls(term_d.grade, term_d.cls);

                    if (checker == 1)
                    {
                        z = 1;
                        break;
                    }
                    else
                    {
                        printf("ERROR!. Grade or Class does not exist. Please input valid Grade & Class.\n\n");
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

        num_of_stu = stu_details(term_d.grade, term_d.cls);

        num_of_sub = subject_list(term_d.grade);

        //Inclusion of marks obtained by students
        printf("\n\n-- Enter The Marks Obtained by The Students (Separate with space) --\n");
        printf("\nNumber of Students : %d\n", num_of_stu);

        for (y=0; y<num_of_sub; y++)
        {
            char mark_list[400];
            char mark_list_copy[400];
            char *spl_mark;
            z = 0;
            i = 0;

            while(1)
            {
                printf("\n%s \t: ", term_d.sub_name_d[y].sub_name);
                scanf(" %[^\n]", mark_list);

                strcpy(mark_list_copy, mark_list);

                checker = check_input_marks(mark_list_copy, num_of_stu);

                spl_mark = strtok(mark_list, " ");
                while(spl_mark != NULL)
                {
                    if(check_input_num(spl_mark) == 1 && checker == 1)
                    {
                        i = atoi (spl_mark);
                        if (i <= 100)
                        {
                            term_stu_d[z].sub_marks_d[y].sub_marks = i;
                            spl_mark = strtok(NULL, " ");
                            z++;

                        }
                        else
                        {
                            printf("ERROR!. Your input is incorrect. Please input correct Subject Marks.\n\n");
                            break;
                        }
                    }
                    else
                    {
                        printf("ERROR!. Your input is incorrect. Please input correct Subject Marks.\n\n");
                        break;
                    }
                }
                if (z == num_of_stu)
                {
                    break;
                }
            }
        }


        //calculate the total marks and average of each student store at the term_stu structure
        int mark, tot;
        double avg;

        for(y=0; y<num_of_stu; y++)
        {
            z = 0;
            tot = 0;

            for (z=0; z<num_of_sub; z++)
            {
                mark = term_stu_d[y].sub_marks_d[z].sub_marks;
                tot = tot + mark;
            }

            avg = (double) tot / num_of_sub;
            avg = roundf(avg*100)/100;

            term_stu_d[y].total = tot;
            term_stu_d[y].average = avg;
            temp_d[y].temp_avg = avg;
        }

        //calculate the rank of each student and store at temp_details structure
        double temp_a;
        char temp_b[100];

        for(y=0; y<num_of_stu; y++)
        {
            for(z=0; z<(num_of_stu-y-1); z++)
            {
                if(temp_d[z].temp_avg<temp_d[z+1].temp_avg)
                {
                    temp_a = temp_d[z].temp_avg;
                    temp_d[z].temp_avg = temp_d[z+1].temp_avg;
                    temp_d[z+1].temp_avg= temp_a;

                    strcpy(temp_b, temp_d[z].temp_index);
                    strcpy(temp_d[z].temp_index, temp_d[z+1].temp_index);
                    strcpy(temp_d[z+1].temp_index, temp_b);
                }
            }
        }

        //assign the rank to the term_stu structure
        z = 1;
        for(y=0; y<num_of_stu; y++)
        {
            i = 0;
            while(1)
            {
                if (strcmp(temp_d[y].temp_index, term_stu_d[i].index) == 0)
                {
                    if (temp_d[y].temp_avg == temp_d[y+1].temp_avg)
                    {
                        j = 0;
                        while(1)
                        {
                            if (strcmp(temp_d[y+1].temp_index, term_stu_d[j].index) == 0)
                            {
                                term_stu_d[i].stu_rank = z;
                                term_stu_d[j].stu_rank = z;
                                break;
                            }
                            j++;             //increasing the index of term_stu_d structure
                        }
                        break;
                    }
                    else
                    {
                        term_stu_d[i].stu_rank = z;
                        z++;                 //increasing the rank
                        break;
                    }
                }
                i++;
            }
        }

        //write term test details and student details (according to the term test) in the term test details file (File_C.txt)
        char temp_fr[20];

        fprintf(file_c, "%s Term Test - %s\n", term_d.term, term_d.year );
        fprintf(file_c, "Grade : %d - %s\n\n", term_d.grade, term_d.cls);

        fprintf(file_c, "%-15s |%-30s", "Index No.", "Student Name");

        for(y=0; y<num_of_sub; y++)
        {
            fprintf(file_c, "|%-19s", term_d.sub_name_d[y].sub_name);
        }

        fprintf(file_c, "|%-18s |%-18s |%-19s", "Total marks", "Average", "Rank");
        fprintf(file_c,"\n");

        fprintf(file_c, "----------------|------------------------------|");

        for(y=0; y<num_of_sub; y++)
        {
            fprintf(file_c, "-------------------|");
        }
        fprintf(file_c, "-------------------|-------------------|---------------\n");

        for(y=0; y<num_of_stu; y++)
        {
            fprintf(file_c, "%-16s", term_stu_d[y].index);
            fprintf(file_c, "|%-30s", term_stu_d[y].name);

            for(z=0; z<num_of_sub; z++)
            {
                sprintf(temp_fr, "%d", term_stu_d[y].sub_marks_d[z].sub_marks);
                fprintf(file_c, "|%-19s", temp_fr);
            }

            sprintf(temp_fr, "%d", term_stu_d[y].total);
            fprintf(file_c, "|%-19s", temp_fr);

            sprintf(temp_fr, "%.2f", term_stu_d[y].average);
            fprintf(file_c, "|%-19s", temp_fr);

            sprintf(temp_fr, "%d", term_stu_d[y].stu_rank);
            fprintf(file_c, "|%-19s", temp_fr);

            fprintf(file_c,"\n");
        }

        fprintf(file_c,"\n\n");

        fflush(file_c);
        printf("\n\nTerm Test details stored successfully!\n\n\n");

        //Inquire the user about printing the rank list.
        char chr_1;
        z = 0;

        while(1)
        {
            printf("Need to print ranked list? (Y/N) : ");
            scanf(" %c", &chr_1);

            //print the rank list
            if (chr_1 == 'Y' || chr_1 == 'y')
            {
                printf("\n%s Term Test - %s \n", term_d.term, term_d.year );
                printf("Grade : %d - %s \n\n", term_d.grade, term_d.cls);
                printf(" %-15s | %-15s | %-30s\n", "Student Rank", "Index No", "Student Name");
                printf("-----------------|-----------------|-------------------------------\n");

                for(y=0; y<num_of_stu; y++)
                {
                    i = 0;
                    while(1)
                    {
                        if(strcmp(temp_d[y].temp_index, term_stu_d[i].index) == 0)
                        {
                            printf(" %-15d | %-15s | %-30s\n", term_stu_d[i].stu_rank, term_stu_d[i].index, term_stu_d[i].name);
                            z = 1;
                            break;
                        }
                        i++;                                        //increasing the index of term_stu_d structure
                    }
                }
            }
            else if (chr_1 == 'N' || chr_1 == 'n')
            {
                break;
            }

            else
            {
                printf("Error. Your input is incorrect. Please try again.\n\n\n");
            }

            if(z ==1)
            {
                break;
            }
        }

        //Inquire the user to add new term test details
        char chr_2, chr_3;
        z = 0;

        while (1)
        {
            printf("\n\nNeed to include an another Term Test details? (Y/N) : ");
            scanf(" %c", &chr_2);

            if (chr_2 == 'N' || chr_2 == 'n')
            {
                fclose(file_c);

                //Inquire the user to go to the main menu
                while(1)
                {
                    printf("\n\nNeed to go to the main menu? (Y/N) : ");
                    scanf(" %c", &chr_3);

                    if(chr_3 == 'Y' || chr_3 == 'y')
                    {
                        printf("\n");
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
                        printf("Error. Your input is incorrect. Please try again.\n");
                    }
                }
            }
            else if (chr_2 == 'Y' || chr_2 == 'y')
            {
                printf("\n");
                break;
            }
            else
            {
                printf("Error. Your input is incorrect. Please try again.\n");
            }

            if (z == 1)
            {
                break;
            }
        }

        if (z == 1)
        {
            break;
        }
    }

	return 0;
}

//getting the current year of computer
int current_year ()
{
    int yr;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    yr = t->tm_year+1900;
    return yr ;
}

//checking grade and class is valid or not
int chek_grd_cls(int grd, char cls[10])
{
    int chk = 0, w = 0, x = 0;
    char *spl_list;
    char *spl_text;
    char str_rcd[MAXCHAR];
    char tr_grade[5];

    FILE *file_a;

    sprintf(tr_grade, "%d", grd);

    if((file_a = fopen("File_A.txt", "r")) != NULL)
    {
        while(fgets(str_rcd, MAXCHAR, file_a) != NULL)
        {
            if (w > 3)
			{
			    spl_list = strtok(str_rcd, " |");

			    for(x=0; x<4; x++)
                {
                    spl_list = strtok(NULL, " |");
                }

				if(strcmp(spl_list, tr_grade) == 0)
				{
					spl_list = strtok(NULL, " |");
					spl_text = strtok(spl_list, "\n");

					if(strcmp(spl_text, cls) == 0)
					{
						chk = 1;
						break;
					}
				}
			}
			w++;        //increasing the number of read line
		}
	}
    else
    {
        printf("File open error");
    }
    fclose(file_a);

    return chk;
}

//reading the students details from file and storing in structures(term_stu & temp_test)
int stu_details(int grd, char cls[10])
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

    if((file_a = fopen("File_A.txt", "r")) != NULL)
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
                        strcpy(term_stu_d[x].index, tr_index);
                        strcpy(temp_d[x].temp_index, tr_index);

                        strcpy(term_stu_d[x].name, tr_name);
                        x++;            //increasing the index of term_stu_d structure
                    }
                }
            }
            w++;                        //increasing the number of read line
        }
    }
    else
    {
        printf("File open error");
    }

    fclose(file_a);
    return x;
}

//updating the subjects in structure(subject_name) according to grade
int subject_list(int ui_grd)
{
    int x, sub_con;

    char *sub_array_1[] = {"Religion", "Language", "English", "Maths  ", "Environment"};
    char *sub_array_2[] = {"Religion", "Language", "English", "Maths  ", "Science", "History", "H.P.E", "Second. Lang.", "P.T.S", "Geography", "Civits", "Basket Sub."};
    char *sub_array_3[] = {"Religion", "Language", "English", "Maths  ", "Science", "History", "Basket Sub I", "Basket Sub II", "Basket Sub III"};

    if (ui_grd <=5)
    {
        for (x=0; x<5; x++)
        {
            strcpy(term_d.sub_name_d[x].sub_name, sub_array_1[x]);
        }

        sub_con = 5;
    }
    else if (ui_grd <= 9)
    {
        for (x=0; x<12; x++)
        {
            strcpy(term_d.sub_name_d[x].sub_name, sub_array_2[x]);
        }

        sub_con = 12;
    }
    else if (ui_grd <= 11)
    {
        for (x=0; x<9; x++)
        {
            strcpy(term_d.sub_name_d[x].sub_name, sub_array_3[x]);
        }

        sub_con = 9;
    }

    return sub_con;
}

//checking the given string is a numeric value
int check_input_num(char str[10])
{
    int x;
    int result = 0;

    for (x=0; str[x]!='\0'; x++)
    {
        if (isdigit(str[x]) != 0)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

//checking the inputted marks count is equal to number of students
int check_input_marks(char mark_l[400], int st_con)
{
    int x = 0, result_cim;
    char *split;

    split = strtok(mark_l, " ");

    while (split != NULL)
    {
        x++;
        split = strtok(NULL, " ");
    }

    if(x == st_con)
    {
        result_cim = 1;
    }
    else
    {
        result_cim = 0;
    }

    return result_cim;
}
