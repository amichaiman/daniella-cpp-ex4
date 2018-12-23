#include <iostream>
#include <cstdlib>
#include "Simulation.h"
#include "TreeNode.h"
#include "GTree.h"
#include <ctime>

using namespace std;

inline void invalidInput(int exitCode) {
    cerr << "ERROR: Invalid input." << endl;
    exit(exitCode);
}
int main(int argc, char** argv) {
    if (argc != 3){
        invalidInput(1);
    }
    srand(time(NULL));
    Simulation simulation; // create new Simulation instance

    if (!simulation.config(argv[1])){ //if config did not succeed, show error massage
        invalidInput(2);
    }

    if (!simulation.init(argv[2])){ //if init did not succeed, show error massage
        invalidInput(3);
    }
    simulation.run(); //if everything is ok at this point, go to run function
    return 0;
}
