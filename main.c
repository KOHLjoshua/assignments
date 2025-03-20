#include <stdio.h>
#include <stdlib.h>

#define NUM_ANIMALS 3
#define MAX_LENGTH 100

int main()
{
    char wild_animals[][];
    char domestic_animals[][];
    char result[][] = "";

    printf("Enter %d wild animals", NUM_ANIMALS);
    for(int i= 0; i < NUM_ANIMALS; i++){
        printf("Wild animal %d: ", i + 1);
        scanf("%s", wild animals[i]);
    }
    printf("Enter %d wild animals", NUM_ANIMALS);
    for(int i= 0; i < NUM_ANIMALS; i++){
        printf("Wild animal %d: ", i + 1);
        scanf("%s", wild animals[i]);
    }

    for (int i = 0; i < NUM_ANIMALS; i++){
        strcat(result, wild_animals[i]);
        strcat(result, "");
        strcat(result, domestic_animals[i]);
        strcat(result, "");
    }

    printf("All the animals merged; %s\n", result);

    return 0;

    /*int ass, coursework, midterm, endofterm;
    double average;
    printf("\physics detail\n");
    printf("enter marks for ass; ");
    scanf("%d",&ass);
    printf("enter marks for coursework; ");
    scanf("%d",&coursework);
    printf("enter marks for midterm; ");
    scanf("%d",&midterm);
    printf("enter marks for endterm; ");
    scanf("%d",&endofterm);

     average = (ass+coursework+midterm+endofterm)/4;
     printf("the average is %2lf\n=====================",average);



     printf("\nchemistry detail\n");
    printf("enter marks for ass; ");
    scanf("%d",&ass);
    printf("enter marks for coursework; ");
    scanf("%d",&coursework);
    printf("enter marks for midterm; ");
    scanf("%d",&midterm);
    printf("enter marks for endterm; ");
    scanf("%d",&endofterm);

     average = (ass+coursework+midterm+endofterm)/4;
     printf("the average is %2lf\n=============",average);

      printf("\nmathematics detail\n");
    printf("enter marks for ass; ");
    scanf("%d",&ass);
    printf("enter marks for coursework; ");
    scanf("%d",&coursework);
    printf("enter marks for midterm; ");
    scanf("%d",&midterm);
    printf("enter marks for endterm; ");
    scanf("%d",&endofterm);

     average = (ass+coursework+midterm+endofterm)/4;
     printf("the average is %2lf\n=============",average);
}
*/
