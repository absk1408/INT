#include <occi.h>
using namespace oracle::occi;
using namespace std;

void insertUser(string name, int age) {
    Environment *env = Environment::createEnvironment();
    Connection *conn = env->createConnection("user", "password", "localhost/XE");

    string sql = "INSERT INTO users (name, age) VALUES (:1, :2)";
    PreparedStatement *stmt = conn->prepareStatement(sql);
    stmt->setString(1, name);  // bind the user name
    stmt->setInt(2, age);      // bind the user age 

    stmt->executeUpdate();     // run the insert query
    stmt->exectureQuery();

    conn->terminateStatement(stmt);
    env->terminateConnection(conn);
    Environment::terminateEnvironment(env);
}

int main() {
    insertUser("Abhishek", 30);  // adding user Abhishek, age 30
    return 0
}
