# Online Store Simulation

This program is a Product Management System that allows users to interact with an inventory of products, make purchases, and manage their shopping cart. It utilizes a Binary Search Tree (BST) data structure for efficient storage and retrieval of products.
Getting Started

To run the program, follow these steps:

1. Clone the GitHub repository:
```
git clone abdirizakduale/Online-Store-Simulation
```

2. Open a terminal or command prompt and navigate to the cloned repository's directory:
```
cd Online-Store-Simulation
```
3. Use the provided makefile to compile the source code:
```
make
```
4. Run the compiled executable:
```
./product_management
```
## Usage

Upon running the program, you will be presented with a menu that offers various options for managing products, purchasing, and interacting with the shopping cart. These options include:

1. Load the inventory: Load product information from a | separated file into the inventory.
2. Display the inventory: Display the list of available products in the inventory.
3. Remove a product from the inventory: Remove a product from the inventory.
4. Purchase a product: Add a product to your shopping cart and calculate its price.
5. Display shopping cart: View the products currently in your shopping cart.
6. Recommend a product: Get recommendations for products similar to the one you're interested in.
7. Remove product from Shopping Cart: Remove a product from your shopping cart.
8. Quit: Exit the program.

## Notes

- Ensure that you load the inventory before performing any other actions that involve products.
- Products removed from the inventory cannot be purchased. The program uses a Binary Search Tree (BST) data structure to manage the inventory efficiently.
