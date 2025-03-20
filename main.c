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
}


/*for (int i; i<4; i++){
int math}
printf("Please insert the marks")
int marks[3]={scanf("%d", &math),};
int average= (math+)/3;
printf average(%d, average);
