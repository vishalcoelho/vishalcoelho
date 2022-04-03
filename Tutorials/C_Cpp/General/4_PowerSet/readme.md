# Problem Statement
Print All the Subsets of a Given Set (Power Set)
February 21, 2015 by Sumit Jain
Objective: Given a set of numbers, print all the posssible subsets of it including empty set.

Power Set: In mathematics, PowerSet of any given set S, PS(S) is set of all subsets of S including empty set.
Example:

 S ={1,2,3}

PS(S): {{ᵩ}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

# Building and Running this Examples
1. Create a build folder under root
   `mkdir build`
2. Open a bash shell at the top folder
    `cmake -S . -B build`
3. This is generating a MSVS project for me. You can instead change the generator to minGW (assuming you already donwloaded it)
   `cmake -G "MinGW Makefiles" -S . -B build`
   1. You can use the 'clean' option to clear out the cmake files in a project
      `cmake --build build --target clean`
4. cd to the build directory and make
   `cd build; make`