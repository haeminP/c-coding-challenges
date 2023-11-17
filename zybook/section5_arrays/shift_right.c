#include <stdio.h>

int main()
{
    int input_num;
    int nums[20];
    int i;
    int shifted_nums[20];

    scanf("%d", &input_num);
    
    for (i = 0; i < input_num; ++i)
        scanf("%d", &nums[i]);

    shifted_nums[0] = nums[input_num -1];

    for (i = 0; i < input_num -1; ++i)
        shifted_nums[i+1] = nums[i];
    

    for (i= 0; i < input_num; ++i)
        printf("%d ", shifted_nums[i]);

    return 0;
}