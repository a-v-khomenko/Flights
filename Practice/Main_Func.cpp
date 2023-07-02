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
        printf("��������� ������ �i���� ����i�. ���� ���������.\n");
        return;
    }

    struct Flight newFlight;
    printf("����i�� ����� �i����������: ");
    scanf("%s", newFlight.departure);
    printf("����i�� ����� �����������: ");
    scanf("%s", newFlight.destination);
    printf("����i�� ����� �����: ");
    scanf("%d", &newFlight.flightNumber);
    printf("����i�� ��� �i����: ");
    scanf("%s", newFlight.aircraftType);
    printf("����i�� �i���i��� �i��� � �i����: ");
    scanf("%d", &newFlight.seats);

    flights[numFlights++] = newFlight;

    printf("���� ���i��� ������.\n");
}

void deleteFlight() {
    int flightNumber;
    printf("����i�� ����� ����� ��� ���������: ");
    scanf("%d", &flightNumber);

    int found = 0;
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].flightNumber == flightNumber) {
            found = 1;
            for (int j = i; j < numFlights - 1; j++) {
                flights[j] = flights[j + 1];
            }
            numFlights--;
            printf("���� ���� ���i��� ��������.\n");
            break;
        }
    }

    if (!found) {
        printf("���� �� ��������.\n");
    }
}

void displayFlights() {
    printf("������ ����i�:\n");
    printf("-----------------------------------------------------------------------\n");
    printf("�i����������\t�����������\t����� �����\t��� �i����\t���i���\n");
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
    printf("����i�� ����� ����� ��� �����������: ");
    scanf("%d", &flightNumber);

    int found = 0;
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].flightNumber == flightNumber) {
            found = 1;
            printf("���� ��������.\n");
            printf("����i�� ����� ����� �i����������: ");
            scanf("%s", flights[i].departure);
            printf("����i�� ����� ����� �����������: ");
            scanf("%s", flights[i].destination);
            printf("����i�� ����� ��� �i����: ");
            scanf("%s", flights[i].aircraftType);
            printf("����i�� ���� �i���i��� �i��� � �i����: ");
            scanf("%d", &flights[i].seats);
            printf("���� ���i��� �i�����������.\n");
            break;
        }
    }

    if (!found) {
        printf("���� �� ��������.\n");
    }
}

void searchByDestination() {
    char destination[50];
    printf("����i�� ����� �����������: ");
    scanf("%s", destination);

    printf("����� �� %s:\n", destination);
    printf("-----------------------------------------\n");
    for (int i = 0; i < numFlights; i++) {
        if (strcmp(flights[i].destination, destination) == 0) {
            printf("����� �����: %d, ��� �i����: %s\n",
                flights[i].flightNumber,
                flights[i].aircraftType);
        }
    }
    printf("-----------------------------------------\n");
}

void searchByAircraftType() {
    char aircraftType[50];
    printf("����i�� ��� �i����: ");
    scanf("%s", aircraftType);

    printf("����� �� ����� �i���� %s:\n", aircraftType);
    printf("-----------------------------------------\n");
    for (int i = 0; i < numFlights; i++) {
        if (strcmp(flights[i].aircraftType, aircraftType) == 0) {
            printf("����� �����: %d, ����� �����������: %s\n",
                flights[i].flightNumber,
                flights[i].destination);
        }
    }
    printf("-----------------------------------------\n");
}
