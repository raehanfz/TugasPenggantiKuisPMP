#include <stdio.h>
#include <stdlib.h>
#include "watashinolib.h"

int main(){
    int arr[30];
    int i = 0;
    FILE *fptr;
    fptr = fopen("file.txt", "r");
    char temp[20];
    while(fgets(temp, 20, fptr)){
        arr[i] = atoi(temp);
        
        i++;
    }
    int size = i;

    int largest3[3];
    Largest3(arr, size, largest3);
    // for(int i=0; i<3; i++){
    //     printf("%d\n", largest3[i]);
    // }

    int x = largest3[0];
    int y = largest3[1];
    int z = largest3[2];

    float perbandingan = Tabung(y, x, 'v') / Tabung(y, z, 'l');
    printf("Perbandingan: %.2f", perbandingan);

    fclose(fptr);
    return 0;
}