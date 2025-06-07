#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_adiva.h"


int main(){
    char nama_file[20];
    int arr_angka[20];
    int arr_output[3];
    char temp[5];
    int temp_angka;
    int N = 0;
    float volume_tabung, luas_permukaan_tabung;
    float ratio;

    printf("Masukan nama file : ");
    fgets(nama_file, sizeof(nama_file), stdin);
    nama_file[strcspn(nama_file, "\n")] = '\0';

    FILE *fptr;
    fptr = fopen(nama_file, "r");
    if(fptr == NULL){
        printf("File tidak ditemukan!\n");
        return 1;
    }
    
    while(fgets(temp, sizeof(temp),fptr)){
        temp_angka = atoi(temp);

        arr_angka[N] = temp_angka;
        N++;
    }

    Largest3(arr_angka, N, arr_output);

    volume_tabung = Tabung(arr_output[1], arr_output[0], 'V');
    luas_permukaan_tabung = Tabung(arr_output[1], arr_output[2], 'L');

    ratio = volume_tabung / luas_permukaan_tabung;

    printf("Perbandingan yang diperoleh : %.2f", ratio);

    return 0;
}
