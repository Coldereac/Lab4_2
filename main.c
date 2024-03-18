
#include "functions.h"

int main(void) {
    char **sent = malloc(L * sizeof(char*)); // массив, де збергігається речення
    int size; // кількість слів у реченні
    int number; // число, яке ми отримаємо від користувача
    size = input(sent); // отримаємо речення від користувача і порахуємо його розмір
    if (size <= 0) {
        puts("No words in input");
    }
    else {
        output(sent); // виведемо це речення
        printf("Input number from 0 to %d\n", size-1); // отримання числа від користувача
        scanf("%d", &number);
        if (number < 0 && number > size) { // перевірка числа
            puts("Wrong number");
        }
        else {
            printf("Inverted word: %s -> %s\n", sent[number], invert(sent[number])); // виведення інвертованого слова
            if (palindrome(sent[number])) { // перевірка на паліндром
                puts("This word is a palindrome");
            }
            else {
                puts("This word is not a palindrome");
            }
        }
    }
    freeMemory(sent, size); //вивільнення пам'яті
    return 0;
}
