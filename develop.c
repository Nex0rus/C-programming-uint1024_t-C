#include <stdio.h>
#include <stdlib.h>
typedef struct unit1024_t {
    unsigned char arr[5];
} unit1024_t;

int main() {
    unit1024_t *unit1;
    unit1 = calloc(1, 155);
    unit1 -> arr[0] = 100;
    unit1 -> arr[1] = 200;
    unit1 -> arr[2] = 1;
    char string_in[309];
    // string_in = calloc(1, 309);
    scanf("%s", &string_in);
    int digit;
    int i = 0;
    char massive[2];
    massive[0] = 5;
    massive[1] = 20;
    printf(massive[0]*massive[1]);
    printf("%d %d %d %d\n",unit1 -> arr[0], unit1 -> arr[1], unit1 -> arr[2], unit1 -> arr[3]);
    for (; i < 309; i++) {
        char symbol = string_in[i];
        if (symbol == '\0') {
            break;
        }

        char temp_string[2];
        temp_string[0] = symbol;
        temp_string[1] = '\0';
        digit = atoi(temp_string);
        printf("%d", digit);
    
    }

    printf("Hello World");
    return 0;
}