#include <iostream>
#include <stdio.h>
//#include <string.h>
#include <algorithm>
using namespace std;

void printQuestion();
void printAnswer(string word, bool palindrome);
int getSize(string word);
string getInput(istream& input);
bool palTest(string word, int begin, int end);

int main()
{
  bool pass   = false;
  int begin   = 0;
  int end     = 0;
  string word = "";

  printQuestion();
  word = getInput(cin);
  end = getSize(word) - 1 ;
  pass = palTest(word, begin, end);
  printAnswer(word, pass);

  return(0);
}


void printQuestion()
{
  printf("Enter a word and to see if it's a Palindrome: ");
}

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

string getInput(istream& input)
{
  string answer;
  input >> answer;
  return answer;
}

bool palTest(string word, int begin, int end)
{
  cout << word[begin] << " " << word[end] << end;
  cout << begin << " " <<  end << endl;
  bool pass;

  if(word[begin] == word[end] && begin != word.length()/2 + 1)
  {
    pass = true;
    palTest(word, begin + 1, end - 1);
  }
  else if(word[begin] != word[end]);
  {
    pass = false;
  }
  return pass;
}

int getSize(string word)
{
  return word.length();
}
