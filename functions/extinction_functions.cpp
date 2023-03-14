#include <cstdlib>

int new_or_extinct(int n_of_species)
// with a 0.5 chance each, add or subtract a species
{
	int num;  // initialise num, which is going to be even or odd;
    rand();
	num = rand() % 2;

	if (num)
    {
	    n_of_species++;
		//cout << "New Species" << endl;
    }
	else
	{
	    n_of_species--;
		//cout << "Species goes extinct" << endl;
	}
	return n_of_species;
}