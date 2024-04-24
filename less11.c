#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} DataEntry;

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    DataEntry entry;

     fgets(line, MAX_LINE_LENGTH, file);

       while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        sscanf(line, "%d;%d;%d;%d;%d;%d",
               &entry.year, &entry.month, &entry.day,
               &entry.hour, &entry.minute, &entry.temperature);

               printf("Дата: %04d-%02d-%02d %02d:%02d, Температура: %d\n",
               entry.year, entry.month, entry.day,
               entry.hour, entry.minute, entry.temperature);
    }

    fclose(file);
    return 0;
}

