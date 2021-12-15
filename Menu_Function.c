#include <stdio.h>

int task_a();
int task_b();
int task_c();
int task_d();
int task_e();
int task_s();

int menu_form()
{
    char task_input;

    printf("\n--------------------------------------------------------------------------------");
    printf("   Menu\n");
    printf("--------------------------------------------------------------------------------\n");

    printf("\n ____________________________________________________ _______________________");
    printf("\n|                                                    |                       |");
    printf("\n|                    Functions                       |         Input         |");
    printf("\n|____________________________________________________|_______________________|");
    printf("\n|                                                    |                       |");
    printf("\n| New Admission                                      |         Task_A        |");
    printf("\n|____________________________________________________|_______________________|");
    printf("\n|                                                    |                       |");
    printf("\n| Engagement in Extracurricular Activities           |         Task_B        |");
    printf("\n|____________________________________________________|_______________________|");
    printf("\n|                                                    |                       |");
    printf("\n| Result of Term Tests and Ranking                   |         Task_C        |");
    printf("\n|____________________________________________________|_______________________|");
    printf("\n|                                                    |                       |");
    printf("\n| Class Monitor and Subject Leaders                  |         Task_D        |");
    printf("\n|____________________________________________________|_______________________|");
    printf("\n|                                                    |                       |");
    printf("\n| Report cards                                       |         Task_E        |");
    printf("\n|____________________________________________________|_______________________|\n\n");

    while(1)
    {
        printf("\nSelect the task : Task_");
        scanf(" %c", &task_input);

        switch(task_input)
        {
            case 'A':
                task_a();
                break;

            case 'B':
                task_b();
                break;

            case 'C':
                task_c();
                break;

            case 'D':
                task_d();
                break;

            case 'E':
                task_e();
                break;

            default:
                printf("ERROR!. Your input is incorrect. Please try again.\n\n");
        }

        if (task_input == 'A' || task_input == 'B' || task_input == 'C' || task_input == 'D' || task_input == 'E')
        {
            break;
        }
    }

    return 0;
}
