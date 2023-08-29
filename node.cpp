/*
   Abdirizak Duale
   CS-302
   08-16-2022
   node implementation file, all tree involved functions handled here, and some functions that also
   work with dynamic binding also here.
*/
#include "node.h"
using namespace std;

//Default constructor for BST class
BST::BST() : root(nullptr) {}

//Destructor for BST class
BST::~BST() {
    remove_all(root);
}

//Copy constructor that class the copy recursive function
BST::BST(const BST & other) : root(nullptr) {
    if (other.root) {
        copy(root, other.root);
    }
}

//Copy recursive function that copies data onto a new tree
void BST::copy(node *& target, node * source) {
    if (!source) {
        target = nullptr;
        return;
    }

    target = new node;
    target->data = source->data;

    copy(target->left, source->left);
    copy(target->right, source->right);
}

//Assignment operator overload for BST class, also interacts with copy recursive function 
BST & BST::operator=(const BST & other) {
    if (this != &other) {
        remove_all(root); 

        if (other.root) {
            copy(root, other.root);
        }
    }
    return *this;
}

//Load inventory onto BST from electronics.txt 
void BST::load() {

    ifstream file_in;
    string line;

    file_in.open("electronics.txt");
    if (file_in) {
        while (getline(file_in, line)) {  
            int id;
            string name;
            float price;

            stringstream ss(line);  
            string token;

            getline(ss, token, '|');
            id = stoi(token);

            getline(ss, token, '|');
            name = token;

            getline(ss, token, '|');
            price = stof(token);

            if (id >= 1001 && id <= 1010) {
                shared_ptr<electronics> ptr = make_shared<camera>(id, name, price);
                add(ptr);
            }

            if(id >= 2001 && id <= 2010) {
                shared_ptr<electronics> ptr = make_shared<laptop>(id, name, price);
                add(ptr);
            }

            if(id >= 3001 && id <= 3010) {
                shared_ptr<electronics> ptr = make_shared<watches>(id, name, price);
                add(ptr);
            }

        }
        file_in.close();
    }
}

//Remove all recursive function that... removes everything in the BST
void BST::remove_all(node *& root){
    if(!root)
        return;

    remove_all(root->left);
    remove_all(root->right);

    delete root;
    root = nullptr;

}

//Insert wrapper function 
void BST::add(shared_ptr<electronics> data){

    add(root, data);
}

//Insert recursive function
void BST::add(node *& root, shared_ptr<electronics> data){

        if (root == nullptr) {
            root = new node;
            root->data = data;
            root->left = nullptr;
            root->right = nullptr;
            return;
        }

        if (data->get_name() == (root->data->get_name()) || data->get_name() < (root->data->get_name()))  {
            add(root->left, data);
        } else {
            add(root->right, data);
        }
}    


//Display wrapper function
void BST::display(){
    display(root, 1, "Root");
}

//Display recursive function
void BST::display(node * root, int level, const string & side){

    if(!root)
        return;

    display(root->left, level + 1, "Left");
    cout << setw(40) << setfill('-') << "" << endl;
    cout << "Current Level is: " << level << " (" << side << ")" << endl;
    root->data->display();
    display(root->right, level + 1, "Right");
    
}

//Find product wrapper function
void BST::find_product(string find, deque<shared_ptr<electronics>> & shopping_cart, int option){
     
    if(!root){
        return;
    }
    find_product(root, find, shopping_cart, option);
    
}

//Find product recursive function also contains some code necessary for RTTI
void BST::find_product(node *& root, string find, deque<shared_ptr<electronics>> & shopping_cart, int option){

    if(find == root->data->get_name()){
        if(option == 1){
            root->data->buy(root->data, shopping_cart);
        }
        else if(option == 2){
            root->data->recommend(root->data);
        }
        else{
            root->data->return_product(root->data, shopping_cart);
        }
    }

    else if(find == (root->data->get_name()) || find < (root->data->get_name())){
        return find_product(root->left, find, shopping_cart, option);
    }
    else{
        return find_product(root->right, find, shopping_cart, option);
    }
}

//Remove wrapper function
int BST::remove(string find){ 

    if(!root)
        return 0;

    return remove(root, find);
}

//Finding the IOS recursive funtion
int BST::find_smallest(node *& root, shared_ptr<electronics> & data){ 

    if(!root->left){
        data = root->data;
        node * hold_right = root->right;
        delete root;
        root = hold_right;
        return 1;
    }
    return find_smallest(root->left, data);
}

//Remove recursive function
int BST::remove(node *& root, string find){

    if(!root)
        return 0;
 
    if(find == root->data->get_name()){
        if(!root->left && !root->right){
            delete root;
            root = nullptr;
        }

        else if(!root->right){
            node * temp = root->left;
            delete root;
            root = temp;
        }

        else if(!root->left){
            node * temp = root->right;
            delete root;
            root = temp;
        }

        else{
            shared_ptr<electronics> data;
            find_smallest(root->right, data);
            root->data = data;
            //root->data = data;
        }

        return 1;
    }

    else if(find == (root->data->get_name()) || find < (root->data->get_name())){
        return remove(root->left, find);
    }
    else{
        return remove(root->right, find);
    }

    return 0;

}