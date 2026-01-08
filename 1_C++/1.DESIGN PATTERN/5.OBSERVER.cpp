//The Observer Pattern is a behavioral design pattern used when you want one object to automatically notify many other objects when its state changes.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Client { // Observer Interface
public:
    virtual void update(const string& message) = 0;
    virtual ~Client() = default;
};
class ConcreteClient : public Client { // Concrete Observer (Client Implementation)
private:
    string name;
public:
    ConcreteClient(const string& clientName) : name(clientName) {}
    void update(const string& message) override {
        cout << "Client " << name << " received message: " << message << endl;
    }
};
class Server {// Subject Interface
public:
    virtual void attach(Client* client) = 0;
    virtual void detach(Client* client) = 0;
    virtual void notify(const string& message) = 0;
    virtual ~Server() = default;
};
class ConcreteServer : public Server { // Concrete Subject (Server Implementation)
private:
    vector<Client*> v;
public:
    void attach(Client* client) override {
        v.push_back(client);
    }
    void detach(Client* client) override {
        v.erase(remove(v.begin(), v.end(), client), v.end());
    }
    void notify(const string& message) override {
        for (Client* client : v) {
            client->update(message);
        }
    }
    void broadcastMessage(const string& message) {
        cout << "Server broadcasting: " << message << endl;
        notify(message);
    }
};
int main() {
    ConcreteServer server;  // Create a server
    ConcreteClient client1("Alice");  // Create clients
    ConcreteClient client2("Bob");
    server.attach(&client1); // Clients subscribe to the server
    server.attach(&client2);// Clients subscribe to the server
    server.broadcastMessage("Server is online!");     // Server broadcasts a message
    server.detach(&client2);     // Client2 unsubscribes    
    server.broadcastMessage("Server shutting down."); // Server broadcasts a final message
    return 0;
}
