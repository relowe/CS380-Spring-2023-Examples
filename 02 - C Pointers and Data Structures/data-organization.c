#include <stdio.h>
#include <stdlib.h>

int main()
{
    // C datatypes in order of size
    char c;        // C standard: sizeof(char) = 1
    short int si;  // sizeof(short int) >= sizeof(char)
    int i;         // sizeof(int) >= sizeof(short int)
    float f;       // sizeof(float) >= sizeof(int) 
    long int li;   // sizeof(long int) >= sizeof(int)
    double d;      // sizeof(double) >= sizeof(float)
    long long ll;  // sizeof(long long) >= sizeof(long int)
    void *ptr;     // a void pointer


    //aggregate types
    int ari[10];
    struct {
        int i;
        double d;
        void *ptr;
    } my_struct;


    // sizeof(expr|type) operator
    printf("sizeof(c)\t%d\n", sizeof(c));
    printf("sizeof(si)\t%d\n", sizeof(si));
    printf("sizeof(i)\t%d\n", sizeof(i));
    printf("sizeof(f)\t%d\n", sizeof(f));
    printf("sizeof(li)\t%d\n", sizeof(li));
    printf("sizeof(d)\t%d\n", sizeof(d));
    printf("sizeof(ll)\t%d\n", sizeof(ll));
    printf("sizeof(ari)\t%d\n", sizeof(ari));
    printf("sizeof(my_struct)\t%d\n", sizeof(my_struct));
    printf("sizeof(ptr)\t%d\n", sizeof(ptr));

    // print out the variable addresses
    //    &var returns the address of that variable
    //         - type of this expression is a pointer to that variable
    printf("&c\t%p\n", &c);
    printf("&si\t%p\n", &si);
    printf("&i\t%p\n", &i);
    printf("&f\t%p\n", &f);
    printf("&li\t%p\n", &li);
    printf("&d\t%p\n", &d);
    printf("&ll\t%p\n", &ll);
    printf("&my_struct\t%p\n", &my_struct);
    printf("&ari\t%p\n", &ari);
    printf("&ptr\t%p\n", &ptr);
}