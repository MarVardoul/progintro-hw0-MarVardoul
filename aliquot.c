#include <stdio.h>

//function to calculate sum of perfect divisors

long long int sum_of_perfect_divisors(long long int n, long long int sum)
{
    if (n <= 1)
        return 0;
    sum = 1; // 1 is always a proper divisor for n > 1
    for (long long int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n)
                sum += i;      // perfect square — add only once
            else
                sum += i + n / i; // add both divisors
        }
    }
   return sum;
}


int main() {

    /* variables */
    long long int initial_number;
    long long int max_length;
    int steps = 0; // length of sequence
    char option;
    long long int sum_main;

    /* messages to user / read user input */

    printf("enter the initial number to calculate the aliquot sequence: \n");
    if (scanf("%lld", &initial_number) != 1) {
        return 1; // invalid input, exit
    }

    printf("press f for full sequence, l to calculate the length \n");
    fflush(stdout);
    if (scanf(" %c", &option) != 1) {
        return 1; // invalid input, exit
    }

    printf("\n");
    if (option == 'f') {
        printf("enter the maximum length of the sequence: \n");
        fflush(stdout);
        if (scanf("%lld", &max_length) != 1) {
            return 1; // invalid input, exit
        }
        printf("\n");
        printf("%lld\n", initial_number);
    } // end if
    else
        max_length = 0; // max length zero, runs until termination condition met

    if (option != 'f' && option != 'l') {
        printf("not a valid option\n");
        return 1;
    } // end if, exits if not given f or l

    if (initial_number <= 0 || max_length < 0 || initial_number > 1000000000000000LL) {
        printf("can't compute the aliquot sequences with these parameters \n");
        return 1;
    } // end if, exits if initial_number or length negative or if initial number greater than 10^15

    for (long long int j = 0; j < max_length || max_length == 0; j++) {
        sum_main = 0; // reset sum for each repetition
        steps++;
        sum_main = sum_of_perfect_divisors(initial_number, sum_main);
        if (sum_main > 1000000000000000LL) {
            printf("the sum exceeded 10^15 \n");
            return 1;
        } // end if, exits if sum exceeds 10^15
        if (option == 'f') {
            printf("%lld\n", sum_main);
        } // end if

        initial_number = sum_main; // update initial number to be sum of perfect divisors

        if (sum_main == 0) {
            break;
        } // end if, stops early if sum is already 0
    } // end for

    if (option == 'l') {
        printf("%d \n", steps);
    } // end if

    return 0;
} // end main
// end aliquot.c