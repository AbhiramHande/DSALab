#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LENGTH_OF_STRING 100

char* assign_string(void){
    char* temp = NULL;
    size_t buffer_size = 0;
    printf("Enter new string to add: ");
    if(getline(&temp, &buffer_size, stdin) == -1){
        printf("Error fetching from stdin.\n");
        return NULL;
    }
    return temp;
}

void add_at_beginning(char*** array, int* size){
    *array = realloc(*array, (++*size)*sizeof(char*));
    if(*array == NULL){
        printf("Error allocating memory. \n");
        return;
    }

    char* string = assign_string();
    if(*size > 1){
        for(int i = *size - 1; i != 0; i--)
            (*array)[i] = (*array)[i-1];
    }
    (*array)[0] = string;
    return;
}

void add_at_end(char*** array, int* size){
    *array = realloc(*array, (++*size)*sizeof(char*));
    if(*array == NULL){
        printf("Error allocating memory. \n");
        return;
    }

    char* string = assign_string();
    (*array)[*size - 1] = string;
    return;
}

void delete_at(char*** array, int* size){
    printf("Enter the position you want to delete: ");
    int position;
    char** arr = *array;
    scanf("%d", &position);

    if(position <= 0 || position > *size){
        printf("Invalid location. \n");
        return;
    }

    free(arr[position - 1]);
    for(; position != *size; position++)
        arr[position-1] = arr[position];
    *array = realloc(*array, (--*size)*sizeof(char*));
    return;
}

int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    fgetc(stdin);
    
    char** string_array = (char**)malloc(size*sizeof(char*)); 
    if (string_array == NULL) 
        printf("Insufficient space.  \n");

    for (int i = 0; i < size; i++) {
        string_array[i] = assign_string();
    }

    bool loop = true;
    while(loop) {
        printf("Please select one of the options by entering the corresponding index number: \n");
        printf("1. Add a string to the end of the array \n");
        printf("2. Add a string to the beginning of the array \n");
        printf("3. Delete the element at a given index of the array \n");
        printf("4. Display the length of the array \n");
        printf("5. Display all the elements of the array in sequence \n");
        printf("6. Quit \n");

        int choice;
        scanf("%d", &choice);
        fgetc(stdin);

        switch(choice) {
            case 1:
                add_at_end(&string_array, &size);
                break;
            
            case 2:
                add_at_beginning(&string_array, &size);
                break;
                

            case 3:
                delete_at(&string_array, &size);
                break;
            
            case 4:
                printf("The size of the array is: %d \n", size);
                break;
            
            case 5:
                for (int i = 0; i < size; i++)
                    printf("%s", string_array[i]);
                break;
            
            case 6:
                loop = false;
                break;
            
            default:
                printf("Please provide an integer within given choice. \n");
                break;
        }    
    }

    for (int i = 0; i < size; i++)
        free(string_array[i]);
    free(string_array);
}
