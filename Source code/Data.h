#ifndef DATA_H
#define DATA_H

#define MAX_NAME_SIZE 50 // ������������ ������ �����
#define MAX_MISC_SIZE (MAX_NAME_SIZE / 2) // ������������ ������ �������, �������� � �.�.
//#define MANUAL_TYPING

typedef struct data //��������� ��� 25 ��������
{
    char name[MAX_NAME_SIZE]; //���
    int schoolnum; //����� �����
    char region[MAX_MISC_SIZE]; // ������
    char subject[MAX_MISC_SIZE]; // �������
    int year; // ���
    int is_deleted; // ���� �������� ������
} data;

int scanf_c(const char* format, ...); // ����������� ������� scanf � ������������� ������ stdin, ����������� ����� ���������� stdarg.h

#endif