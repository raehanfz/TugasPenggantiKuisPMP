#include <stdio.h>
#include <math.h>

int FindMaxValueIndex(int *array, int array_size){
    int max_value = array[0];
    int max_value_index  = 0;
    for(int i=0; i<array_size; i++){
        if(array[i] == -999){ // Kalau udh diambil skip
            continue;
        }
        if(array[i] > max_value){
            max_value = array[i];
            max_value_index = i;
        }
    }
    return max_value_index;
}

void Largest3(int *array, int array_size, int output_array[3]){
    // Kalau kurang dari 3 isi array nya
    if(array_size == 1){
        output_array[0] = array[0];
        output_array[1] = array[0];
        output_array[2] = array[0];
        return;
    }
    if(array_size == 2){
        if(array[0] > array[1]){
            output_array[0] = array[0];
            output_array[1] = array[0];
            output_array[2] = array[1];
        }
        else{
            output_array[0] = array[1];
            output_array[1] = array[1];
            output_array[2] = array[0];
        }
        return;
    }

    int max_index;
    for(int i=0; i<3; i++){
        max_index = FindMaxValueIndex(array, array_size);
        output_array[i] = array[max_index];
        array[max_index] = -999; // Tandain kalau index ini udh diambil
    }
}

float Tabung(int h, int r, char output_mode){
    float PI = 3.14159265;
    if(output_mode == 'V' || output_mode == 'v'){
        float volume = PI * r * r * h;
        return volume;
    }
    else if(output_mode == 'L' || output_mode == 'l'){
        float luas_permukaan = (2 * PI * r * r) + (2 * PI * r * h);
        return luas_permukaan;
    }
}