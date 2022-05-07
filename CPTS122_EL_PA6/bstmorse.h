#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class bstnode {
public:
	bstnode();
	bstnode(std::string* morseNew, std::string* charNew);
	~bstnode();

	bstnode* getLeft() const;
	bstnode* getRight() const;
	std::string* getMorse() const;
	std::string* getChara() const;

	void setLeft(bstnode* leftNew);
	void setRight(bstnode* rightNew);
	void setMorse(std::string* morseNew);
	void setChar(std::string* charNew);

	

private:
	bstnode* leftPoint;
	bstnode* rightPoint;
	std::string* morse;
	std::string* character;
}Bstnode;

class bst {
public:

	bst();
	~bst();
	void insertFile(FILE* infile); 
	void insert(std::string* charNew, std::string* morseNew, bstnode* current);

	void printConvert(FILE* infile);
	void printTree(bstnode* current);

	bstnode* getRoot() const;

	std::string* searchCheck(bstnode* current, std::string* input);
private:
	bstnode* root;
}Bst;