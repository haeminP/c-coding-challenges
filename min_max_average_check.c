#include <stdio.h>
#include <ctype.h>
#include <float.h>

int main()
{
    float num;
    float max = -FLT_MAX;
    float min = FLT_MAX;
    float sum = 0.0f;
    float average = 0.0f;
    int counter = 0;
    

    while(scanf("%f", &num) == 1)
    {
        // TODO: ignore negative values & values over 100
        if(num < 0 || num > 100)
            continue;

        if(num > max)
            max = num;
        
        if(num < min)
            min = num;
        
        sum += num;

        counter++;
    }

    if (counter > 0)
    {
        average = sum / counter;
        printf("min = %f, max = %f, ave = %f", min, max, average);
    }

    else
        printf("No inputs");

    return 0;

}
