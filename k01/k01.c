#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int N);
extern double var_online(double val,double ave,double square_ave,int N);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    int N=0;
    double ave=0;
    double var, square_ave, varM;
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        sscanf(buf,"%lf",&val);

        N++;
        var=var_online(val,ave,square_ave,N);
        ave=ave_online(val,ave,N);
        square_ave=ave_online(pow(val,2),square_ave,N);
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    varM=N*var/(N-1);
    printf("ave=%f\n",ave);
    printf("var=%f\n",var);
    printf("est ave=%f\n",ave);
    printf("est var=%f\n",varM);

    return 0;

}

double ave_online(double val,double ave,int N)
{
    return(((N-1)*ave/N)+(val/N));
}
double var_online(double val,double ave,double square_ave,int N)
{
    return(((N-1)*square_ave/N)+pow(val,2)/N)-pow((((N-1)*ave/N)+(val/N)),2);
}

