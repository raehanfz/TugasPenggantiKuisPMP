//run program di terminal: gcc main.c source/Library.c -Iinclude -o main
#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

int main(void){
    int arr_angka[20];
    int arr_output[3];
    char temp[5];
    int temp_angka;
    int N = 0;
    float volume_tabung, luas_permukaan_tabung;

    // Buka file
    FILE *fptr = fopen("data/arr.txt", "r");
    if (fptr == NULL) {
        printf("File tidak ditemukan!\n");
        return 1;
    }

    // Baca angka dari file
    while (fgets(temp, sizeof(temp), fptr) != NULL) {
        temp_angka = atoi(temp);
        arr_angka[N++] = temp_angka;
    }

    fclose(fptr);

    Largest3(arr_angka, N, arr_output);
    printf("\n");
    volume_tabung = Tabung(3, 4, 'v');
    luas_permukaan_tabung = Tabung(8, 9, 'l');

    printf("rasio volume dan luas permukaan tabung: %f", volume_tabung/luas_permukaan_tabung);

    return 0;
}
