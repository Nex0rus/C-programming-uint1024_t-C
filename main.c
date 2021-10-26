#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(a, b) ((a) >=(b)) ? (a) : (b)
typedef struct unit1024_t {
    unsigned char arr[155];
} unit1024_t;

void scanf_value(unit1024_t* x);
void printf_value(unit1024_t* x);
unit1024_t from_unit(unsigned x);
unit1024_t add_op(unit1024_t x, unit1024_t y);
unit1024_t subtr_op(unit1024_t x, unit1024_t y);
unit1024_t mult_op(unit1024_t x, unit1024_t y);


int main(int argc, char* argv[]) {

    unit1024_t* number1;
    number1 = calloc(1, 155);
    scanf_value(number1);
    unsigned int x;
    scanf("%d", &x);
    unit1024_t* number2;
    number2 = calloc(1, 155);
    *number2 = from_unit(x);
    // scanf_value(number2);
    unit1024_t* res;
    res = calloc(1, 155);
    printf("unit1024_t number scanned from input is:\n");
    printf_value(number1);
    printf("unit1024_t number generated from unsigned int x is:\n");
    printf_value(number2);
    *res = add_op(*number1, *number2);
    printf("The summ of unit1024_t scanned and unit1024_t generated from unsigned int x is:\n");
    printf_value(res);
    *res = subtr_op(*number1, *number2);
    printf("The residual of unit1024_t scanned and unit1024_t generated from unsigned int x is:\n");
    printf_value(res);
    *res = mult_op(*number1, *number2);
    printf("The product of unit1024_t scanned and unit1024_t generated from unsigned int x is:\n");
    printf_value(res);

    return 0;
}


unit1024_t from_unit(unsigned int x) {

    unit1024_t *temp;
    temp = calloc(1, 155);
    int i = 0;

    while (x != 0) {

        temp -> arr[i] = x%100;
        x = (int)x/100;
        i++;

    }

    return *temp;

}


unit1024_t add_op(unit1024_t x, unit1024_t y) {

    unit1024_t *summ;
    summ = calloc(1, 155);
    unsigned char carry = 0;
    unsigned char plasces_summ = 0;

    for (unsigned char i = 0; i < 155; i++) {

        plasces_summ = x.arr[i] + y.arr[i] + carry;
        summ -> arr[i] = plasces_summ%100;
        carry = (int)(plasces_summ/100);

    }

    return *summ;
}

unit1024_t subtr_op(unit1024_t x, unit1024_t y) {

    unit1024_t *subtr;
    subtr = calloc(1, 155);
    unsigned char carry = 0;
    signed char places_subtr = 0;

    for (unsigned char i = 0; i < 155; i++) {
        
        places_subtr = x.arr[i] - y.arr[i] - carry;

        if (places_subtr < 0) {
            places_subtr += 100;
            carry = 1;
        }

        subtr -> arr[i] = places_subtr;
    }

    return *subtr;

}


unit1024_t mult_op(unit1024_t x, unit1024_t y) {
    
    unit1024_t *mult;
    mult = calloc(1, 155);
    unsigned char carry = 0, x_start = 154, y_start = 154;
    int places_mult = 0;

    while (x.arr[x_start] == 0) {
        x_start--;
    }

    while (y.arr[y_start] == 0) {
        y_start--;
    }

    for (int i = 0; i <= x_start; i++) {

        for (int j = 0; j <=y_start+1; j++) {

            places_mult = x.arr[i]*y.arr[j] + carry;
            mult -> arr[i+j] += places_mult%100;
            carry = (int)(mult -> arr[i+j]/100) + (int)(places_mult/100);
            mult -> arr[i+j] = (mult -> arr[i+j])%100;
            
        }
        

    }

    return *mult;

}


void printf_value(unit1024_t* x) {

    int j = 154;

    while (x->arr[j] == 0 && j > -1) {
        j--;
    }

    if (j == -1) {
        printf("0\n");
        return;
    }

    for (int i = j; i > -1; i--) {

        if ((int)((x ->arr[i])/10) == 0 && i!= j && i !=0 ) {

            if (i!=0) {
                printf("0%d", x -> arr[i]);
            }

        }

        else if (i == 0) {

            if (x -> arr[i] / 10 == 0) {
                printf("0%d\n", x -> arr[i]);
            }
            else {
                printf("%d\n", x -> arr[i]);
            }

        }

        else {
            printf("%d", x -> arr[i]);
        }

    }

}


void scanf_value(unit1024_t* x) {

    char string_in[309];
    scanf("%s", &string_in);
    int index = 0;
    int digit = 0;
    int temp_sum = 0;
    int end_index = 0;

    while (string_in[end_index] != '\0') {
        end_index++;
    }    

    for (int i = end_index-1; i > -1; i--) {

        char symbol = string_in[i];
        char temp_string[2];
        temp_string[0] = symbol;
        temp_string[1] = '\0';
        digit = atoi(temp_string);

        if (i%2 == (end_index-1)%2 && i != 0) {
            temp_sum += digit;
        }

        else if (i == 0 && temp_sum!=0) {
            temp_sum += digit*10;
            x -> arr[index] = temp_sum;
            temp_sum = 0;
        }

        else if (i ==0 && temp_sum == 0) {
            temp_sum += digit;
            x -> arr[index] = temp_sum;
            temp_sum = 0;
        }

        else {
            temp_sum+=digit*10;
            x -> arr[index] = temp_sum;
            temp_sum = 0;
            index++;
        }
        
    }

}
