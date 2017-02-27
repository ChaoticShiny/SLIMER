# simulation
This readme covers how to run the GEANT4 simulation for SLIMER, as well as the current procedures for processing experimental data using ImageJ, and comparing experimental and simulation data using ROOT.

REQUIREMENTS
- CMake
- GEANT4
- ROOT
- ImageJ


CONTENTS
code
- CMakeLists and exec.mac should be left alone.
- Run.mac should be modified depending on the desired simulation.

code_build
- Everything in this folder should be generated automatically. 
- Temporary changes can be made here, but will be overwritten next time the code is compiled.

other_code
- This folder contains all the root scripts used to view and compare data. See "ROOT/SCRIPTS" for more information.

RUNNING A SIMULATION
1. If the folder code_build does not already exist in parallel with code, create it. 
2. From code_build, run sudo cmake -DGeant4_DIR=/path/to/geant4.9.6.p04/lib[64]/Geant4-9.6.0/
3. From code_build, and as superuser, run make && make install. Note: running sudo make && make install does not work.
4. To run the macros, first run ./exec exec.mac and then ./exec run.mac.
5. To store the output from run.mac in a text file, use ./exec run.mac >> output.txt.

IMAGEJ
Images are analyzed through ImageJ with several macros: 
1. The getAverage macro takes the average of all the images in the set. This is to establish a baseline that can then be subtracted from every image in order to eliminate some background noise.
2. The subtractAverage macro subtracts the generated average from every image.
3. The gaussianBlur macro applies a gaussian blur to every image. This makes events more easily visible.
4. The getResults2 macro (there is no getResults1 or getResults) looks for peaks in each image, and records information about all of them that it finds.
5. The AllValuesLooped macro tests every image to see if it contains an event, and copies each image into either an "events" folder or a "noevents" folder.
Notes: 
- AllValuesLooped sorts the images after the gaussian blur has been applied to them. 
- All the other macros use every image, unsorted. The number of events per run is used in other data, but it's not important for the macros. 
- What we've found so far indicates that AllValuesLooped is fairly accurate, although it picks up about 50 images per 10000 as having events that do not have events. It has no way to account for multiple events per image. 
- It works by looking first for pixels that are above a certain grayscale brightness, and then searching for a certain number of pixels in a small square around the bright pixel that are above a different, slightly lower brightness.

ROOT/SCRIPTS
- addTwoHists.C: Run with root -l addTwoHists.C. The input of this macro can be changed, but its purpose is to add Sr and Y runs together to get a more accurate representation of the decay.
- calgraph.C
- C14peakheight.C
- attempt.hh
- graphToHist.C: 
- min_activity.C: Run with root -l min_activity.C. Right now, this only plots specific numbers, which are found in a way I do not yet recall. It determines the minimum activity we should be able to detect in a 10000-image run.
- plotResultsAgain.C and plotResultsAgain.h: 
- script.cc
- simcompare_with_ij2root.C
- attempt.cc and attempt.hh: 

CURRENT BUGS
- run.mac gets into an apparently infinite loop. 
