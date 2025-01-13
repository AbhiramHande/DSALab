#include <sys/time.h>
#include "student.h"
#include "linked_list.h"

#define NUMBER_OF_STUDENTS 10000
#define NUMBER_OF_CHANGES 10

void main(){
    //Task 10a: Retrive and store data from data.txt n a dynamic array and a linked list
    //Compare the time taken for doing so in each case.
    FILE* fp = fopen("data.txt", "r");
    student* dynamic_array = (student*)malloc(NUMBER_OF_STUDENTS * sizeof(student));
    LIST list = createNewList();
    int i = 0;
    char line[100];

    if(!fp){
        printf("Error opening file \n");
        return;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);
    while (fgets(line, 100, fp)){
        char* id = strtok(line, ",");
        strncpy(dynamic_array[i].ID, id, LENGTH_OF_ID);
        dynamic_array[i].ID[LENGTH_OF_ID] = '\0';
        char* cg = strtok(NULL, ",");
        dynamic_array[i].CGPA = atof(cg);
        i++;
        if(i >= NUMBER_OF_STUDENTS)
            break;
    }
    gettimeofday(&end, NULL);
    printf("Time taken for inserting %d elemnts into a dynamic array is: %ld microseconds\n", NUMBER_OF_STUDENTS,
    ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));

    fclose(fp);
    fp = fopen("data.txt", "r");

    gettimeofday(&start, NULL);
    while(fgets(line, 100, fp)){
        char* id = strtok(line, ",");
        char* cg = strtok(NULL, ",");
        student* data = malloc(sizeof(student));
        data->CGPA = atof(cg);
        strncpy(data->ID, id, LENGTH_OF_ID);
        data->ID[LENGTH_OF_ID] = '\0';
        NODE node = createNewNode(data);
        insertAtEnd(list, node);
    }
    gettimeofday(&end, NULL);
    printf("Time taken for inserting %d elements into a linked list is: %ld microseconds\n", NUMBER_OF_STUDENTS,
    ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
    fclose(fp);

    //Task 10b. Prompt the user to enter new entries into the records at user specific locations. 
    //Then, insert those records into the two data structures separately and compare the time taken by them for the same. 
    int time_dynamic_array, time_linked_list;
    int size = NUMBER_OF_STUDENTS;
    while(true){
        printf("Enter any non-zero integer to make a new addition\n");
        printf("Enter 0 to exit program\n");
        int choice = 0;
        scanf("%d", &choice);

        if(choice){
            int val, position;
            float CG;
            char id[LENGTH_OF_ID+1];
            fprintf(stdout, "Enter the record you wish to add in the following format: <position> <CGPA> <Student ID>.\n");
            scanf("%d %f %13s", &position, &CG, id);
            

            if(position <= 0 || position > size + 1){
                fprintf(stderr, "Invalid position: Position expected to be between 1 and %d", size + 1);
                continue;
            }
            size++;

            gettimeofday(&start, NULL);
            dynamic_array = realloc(dynamic_array, size*sizeof(student));
            for(int i = size - 1; i >= position; i--)
                dynamic_array[i] = dynamic_array[i - 1];
            dynamic_array[position - 1].CGPA = CG;
            strcpy(dynamic_array[position - 1].ID, id);
            gettimeofday(&end, NULL);
            printf("Time taken for inserting a new element into the linked list is: %ld microseconds\n",
            ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));

            if(position != 1)
                printf("%d %f %s\n", position-1, dynamic_array[position-2].CGPA, dynamic_array[position-2].ID);
            printf("%d %f %s\n", position, dynamic_array[position-1].CGPA, dynamic_array[position-1].ID);
            if(position != size)
                printf("%d %f %s\n", position+1, dynamic_array[position].CGPA, dynamic_array[position].ID);

            gettimeofday(&start, NULL);
            student* new_student = malloc(sizeof(student));
            new_student->CGPA = CG;
            strncpy(new_student->ID, id, LENGTH_OF_ID);
            new_student->ID[LENGTH_OF_ID] = '\0';

            NODE new_node = createNewNode(new_student);
            insertAtEnd(list, new_node);
            
            gettimeofday(&end, NULL);
            printf("Time taken for inserting a new element into the linked list is: %ld microseconds\n",
            ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
        }
        else
            break;
    }
    
    free(dynamic_array);
    while(removeFromBeginning(list));
    free(list);
    return;    
}
