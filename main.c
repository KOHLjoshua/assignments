/*
Hello There 
This code is developed to respond to the DSA assignments request by Mr.Dallington.
Hope you have fun contributing to this code.

Happy Hunting.
*/

#include <stdio.h>

int main() {
    int n=3,x=2;
    char domestic_animals[n][50];
    char wild_animals[x][50];
    char* merged_animals[n+x];
    for(int i=0;i<n;i++){
        printf("Enter domestic animal: ");
        scanf("%s",domestic_animals[i]);
        merged_animals[i] = domestic_animals[i];
    }
    printf("\n");
    for(int i=0;i<x;i++){
        printf("Enter wild animal: ");
        scanf("%s",wild_animals[i]);
        merged_animals[n+i] = wild_animals[i];
    }
    printf("\n  Merged array; ");
    for(int i=0;i<n+x;i++){
        printf("%s ",merged_animals[i]);
    }
    return 0;
}

#include <stdio.h>
char* exams[4] = {"assignments", "coursework", "midTerm", "EndOfTerm"};
float Get_averagePhysics(){
    float physics[4];

    float sum = 0;
    printf("\t PHYSICS MARKS\n");
for (int i=0;i<4;i++){
    while(1){
        printf("%s: ",exams[i]);
        scanf("%f",&physics[i]);
            if (physics[i]<0 || physics[i]>100){
                printf("Invalid input.Please enter marks within range(0-100)  \n");

            }else{
                break;
            }
        }
    }
for (int i=0;i<4;i++){
        sum += physics[i];
    }
    return sum/4;
}
float Get_averageChemistry(){
    float chemistry[4];


    float sum = 0;
    printf("\n\t CHEMISTRY MARKS \n");
for (int i=0;i<4;i++){
    while(1){
        printf("%s: ",exams[i]);
        scanf("%f",&chemistry[i]);
        if (chemistry[i]<0|| chemistry[i]>100){

                printf("Invalid input.Please marks within range(0-100)\n");
            }else{
                break;
            }
        }
    }
for (int i=0;i<4;i++){
        sum += chemistry[i];
    }
    return sum/4;
}
float Get_averageMathematics(){
    float mathematics[4];


    float sum = 0;
    printf("\n\t MATHEMATICS MARKS \n");
for (int i=0;i<4;i++){
    while(1){
        printf("%s: ",exams[i]);
        scanf("%f",&mathematics[i]);
        if (mathematics[i]<0|| mathematics[i]>100){

                printf("Invalid input.Please marks within range(0-100)\n");
            }else{
                break;
            }
        }
    }
for (int i=0;i<4;i++){
        sum += mathematics[i];
    }
    return sum/4;
}
int main() {
    float averagePhysics = Get_averagePhysics();
    printf("Physics average is %.2f\n",averagePhysics);
    float averageChemistry = Get_averageChemistry();
    printf("Chemistry average is %.2f\n",averageChemistry);
    float averageMathematics = Get_averageMathematics();
    printf("Chemistry average is %.2f\n",averageMathematics);
    float overall_average = (averagePhysics + averageChemistry + averageMathematics )/3;


    printf("\nThe overall average for PCM is %.2f",overall_average);
    return 0;
}
