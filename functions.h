//
// Created by Malinka on 11/03/2024.
//

/*
*З клавіатури вводиться речення: послідовність слів, розділених будь-
якою кількістю пробілів, що закінчується крапкою (крапка не є символом рядка,

це ознака закінчення введення). Все речення зберігається як масив слів!!
Інвертувати вказане користувачем слово і перевірити, чи є воно паліндромом.
Рядок оголосити, як :
2 варіант – char **sent;
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define L 10
#define WORDLEN 30
#define POINT "."

int input(char **arr); // отримання речення від користувача і повернення кількості слів у цьому реченні; arr - масив слів
void output(const char **arr); // виведення речення; arr - масив слів
void freeMemory(char **arr, int size); // вивільнення речення; arr - масив слів, size - кількість слів у реченні
char* invert(const char *str); // повернення інвертованого слова; str - слово
bool palindrome(const char *str); // перевірка слова на паліндром; str - слово
int compare(const char *str1, const char *str2); //порівняння двох слів
//1 - слова рівні
//0 - слова не рівні
//-1 - перше слово більше
//2 - друге слово більше
#endif //FUNCTIONS_H
