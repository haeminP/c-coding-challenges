#include <stdio.h>

double calc_average(double score_vals[], int num_vals);
void print_scores(double score_vals[], int num_vals);
void adjust_scores(double score_vals[], int num_vals, double score_adj);

int main()
{
    const int NUM_SCORES = 4;   // Array size
    double test_scores[NUM_SCORES];
    int i;
    double average_score;

    // Prompt user to input test scores
    printf("Enter %d test scores\n", NUM_SCORES);

    for (i = 0; i < NUM_SCORES; ++i)
    {
        printf("Test score: ");
        scanf("%lf", &test_scores[i]);
    }

    printf("\n");

    // Print original scores
    printf("Original test scores: ");
    print_scores(test_scores, NUM_SCORES);

    // Adjust original scores and print adjusted scores
    adjust_scores(test_scores, NUM_SCORES, 2.0);
    printf("Adjust test scores: ");
    print_scores(test_scores, NUM_SCORES);

    // Call function to calculate average
    average_score = calc_average(test_scores, NUM_SCORES);
    
    printf("\nAverage adjusted test score: %lf\n", average_score);

    return 0;
}

double calc_average(double score_vals[], int num_vals)
{
    double sum = 0.0;
    int i;

    for (i = 0; i < num_vals; ++i)
    {
        sum += score_vals[i];
    }

    return sum / num_vals;
}

void print_scores(double score_vals[], int num_vals)
{
    int i;
    for (i = 0; i < num_vals; ++i)
        printf("%lf ", score_vals[i]);
    printf("\n");
}

void adjust_scores(double score_vals[], int num_vals, double score_adj)
{
    int i;
    for (i = 0; i < num_vals; ++i)
        score_vals[i] += score_adj;
}