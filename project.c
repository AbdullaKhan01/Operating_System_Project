// RegNo: 12217713, Name: Abdulla Khan , Section: K22SA , Roll No: 20
/*
Problem 7: You are tasked with writing a program that dynamically allocates memory for a data structure. Your program should perform the following steps:

1. Prompt the user to enter the number of elements to allocate memory for

2. Use the malloc() function to allocate memory for the specified number of elements.

3. Prompt the user to enter values for the allocated memory

4. Store the user's input in the allocated memory. 5. Print the values stored in the allocated memory.

6. Use the free() function to release the memory allocated in step 2.

Your program should include error handling for the memory allocation step to detect and handle any errors that may occur. You may also want to include options to specify the size and type of the elements to be allocated, as well as the input and output formats. Additionally, you may want to consider using functions or structs to organize and manipulate the allocated memory
*/
#include<stdio.h>
#include<stdlib.h>

struct Person{
    char name[30];
    char gender [10];
    int age;
 };

struct Person* persons;
void integerInput (int *arr, int n){
    for (int i=0;i<n;i++){
        printf("Enter the value of integer %d: ",i+1);
        scanf("%d",&arr[i]);
    }

}

void floatInput (float *arr, int n){ 
    for (int i=0;i<n;i++){
        printf("Enter the value of float %d : ",i+1); scanf("%f",&arr[i]);
    }

}

void doubleInput (double* arr, int n){
    for (int i=0;i<n;i++){
        printf("Enter the value of double %d ",i+1);
        scanf("%lf",&arr[i]);
     }

}
void charInput (char* str1){
    printf("Enter the character stream: \n");
    scanf("%s", str1);

}

void inputStruct(struct Person *ptr, int n){
    for (int i=0;i<n;i++){
        printf("Enter Name of Person %d : ",i+1);
        scanf("%s", (ptr+i)->name);
        printf("Enter the age of Person %d ",i+1);

        scanf("%d", &(ptr+i)->age);


        printf("Enter the gender of Person %d: ",i+1); 
        scanf("%s", (ptr+i)->gender);
    }

 }

int main(){

//Write your code here/
    printf("WELCOME TO THE PROGRAM \n\n");
    int n;
    printf("Enter the no of elements to allocate memory for : \n");
    scanf("%d", &n);
    printf("Enter 1 to allocate memory of interger type\n");
    printf("Enter 2 allocate memory of float type\n");
    printf("Enter 3 to allocate memory for double type\n"); 
    printf("Enter 4 to allocate memory for char type\n");
    printf("Enter 5 to allocate memory for Struct type\n");
    printf("Enter 6 to exit\n");
    printf("Enter your choice: \n");

    int tt;
    scanf("%d", &tt);
    switch(tt){
        case 1:;

        int* data;

        data = (int*)malloc(n*sizeof(int));

        if(data == NULL) {
            printf("Memory allocation failed\n");
            exit(0);
        }
        integerInput (data,n);
        printf("\nThe values are: ");
        for (int i=0;i<n;i++){
            printf("%d ", data[i]);
        }
        free(data);
        printf("\nMemory Deallocated\n");
        break;

        case 2:;

        float *arr1;
        arr1 = (float*)malloc(n*sizeof(float));

        if(arr1 == NULL) {

        printf("Memory allocation failed\n");
        exit(0);
        }
        floatInput(arr1,n);
        printf("\nThe values are: ");

        for(int i=0;i<n;i++){
            printf("%f ",arr1[i]);

        }
        free(arr1);
        printf("\nMemory Deallocated\n");
        break;

        case 3:;
        double* arr2;
        arr2 = (double*)malloc(n*sizeof(double));

        if(arr2== NULL) {
            printf("Memory allocation failed\n");
            exit(0);

        }
        doubleInput (arr2,n);
        printf("\nThe values are: ");
        for(int i=0;i<n;i++){
            printf("%lf ", arr2[i]);
        }
        free(arr2);
        printf("\nMemory Deallocated\n");
        break;

        case 4:;

        char *str1;
        str1 = (char*)malloc(n*sizeof(char));
        if(str1 == NULL) {
            printf("Memory allocated failed\n");
            exit(0);
        }
        charInput(str1);
        printf("The character stream is: %s\n", str1);
        free(str1);
        printf("Memory Deallocated\n");
        break;

        case 5:
        persons = (struct Person*)malloc(n*sizeof(struct Person));

        if(persons == NULL) {
            printf("Memory allocation failed \n");
            exit(0);
        }

        inputStruct(persons,n);
        for(int i=0;i<n;i++){
            printf("The Details of Person %d is :\n",i+1);
            printf("Name: %s\n", (persons+i)->name);
            printf("Age: %d\n", (persons+i)->age);
            printf("Gender : %s\n\n", (persons+i)->gender);
        }
        free(persons);
        printf("Memory Deallocated\n");
        break;

        default:exit(0);

        }

        return 0;
}



