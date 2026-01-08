#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

struct JsonValue {
    enum Type { STRING, NUMBER, OBJECT, ARRAY } type;
    string str;
    int number;
    map<string, JsonValue> object;
    vector<JsonValue> array;
};

string s;
int pos = 0;

void skipSpaces() {
    while (pos < s.size() && isspace(s[pos])) pos++;
}

string parseString() {
    pos++;
    string res;
    while (s[pos] != '"') res += s[pos++];
    pos++;
    return res;
}

int parseNumber() {
    int n = 0;
    while (isdigit(s[pos])) n = n * 10 + (s[pos++] - '0');
    return n;
}

JsonValue parseValue();

JsonValue parseArray() {
    JsonValue v;
    v.type = JsonValue::ARRAY;
    pos++;
    skipSpaces();

    while (s[pos] != ']') {
        v.array.push_back(parseValue());
        skipSpaces();
        if (s[pos] == ',') pos++, skipSpaces();
    }
    pos++;
    return v;
}

JsonValue parseObject() {
    JsonValue v;
    v.type = JsonValue::OBJECT;
    pos++;
    skipSpaces();

    while (s[pos] != '}') {
        string key = parseString();
        skipSpaces();
        pos++; // :
        skipSpaces();
        v.object[key] = parseValue();
        skipSpaces();
        if (s[pos] == ',') pos++, skipSpaces();
    }
    pos++;
    return v;
}

JsonValue parseValue() {
    skipSpaces();

    if (s[pos] == '"') {
        JsonValue v;
        v.type = JsonValue::STRING;
        v.str = parseString();
        return v;
    }
    if (isdigit(s[pos])) {
        JsonValue v;
        v.type = JsonValue::NUMBER;
        v.number = parseNumber();
        return v;
    }
    if (s[pos] == '{') return parseObject();
    if (s[pos] == '[') return parseArray();

    throw runtime_error("Invalid JSON");
}

int main() {
    s = R"({
      "x": [1, 2, {"y": ["a", "b"]}],
      "z": {"k": 10}
    })";

    JsonValue root = parseValue();

    cout << root.object["x"].array[2].object["y"].array[1].str << endl;
    cout << root.object["z"].object["k"].number << endl;
}
