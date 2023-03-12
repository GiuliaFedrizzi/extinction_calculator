# Extinction Calculator

Starting from a population of species (one genus), we assume that at every "event" (timestep) 
 either a new species appears or an existing species goes extinct. These two outcomes have the same probability, 0.5.

 How many tsteps can a genus survive before all of its species go extinct?

 This is equivalent to the gambler's ruin problem and was inspired 
 by the book "La Malinconia del Mammut" by Massimo Sandal (2019).

 `species_extinction_calculator.cpp` (numerically) calculates the probability that one genus with `species_in_genus` species will survive after a certain `n_of_events` events. `plotme.p` plots the generated data by typing ```gnuplot plotme.p```.

 `species_extinction_plot.cpp` is a script that generates csv files that can be plotted to visualise the trend of species in one genus in time.

