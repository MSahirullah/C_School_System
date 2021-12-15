#include <stdio.h>

int menu_form();

int main()
{
    printf("\n===============================================================================\n\n");

    printf("            ******************************************************\n");
    printf("            *                                                    *\n");
    printf("            *               -----------------------              *\n");
    printf("            *                 Aviano High School                 *\n");
    printf("            *               -----------------------              *\n");
    printf("            *                                                    *\n");
    printf("            *          75 Elvitigala Mawatha, Colombo 4          *\n");
    printf("            *              035-2245785 / 035-2245786             *\n");
    printf("            *                                                    *\n");
    printf("            ******************************************************\n\n");

    //printf("\n===============================================================================\n\n");

    printf("\n================================ School System ================================\n\n");

    printf("Press any key to continue ...");
    _getch();

    printf("\n\n");
    menu_form();


    return 0;
}
