/*
   Abdirizak Duale
   CS-302
   08-16-2022
   Main function implemented client interaction happens mainly through here
*/
#include "electronics.h"
#include "node.h"
using namespace std;


//main function that handles the while loop that the client sees when they're choosing their options
int main(){
    
    BST object;
    BST object2;

    bool test = true;
    bool flag = false;
    deque<shared_ptr<electronics>> shopping_cart;
    set<string> history;
    //string history[100]; 

	while(test){
		
        char choice;

        cout << setw(100) << setfill('-') << "" << endl;
		cout << "1. Load the inventory" << endl;
		cout << "2. Display the inventory" << endl;
		cout << "3. Remove a product from the inventory" << endl;
        cout << setw(100) << setfill('-') << "" << endl;
        cout << "Dynamic Binding options (Purchase a camera for RTTI). Tree options above." << endl;
        cout << setw(100) << setfill('-') << "" << endl;
        cout << "4. Purchase a product" << endl;
        cout << "5. Display shopping cart" << endl;
        cout << "6. Recommend a product" << endl;
        cout << "7. Remove product from Shopping Cart" << endl;
        cout << setw(100) << setfill('-') << "" << endl;
        cout << "8. Quit" << endl;
        cout << setw(100) << setfill('-') << "" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		cin.ignore(100, '\n');


		if(choice == '1'){
            
            flag = true;
            
            cout << setw(100) << setfill('-') << "" << endl;
            cout << "Loading the inventory" << endl;
            
            object.load();
            object2 = object;
        }
        else if(choice == '2'){
            
            char test;

            if(!flag){
                cout << setw(100) << setfill('-') << "" << endl;
                cout << "Please load the inventory first!" << endl;
            }
            else{
                cout << "Do you want to display for tree number 1, or tree number 2: ";
                cin >> test;
                if(test == '1'){
                    cout << setw(100) << setfill('-') << "" << endl;
                    cout << "Displaying the inventory for tree number 1" << endl;
                    object.display();
                }
                if(test == '2'){
                    cout << setw(100) << setfill('-') << "" << endl;
                    cout << "Displaying the inventory for tree number 2" << endl;
                    object2.display();
                }
                else{
                    cout << setw(100) << setfill('-') << "" << endl;
                    cout << "Please enter either 1, or 2" << endl;
                }
            }
        }
        else if(choice == '3'){
            
            if(!flag){
                cout << setw(100) << setfill('-') << "" << endl;
                cout << "Please load the inventory first!" << endl;
            }
            else{
                
                string remove;
                cout << setw(100) << setfill('-') << "" << endl;
                cout << "What is the name of the product you want to remove: ";
                getline(cin, remove);
                
                history.insert(remove);

                object.remove(remove);
            }

        }
        else if(choice == '4'){
            if(!flag){
                cout << setw(100) << setfill('-') << "" << endl;
                cout << "Please load the inventory first!" << endl;
            }
            else{
                string buy;
                
                cout << setw(100) << setfill('-') << "" << endl;
                cout << "What is the product that you would like to buy: ";
                getline(cin, buy);
                
                if(history.count(buy)){
                    cout << setw(100) << setfill('-') << "" << endl;
                    throw std::runtime_error("Can't buy something that was removed from inventory");
                    //cout << "Can't buy something that was removed from inventory" << endl;
                }
                else{
                    object.find_product(buy, shopping_cart, 1);
                }
                
            }
            
        }
        else if(choice == '5'){
            if(shopping_cart.empty()){
                cout << setw(100) << setfill('-') << "" << endl;
                cout << "Your shopping cart is empty" << endl;
            }
            else{
                int i = 1;
                cout << setw(100) << setfill('-') << "" << endl;
                cout << "Your shopping cart has: " << endl;
                cout << setw(100) << setfill('-') << "" << endl;
                for(auto & shopping_cart : shopping_cart){
                    cout << i << ". " << shopping_cart->get_name() << endl;
                    i++;
                }
            }
        }
        else if(choice == '6'){
            
            string find;

            if(!flag){
                cout << setw(100) << setfill('-') << "" << endl;
                cout << "Please load the inventory first!" << endl;
            }
            else{
                
                cout << setw(100) << setfill('-') << "" << endl;
                cout << "What product are you interested in: ";
                getline(cin, find);
                
                object.find_product(find, shopping_cart, 2);
            }
        }
        
        else if(choice == '7'){
            
            string find;

            if(!flag){
                cout << setw(100) << setfill('-') << "" << endl;
                cout << "Please load the inventory first!" << endl;
            }
            else if(shopping_cart.empty()){
                cout << setw(100) << setfill('-') << "" << endl;
                cout << "Your shopping cart is empty" << endl;
            }
            else{
                
                cout << setw(100) << setfill('-') << "" << endl;
                cout << "What product do you want to remove: ";
                getline(cin, find);
                
                object.find_product(find, shopping_cart, 3);
            }
        }

        else if(choice == '8'){
            test = false;
        }
        else{
            cout << setw(100) << setfill('-') << "" << endl;
            cout << "Enter: 1, 2, or 3 as your next option" << endl;
        }
    }

    
    return 0;
}