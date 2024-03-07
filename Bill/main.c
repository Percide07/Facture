#include <stdio.h>
#include <stdlib.h>

struct Article {
    char name[50];
    float price;
};

struct Invoice {
    char customerName[50];
    struct Article articles[3];
    float totalHT;
    float VATRate;
    float VATAmount;
    float totalTTC;
    char paymentMethod[20];
};


float calculateTotalHT(struct Article articles[]) {
    float totalHT = 0;
    for (int i = 0; i < 3; i++) {
        totalHT += articles[i].price;
    }
    return totalHT;
}

float calculateVATAmount(float totalHT, float VATRate) {
    return totalHT * (VATRate / 100);
}


float calculateTotalTTC(float totalHT, float VATAmount) {
    return totalHT + VATAmount;
}

int main() {

    struct Invoice invoice;
    printf("Customer name: ");
    scanf("%s", invoice.customerName);

    for (int i = 0; i < 3; i++) {
        printf("Name of article %d: ", i + 1);
        scanf("%s", invoice.articles[i].name);
        printf("Price of article %d: ", i + 1);
        scanf("%f", &invoice.articles[i].price);
    }

    invoice.totalHT = calculateTotalHT(invoice.articles);

    printf("VAT rate: ");
    scanf("%f", &invoice.VATRate);

    invoice.VATAmount = calculateVATAmount(invoice.totalHT, invoice.VATRate);

    invoice.totalTTC = calculateTotalTTC(invoice.totalHT, invoice.VATAmount);

    printf("Payment method: ");
    scanf("%s", invoice.paymentMethod);


    printf("\n--- Invoice ---\n");
    printf("Customer name: %s\n", invoice.customerName);
    printf("Articles: \n");
    for (int i = 0; i < 3; i++) {
        printf("    %s : %.2f\n", invoice.articles[i].name, invoice.articles[i].price);
    }
    printf("Total HT: %.2f\n", invoice.totalHT);
    printf("VAT rate: %.2f%%\n", invoice.VATRate);
    printf("VAT amount: %.2f\n", invoice.VATAmount);
    printf("Total TTC: %.2f\n", invoice.totalTTC);
    printf("Payment method: %s\n", invoice.paymentMethod);

    return 0;
}

