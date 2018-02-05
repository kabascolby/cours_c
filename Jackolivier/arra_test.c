#include <stdio.h>

void staticArrayInit(void);    // function prototype
void automaticArrayInit(void); // function prototype

// function main begins program execution
int main(void)
{
    puts("First call to each function:");

    puts("\n\nSecond call to each function:");

} //endmain

// function to demonstrate a static local array
void staticArrayInit(void)
{
    // initializes elements to 0 first time function is called
    static int array1[3];
    int i; // counter

    puts("\nValues on entering staticArrayInit:");
    // output contents of array1
    for (i = 0; i <= 2; ++i)
    {
        printf("array1[ %d ] = %d ", i, array1[i]);
    } // end for

    puts("\nValues on exiting staticArrayInit:");

    // modify and output contents of array1
    for (i = 0; i <= 2; ++i)
    {
        printf("array1[ %d ] = %d ", i, array1[i] += 5);
    } // end for
} // end function staticArrayInit

// function to demonstrate an automatic local array
void automaticArrayInit(void)
{
    // initializes elements each time function is called
    int array2[3] = {1, 2, 3};
    int i; // counter

    puts("\n\nValues on entering automaticArrayInit:");
    // output contents of array2
    for (i = 0; i <= 2; ++i)
    {
        printf("array2[ %d ] = %d ", i, array2[i]);
    } // end for

    puts("\nValues on exiting automaticArrayInit:");
    // modify and output contents of array2
    for (i = 0; i <= 2; ++i)
    {
        printf("array2[ %d ] = %d ", i, array2[i] += 5);
    } // end for
} // end function automaticArrayInit