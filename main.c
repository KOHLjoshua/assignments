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
    char* dom[n][50];
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


    /*int assignment, coursework, midterm, endofterm;
    double average1, average2, average3;
    double overall_average;
    printf("\tphysics detail\n");
    printf("enter marks for assignment; ");
    scanf("%d",&assignment);
    printf("enter marks for coursework; ");
    scanf("%d",&coursework);
    printf("enter marks for midterm; ");
    scanf("%d",&midterm);
    printf("enter marks for endterm; ");
    scanf("%d",&endofterm);

     average1 = (ass+coursework+midterm+endofterm)/4;
     printf("the average is %2lf\n",average1);



     printf("\t\nchemistry detail\n");
    printf("enter marks for assignment; ");
    scanf("%d",&assignment);
    printf("enter marks for coursework; ");
    scanf("%d",&coursework);
    printf("enter marks for midterm; ");
    scanf("%d",&midterm);
    printf("enter marks for endterm; ");
    scanf("%d",&endofterm);

     average2 = (ass+coursework+midterm+endofterm)/4;
     printf("the average is %2lf\n",average2);

      printf("\t\nmathematics detail\n");
    printf("enter marks for assignment; ");
    scanf("%d",&assignment);
    printf("enter marks for coursework; ");
    scanf("%d",&coursework);
    printf("enter marks for midterm; ");
    scanf("%d",&midterm);
    printf("enter marks for endterm; ");
    scanf("%d",&endofterm);

     average3 = (ass+coursework+midterm+endofterm)/4;
     printf("the average is %2lf\n",average3);

     overall_average = (average1 + average2 + average3)/3;
     printf("\n The overall average for PCM is %2lf",overall_average);

     return 0;
}
*/
