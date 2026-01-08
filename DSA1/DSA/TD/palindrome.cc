#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <algorithm>
using namespace std;
class Palindrome
{
public:
   static bool isPalindrome(std::string str){

      str.erase(std::remove_if(str.begin(),str.end(),[](char x) { return isalpha(x) == 0;}),str.end());

      for (std::size_t i = 0; i < str.size() / 2; ++i){
         auto c0 = tolower(str[i]);
         auto c1 = tolower(str[str.size() - i - 1]);
         if (c0 != c1)
            return false;
      }
      return true;
   }
};


#ifndef RunTests
int main(int argc, const char* argv[])
{
   std::cout << Palindrome::isPalindrome("Noel sees Leon.");
}
#endif