# Debugging C++ programs thorough test randomizer and another C++ program 

First you need to create cpp programs such as: 
  1) Generator that receives one extra parametr - seed of the test,
     and just to print tests using this seed (use "cout")
     {example in the gen.cpp file!}
     
  2) Any solve of a problem. Just be sure it fully works
  3) Solve that you gonna debug

Compile stress.cpp as you compile basic programs (example: "g++ stress.cpp -o stress")

Then run testing program (stress) with parametrs:
  1) Name of program that you want to debug (without .cpp)
  2) Name of program that fully works (without .cpp)
  3) Name of test generator (without .cpp)
  4) Amount of tests you want to run (number)

Program is wrotten for Windows, but to make it fit with Linux you just need to change a few system commands to familiar in Linux.
You can also write smart checker. Here I use Windows command "comp" for character-to-character comprasion.
