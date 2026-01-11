#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include <unistd.h>

#define SHM_SIZE 1024  // Shared memory size (simulate DB page cache)

int main() {
    // Generate unique key for shared memory
    key_t key = ftok("shmfile", 65);
    
    // Create shared memory segment
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        return 1;
    }

    // Attach shared memory to process
    char* shm_ptr = (char*)shmat(shmid, nullptr, 0);
    if (shm_ptr == (char*)-1) {
        perror("shmat failed");
        return 1;
    }

    // Simulating database pages stored in shared memory
    const char* db_page = "Page 1: User Data | Page 2: Transactions | Page 3: Products";
    strncpy(shm_ptr, db_page, SHM_SIZE);
    
    std::cout << "Server: Database pages cached in shared memory.\n";
    
    // Keep running to allow client access
    std::cout << "Server running... Press Ctrl+C to stop.\n";
    while (true) { sleep(1); }

    // Detach shared memory (never reached in this example)
    shmdt(shm_ptr);
    
    return 0;
}
