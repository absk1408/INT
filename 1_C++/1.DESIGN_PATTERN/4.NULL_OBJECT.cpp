#include <iostream>
#include <string>
using namespace std;
class Client {
public:
    virtual void receiveMessage(const string& message) = 0; // Abstract method
    virtual ~Client() = default;
};
class RealClient : public Client {// Concrete Client Implementation
private:
    string name;
public:
    RealClient(const string& clientName) : name(clientName) {}
    void receiveMessage(const string& message) override {
        cout << "Client " << name << " received: " << message << endl;
    }
};
class NullClient : public Client {// Null Object Implementation of Client
public:
    void receiveMessage(const string& message) override {
        cout << "NullClient received a message but does nothing." << endl;
    }
};
class Server {
private:
    Client* client;
public:
    Server(Client* clientInstance) : client(clientInstance) {}
    void sendMessage(const string& message) {
        cout << "Server: Sending message..." << endl;
        client->receiveMessage(message); // Always safe, no null checks needed
    }
};
int main() {
    RealClient realClient("Alice");    // Create a real client
    NullClient nullClient;    // Create a null client
    Server serverWithClient(&realClient);    // Server with a real client
    serverWithClient.sendMessage("Hello, Alice!");
    Server serverWithoutClient(&nullClient);// Server with no real client (uses null client)
    serverWithoutClient.sendMessage("Hello, anyone?");
    return 0;
}
