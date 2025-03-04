#ifndef DATA_H
#define DATA_H

#define MAX_NAME_SIZE 50 // максимальный размер имени
#define MAX_MISC_SIZE (MAX_NAME_SIZE / 2) // максимальный размер региона, предмета и т.д.
//#define MANUAL_TYPING

typedef struct data //структура для 25 варианта
{
    char name[MAX_NAME_SIZE]; //ФИО
    int schoolnum; //номер школы
    char region[MAX_MISC_SIZE]; // регион
    char subject[MAX_MISC_SIZE]; // предмет
    int year; // год
    int is_deleted; // флаг удаления записи
} data;

int scanf_c(const char* format, ...); // стандартная функция scanf с автоотчисткой буфера stdin, реализовано через библиотеку stdarg.h

#endif