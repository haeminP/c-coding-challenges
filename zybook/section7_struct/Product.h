#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct Product_struct
{
    char productCode[20];
    double productPrice;
    int productCount;
} Product;

Product InitProduct(char* code, double price, int count);
Product SetCode(char *code, Product product);
void GetCode(char* productCode, Product product);
Product SetPrice(double price, Product product);
double GetPrice(Product product);
Product SetCount(int count, Product product);
int GetCount(Product product);
Product AddInventory(int amt, Product product);
Product SellInventory(int amt, Product product);


#endif