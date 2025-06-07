#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Library.h" 

void Largest3(int* array_data, int len, int array_output[3]){
    if (len == 1){
        array_output[0] = array_data[0];
        array_output[1] = array_data[0];
        array_output[2] = array_data[0];
    } else if (len == 2){
        if (array_data[0] > array_data[1]){
                array_output[0] = array_data[0];
                array_output[1] = array_data[0];
                array_output[2] = array_data[1];
        } else {
                array_output[0] = array_data[1];
                array_output[1] = array_data[1];
                array_output[2] = array_data[0];
        }
    } else {
        int first = -9999, second = -9999, third = -9999;
        for (int i = 0; i < len; i++){
            if (array_data[i] > first){
                third = second;
                second = first;
                first = array_data[i];
            } else if (array_data[i] > second){
                third = second;
                second = array_data[i];
            } else if (array_data[i] > third){
                third = array_data[i];
            }
        }
        array_output[0] = first;
        array_output[1] = second;
        array_output[2] = third;
    }
    printf("%d %d %d", array_output[0], array_output[1], array_output[2]);
}

float Tabung(int r, int h, char jenis_input){
    float volume = PI*r*r*h, surfaceArea = 2*PI*r*(r+h);
    if (jenis_input == 'v'){
        return volume;
    } else {
        return surfaceArea;
    }
    
}