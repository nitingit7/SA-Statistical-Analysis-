#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>

#define M_PI_VALUE 3.14159
#define M 10000
#define N 1000

void Generating_Normal_Mean(double mean[], int size){
    for(int i=0;i<M;i++){
        double sum =0;
        for (int j=0;j<N;j++){
            double U1 = (double)rand() / RAND_MAX;
            if(U1==0.0){
                U1 = 1e-10; //Samlle value for log;
            }
            double U2 = (double)rand() / RAND_MAX;
            double z = sqrt(-2*log(U1))*cos(2*M_PI_VALUE*U2);
            sum+=z;
        }
        mean[i] = sum / N;
    }
}
void Plot_Graph_From_Text(double mean[], int size, const char* Filname){

    FILE* file = fopen(Filname, "w");
    if(file == NULL){
        printf("Failed to return the file");
        return;
    }
    for(int i=0;i<size;i++){
        fprintf(file, "%f\n", mean[i]);
    }
    fclose(file);
}

int main(){
    double mean[M];
    
    srand(time(NULL));
    Generating_Normal_Mean(mean,M);
    Plot_Graph_From_Text(mean,M,"DataSavedNormal.txt");
    return 0;
}
