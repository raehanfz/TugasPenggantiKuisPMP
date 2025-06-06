#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library.h" 

void LargestThree(int array[], int len){
    if (len == 1){
        printf("%d %d %d\n", array[0], array[0], array[0]);
    } else if (len == 2){
        if (array[0] > array[1]){
            printf("%d %d %d\n", array[0], array[0], array[1]);
        } else {
            printf("%d %d %d\n", array[1], array[1], array[0]);
        }
    } else {
        int first = -9999, second = -9999, third = -9999;
        for (int i = 0; i < len; i++){
            if (array[i] > first){
                third = second;
                second = first;
                first = array[i];
            } else if (array[i] > second){
                third = second;
                second = array[i];
            } else if (array[i] > third){
                third = array[i];
            }
        }
        printf("%d %d %d\n", first, second, third);
    }
}


void SilinderVolumeAndSurfaceArea(int r, int h){
    float volume = PI*r*r*h, surfaceArea = 2*PI*r*(r+h);
    printf("volume: %f\nsurface area: %f\n", volume, surfaceArea);
}

int* GetArray(char namafile[MAX_ARRAY_SIZE], int line, int size){
    FILE* fptr = fopen(namafile, "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return NULL;
    }

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        fclose(fptr);
        return NULL;
    }

    char buffer[32];
    int counter = 1;

    while (fgets(buffer, sizeof(buffer), fptr)) {
        if (counter == line) {
            // Tokenize the line and fill the array
            char* token = strtok(buffer, " \t\n");
            for (int i = 0; i < size; i++) {
                if (token == NULL) {
                    fprintf(stderr, "Not enough numbers on line %d\n", line);
                    free(arr);
                    fclose(fptr);
                    return NULL;
                }
                arr[i] = atoi(token);
                token = strtok(NULL, " \t\n");
            }
            break;
        }
        counter++;
    }

    if (counter < line) {
        fprintf(stderr, "Line %d not found in file\n", line);
        free(arr);
        arr = NULL;
    }

    fclose(fptr);
    return arr;
}