#include <stdio.h>

typedef struct
{
    float real;
    float imag;
} Complex;

Complex addComplex(Complex c1, Complex c2)
{
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;

    return result;
}

Complex multiplyComplex(Complex c1, Complex c2)
{
    Complex result;

    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;

    return result;
}

void printComplex(Complex c)
{
    if(c.imag < 0) printf("%.2f - %.2fi", c.real, c.imag);

    else printf("%.2f + %.2fi", c.real, c.imag);
}

int main()
{
    Complex c1, c2, sum, product;

    printf("Enter real and imaginary parts of the first complex number:\n");
    scanf("%f %f", &c1.real, &c1.imag);
    
    printf("Enter real and imaginary parts of the second complex number:\n");
    scanf("%f %f", &c2.real, &c2.imag);

    sum = addComplex(c1, c2);

    product = multiplyComplex(c1, c2);

    printf("Sum of the complex numbers: ");
    printComplex(sum);
    printf("\nProduct of the complex numbers: ");
    printComplex(product);
    printf("\n");

    return 0;
}