﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Main_Func.h"

int main() {
    setlocale(LC_ALL, "Ukr");
    int choice;

    while (1) {
        printf("\n");
        printf("Функцiї керування базою даних рейсiв\n");
        printf("-------------------------------------\n");
        printf("1. Додати рейс\n");
        printf("2. Видалити рейс\n");
        printf("3. Показати рейси\n");
        printf("4. Редагувати рейс\n");
        printf("5. Пошук рейсiв за пунктом призначення\n");
        printf("6. Пошук рейсiв за типом лiтака\n");
        printf("0. Вихiд\n");
        printf("-------------------------------------\n");
        printf("Введiть номер команди: ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            printf("Вихiд з програми...\n");
            exit(0);
        case 1:
            addFlight();
            break;
        case 2:
            deleteFlight();
            break;
        case 3:
            displayFlights();
            break;
        case 4:
            modifyFlight();
            break;
        case 5:
            searchByDestination();
            break;
        case 6:
            searchByAircraftType();
            break;
        default:
            printf("Неправильнi введенi данi. Введiть номер з запропоновани команд.\n");
            break;
        }
    }

    return 0;
}
