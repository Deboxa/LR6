#include <stdio.h>
#include <string.h>
#include "Menu.h"
#include "Search_menu.h"
#include "Data.h"

int main(void) 
{
    printf("This program supports only English language(VS2022)\n");
    char file_name[MAX_MISC_SIZE];
    printf("Enter name of file(no more than %d)\n", (MAX_MISC_SIZE - 5));
    scanf_c(" %45[^.\n]", file_name);
    if ((strlen(file_name) + 4) > MAX_MISC_SIZE) {
        printf("File name is too long!\n");
        return 1;
    }
    if (strstr(file_name, ".bin") == NULL)
        strcat(file_name, ".bin");
    menu(file_name);
    return 0;
}