#include <stdio.h>

void countdown(int i);


long factorial_iter(int i){
    long factorial = 1.0;

    for (i; i > 0; --i)
        factorial *= i;
    
    return factorial;
}

long factorial_recur(int i){
    if(i == 1)
        return i;

    else 
        return i * factorial_recur(i-1);
}


void fibonacci_iter(int i){
    int fib_nums[i];
    fib_nums[0] = 0;
    fib_nums[1] = 1;
    
    for (int j = 2; j < i; ++j){
        fib_nums[j] = fib_nums[j-1] + fib_nums[j-2];
    }

    for (int j = 0; j < i; ++j)
        printf("%d ", fib_nums[j]);
}



int fibonacci_recur(int i){
    // two base cases
    if (i == 0)
        return i;
    if (i == 1)
        return i;

    // recursive case
    else
        return fibonacci_recur(i-1) + fibonacci_recur(i-2);  

}

int main(){
    printf("%ld\n", factorial_iter(5));

    printf("%ld\n", factorial_recur(5));

    fibonacci_iter(5);

    printf("\n%d", fibonacci_recur(5));

    return 0;
}