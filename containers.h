#include <string>
#include <cstddef> // size_t
#include <functional> // std::hash
using namespace std;


// Product Struct
struct Product
{
    string uniqId;
    string productName;
    string category;
    double price;

    Product() {}
    Product(string id, string name, string cat, double pr)
        : uniqId(id), productName(name), category(cat), price(pr) {}
};


template <typename T>
class MyVector
{
private:
    T *arr;
    size_t cap;
    size_t len;

    void resize()
    {
        size_t newCap = cap * 2;
        T *newArr = new T[newCap];
        for (size_t i = 0; i < len; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
        cap = newCap;
    }

public:
    MyVector(size_t initCap = 8)
    {
        cap = initCap;
        len = 0;
        arr = new T[cap];
    }

    ~MyVector() { delete[] arr; }

    void push_back(const T &val)
    {
        if (len == cap)
            resize();
        arr[len++] = val;
    }

    size_t size() const { return len; }

    T &operator[](size_t idx) { return arr[idx]; }

    const T &operator[](size_t idx) const { return arr[idx]; }
};



template <typename Key, typename Value>
class HashTable
{
private:
    struct Node
    {
        Key key;
        Value value;
        Node *next;
        Node(const Key &k, const Value &v) : key(k), value(v), next(nullptr) {}
    };

    Node **buckets;
    size_t capacity;
    size_t size;

    size_t hashFunc(const Key &key) const
    {
        return std::hash<Key>{}(key) % capacity;
    }

public:
    HashTable(size_t cap = 101)
    {
        capacity = cap;
        size = 0;
        buckets = new Node *[capacity];
        for (size_t i = 0; i < capacity; i++)
            buckets[i] = nullptr;
    }

    ~HashTable()
    {
        for (size_t i = 0; i < capacity; i++)
        {
            Node *curr = buckets[i];
            while (curr)
            {
                Node *temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] buckets;
    }

    void insert(const Key &key, const Value &value)
    {
        size_t idx = hashFunc(key);
        Node *curr = buckets[idx];
        while (curr)
        {
            if (curr->key == key)
            {
                curr->value = value; // update
                return;
            }
            curr = curr->next;
        }
        Node *newNode = new Node(key, value);
        newNode->next = buckets[idx];
        buckets[idx] = newNode;
        size++;
    }

    bool find(const Key &key, Value &result) const
    {
        size_t idx = hashFunc(key);
        Node *curr = buckets[idx];
        while (curr)
        {
            if (curr->key == key)
            {
                result = curr->value;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};
