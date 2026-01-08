#include<iostream>
using namespace std;
struct HiddenData;  // Forward declaration (incomplete type)
HiddenData* createData(int value);
void processData(HiddenData *data);
void destroyData(HiddenData *data);

// In source file:
struct HiddenData { int secret; };

HiddenData* createData(int value) {
    HiddenData *d = new HiddenData;
    d->secret = value;
    return d;
}

void processData(HiddenData *data) {
    data->secret=909;
    cout << "Secret: " << data->secret << endl;
}

void destroyData(HiddenData *data) {
    delete data;
}

int main() {
    HiddenData *data = createData(42);
    processData(data);
    destroyData(data);
    return 0;
}