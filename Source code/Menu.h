#ifndef MENU_H
#define MENU_H

typedef enum //перечисление дл€ menu
{
    add = 1,
    delrecord,
    search,
    edit,
    print,
    exit_menu
} functions;

//основное меню
void menu(const char* file_name);
//добавление записи/создание файла c условной компил€цией ввода - ручной и из массива(у мен€ из файла, думаю разницы - нет
//файл с запис€ми задан в бинарном виде, записи созданы нейросетью(50 записей) и записаны в файл мной отдельной программой
static void add_record(const char* file_name);
//удаление записи по индексу, сделано через переключение флага is_deleted
static void delete_record(const char* file_name, int index);
//редактирование записи(замена старой на новую)
static void edit_record(const char* file_name, int index);
//выписывание записей с их индексами
static int print_records(const char* file_name);

#endif
