#include <iostream>
#include <string>
using namespace std;
class TextInput{
    string data;
public:
   virtual ~TextInput(){};
   virtual void add(char c) { data += c; }
   string getValue() { return data; }
};

class NumericInput : public TextInput{
   void add(char c) override{
      if (('0' <= c) && (c <= '9'))
         TextInput::add(c);
   }
};
int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    input->add('9');
    input->add('1');
    input->add('c');
    cout << input->getValue();
}