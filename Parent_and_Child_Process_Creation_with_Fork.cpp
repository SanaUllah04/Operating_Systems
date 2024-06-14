#include <iostream>  // Include the input/output stream library.
#include <sys/wait.h>  // Include the header file for the wait system call.
#include <unistd.h>   // Include the header file for the getpid and getppid functions.
using namespace std;

int main() {  // Start the main function.
    std::cout << "Hello, I am parent." << std::endl;  // Print "Hello, I am parent." to the standard output.

    cout<<endl<<"Parent ID : "<<getpid();
     cout<<endl<<"Child ID : "<<getppid();

    pid_t no = fork();  // Create a child process using the fork system call and store its process ID.

    if (no < 0) {  // If the fork failed (returned a negative value),
        cout << "Fork failed." << std::endl;  // Print an error message to the standard error.
        return 1;  // Return 1 to indicate failure.
    } else if (no == 0) {  // If the process ID is 0, it's the child process.
        std::cout << "Hello, I am child." << std::endl;  // Print "Hello, I am child." to the standard output.
        exit(0);  // Exit the child process with status 0 to indicate successful execution.
    } else {  // Otherwise, it's the parent process.
        int status;  // Declare an integer variable to store the child process status.
        waitpid(no, &status, 0);  // Wait for the child process to terminate and store its status.
        cout<<endl<<"Status of Child: "<<status;
    }

    return 0;  // Return 0 to indicate successful execution.
}
