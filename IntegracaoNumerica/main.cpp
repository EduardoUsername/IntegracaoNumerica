#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

double fx(double x){
    return x * x;
}

vector<int> preanderson(int n){
    vector<int> coeficientes;
    for(int i = n; i >= 0; i--){
        int a;
        scanf("%d", &a);
        coeficientes.push_back(a);
    }
    return coeficientes;
}

double funcaoanderson(double x, vector<int> cci){
    double soma = 0;
    for(int i = cci.size() - 1; i >= 0; i--){
        soma += cci[i] * (pow(x, i));
    }
    return soma;
}


int main(){
    double x0, x1;
    int n;
    int k;
    printf("DIGITE UM EXPOENTE POR FAVOR AMIGUINHO: \n");
    scanf("%d", &k);
    vector<int> cc = preanderson(k);
    double area = 0;
    double areaintegral;
    double deltax;
    printf("Defina o x inicial\n");
    scanf("%lf", &x0);
    printf("Defina o x final\n");
    scanf("%lf",&x1);
    if(x1 <= x0){
        printf("nananinanao");
        return 1;
    }
    printf("Defina o n\n");
    scanf("%d",&n);
    deltax = (x1 - x0)/n;
    for(int i = 0; i <n; i++){
        double yi;
        double xi;
        double areai;
        xi = x0 + deltax * i;
        yi = funcaoanderson(xi, cc);
        areai = yi * deltax;
        area += areai;
    }
    
    areaintegral = (pow(x1,3) - pow(x0,3))/3;
    printf("Area Calculada = %.4lf numero partições = %d\n", area, n);
    printf("Area calculada = %.4lf\n", areaintegral);
    
    
    return 0;
}