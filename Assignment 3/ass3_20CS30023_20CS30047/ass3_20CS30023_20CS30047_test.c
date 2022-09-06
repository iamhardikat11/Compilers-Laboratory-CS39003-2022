/*
*   Compilers Labortary
*   Compilers Assignment 3
*   Hardik Pravin Soni - 20CS30023
*   Saurabh Jaiswal - 20CS30047
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define NUMBER 1234
#define MOD 1e9+7
#define forn(i, e) for(int i=0;i<e;i++)
#define forsn(i,s,e) for(int i=s;i<e;i++)
#define INF 2e18
#define max(a,b) a > b ? a : b
#define min(a,b) a > b ? b : a

typedef long long ll
typedef long double ld


typedef struct student {
    char name[30];
    unsigned int rollNo;
    float gpa;
} stud;

enum week{ 
    Monday, 
    Tuesday, 
    Wednesday, 
    Thursday, 
    Friday, 
    Saturday, 
    Sunday 
};

int main()
{
    double d1,d2,d3;
    d1 = 12345.;
    d2 = .98765;
    d3 = 12.2345E2;
    int ch = 6;
    switch(ch)
    {
        case 1:
            printf("Number is %d\n.",1);
            break;
        case 2:
            printf("Number is %d\n.",2);
            break;
        case 3:
            printf("Number is %d\n.",3);
            break;
        case 4:
            printf("Number is %d\n.",4);
            break;
        case 5:
            printf("Number is %d\n.",5);
            break;
        case 6:
            printf("Number is %d\n.",6);
            break;
        default:    
            printf("None of the Integers Matched.\n");
    }
    float f1,f2,f3;
    f1 = 1234.;
    f2 = .2345
    f3 = 123.23E4;
    const float f4 = .234E-2;
    do
    {
        int k = f4 % 10;
        printf("%f ",f4);
        f4 = f4/10;
    }while(f3!=0.0)
    printf("\n");
    unsigned long l1 = 34832984032942;
    signed long l2 = -384823432089;
    signed short s1 = 234;
    signed short s2 = -32768;
    unsigned short s3 = 32767;
    signed long s = -12443;
    char *ch1;
    ch1 = (char *)malloc(100 * sizeof(char));
    char *h = "Hello  welcome to this program .\n";
    *ch1 = "This is a String !! /* Hello This is our Team.*/ Not even multi-line comments will be read here.\n";
    do {
        s << 2;
        s >> 2;
        s = ~s;
        s = s | s;
        s = s * s;
        s = s + 2;
        s++;
        s -= 2;
        s = !s;
        s = s % 200;
        if(s > 200 && s < 200 && s==200)
            continue;
        else if(s >= 200 && s<200)
            s += 1;
        s-=1;
        s++;
        s--;
        int k = s > 200 ? 1 : 0;
        int r *= 10;
        (s/=10); 
        (s%=10);
        s>>=20;
        s<<=20;
        int w = s & 1 ^ 100;
        s&=1;
        s^=1;
        int t = f1 || f2;
        if(s < 10 && s > 0)
            goto some_label;
        some_label:
            continue;
    } while(n2 != -1 || !n1);
    goto studentLabel;
    newLabel:   
        stud student1, student2;
        student1.name = "teddy123";
        student1.rollNo = 23;
        student1.gpa = 9.4;
        student2.name = "name123";
        student2.rollNo = 27;
        student2.gpa = 9.5;
    return 0;    
}
