#include <iostream>
#include <string>
using namespace std;
// Base Logger using CRTP
template <typename Derived>
class Logger {
public:
    void log(const string& message) {
        cout << "[" << static_cast<Derived*>(this)->name() << "] " << message << endl;
    }
};

// Derived class that wants logging
class FileProcessor : public Logger<FileProcessor> {
public:
    string name() const {
        return "FileProcessor";
    }
    void process() {
        log("Processing file started");
        // Simulate work
        cout << "Doing file processing..." << endl;
        log("Processing file finished");
    }
};
// Another class using the same Logger base
class NetworkManager : public Logger<NetworkManager> {
public:
    string name() const {
        return "NetworkManager";
    }
    void connect() {
        log("Connecting to server...");
        // Simulate work
        cout << "Connection established!" << endl;
        log("Connection successful");
    }
};
int main() {
    FileProcessor fp;
    fp.process();
    cout << endl;
    NetworkManager nm;
    nm.connect();
    
}