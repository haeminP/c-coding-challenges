#include <stdio.h>

int main()
{
    int input_num;
    int nums[20];
    int i;
    int temp_val;

    scanf("%d", &input_num);
    
    for (i = 0; i < input_num; ++i)
        scanf("%d", &nums[i]);
    
    temp_val = nums[0];
    nums[0] = nums[input_num -1];
    nums[input_num -1] = temp_val;

    for (i= 0; i < input_num; ++i)
        printf("%d ", nums[i]);

    return 0;
}