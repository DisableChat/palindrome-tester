//*********************************************************************************
// User:        MagikarpUsedFly
// Description: palindromeTester simply tests whether the inputed string is a
//              palindrome or not. Note this implementation is done recursivly
//*********************************************************************************

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

// Function declorations, further info can be found in the definition section
// of each function
void printQuestion();
void printAnswer(string word, bool palindrome);
string getInput(istream& input);
bool palTest(string word, int begin, int end);

int main()
{
  // Variables used for palindrome test
  bool isPalindrome   = false;
  int begin           = 0;
  int end             = 0;
  string word         = "";

  printQuestion();
  word = getInput(cin);
  // Finding the end location of the string
  end = word.length() - 1 ;
  isPalindrome = palTest(word, begin, end);
  printAnswer(word, isPalindrome);

  return(0);
}

//*********************************************************************************
// Func:        printQuestion
// Param:       None
// Description: Prints the question
//*********************************************************************************
void printQuestion()
{
  printf("Enter a word and to see if it's a Palindrome: ");
}

//*********************************************************************************
// Func:        printAnswer
// Param:       word, word being passed in
//              palindrome, either true or false regarding word being a palindrome
// Description: Prints the question
//*********************************************************************************
void printAnswer(string word, bool palindrome)
{
  transform(word.begin(), word.end(), word.begin(), ::toupper);

  if(palindrome == true)
  {
    printf("The word: %s is a palindrome!\n", word.c_str());
  }
  else
  {
    printf("The word: %s is a NOT palindrome!\n", word.c_str());
  }
}

//*********************************************************************************
// Func:        getInput
// Param:       input, type istream
// Description: Simply returns the input of the user
//*********************************************************************************
string getInput(istream& input)
{
  string answer;
  input >> answer;
  return answer;
}


//*********************************************************************************
// Func:        palTest
// Param:       word, string that tested
//              begin, begin location
//              end, ending location
// Description: test if the passed in string is a palindrome, this function
//              tests this by recursivly calling palTest on the index's of the
//              string starting from the outside chars and moving inwards.
//*********************************************************************************
bool palTest(string word, int begin, int end)
{
  if(word[begin] != word[end])
  {
    return false;
  }
  else if(begin <= end)
  {
    return palTest(word, begin + 1, end - 1);
  }
  else
  {
    return true;
  }
}
