/*
   Abdirizak Duale
   CS-302
   08-16-2022
   node.h file where all my soon to implemented node functions are declared
*/
#include "electronics.h"

class node {
    public: 
        //node(shared_ptr<electronics> value) : data(value), left(nullptr), right(nullptr) {}
        shared_ptr<electronics> data;
        node * left;
        node * right;

    private:
};

class BST {
    public: 
        BST();
        ~BST();
        BST(const BST &);
        BST & operator=(const BST &);
        void load();
        void add(shared_ptr<electronics>);
        int remove(string);
        void find_product(string, deque<shared_ptr<electronics>> &, int);
        void display();

    private:
        node * root;
        void copy(node *&, node *);
        void remove_all(node *&);
        void display(node *, int, const string &);
        void add(node *&, shared_ptr<electronics>);
        int remove(node *&, string);
        void find_product(node *&, string, deque<shared_ptr<electronics>> &, int);
        int find_smallest(node *&, shared_ptr<electronics> &);
};