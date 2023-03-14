/*
 Starting from a population of species (one genus), we assume that at every "event" (timestep) 
 either a new species appears or an existing species goes extinct. These two have the same probability, 0.5.

 How many tsteps can a genus survive before all of its species go extinct?

 This is equivalent to the gambler's ruin problem and was inspired 
 by the book "La Malinconia del Mammut" by Massimo Sandal (2019)
*/
#include<iostream>
#include<ctime>
#include<cstdlib>
#include <fstream>
#include <vector>
#include <numeric>
#include <stdio.h>
#include <string>

#include <sstream>


using namespace std;

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

int main()
{
    //srand(static_cast<size_t>(time(nullptr)));  

    int n_of_events = 40;   // at each event, either we lose 1 species or we gain a new one
    int repetitions = 1;    // how many times I run the simulations
    int n_of_species;       // to start with 

    for (int species_in_genus = 2; species_in_genus<5; species_in_genus+=2)  // repeat for different n of species in genus
    {
        std::ostringstream oss;
        oss << "pop"<< setw(3) << setfill('0') << species_in_genus  << ".csv"; // set name, pad with zeros
        std::string species_in_genus_s = oss.str();
        ofstream popfile(species_in_genus_s);  // population file

            n_of_species = species_in_genus;  // the initial value for the number of species is taken from the for loop
            int tstep = 0;
            while (tstep < n_of_events+1)
            {
                n_of_species = new_or_extinct(n_of_species);
                popfile << tstep << " " << n_of_species << endl;
                tstep++;

                if (n_of_species < 1)  // when all the species are extinct
                {
                    break;
                }
            }
    }
}