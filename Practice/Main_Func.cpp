#include "Main_Func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_FLIGHTS 100

struct Flight {
    char departure[50];
    char destination[50];
    int flightNumber;
    char aircraftType[50];
    int seats;
};

struct Flight flights[MAX_FLIGHTS];
int numFlights = 0;

void addFlight() {
    if (numFlights >= MAX_FLIGHTS) {
        printf("Неможливо додати бiльше рейсiв. База заповнена.\n");
        return;
    }

    struct Flight newFlight;
    printf("Введiть пункт вiдправлення: ");
    scanf("%s", newFlight.departure);
    printf("Введiть пункт призначення: ");
    scanf("%s", newFlight.destination);
    printf("Введiть номер рейсу: ");
    scanf("%d", &newFlight.flightNumber);
    printf("Введiть тип лiтака: ");
    scanf("%s", newFlight.aircraftType);
    printf("Введiть кiлькiсть мiсць у лiтаку: ");
    scanf("%d", &newFlight.seats);

    flights[numFlights++] = newFlight;

    printf("Рейс успiшно додано.\n");
}

void deleteFlight() {
    int flightNumber;
    printf("Введiть номер рейсу для видалення: ");
    scanf("%d", &flightNumber);

    int found = 0;
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].flightNumber == flightNumber) {
            found = 1;
            for (int j = i; j < numFlights - 1; j++) {
                flights[j] = flights[j + 1];
            }
            numFlights--;
            printf("Рейс було успiшно видалено.\n");
            break;
        }
    }

    if (!found) {
        printf("Рейс не знайдено.\n");
    }
}

void displayFlights() {
    printf("Список рейсiв:\n");
    printf("-----------------------------------------------------------------------\n");
    printf("Вiдправлення\tПризначення\tНомер рейсу\tТип лiтака\tСидiння\n");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < numFlights; i++) {
        printf("%s\t\t%s\t\t%d\t\t%s\t\t%d\n",
            flights[i].departure,
            flights[i].destination,
            flights[i].flightNumber,
            flights[i].aircraftType,
            flights[i].seats);
    }
    printf("-----------------------------------------------------------------------\n");
}

void modifyFlight() {
    int flightNumber;
    printf("Введiть номер рейсу для редагування: ");
    scanf("%d", &flightNumber);

    int found = 0;
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].flightNumber == flightNumber) {
            found = 1;
            printf("Рейс знайдено.\n");
            printf("Введiть новий пункт вiдправлення: ");
            scanf("%s", flights[i].departure);
            printf("Введiть новий пункт призначення: ");
            scanf("%s", flights[i].destination);
            printf("Введiть новий тип лiтака: ");
            scanf("%s", flights[i].aircraftType);
            printf("Введiть нову кiлькiсть мiсць в лiтаку: ");
            scanf("%d", &flights[i].seats);
            printf("Рейс успiшно вiдредаговано.\n");
            break;
        }
    }

    if (!found) {
        printf("Рейс не знайдено.\n");
    }
}

void searchByDestination() {
    char destination[50];
    printf("Введiть пункт призначення: ");
    scanf("%s", destination);

    printf("Рейси до %s:\n", destination);
    printf("-----------------------------------------\n");
    for (int i = 0; i < numFlights; i++) {
        if (strcmp(flights[i].destination, destination) == 0) {
            printf("Номер рейсу: %d, Тип лiтака: %s\n",
                flights[i].flightNumber,
                flights[i].aircraftType);
        }
    }
    printf("-----------------------------------------\n");
}

void searchByAircraftType() {
    char aircraftType[50];
    printf("Введiть тип лiтака: ");
    scanf("%s", aircraftType);

    printf("Рейси за типом лiтака %s:\n", aircraftType);
    printf("-----------------------------------------\n");
    for (int i = 0; i < numFlights; i++) {
        if (strcmp(flights[i].aircraftType, aircraftType) == 0) {
            printf("Номер рейсу: %d, Пункт призначення: %s\n",
                flights[i].flightNumber,
                flights[i].destination);
        }
    }
    printf("-----------------------------------------\n");
}
