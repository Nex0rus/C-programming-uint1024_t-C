#include <stdio.h>
#include <malloc.h>

typedef struct unit1024_t {
    unsigned char arr[309];
} unit1024_t;

int main() {
    unit1024_t* unit1;
    // unit1 = (unsigned char*)сalloc(1, 309);
    unit1->arr[0] = 100;
    unit1->arr[1] = 200;
    unit1->arr[2] = 1;
    // for(int i = 0; i < 310; i++) {
    //     printf("%c\n", (*unit1).arr[i]);
    // }
    printf("%c %c %c",unit1->arr[0], unit1->arr[1], unit1->arr[2]);
    printf("Hello World");


    return 0;
}