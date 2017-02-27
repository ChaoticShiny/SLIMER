/* ~~ NOT MEANT TO BE COMPILED ~~ */

Notes: 
~ Instead of "main," the main function needs to be whatever the filename is. For example, attempt.cc says "int attempt ()" instead of "int main ()".
~ Use ROOT version 5.34/14. 
~ Run with "root -l foo.cc" after making sure the main function name is correct. 

Log: 
6/10/2016: Created files, got them running. 
6/13/2016: Reads only 0s out from file, not sure why. 
6/28/2016: This log was a stupid idea.

Next things to do: 
- Get AllValuesLooped macro to recommend a threshold at which to run the getResults2 macro. 
- Figure out how number of events corresponds to time; for a good calibration, the number of events should be more or less the same. 
	- This will require knowing several things, either 
		1. that the events in the macro are not directional, or 
		2. that they are directional, which will require knowing
		   ~ FOV of the objective
		   ~ efficency of the camera (how would we know this?)
		3. the activity of the source in decay events per unit of time
- Come up with some intelligent way to calibrate the camera data based on the simulation data
	- Compare lots of runs, especially C-14 and Sr-90, with different thicknesses of CsI
- Also need to finish logging all the sources, on Thursday once I have radiation training