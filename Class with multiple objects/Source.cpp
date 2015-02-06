//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Gary Muller
// Spring 2015
// CS 225 Assignment 1

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Header files standard libraries and classes
#include <iostream>
#include <string>
#include <locale>
#include "mediaItems.h"

//Gloabal Variables
bool done = false;

mediaItems* Items_ptr;
int* itemNum_ptr;

std::locale* locale;


//Function Prototypes
void process_menu_in(char);
void print_menu();



//Main Function
int main()
{
	//Create an array of 20 media items for filling with data
	//useing the global pointer we can use the item specified with 
	mediaItems Items[20];
	Items_ptr = &Items[0];
	int itemNum = 0;
	itemNum_ptr = &itemNum;

	//use the imbue functionality to make the output look pretty
	std::locale mylocal("");
	locale = &mylocal;
	std::cout.imbue(*locale);

	//core program 
	std::string menu_in;
	print_menu();

	while (!done)
	{
		std::cout << std::endl << "Menu [" << *itemNum_ptr << "]: ";
		std::cin >> menu_in;
		process_menu_in(menu_in[0]);
	}
	std::cout << std::endl << "Goodbye" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Declarations
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Process Menu Function
void process_menu_in(char inchar)
{
	std::cout.imbue(*locale);
	std::cout.precision(2);

	switch (toupper(inchar))
	{

	// Print all objects
	case '*':
	{
		std::cout << std::endl << std::endl << "==== All Items Start ====" << std::endl;
		int count = 0;
		while (count <= 19)
		{
			std::cout << std::endl << "Item [" << count << "]" << std::endl;
			Items_ptr[count].toCout();
			count++;
		}
		std::cout << std::endl << "===== All Items End =====" << std::endl;
	}
	break;

	//increase item number by 1
	case '+':
	{
		if (*itemNum_ptr < 19)
		{
			*itemNum_ptr = *itemNum_ptr + 1;
		}
		else if (*itemNum_ptr >= 19)
		{
			*itemNum_ptr = 19;
		}
		std::cout << std::endl;
	}
	break;

	//decrease item number by 1
	case '-':
	{
		if (*itemNum_ptr > 0)
		{
			*itemNum_ptr = *itemNum_ptr - 1;
		}
		else if (*itemNum_ptr <= 0)
		{
			*itemNum_ptr = 0;
		}
		std::cout << std::endl;
	}
	break;

	// set a custom item number between 0-19
	case '#':
	{
		//declare temp vaiable and read in user value
		int new_itemNum;
		std::cout << "Enter new item number : ";
		std::cin >> new_itemNum;

		//validate input
		if ((new_itemNum >= 0) && (new_itemNum <= 19))
		{
			*itemNum_ptr = new_itemNum;
		}
		else{
			std::cout << "Please enter a valid number beteen 0-19";
		}

		//clear buffer for next input
		std::cin.ignore(10000, '\n');
		std::cout << std::endl;
	}
	break;

	// clear item menu option
	case '0':
	{
		Items_ptr[*itemNum_ptr] = mediaItems();
	}
	break;

	// display item menu option
	case 'D':
		Items_ptr[*itemNum_ptr].toCout();
		break;

	// enter item name menu option
	case 'N':
	{
		std::string new_name;
		std::cout << "Enter Media Item Title : ";
		std::getline(std::cin, new_name);
		Items_ptr[*itemNum_ptr].setName(new_name);
	}
	break;

	// enter item author menu option
	case 'A':
	{
		std::string new_author;
		std::cout << "Enter Media Item Author : ";
		std::getline(std::cin, new_author);
		Items_ptr[*itemNum_ptr].setAuthor(new_author);
	}
	break;

	// enter item page count menu option
	case 'P':
	{
		int new_pages;
		std::cout << "Enter Media Item Pages : ";
		std::cin >> new_pages;
		Items_ptr[*itemNum_ptr].setPages(new_pages);
		std::cin.ignore(10000, '\n');
	}
	break;

	// set the item in print status
	case 'I':
	{
		bool printStatus;
		std::cout << "Is the book still in print (0/1) : ";
		std::cin >> printStatus;
		std::cin.ignore(10000, '\n');
		Items_ptr[*itemNum_ptr].setInPrint(printStatus);
	}
	break;

	// set the item value ($)
	case 'V':
	{
		double new_price;
		std::cout << "Enter Media Item value : ";
		std::cin >> new_price;
		std::cin.ignore(10000, '\n');
		Items_ptr[*itemNum_ptr].setPrice(new_price);
	}
	break;

	// set the item publication year
	case 'Y':
	{
		int new_year;
		std::cout << "Enter Media Item publication year : ";
		std::cin >> new_year;
		std::cin.ignore(10000, '\n');
		Items_ptr[*itemNum_ptr].setPubYear(new_year);
	}
	break;

	// display menu again menu option
	case 'M':
		print_menu();
		break;

	// quit program menu option
	case 'Q':
		done = true;
		break;

	// default option if wrong key entered
	default:
		std::cout << "Please select an option from the menu" << std::endl << "to see the menu again type 'm'";
		break;
	}
}

//Print Menu Function
void print_menu()
{
	std::cout << std::endl
		<< "* - Display all media items data" << std::endl
		<< "+//- increment // decrement the selecte item w/in the Array" << std::endl
		<< "# - set the selected media item" << std::endl
		<< "0 - Clear Media Item Data" << std::endl
		<< "D - Display Media Item Data" << std::endl
		<< "N - Set Media Item Name" << std::endl
		<< "A - Set Media Item Author" << std::endl
		<< "P - Set Media Item Pages" << std::endl
		<< "I - set in print status" << std::endl
		<< "V - set item Value//Price" << std::endl
		<< "Y - set item Publication Year" << std::endl
		<< "M - Print this Menu" << std::endl
		<< "Q - Quit this program" << std::endl << std::endl;
}