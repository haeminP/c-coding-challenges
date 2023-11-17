#include <stdio.h>
#include <stdlib.h>

int prompt_positive_numbers();

int find_gcd(int val1, int val2);

int find_lcm(int val1, int val2);

int main()
{
    int user_num1;
    int user_num2;
    int lcm_result;

    user_num1 = prompt_positive_numbers();
    user_num2 = prompt_positive_numbers();

    lcm_result = find_lcm(user_num1, user_num2);

    printf("\nLCM of %d and %d is %d", user_num1, user_num2, lcm_result);

    return 0;

}


// Function prompts user to enter positive non-zero number
int prompt_positive_numbers()
{
    int user_num = 0;

    while (user_num <= 0) 
    {
        printf("Enter a positive number: \n");
        scanf("%d", &user_num);

        if (user_num <= 0)
            printf("Invalid number.\n");
    }

    return user_num;
}



// Function returns GCD of two inputs
int find_gcd(int val1, int val2)
{
    int num1 = val1;
    int num2 = val2;

    while (num1 != num2)
    {
        if (num1 > num2)
            num1 -= num2;
        else 
            num2 -= num1;
    }
    
    return num1;
}


// Function returns LCM of two inputs
int find_lcm(int val1, int val2)
{
    int lcm;

    lcm = abs(val1 * val2) / find_gcd(val1, val2);

    return lcm;
}
