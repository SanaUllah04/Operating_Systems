#include <iostream>
#include <csignal>
using namespace std;


void interruptHandler(int signal) 
{
    // CTRL + C signal being Ignored And Printed.
    cout << "Interrupt signal (" << signal << ") received.\n";
}

int main() 
{
    // Set up a signal handler for interrupt (Ctrl+C)
    signal(SIGINT, interruptHandler);

    while (true) {
        // Progam will keep running until encounter an Interrupt  [Such as Ctrl + Z].
    }

    return 0;
}
