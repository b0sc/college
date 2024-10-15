#include <stdio.h>


double absf(double num){
    // if number is greater or equal to 0, return the number
    if(num>=0) return num;
    //  as num < 0 , are {-1,-2,-3.....-inf}
    // and when multiplied by -1, they become positive
    return num*-1;
}

double c_sqrt(double num) {
    // ignore negatives numbers
    if (num < 0) {
        return -1;
    }
    // return 0, as root of zero is zero
    if (num == 0) {
        return 0;
    }
    // assume the number as intial guess
    double guess = num;
    // error upto 6th decimal places ( 10 * -6 )
    double epsilon = 1e-6;
    // initial difference zero
    double difference = 0;

    do {
        double next_guess = 0.5 * (guess + num / guess);
        difference = absf(next_guess - guess);
        guess = next_guess;
    } while (difference > epsilon);

    return guess;
}

int main() {
    double num;
    printf("Enter a number: ");
    scanf("%lf", &num);
    double result = c_sqrt(num);
    if(result>=0){
        printf("The square root of %lf is %lf.\n",num,result);
    }else{
        printf("%lf has no roots.\n",num);
    }
}
   
