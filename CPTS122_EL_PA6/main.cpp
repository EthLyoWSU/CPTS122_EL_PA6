#include "bstmorse.h"

int main(void)
{
	bst mybst;

	FILE* table;
	FILE* convert;
	fopen_s(&table, "MorseTable.txt", "r");

	mybst.insertFile(table);
	fclose(table);


	mybst.printTree(mybst.getRoot());

	fopen_s(&convert, "Convert.txt", "r");
	mybst.printConvert(convert);
}