#include <stdio.h>
#include <stdlib.h>

#define NUM_ANIMALS 10


int main()
{
    int n,k;
    char wild_animals[n];
    char domestic_animals[k];
    char result[n+k];

    printf("Enter %d wild animals\n", n);
    if(n>NUM_ANIMALS){
        printf("choose a number less than 10\n");
    }else{

    for(int i= 0; i < n; i++){
        printf("Wild animal %d:\n ", i + 1);
        scanf("%s", wild_animals[i]);
    }
    }
    printf("Enter %d wild animals", k);
    if(k>NUM_ANIMALS){
            printf("Please enter a number less than 10\n");

    }else{
    for(int i= 0; i < k; i++){
        printf("Wild animal %d: ", i + 1);
        scanf("%s", wild_animals[i]);
    }
    }

for(int i = 0;i<n;i++){
    wild_animals[i] = result[i];

}
for(int i = 0;i<k;i++){
    domestic_animals[i] = result[n + i];

}
for(int i = 0; i < k+n; i++){
    printf("The weird animals that want merging are; %s", result[i]);
}


    return 0;
}


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
