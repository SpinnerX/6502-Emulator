#include <iostream>
#include "instructionInitializedTest.h"
using namespace std;

int main(){
    CPUData configs;
    testLoadInstructions(configs);
    testStoringInstructions(configs);
    testTransferInstructions(configs);
    testStackInstructions(configs);
}