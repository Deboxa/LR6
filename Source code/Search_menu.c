#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include "Search_menu.h"
#include "Data.h"
#include "Menu.h"

void search_menu(const char* file_name)
{
    data_cord sv = name;
    while (sv != exit_search)
    {
        printf("\nChoose field from list\n"
            "1 Name\n"
            "2 School number\n"
            "3 Region\n"
            "4 Subject\n"
            "5 Year\n"
            "6 Back\n");
        if (scanf_c("%d", &sv) != 1)
        {
            printf("Input error!\n");
            continue;
        }
        switch (sv)
        {
        case name:
        {
            char name[MAX_NAME_SIZE] = { 0 };
            printf("\nEnter the name\n");
            scanf_c(" %[^\n]", name);
            search_record(file_name, is_correct_name, name);
            break;
        }
        case schoolnum:
        {
            int schoolnum;
            printf("\nEnter the school number\n");
            if (scanf_c("%d", &schoolnum) != 1)
            {
                printf("Input error!\n");
                break;
            }
            search_record(file_name, is_correct_schoolnum, &schoolnum);
            break;
        }
        case region:
        {
            char region[MAX_MISC_SIZE];
            printf("\nEnter the region\n");
            scanf_c(" %[^\n]", region);
            search_record(file_name, is_correct_region, region);
            break;
        }
        case subject:
        {
            char subject[MAX_MISC_SIZE];
            printf("\nEnter the subject\n");
            scanf_c(" %[^\n]", subject);
            search_record(file_name, is_correct_subject, subject);
            break;
        }
        case year:
        {
            int year;
            printf("\nEnter the year\n");
            if (scanf_c("%d", &year) != 1)
            {
                printf("Input error!\n");
                break;
            }
            search_record(file_name, is_correct_year, &year);
            break;
        }
        case exit_search:
            break;
        default:
            printf("Input error!\n");
            break;
        }
    }
}

static int is_correct_name(const data* person, const void* value)
{
    return strcmp(person->name, (const char*)value) == 0;
}

static int is_correct_schoolnum(const data* person, const void* value)
{
    return person->schoolnum == *(const int*)value;
}

static int is_correct_region(const data* person, const void* value)
{
    return strcmp(person->region, (const char*)value) == 0;
}

static int is_correct_subject(const data* person, const void* value)
{
    return strcmp(person->subject, (const char*)value) == 0;
}

static int is_correct_year(const data* person, const void* value)
{
    return person->year == *(const int*)value;
}

static void search_record(const char* file_name, search_func search_type, const void* value)
{
    FILE* file = fopen(file_name, "rb");
    if (file == NULL)
    {
        perror("File cannot be opened");
        return;
    }
    data person;
    int correct = 0;
    while (fread(&person, sizeof(data), 1, file) == 1)
    {
        if (person.is_deleted != 1 && search_type(&person, value) == 1)
        {
            printf("Found: %s %d %s %s %d\n", person.name, person.schoolnum, person.region, person.subject, person.year);
            correct = 1;
        }
    }
    if (correct != 1)
        printf("No records found\n");
    fclose(file);
}