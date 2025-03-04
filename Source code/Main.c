#include <stdio.h>
#include <string.h>
#include "Menu.h"
#include "Search_menu.h"
#include "Data.h"

int main(void) {
#pragma warning(push)
#pragma warning(disable: 6054) //убирает предупреждение дл€ 16 строки (переполнение названи€)
    printf("This program supports only English language(Stupid VS2022)\n");
    char file_name[MAX_MISC_SIZE];
    printf("Enter name of file(no more than %d)\n", (MAX_MISC_SIZE - 5));
    scanf_c(" %45[^.\n]", file_name);
    if ((strlen(file_name) + 4) > MAX_MISC_SIZE) {
        printf("File name is too long!\n");
        return 1;
    }
#pragma warning(pop)
    if (strstr(file_name, ".bin") == NULL)
        strcat(file_name, ".bin");
    menu(file_name);
    return 0;
}

/* 
пользовалс€ нейросетью deepseek дл€ :
* создани€ массива записей
* директив pragma
* создани€ функции scanf_c
* помощи в организации проекта
* правильного определени€ сигнатуры указател€ на функцию search_func
*/