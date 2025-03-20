/*
Hello There 
This code is developed to respond to the DSA assignments request by Mr.Dallington.
Hope you have fun contributing to this code.

Happy Hunting.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=3,x=2;
    char* dom[n][50 ];
    char* wild[x][50];
    char* merged[n+x];
    for(int i=0;i<n;i++){
        printf("Enter domestic animal: ");
        scanf("%s",&dom[i]);
        merged[i]=dom[i];
    }
    printf("\n");
    for(int i=0;i<x;i++){
        printf("Enter wild animal: ");
        scanf("%s",&wild[i]);
        merged[n+i]=wild[i];
    }
    printf("\n  Merged array; ");
    for(int i=0;i<n+x;i++){
        printf("%s ",merged[i]);
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



     printf("===\nchemistry detail\n");
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
