/*
   Abdirizak Duale
   CS-302
   08-16-2022
   electronics implementation file where all my functions for my derivd classes, and some getters from my base class
   are implemented. No virtual functions implemented for my base class since I was using pure virtual functions.
*/
#include "electronics.h"
using namespace std;

electronics::electronics() : id(0), name(" "), price(0.0) {}

//< operator overload, I was using this earlier but don't need it anymore
bool electronics::operator<(const electronics & op1){
    return name < op1.name;
}

//= operator overload, I was using this earlier but don't need it anymore
electronics & electronics::operator=(const electronics & other){
    if(this != &other){
        name = other.name;
    }
    return *this;
}

//virtual destructor needed to delete dynamic memory allocated for RTTI
electronics::~electronics() {}

//name getter function
string electronics::get_name(){
    return name;
}

//id getter function
int electronics::get_id(){
    return id;
}

//price getter function
int electronics::get_price(){
    return price;
}

//initialization list for electronics constructor
electronics::electronics(int x, string value, float y) : id(x), name(value), price(y) {}

//initialization list for camera constructor
camera::camera(int x, string value, float y) : electronics(x, value, y) {}

//dynamically binded display function for my camera derived class
void camera::display(){

    cout << "Product ID: " << id << endl;
    cout << "Name is: " << name << endl;
    cout << "Price is: $" << price << endl;
}

//dynamically binded buy/purchase function for my camera derived class
void camera::buy(shared_ptr<electronics> data, deque<shared_ptr<electronics>> & shopping_cart){
    
    string choice;

    cout << setw(100) << setfill('-') << "" << endl;
    cout << "Would you like to add insurance that costs 5% of the orignial price of your camera? please enter yes or no. (RTTI): ";
    cin >> choice;
    if(choice == "yes"){
        cout << setw(100) << setfill('-') << "" << endl;
        cout << data->get_name() << " will be added to your shopping cart with insurance" << endl;
        shopping_cart.push_back(data);
       electronics * name = new camera(*this); 
       camera * insurance = dynamic_cast<camera *>(name);
       insurance->add_insurance(data);
       delete name;
    }
    else if(choice == "no"){
        cout << setw(100) << setfill('-') << "" << endl;
        cout << data->get_name() << " will be added to your shopping cart without insurance" << endl;
        shopping_cart.push_back(data);
    }
    else{
        cout << setw(100) << setfill('-') << "" << endl;
        cout << "Please enter either yes or no!" << endl;
    }

}

//RTTI implementation for my camera derived class;
void camera::add_insurance(shared_ptr<electronics> data){

    float price = data->get_price();
    float post_insurance = price * .05 + price;
    
    cout << setw(100) << setfill('-') << "" << endl;
    cout << "The insurance will be added to your product. Your orginal price was $" << price << "," << endl;
    cout << "your new total with insurance comes out to $" << post_insurance << "." << endl;
}

//dynamically binded recommend function for my camera derived class
void camera::recommend(shared_ptr<electronics> data){
    istringstream iss(data->get_name());
    string company;
    iss >> company;
    
    int price = data->get_price();
    float discount = price - price * 0.15;
    
    cout << setw(100) << setfill('-') << "" << endl;
    cout << "This product is made by " << company << " which is a very rebutable brand" << endl;
    cout << "this product usually goes for $" << price << " but we will give you a 15% discount" << endl;
    cout << "this lowers the price down to $" << discount << "!" << " I can't recommend it enought!" << endl;
    
}

//dynamically binded return function for my camera derived class
void camera::return_product(shared_ptr<electronics> data, deque<shared_ptr<electronics>> & shopping_cart){

    cout << setw(100) << setfill('-') << "" << endl;
    cout << "Removing " << data->get_name() << " from you shopping cart" << endl;
    
    for (auto it = shopping_cart.begin(); it != shopping_cart.end(); ) {
        if (data == *it) {
           it = shopping_cart.erase(it);
        } else {
            ++it;
        }
    }

}

//initialization list for laptop constructor
laptop::laptop(int x, string value, float y) : electronics(x, value, y) {}

//dynamically binded display function for my laptop derived class
void laptop::display(){

    cout << "Product ID: " << id << endl;
    cout << "Name is: " << name << endl;
    cout << "Price is: $" << price << endl;
}

//dynamically binded buy/purchase function for my laptop derived class
void laptop::buy(shared_ptr<electronics> data, deque<shared_ptr<electronics>> & shopping_cart){

    cout << setw(100) << setfill('-') << "" << endl;
    cout << data->get_name() << " will be added to your shopping cart" << endl;
    shopping_cart.push_back(data);
}

//dynamically binded recommend function for my laptop derived class
void laptop::recommend(shared_ptr<electronics> data){
    istringstream iss(data->get_name());
    string company;
    iss >> company;
    
    int price = data->get_price();
    int discount = price - price * 0.15;
    
    cout << setw(100) << setfill('-') << "" << endl;
    cout << "This product is made by " << company << " which is a very rebutable brand" << endl;
    cout << "this product usually goes for $" << price << " but we will give you a 15% discount" << endl;
    cout << "this lowers the price down to $" << discount << "!" << " I can't recommend it enough!" << endl;
}

//dynamically binded return function for my laptop derived class
void laptop::return_product(shared_ptr<electronics> data, deque<shared_ptr<electronics>> & shopping_cart){

    cout << setw(100) << setfill('-') << "" << endl;
    cout << "Removing " << data->get_name() << " from you shopping cart" << endl;

    for (auto it = shopping_cart.begin(); it != shopping_cart.end(); ) {
        if (data == *it) {
            it = shopping_cart.erase(it); 
        } else {
            ++it;
        }
    }
}

//initialization list for watches constructor
watches::watches(int x, string value, float y) : electronics(x, value, y) {}

//dynamically binded display function for my watches derived class
void watches::display(){

    cout << "Product ID: " << id << endl;
    cout << "Name is: " << name << endl;
    cout << "Price is: $" << price << endl;
}

//dynamically binded buy/purchase function for my watches derived class
void watches::buy(shared_ptr<electronics> data, deque<shared_ptr<electronics>> & shopping_cart){

    cout << setw(100) << setfill('-') << "" << endl;
    cout << data->get_name() << " will be added to your shopping cart" << endl;
    shopping_cart.push_back(data);
}

//dynamically binded recommend function for my watches derived class
void watches::recommend(shared_ptr<electronics> data){
    istringstream iss(data->get_name());
    string company;
    iss >> company;
    
    int price = data->get_price();
    int discount = price - price * 0.15;
    
    cout << setw(100) << setfill('-') << "" << endl;
    cout << "This product is made by " << company << " which is a very rebutable brand" << endl;
    cout << "this product usually goes for $" << price << " but we will give you a 15% discount" << endl;
    cout << "this lowers the price down to $" << discount << "!" << " I can't recommend it enought!" << endl;
}

//dynamically binded return function for my watches derived class
void watches::return_product(shared_ptr<electronics> data, deque<shared_ptr<electronics>> & shopping_cart){

    cout << setw(100) << setfill('-') << "" << endl;
    cout << "Removing " << data->get_name() << " from you shopping cart" << endl;

    for (auto it = shopping_cart.begin(); it != shopping_cart.end(); ) {
        if (data == *it) {
            it = shopping_cart.erase(it);
        } else {
            ++it;
        }
    }
}
