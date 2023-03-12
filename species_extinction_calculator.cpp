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

using namespace std;

int new_or_extinct(int n_of_species)
/* with a 0.5 chance each, add or subtract a species from the initial number of species */
{
	int num;  // initialise num, which is going to be the mod of rand/2, so 0 if rand is even and 1 if rand is odd;
    rand();
	num = rand() % 2;  // now num can be 0 or 1

	if (num)  // if it's 1
    {
	    n_of_species++;  // increase the num of species in the genus
		//cout << "New Species" << endl;
    }
	else
	{
	    n_of_species--;  // decrease the num of species in the genus (one goes extinct)
		//cout << "Species goes extinct" << endl;
	}
	return n_of_species;
}

int main()
{
    srand(static_cast<size_t>(time(nullptr)));    // truly random

    int n_of_events = 100;  // how many times I 'flip the coin' of extinction
    int repetitions = 1e8;  // repeat many times to avoid variability
    int n_of_species;
    // int sims = 0;
    ofstream extfile("species_survived_extinct.csv"); // file
    for (int species_in_genus = 2; species_in_genus<32; species_in_genus+=2)  // repeat for different n of species in genus
    {
        int tot_extinct = 0;
        int tot_survived = 0;
        //cout<<"\n Species in Genus = "<<species_in_genus<<endl;
        int r=0;
        while (r<repetitions)
        {
            n_of_species = species_in_genus;
            int times, tstep = 0;
            while (tstep < n_of_events)
            {
                // sims++;  // counter for simulations
                n_of_species = new_or_extinct(n_of_species);
                //cout<<n_of_species<<" ";
                tstep++;
                if (n_of_species < 1)  // when all the species are extinct
                {
                    //cout<<". All species extinct, t = "<<tstep<<endl;
                    tot_extinct++;
                    break;
                }
            }
            if (n_of_species>0)
            {
                //cout<<"genus survived!"<<endl;
                tot_survived++;
            }
        r++;  // increase counter for repetitions
        }
        // End of repetitions for this genus.
        // Before moving on to the next one, give me some stats:
        cout<<"Of the genus with "<< species_in_genus << " species, "<< tot_survived << " survived, "<< tot_extinct << " went extinct."<<endl;
        extfile << species_in_genus << " " << (double)tot_survived/(double)repetitions << " " << (double)tot_extinct/(double)repetitions << endl;  // probability of surviving
    }

}