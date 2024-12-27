#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double array[], int size, double results[]) {
   
    double sum = 0;
    double product = 1;  
    double reciprocalSum = 0; 
    double maxVal = array[0];
    double minVal = array[0];

    for (int i = 0; i < size; i++) {
        sum += array[i];
        product *= array[i];
        reciprocalSum += 1.0 / array[i];

        if (array[i] > maxVal) maxVal = array[i];
        if (array[i] < minVal) minVal = array[i];
    }

    
    double arithmeticMean = sum / size;

    
    double variance = 0;
    for (int i = 0; i < size; i++) {
        variance += pow(array[i] - arithmeticMean, 2);
    }
    double standardDeviation = sqrt(variance / size);

    
    double geometricMean = pow(product, 1.0 / size);

    
    double harmonicMean = size / reciprocalSum;

    
    results[0] = arithmeticMean;
    results[1] = standardDeviation;
    results[2] = geometricMean;
    results[3] = harmonicMean;
    results[4] = maxVal;
    results[5] = minVal;
}