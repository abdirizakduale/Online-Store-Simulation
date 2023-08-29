#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <deque>
#include <fstream>
#include <cstring>
#include <set>
using std::set;
using std::shared_ptr;
using std::unique_ptr;
using std::string;
using std::deque;


class electronics {
public:
    electronics(); //electronics default constructor
    electronics(int, string, float); //electrnoics constructor
    bool operator<(const electronics &); //electronics < operator overload
    electronics & operator=(const electronics &); //electrnoics = operator overload
    virtual ~electronics(); //Virtual destructor
    virtual void display() = 0; // Display product information pure virutal function
    virtual void buy(shared_ptr<electronics>, deque<shared_ptr<electronics>> &) = 0; // Buy the product pure virtual function
    virtual void recommend(shared_ptr<electronics>) = 0; // Recommend similar products
    virtual void return_product(shared_ptr<electronics>, deque<shared_ptr<electronics>> &) = 0; // Return a product pure virtual function
    string get_name(); //Get name function
    int get_id(); //Get ID function
    int get_price(); //Get price function

protected:
    int id;
    string name;
    string spec;
    float price;
};

class camera : public electronics {
public:
    camera(int, string, float);
    void buy(shared_ptr<electronics>, deque<shared_ptr<electronics>> &); // Buy a camera
    void recommend(shared_ptr<electronics>); // Recommend cameras with a discount!
    void return_product(shared_ptr<electronics>, deque<shared_ptr<electronics>> &); // Return a camera
    void add_insurance(shared_ptr<electronics>); // Add insurance to a camera
    void display(); // Display camera information
};

class laptop: public electronics {
public:
    laptop(int, string, float);
    void buy(shared_ptr<electronics>, deque<shared_ptr<electronics>> &); // Buy a laptop
    void recommend(shared_ptr<electronics>); // Recommend laptops with a discount!
    void return_product(shared_ptr<electronics>, deque<shared_ptr<electronics>> &); // Return a laptop
    void display(); // Display laptop information
};

class watches: public electronics {
public:
    watches(int, string, float);
    void buy(shared_ptr<electronics>, deque<shared_ptr<electronics>> &); // Buy a watch
    void recommend(shared_ptr<electronics>); // Recommend watches with a discount!
    void return_product(shared_ptr<electronics>, deque<shared_ptr<electronics>> &); // Return a watch
    void display(); // Display watch information
};