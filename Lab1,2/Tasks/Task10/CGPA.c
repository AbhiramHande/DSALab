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
        NODE node = createNewNode(data);
        insertAtEnd(list, node);
    }
    gettimeofday(&end, NULL);
    printf("Time taken for inserting %d elemnts into a linked list is: %ld microseconds\n", NUMBER_OF_STUDENTS,
    ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));

    //Task 10b. Prompt the user to enter new entries into the records at user specific locations. 
    //Then, insert those records into the two data structures separately and compare the time taken by them for the same. 
    int time_dynamic_array, time_linked_list;
    int size = NUMBER_OF_STUDENTS;
    for(int i = 0; i < NUMBER_OF_CHANGES; i++){
        int position;
        float CG;
        char id[LENGTH_OF_ID];
        scanf("%d %f %s", &position, &CG, &id);
        size++;
        realloc(dynamic_array, size*sizeof(student));
    }

    return;    
}