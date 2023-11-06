#include <iostream>
#include "instructionInitializedTest.h"
using namespace std;

int main(){
    CPUConfigs configs;
    testLoadInstructions(configs);
    testStoringInstructions(configs);
    testTransferInstructions(configs);
    testStackInstructions(configs);
}