//Program for array traversal in spiral order

/*
i = start index of row of matrix
j = start index of column of matrix
m = end index of row of matrix
n = end index of column of matrix
x = loop traversal 
*/

#include<stdio.h>
#include<stdlib.h>

void traversal(int n, int a[][n]){
    int i=0, j=0, x, m=n;
    while(i<m && j<n){
        //printing first row of the matrix
        for(x=j; x<n; ++x)
            printf("%d ",a[i][x]);
        i++;

        //printing last column of the matrix
        for(x=i; x<m; ++x)
            printf("%d ",a[x][n-1]);
        n--;

        //printing last row of the matrix
        if(i<m){
            for(x=n-1; x>=j; --x)
                printf("%d ",a[m-1][x]);
            m--;
        }
        
        //printing first column of matrix
        if(j<n){
            for(x=m-1; x>=i; --x)
                printf("%d ",a[x][j]);
            j++;
        }
        
    }
}

int main(){
    int order,n,temp,x;
    printf("Enter the order of matrix:\n");
    while(1){
        scanf("%d",&n);
        if (n > 0){
            while(getchar()!='\n');
            break;
        }
        else{
            while(getchar()!='\n');
            printf("Invalid order! Enter again\n");
        }
    }
    order = n;
    int a[order][order];
    printf("Enter array values:\n");
    for(int i=0; i<order; i++){
        for(int j=0; j<order; j++){
            x = scanf("%d",&temp);
            //printf("true = %d\n",x);
            if(x)
                a[i][j] = temp;
            else{
                printf("Invalid input! Try again\n");
                --j;
            }
            //clear buffer after scanf read.
            while(getchar()!='\n');
        }
    }
    printf("Spiral array traversal is:\n");
    traversal(n, a);
    return 0;
}
