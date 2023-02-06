#include <stdio.h>
#include <math.h>

int main()
{
    printf("\t(3/2)^n\tn^3\tn\tln(n)\t2^n\t2^(lg(n))\te^n\tlg(lg(n))\tln(ln(n))\t(lg(n))^2");
    for(double i=0;i<100;i++){
        printf("\n%.2f\t",i);
        printf("%.2f",pow((3.0/2.0),i));
        printf("\t%.2f",pow(i,3));
        printf("\t%.2f",i);
        printf("\t%.2f",log(i));
        printf("\t%.2f",pow(2,i));
        printf("\t%.2f",pow(2,(log2(i))));
        printf("\t%.2f",pow(2.713,i));
        printf("\t%.2f",log2(log2(i)));
        printf("\t%.2f",log(log(i)));
        printf("\t%.2f",pow((log2(i)),2));
        // printf("\n");
        
    }

    return 0;
}