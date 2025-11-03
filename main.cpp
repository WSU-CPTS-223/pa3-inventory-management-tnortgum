#include <iostream>
#include <string>
#include <sstream>

#include "bootstrap.h"
using namespace std;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        string cmd, id;
        stringstream ss(line);
        ss >> cmd >> id;

        Product result;
        if (inventoryById.find(id, result))
        {
            cout << "Product found:\n";
            cout << " ID: " << result.uniqId << "\n";
            cout << " Name: " << result.productName << "\n";
            cout << " Category: " << result.category << "\n";
            cout << " Price: $" << result.price << "\n";
        }
        else
        {
            cout << "Inventory/Product not found\n";
        }
        return;
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        string cmd, category;
        stringstream ss(line);
        ss >> cmd >> category;

        MyVector<Product> list;
        if (inventoryByCategory.find(category, list))
        {
            cout << "Products in category '" << category << "':\n";
            for (size_t i = 0; i < list.size(); i++)
            {
                cout << "  [" << list[i].uniqId << "] " << list[i].productName << "\n";
            }
        }
        else
        {
            cout << "Invalid Category\n";
        }
        return;
    }
}

void bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    loadSampleData();
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
}

int main(int argc, char const *argv[])
{
    string line;
    bootStrap();
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
