#include <iostream>
#include <unistd.h>     // fork(), sleep()
#include <signal.h>     // kill()
#include <sys/wait.h>   // wait()

using namespace std;

int main() {
    pid_t pid = fork();  // Step 1: Create child process

    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    }

    if (pid == 0) {    // Step 2: Code running in the child process
        cout << "Child"<<getpid() << ")" << endl; // this going to return child process
        while (true) { //Child still alive...
            sleep(1);  
        }
    } 
    else {
        sleep(5);  // Let the child run for 3 seconds
        cout << "Parent:"<< pid << ")" << endl;
        kill(pid, SIGKILL);  // Step 5: Send SIGKILL to child
        wait(NULL);  // Step 6: Reap child to prevent zombie
        cout << "Parent: Child process killed." << endl;
    }
    return 0;
}
