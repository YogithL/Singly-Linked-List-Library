#ifndef SLIST_H
#define SLIST_H
#include <string>

class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    
};

class node
{
    public:
        Airport data;
        node* link;
};

class LinkedList
{
    public:
        node*head;

        LinkedList();
        ~LinkedList();
        void add(Airport *x);
        void clear();
        bool equals(LinkedList& x);
        node* get(int x);
        void insert(int index, Airport x);
        void exchg(int index1, int index2);
        void swap(int index1, int index2);
        bool isEmpty();
        void remove(int index);
        void set(int index, Airport value);
        int size();
        LinkedList subList( int start, int length);
        std:: string toString();

};

#endif
