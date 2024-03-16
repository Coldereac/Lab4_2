//
// Created by Malinka on 11/03/2024.
//

#include "functions.h"

//1 - слова рівні
//0 - слова не рівні
//-1 - перше слово більше
//2 - друге слово більше
int compare(char *str1, char *str2) {
    int result = 1; // результат перевірки
    if (strlen(str1) > strlen(str2)) {
        result = -1;
    }
    else if(strlen(str1) < strlen(str2)){
        result = 2;
    }
    else {
        while (result && *str1 != '\0' && *str2 != '\0') { // доки не дійдемо до кінця слів
            if (*str1 != *str2) {
                // якщо теперешній символ першого слова не дорівнює
                // теперішньому символу іншого слова, то вони не є однаковими
                // Перевірка, якщо різний регістр
                if (abs(*str1 - *str2) != 32) {
                    result = 0;
                }
            }
            *str1++; //переміщення по слову вперед
            *str2++;
        }
    }
    return result;
}

int input(char **arr) {
    int i = 0; // кількість слів у реченні
    //виділення пам'яті під перший елемент з його отриманням
    //якщо він не є точкою, то продовжуємо
    *arr = (char*) malloc(WORDLEN * sizeof(char));
    scanf("%s", arr[i]);
    *arr = (char*) realloc(*arr, (strlen(*arr)+1) * sizeof(char)); // перевиділення пам'яті під точну кількість символів
    while (arr[i][0] != '.') { // порівнюємо слово з точкою, якщо вони не однакові, то отримуємо наступне слово
        i++;
        *(arr+i) = (char*) malloc(WORDLEN * sizeof(char));
        scanf("%s", arr[i]);
        *(arr+i) = (char*) realloc(*(arr+i), (strlen(*(arr+i))+1) * sizeof(char)); // перевиділення пам'яті під точну кількість символів
    }
    return i; // повертаємо кількість слів у реченні
}

void output(char **arr) {
    for (int i = 0; arr[i][0] != '.'; i++) { //виводимо, доки не дійдемо до точки
        printf("%s ", arr[i]);
    }
    printf("\n");
}

void freeMemory(char **arr, int size) {
    for (int i = 0; i < size+1; ++i) { //вивільняємо пам'ять кожного масива в масиві
        free(arr[i]);
    }
    free(arr); // вивільняємо пам'ять під масив
}

char* invert(char *str) {
    int length = strlen(str); // довжина слова
    char *temp = (char*) malloc(length * sizeof(char)); // обернене слово
    int i = 0; // лічильник для оберненого слова
    //j - лічильник для оригінального слова
    //записуємо у temp char-и з str, починаючи з останнього і до першого
    for (int j = length - 1; i < length; ++i, --j) {
        *(temp + i) = *(str+j);
    }
    temp[i] = '\0'; // додаємо в кінець спец символ
    return temp;
}

/*
bool palindrome(char *str) {
    bool result = true; // результат перевірки
    int length = strlen(str); // довжина слова
    for (int i = 0; i < length / 2 && result; ++i) { // йдемо від 0 до середини слова
        if (*(str + i) != *(str + length - i - 1)) { // якщо символ у початку не дорівнює символу у кінці, то перевіряємо ще й з регістром
            if (abs(*(str + i) - *(str + length - i - 1)) != 32) { // перевірка на можливу різницю регістрів
                result = false; // якщо не співпадають, то це не є паліндромом
            }
        }
    }
    return result;
}
*/

bool palindrome(char *str1) {
    return compare(str1, invert(str1)) == 1;
}