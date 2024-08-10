#include <stdio.h>

struct Complex
{
    float real;
    float imag;
};

struct Complex addComplex(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

void multiplyComplex(struct Complex *result, struct Complex *c1, struct Complex *c2)
{
    result->real = c1->real * c2->real - c1->imag * c2->imag;
    result->imag = c1->real * c2->imag + c1->imag * c2->real;
}

int main()
{
    struct Complex c1, c2, result;
    int choice;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add two complex numbers\n");
        printf("2. Multiply two complex numbers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("Enter the first complex number (real and imaginary): ");
        scanf("%f %f", &c1.real, &c1.imag);
        printf("Enter the second complex number (real and imaginary): ");
        scanf("%f %f", &c2.real, &c2.imag);

        switch (choice)
        {
        case 1:
            result = addComplex(c1, c2);
            printf("\nSum: %.2f + %.2fi\n", result.real, result.imag);
            break;
        case 2:
            multiplyComplex(&result, &c1, &c2);
            printf("\nProduct: %.2f + %.2fi\n", result.real, result.imag);
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
