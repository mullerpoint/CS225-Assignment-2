//
//Media Item Class declaration
//

class mediaItems
{
private:
	std::string name;
	std::string author;
	int pages;

	bool in_print;
	bool in_print_def;

	double price;

	int pub_year;
	bool pub_year_def;

	bool hasData;

public:
	void setName(std::string);
	void setAuthor(std::string);
	void setPages(int);
	void setInPrint(bool);
	void setPrice(double);
	void setPubYear(int);
	void toCout();
	void modified(bool);
	mediaItems();
};

