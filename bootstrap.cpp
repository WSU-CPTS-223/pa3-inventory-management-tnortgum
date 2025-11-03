#include <iostream>
#include "bootstrap.h"

using namespace std;

// Define global tables
HashTable<string, Product> inventoryById;
HashTable<string, MyVector<Product>> inventoryByCategory;

void loadSampleData()
{
    Product p1("A100", "Echo Dot", "Electronics", 49.99);
    Product p2("A101", "Fire Stick", "Electronics", 39.99);
    Product p3("B200", "Kindle Paperwhite", "Books", 129.99);
    Product p4("C300", "Amazon Basics Mouse", "Accessories", 14.99);

    inventoryById.insert(p1.uniqId, p1);
    inventoryById.insert(p2.uniqId, p2);
    inventoryById.insert(p3.uniqId, p3);
    inventoryById.insert(p4.uniqId, p4);

    MyVector<Product> eList;
    eList.push_back(p1);
    eList.push_back(p2);
    inventoryByCategory.insert("Electronics", eList);

    MyVector<Product> bList;
    bList.push_back(p3);
    inventoryByCategory.insert("Books", bList);

    MyVector<Product> aList;
    aList.push_back(p4);
    inventoryByCategory.insert("Accessories", aList);
}
