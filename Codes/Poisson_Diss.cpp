#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define M 10000
#define N 1000

void GeneratingPoissonMean(double mean[], int size, double lembda){
    for(int i=0;i<size;i++){
        double sum = 0;
        for(int j=0;j<N;j++){
            double L = exp(-lembda);
            double p = 1.0;
            int k = 0;
            do{
                k++;
                p*=(double)rand() / RAND_MAX;
            } while(p>L);
            sum += k -1;
        }
        mean[i] = sum/N;
    }
}  
void Generating_TXT_File(double mean[], int size, const char* Filename){
    FILE* file = fopen(Filename, "w");
    if(file == NULL){
        printf("UNsecussfull to create file");
        return;
    }
    else{
        printf("FIle created Successfully");
    }
    for(int i =0; i<size; i++){
        fprintf(file, "%f\n", mean[i]);
    }
    fclose(file);
}

int main(){
    double means[M];

    srand(time(NULL));
    
    GeneratingPoissonMean(means, M, 10.0);
    Generating_TXT_File(means ,M, "PoissonDataPracrice.txt");
    return 0;
}
