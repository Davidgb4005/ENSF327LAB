/*
* File Name: lab5ExC.cpp
* Assignment: Lab 5 Exercise C
* Lab section: Summer
* Completed by: David Burgoin
* Development Date: May 31/2024
*/
#include <iostream>
using namespace std;

void insertion_sort(int *int_array, int n);
/* REQUIRES
 *    n > 0. 
 *    Array elements int_array[0] ... int_array[n - 1] exist.
 * PROMISES
 *    Element values are rearranged in non-decreasing order.
 */

void insertion_sort(const char** str_array, int n);

/* REQUIRES
 *   n > 0.
 *   Array elements str_array[0] ... str_array[n - 1] exist.
 * PROMISES
 *   pointers in str_array are rearranged so that strings:
 *   str_array[0] points to a string with the smallest string (lexicographicall) ,
 *   str_array[1] points to the second smallest string, ..., str_array[n-2] 
 *   points to the second largest, and str_array[n-1] points to the largest string
 */
int str_lex_value(const char* str_adr);

void ptr_swap(const char** ptr1, const char** ptr2);
void value_swap(int * val1, int * val2);

int main(void)
{
    const char* s[] = { "AB", "XY", "EZ"};
    const char** z = s;
    z += 1;

    
    cout << "The value of **z is: " << **z << endl;
    cout << "The value of *z is: " << *z << endl;
    cout << "The value of **(z-1) is: " << **(z-1)<< endl;
    cout << "The value of *(z-1) is: " << *(z-1)<< endl;
    cout << "The value of z[1][1] is: " << z[1][1]<< endl;
    cout << "The value of *(*(z+1)+1) is: " << *(*(z+1)+1)<< endl;
 
    // point 1

    int a[] = { 413, 282, 660, 171, 308, 537 };
    
    int i;
    int n_elements = sizeof(a) / sizeof(int);
    
    cout << "Here is your array of integers before sorting: \n";
    for(i = 0; i < n_elements; i++)
        cout <<  a[i] << endl;
    cout << endl;
    
    insertion_sort(a, n_elements);
    
    cout << "Here is your array of ints after sorting:  \n" ;
    for(i = 0; i < n_elements; i++)
        cout << a[i] << endl;
#if 1
    const char* strings[] = { "Red", "Blue", "pink","apple", "almond","white",
                                               "nut", "Law", "cup"};
    
    n_elements = sizeof(strings) / sizeof(char*);
    
    cout << "\nHere is your array of strings before sorting: \n";
    for(i = 0; i < n_elements; i++)
        cout <<  strings[i] << endl;
    cout << endl;

    insertion_sort(strings, sizeof(strings)/sizeof(char*));

    
    cout << "Here is your array of strings after sorting:  \n" ;
    for(i = 0; i < n_elements; i++)
        cout << strings[i] << endl;
    cout << endl;
    
#endif
    
    return 0;
}

void insertion_sort(int *a, int n)
{
    int i;
    int j;
    int value_to_insert;
    
    for (i = 1; i < n; i++) {
        value_to_insert = a[i];
        
        /* Shift values greater than value_to_insert. */
        j = i;
        while ( j > 0 && a[j - 1] > value_to_insert  ) {
            a[j] = a[j - 1];
            j--;
        }
        
        a[j] = value_to_insert;
    }
}

void insertion_sort(const char** str_array, int n){
    int str_value_index[n]={};
    for(int i = 0;i<n;i++){
        str_value_index[i] = str_lex_value(str_array[i]);
    }
    for(int i = 0;i<n;i++){
        for(int k = i;k<n;k++)
            if (str_value_index[i]<str_value_index[k]){
                value_swap(str_value_index+i,str_value_index+k);
                ptr_swap(&str_array[i],&str_array[k]);

        }
    }
}

int str_lex_value(const char* str_adr){
    int str_value=0;
    int i = 0;
    while (str_adr[i] != 0){
        str_value=str_value+str_adr[i];
        i++;
    }
    return str_value;
}

void ptr_swap(const char** ptr1, const char** ptr2){
    const char * ptr_value = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = ptr_value;

}

void value_swap(int * val1, int * val2){
    int a = 0;
    a = *val1;
    *val1 = *val2;
    *val2 = a;
}

