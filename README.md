# Extinction Calculator

Starting from a population of species (one genus), we assume that at every "event" (timestep) 
 either a new species appears or an existing species goes extinct. These two outcomes have the same probability, 0.5.

 How many tsteps can a genus survive before all of its species go extinct?

 This is equivalent to the gambler's ruin problem and was inspired 
 by the book "La Malinconia del Mammut" by Massimo Sandal (2019).

 ## `species_extinction_calculator` 
 
 (numerically) calculates the probability that one genus with `species_in_genus` species will survive after a certain `n_of_events` events. Each *extinction simulation* is repeated multiple times, then the results averaged, to avoid variability.
 
 Output file: a csv file with columns 'Number of initial species', 'Probability of surviving', 'Probability of going extinct'.

 `plotme.p` plots the generated data by typing ```gnuplot plotme.p```.




 ## `species_extinction_plot`
  generates csv files that can be plotted to visualise the trend in time of the number of species in one genus.

 To compile: enter one of these two directories and type `make`.

