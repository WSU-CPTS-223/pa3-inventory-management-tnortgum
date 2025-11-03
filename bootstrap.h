#include "containers.h"

extern HashTable<string, Product> inventoryById;
extern HashTable<string, MyVector<Product>> inventoryByCategory;

void bootStrap();
void loadSampleData();
