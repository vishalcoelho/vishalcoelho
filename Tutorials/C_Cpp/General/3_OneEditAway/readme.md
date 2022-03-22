# Problem Statement
Write a function that returns whether two words are exactly "one edit" away using the following signature:
bool OneEditApart(string s1, string s2);
An edit is:
Inserting one character anywhere in the word (including at the beginning and end)
Removing one character
Replacing one character
Examples:
OneEditApart("cat", "dog") = false
OneEditApart("cat", "cats") = true
OneEditApart("cat", "cut") = true
OneEditApart("cat", "cast") = true
OneEditApart("cat", "at") = true
OneEditApart("cat", "act") = false

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