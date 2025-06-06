//run program di terminal: gcc main.c source/Library.c -Iinclude -o main
#include <stdio.h>
#include <stdlib.h>
#include "Library.h"

int main(void){
    int* arr1 = GetArray("data/arr.txt", 1, 1);
    int* arr2 = GetArray("data/arr.txt", 2, 2);
    int* arr3 = GetArray("data/arr.txt", 3, 4);
    int* arr4 = GetArray("data/arr.txt", 4, 7);

    if (arr1) LargestThree(arr1, 1);
    if (arr2) LargestThree(arr2, 2);
    if (arr3) LargestThree(arr3, 4);
    if (arr4) LargestThree(arr4, 7);

    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);

    SilinderVolumeAndSurfaceArea(3, 4);
    SilinderVolumeAndSurfaceArea(8, 9);

    return 0;
}
