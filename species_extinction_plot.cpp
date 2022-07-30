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

    int n_of_events = 10;
    int repetitions = 10;
    int n_of_species;
    int sims = 0;
    //ofstream extfile("extinct_or_survived.csv");  // file that will be saved
    // for (int t=1;t<n_of_events+1;t++)
    // {
    //     extfile<<t<<" ";
    // }
    // extfile<<endl;

    for (int species_in_genus = 2; species_in_genus<22; species_in_genus+=2)  // repeat for different n of species in genus
    {

        int a[n_of_events][repetitions+1]; // initialise 2d vector to store data. Columns needed are n of repetitions + 1 for time
        fill(a[0], a[0] + n_of_events * (repetitions), 0);   // fill with zeros (n_of_events * repetitions is the size)

        int tot_extinct = 0; // reset counters for extinct and surviving species
        int tot_survived = 0;
        int wrote_time = 0;
        //cout<<"\n Species in Genus = "<<species_in_genus<<endl;
        int r=0;
        while (r<repetitions)
        {
            int i = 10; int j = 10;

            n_of_species = species_in_genus;  // the initial value for the number of species is taken from the for loop
            int times, tstep = 0;
            while (tstep < n_of_events+1)
            {
                sims++;  // counter for simulations
                n_of_species = new_or_extinct(n_of_species);
                //extfile<<n_of_species<<" ";  // write it to file
                a[tstep][r+1] = n_of_species;  // fill the array. r+1 because the first column (0) is reserved for time
                tstep++;
                if (wrote_time == 0) // haven't saved 'time' in the array yet
                    {
                        for (int t = 1;t<n_of_events+1;t++)
                            a[t][0] = t;
                        wrote_time = 1;
                    }
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
        //extfile<<endl;
        }
        // End of repetitions for this genus.
        // Before moving on to the next one, give me some stats:
        cout<<"#Of the genus with "<< species_in_genus << " species, "<< tot_survived << " survived, "<< tot_extinct << " went extinct."<<endl;
        
        // and write to file

        std::ostringstream oss;
        oss << "pop"<< setw(3) << setfill('0') << species_in_genus  << ".csv"; // set name, pad with zeros
        std::string species_in_genus_s = oss.str();
        ofstream popfile(species_in_genus_s);

        for (int x=0;x<n_of_events+1;x++)
            {
                for (int y=0;y<repetitions+2;y++)
                {
                    popfile << a[x][y];
                    popfile << " ";
                }
                popfile << endl;
                
            }
        

    }

}