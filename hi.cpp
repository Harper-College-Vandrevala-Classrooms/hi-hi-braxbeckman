#include <cassert>
#include <iostream>
#include <string>
using namespace std;

string in1;
string in2;


// Write a recursive function that calls itself if value is zero (If characters are identical) or returns (+/-)
// depending on whether value is pos or negative
int strcmp_case_insensitive(string, string);

int main()
{
  assert(strcmp_case_insensitive("apple", "bannana") < 0);
  cout << "First compare done" << endl << endl;

  assert(strcmp_case_insensitive("bannana", "apple") > 0);
  cout << "Second compare done" << endl << endl;

  assert(strcmp_case_insensitive("apple", "apple") == 0);
  cout << "Third compare done" << endl << endl;

  assert(strcmp_case_insensitive("Apple", "apple") == 0);
  cout << "Fourth compare done" << endl << endl;

  cout << "Apples vs Apple comparison = " << strcmp_case_insensitive("apples", "apple") << endl;
  assert(strcmp_case_insensitive("apples", "apple") == 1);
  cout << "Fifth compare done" << endl << endl;

  cout << "Apple vs Apples comparison = " << strcmp_case_insensitive("apple", "apples") << endl;
  assert(strcmp_case_insensitive("apple", "apples") == -1);
  cout << "Sixth compare done" << endl << endl;

  /*cout << "Please enter the first input: ";
  cin >> in1;
  cout << endl << "Please enter the second input: ";
  cin >> in2;*/
}

int strcmp_case_insensitive(string string1, string string2)
{
  int minLength{0};
  int tieBreaker{0};

  if (string1.length() - string2.length() > 0)
  {
    minLength = string2.length();
    tieBreaker = 1;
  }
  else if (string2.length() - string1.length() > 0)
  {
    minLength = string1.length();
    tieBreaker = 2;
  }
  else
  {
    minLength = string1.length();
    tieBreaker = 0;
  }


  // cout << "MinLength = " << minLength << endl << endl;

  for (int i = 0; i < minLength; i++)
  {
    // cout << "i = " << i << endl << "char value = " << tolower(string1[i]) - tolower(string2[i]) << endl;

    if (tolower(string1[i]) - tolower(string2[i]) == 0)
    {
      if ((string1.length() - string2.length() == 0) && (i == minLength - 1))
      {
        return 0;
      }
      // If string 1 is longer than string 2, and we have reached the end of the string, return positive
      else if (tieBreaker == 1)
      {
        return 1;
      }
      // If string 2 is longer than string 1, and we have reached the end of the string, return positive
      else if (tieBreaker == 2)
      {
        return -1;
      }
      else
      {
        continue;
      }
    }
    else if (tolower(string1[i]) - tolower(string2[i]) > 0)
    {
      return 1;
    }
    else if (tolower(string1[i]) - tolower(string2[i]) < 0)
    {
      return -1;
    }
  }

  return 999; // Debug value
}
