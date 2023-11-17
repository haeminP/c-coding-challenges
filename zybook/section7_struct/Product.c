#include <stdio.h>
#include <string.h>

#include "Product.h"

Product InitProduct(char* code, double price, int count){

    Product newProduct;
    strcpy(newProduct.productCode, code);
    newProduct.productPrice = price;
    newProduct.productCount = count;

    return newProduct;
}

Product SetCode(char *code, Product product){
    strcpy(product.productCode, code);
    return product;
}

void GetCode(char* productCode, Product product){
    strcpy(productCode, product.productCode);
}

Product SetPrice(double price, Product product){
    product.productPrice = price;
    return product;
}

double GetPrice(Product product){
    return product.productPrice;
}

Product SetCount(int count, Product product){
    product.productCount = count;
    return product;
}

int GetCount(Product product){
    return product.productCount;
}

Product AddInventory(int amt, Product product){
    product.productCount += amt;
    return product;
}

Product SellInventory(int amt, Product product){
    product.productCount -= amt;
    return product;
}

