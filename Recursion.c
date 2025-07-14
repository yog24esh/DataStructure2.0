#include<stdio.h>

void displayNum1toN(int num);
int displayAndSummation(int num);
int sumOfDigit(int num);
void baseConversion(int decimal, int base);
float exponentiationOfFloat(float base, int exponent);
void primeFactorization(int num);


int main(){

    int num;
    printf("Enter number\n");
    scanf("%d",&num);
    // printdisplayNum1toN(num);
    // printf("\b\b = %d  \n",displayAndSummation(num));
    // printf("%d\n",sumOfDigit(num));    
    // baseConversion(num,2);
    // exponentiationOfFloat(1.01,num);
    primeFactorization(num);
    return 0;
}

void displayNum1toN(int num)
{
    //base case
    if(num==0) return ;
    //winding phase
    displayNum1toN(num-1);
    //unwinding phase
    printf(" %d ",num);
}

int displayAndSummation(int num)
{
    int sum=0;
    if(num==0) return 0;
    sum =  num + displayAndSummation(num-1); 
    printf(" %d +",num);
    return sum;
}

int sumOfDigit(int num)
{
    int sum;
    if(num/10==0) return num;
    sum = num%10 + sumOfDigit(num/10); 
    return sum;
}

void baseConversion(int decimal, int base)
{
    /*
        divide till remainder is zero
        print in reverse order
    */
    int remainder = decimal%base;
    //exit condition
    if(decimal==0) return;
    baseConversion(decimal/base,base);
    if(remainder<10){
        printf("%d",remainder);
    }else{
        printf("%c", remainder -10 +'A');
    }
}

float exponentiationOfFloat(float base, int exponent)
{
    //exit case or recursive base case
    if(exponent==1) return base;
    printf("%f",base * exponentiationOfFloat(base,exponent-1));
    return 0;
}

void primeFactorization(int num)
{
    int prime = 2;
    //base case
    if(num==1) return;
    while(num%prime != 0){
        prime++;
    }
    printf("%d",prime);
    primeFactorization(num/prime);
}
