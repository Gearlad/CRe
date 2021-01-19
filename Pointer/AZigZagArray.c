void prepare_array(int buffer[], int *array[], int row, int column[]) {
 
    int *currAddress = &(buffer[0]);
 
    for(int i = 0; i < row; i++) {
        array[i] = currAddress;
        currAddress += column[i];
    }
}
