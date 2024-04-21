//
//  main.c
//  Knapsack-Problem
//
//  Created by Md Moinuddin Quazi on 4/21/24.
//

#include <stdio.h>


void main()
{
    int n , m , w[100], p[100], ratio[100], i, j, u , temp;
    float xr, x[100], total_profit = 0 , total_weight = 0;
    printf("Enter the Number of Items(n):");
    scanf("%d",&n);
    printf("Enter the capacity of Knapsack(m):");
    scanf("%d",&m);
    u = m;
    for(i=0;i<n;i++)
    {
        x[i]=0;
    }
    printf("Enter the weights of items:");
    for (i=0; i<n; i++)
    {
        printf("\n\tWeight of item %d = ",i+1);
        scanf("%d",&w[i]);
    }
    printf("\nEnter the profit Values of items : ");
    for (i=0; i<n; i++)
    {
        printf("\n\tProfit of item %d = ",i+1);
        scanf("%d",&p[i]);
    }
    for(i=0;i<n;i++)
    {
        ratio[i]=p[i]/w[i];
    }
    for (i=0; i<n; i++) 
    {
        for(j=0;j<n-1;j++)
        {
            if(ratio[j]<ratio[i])
            {
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;
                
                temp=w[i];
                w[i]=w[j];
                w[j]=temp;
                
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    printf("\n The Table after Sorting based on Ratio: \n");
    printf("\nItem:\t\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",i+1);
    }
    printf("\nProfit:\t\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",p[i]);
    }
    printf("\nWeights:\t");
    {
        printf("%d\t",w[i]);
    }
    printf("\nRATIO:\t\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",ratio[i]);
    }
    for(i=0;i<n;i++)
    {
        if(w[i]<=u)
        {
            x[i]=1;
            u=u-w[i];
        }
        else if (w[i]>u)
        {
            break;
        }
    }
    if(i<=n)
    {
        xr = (float)u/w[i];
        x[i]=xr;
    }
    printf("\n X = [");
    for(i=0;i<n;i++)
    {
        printf("%.3f , ",x[i]);
    }
    printf("]");
    for(i=0;i<n;i++)
    {
        total_profit += x[i]*p[i];
        total_weight += x[i]*w[i];
    }
    printf("\nTotal Profit = %.2f \n Total Weight = %.2f",total_profit,total_weight);
}
