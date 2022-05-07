#define _CRT_SECURE_NO_WARNINGS
#include "bstmorse.h"

bstnode::bstnode()
{
	this->leftPoint = nullptr;
	this->rightPoint = nullptr;
	this->character = nullptr;
	this->morse = nullptr;
}

bstnode::bstnode(std::string* morseNew, std::string* charNew)
{
	this->leftPoint = nullptr;
	this->rightPoint = nullptr;
	this->morse = morseNew;
	this->character = charNew;
}

bstnode* bstnode::getLeft() const
{
	return this->leftPoint;
}

bstnode* bstnode::getRight() const
{
	return this->rightPoint;
}

std::string* bstnode::getMorse() const
{
	return this->morse;
}

std::string* bstnode::getChara() const
{
	return this->character;
}

void bstnode::setLeft(bstnode* leftNew)
{
	this->leftPoint = leftNew;
}

void bstnode::setRight(bstnode* rightNew)
{
	this->rightPoint = rightNew;
}

void bstnode::setMorse(std::string* morseNew)
{
	this->morse = morseNew;
}

void bstnode::setChar(std::string* charNew)
{
	this->character = charNew;
}

std::string* bst::searchCheck(bstnode * current, std::string * input)
{
	if (current->getChara()->compare(*input) == 0)
	{
		return current->getMorse();
	}
	else if (current->getChara()->compare(*input) > 0)
	{
		return searchCheck(current->getLeft(), input);
	}
	else
	{
		return searchCheck(current->getRight(), input);
	}
}

void bst::insertFile(FILE* infile)
{
	char* token;
	char line[100];
	std::string temp1, temp2;
	while (fgets(line, 100, infile))
	{
		token = strtok(line, " ");
		temp1 = std::string(token);
		token = strtok(NULL, " ");
		temp2 = std::string(token);
		insert(&temp1, &temp2, this->root);
	}

}

void bst::insert(std::string* charNew, std::string* morseNew, bstnode* current)
{
	bstnode* temp;
	if (current == nullptr)
	{
		this->root = new bstnode(morseNew, charNew);
	}
	else
	{
		if (current->getChara()->compare(*charNew) > 0)
		{
			if (current->getRight() == nullptr)
			{
				temp = new bstnode(morseNew, charNew);
				current->setRight(temp);
			}
			else
			{
				insert(charNew, morseNew, current->getRight());
			}
		}
		else if (current->getChara()->compare(*charNew) < 0)
		{
			if (current->getLeft() == nullptr)
			{
				temp = new bstnode(morseNew, charNew);
				current->setLeft(temp);
			}
			else
			{
				insert(charNew, morseNew, current->getLeft());
			}
		}
	}
}

void bst::printTree(bstnode* current)
{
	printTree(current->getLeft());
	cout << current->getChara() << " " << current->getMorse() << endl;
	printTree(current->getRight());
}

void bst::printConvert(FILE* infile)
{
	char line[100];

	int count;

	std::string temp;

	char space = ' ';


	while (fgets(line, 100, infile))
	{
		for (count = 0; count < 100; ++count)
		{
			if (line[count] == space)
			{
				cout << "   ";
			}
			else
			{
				temp = std::string(&line[count]);
				cout << " " << this->searchCheck(this->root, &temp) << " ";
			}
		}
	}
}

bstnode* bst::getRoot() const
{
	return this->root;
}

bst::bst()
{
	this->root = nullptr;
}

bstnode::~bstnode()
{

}

bst::~bst()
{

}