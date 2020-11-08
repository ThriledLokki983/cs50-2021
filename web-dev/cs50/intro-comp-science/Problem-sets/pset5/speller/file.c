#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE *file;
	char *word;

	// open the file form a location
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("Could not read file");
	}
	else 
	{
		fscanf(file "%s", word);

		fprintf("%s\n", word);

		fclose(file);
	}
}