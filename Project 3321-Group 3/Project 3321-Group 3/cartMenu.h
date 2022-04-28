#pragma once
#include "products.h"
#include "guestMenu.h"

//Function related to Cart menu
//Functions declaration

//Function to print cart menu-Kris Ly
void printCartMenu();

//Function to print detail menu based on input-Kris Ly
void printDetailCartMenu(int);

//Function to display items in cart-Kris Ly
void viewCartInUSD();

//Function to display items in cart-Kris Ly
void viewCartInCAD();

//Function to display items in cart-Kris Ly
void viewCartInEUR();

//Function to modify items in cart-Kris Ly
void modifyCart();

//Function to update quantity of item in cart-Kris Ly
void updateQuantity();

//Function to delete items in cart-Kris Ly
void deleteItem();

//Function to add items in cart-Kris Ly
void addItem();

//Function to check total price of item in cart in USD-Kris Ly
double checkTotalUSD();

//Function to check total price of item in cart-Kris Ly
double checkTotalCAD();

//Function to check total price of item in cart-Kris Ly
double checkTotalEUR();