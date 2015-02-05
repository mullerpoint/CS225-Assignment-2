//
// Media Item Class Implementation
//

#include <iostream>
#include <string>
#include "mediaItems.h"


//Constructor - set name/author blank, pages/price to 0, and inprint/pubyear to default = true
mediaItems::mediaItems()
{
	mediaItems::setName("");
	mediaItems::setAuthor("");
	mediaItems::setPages(0);

	mediaItems::setInPrint(false);
	in_print_def = true;

	mediaItems::setPrice(0.00);	

	mediaItems::setPubYear(1970);
	pub_year_def = true;

	mediaItems::modified(false);
}


// display all elements
void mediaItems::toCout()
{
	//if the hasData flag is not set the item is empty
	if (hasData == false)
	{
		std::cout << "This item is empty" << std::endl;
	}
	// if the has data flag is set the item has some data in it
	else if (hasData == true)
	{
		// display item name if present
		if (name == "");
		else if (name != "")
		{
			std::cout << "  Media Item : " << name << std::endl;
		}

		//display author name if present
		if (author == "");
		else if (author != "")
		{
			std::cout << "      Author : " << author << std::endl;
		}
		
		//display page count if present
		if (pages == 0);
		else if (pages != 0)
		{
			std::cout << "       Pages : " << pages << std::endl;
		}
		
		//display price if set
		if (price == 0.00);
		else if (price != 0.00)
		{
			std::cout << "       Price : $" << std::fixed << price << std::endl;
		}

		//display if the item is in print; check for default then prints the value
		if (in_print_def == true);
		else if (in_print_def == false)
		{
			if (in_print == true)
			{
				std::cout << "Print Status : " << "True" << std::endl;
			}
			else if (in_print == false)
			{
				std::cout << "Print Status : " << "False" << std::endl;
			}
		}

		//display publication year if set; check if the value is default
		if (pub_year_def == true);
		else if (pub_year_def == false)
		{
			std::cout << "    Pub Year : " << pub_year << std::endl;
		}
		
		std::cout << std::endl;
		
		//std::cout << "has data test: " << hasData << std::endl;
	}
}


//set title of book
void mediaItems::setName(std::string new_name)
{
	mediaItems::name = new_name;
	mediaItems::modified(true);
}

//set book author
void mediaItems::setAuthor(std::string new_author)
{
	mediaItems::author = new_author;
	mediaItems::modified(true);
}

//set book page count - validate that the book doesnt have a negative page count
void mediaItems::setPages(int new_pages)
{
	if (new_pages >= 0)
	{
		mediaItems::pages = new_pages;
		mediaItems::modified(true);
	}
	else
	{
		std::cout << "Please enter a valid positive page number.";
	}
	
}

//set book in print status
void mediaItems::setInPrint(bool printStatus)
{
	in_print = printStatus;
	in_print_def = false;
	mediaItems::modified(true);
}

//set the book price - validate that the price is not negative
void mediaItems::setPrice(double new_price)
{
	if (new_price >= 0)
	{
		mediaItems::price = new_price;
		mediaItems::modified(true);
	}
	else
	{
		std::cout << "Please enter a valid positive price.";
	}
	
}

// set the publication year - validates that the book was not published in a negative year
void mediaItems::setPubYear(int new_year)
{
	if (new_year >= 0)
	{
		mediaItems::pub_year = new_year;
		mediaItems::pub_year_def = false;
		mediaItems::modified(true);
	}
	else
	{
		std::cout << "Please enter a valid Year.";
	}
	
}

// set a modified flag
void mediaItems::modified(bool data)
{
	mediaItems::hasData = data;
}
