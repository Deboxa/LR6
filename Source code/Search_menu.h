#ifndef SEARCH_MENU_H
#define SEARCH_MENU_H
#include "Data.h"

//������������ ��� search_menu ��� �������� � �������������
typedef enum
{
    name = 1,
    schoolnum,
    region,
    subject,
    year,
    exit_search
} data_cord;
//����������� ���� ������ - ��������� �� �������
typedef int (*search_func)(const data*, const void*);
//���� ��� ������� ������
void search_menu(const char* file_name);

//���� ���������� ������� �� ������ ����� ��������� data, ��������� ���� 1 ���� 0, ������������ �� ���������� ���������
static int is_correct_name(const data* person, const void* value);
static int is_correct_schoolnum(const data* person, const void* value);
static int is_correct_region(const data* person, const void* value);
static int is_correct_subject(const data* person, const void* value);
static int is_correct_year(const data* person, const void* value);
//��������������� ������� ������� ���������� ����� �� ���������
static void search_record(const char* file_name, search_func search_type, const void* value);
#endif