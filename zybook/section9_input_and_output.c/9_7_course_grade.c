#include <stdio.h>

int main(){

    FILE* inFile = NULL;
    FILE* outFILE = NULL;

    char firstName[25];
    char lastName[25];
    
    float studentAvg;
    char grade;
    int midterm1;
    int midterm2;
    int final;
    float examAvg[3] = {0.0, 0.0, 0.0};
    
    int valuesRead;
    int count = 0;

    char fileName[25];
    scanf("%s", fileName);

    inFile = fopen(fileName, "r");
    outFILE = fopen("report.txt", "w");
    
    if (inFile == NULL){
        printf("Could not open file.\n");
        return -1;      // -1 indicates an error
    }

    valuesRead = fscanf(inFile, "%s %s %d %d %d", lastName, firstName, &midterm1, &midterm2, &final);

    while (!feof(inFile)){
        if (valuesRead < 5){
            printf("Not enough data\n");
        }

        else if (valuesRead == 5){
            // calculate student average and exam average
            studentAvg = (midterm1 + midterm2 + final) / 3;
            examAvg[0] += midterm1;
            examAvg[1] += midterm2;
            examAvg[2] += final;

            if (studentAvg >= 90)
                grade = 'A';
            else if (studentAvg >= 80)
                grade = 'B';
            else if (studentAvg >= 70)
                grade = 'C';
            else if (studentAvg >= 60)
                grade = 'D';
            else
                grade = 'F';

            fprintf(outFILE, "%s\t%s\t%d\t%d\t%d\t%c\n", lastName, firstName, midterm1, midterm2, final, grade);
            ++count;
        }

        else {
            printf("Input failure before reaching end of file.\n");
            break;
        }

        valuesRead = fscanf(inFile, "%s %s %d %d %d", lastName, firstName, &midterm1, &midterm2, &final);
    }

    fprintf(outFILE, "\nAverages: midterm1 %.2f, midterm2 %.2f, final %.2f\n", examAvg[0]/count, examAvg[1]/count, examAvg[2]/count);

// Done with file, so close it
    fclose(inFile);
    fclose(outFILE);



    return 0;
}