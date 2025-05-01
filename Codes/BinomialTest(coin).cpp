#include <iostream>
#include <cmath>

using namespace std;

//Function to calculate the factorial
long factorial(int n){
    long long result = 1;
    for(int i=1; i<=n; i++){
        result *= i;
    }
    return result;
}

// double factorial(int n){
//     return tgamma(n+1);
// }

//Function to compute the nCr
double nCr(int n, int r){
    if (n<r) return 0;
    return (factorial(n)/(factorial(r)*factorial(n-r)));
}

//Function to caluculate Binomial Probability
int BinomialProbabiltyOfHead(int NumberToss, float headProb){
    cout<<"Head          Probability\n";
    for(int i=0; i<=NumberToss; i++){
        double result = nCr(NumberToss, i) * pow(headProb, i) * pow(1-headProb, NumberToss-i);
        cout<<i<<"           "<<result<<"\n";
    }
    return 0;
}

int main(){
    int n;
    double q;
    cout<<"Enter the number of Toss: ";
    cin>>n;
    cout<<"Enter the probablity of head(q)[0<=q<=1]: ";
    cin>>q;
    BinomialProbabiltyOfHead(n, q);
    
}
