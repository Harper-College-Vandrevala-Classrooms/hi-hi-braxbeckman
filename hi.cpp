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
  assert(strcmp_case_insensitive("apple", "bannana") == -1);
  cout << "\"apple\" compared to \"banana\" == " << strcmp_case_insensitive("apple", "banana") << endl << endl;

  assert(strcmp_case_insensitive("bannana", "apple") == 1);
  cout << "\"banana\" compared to \"apple\" == " << strcmp_case_insensitive("banana", "apple") << endl << endl;

  assert(strcmp_case_insensitive("apple", "apple") == 0);
  cout << "\"apple\" compared to \"apple\" == " << strcmp_case_insensitive("apple", "apple") << endl << endl;

  assert(strcmp_case_insensitive("Apple", "apple") == 0);
  cout << "\"Apple\" compared to \"apple\" == " << strcmp_case_insensitive("Apple", "apple") << endl << endl;

  assert(strcmp_case_insensitive("apples", "apple") == 1);
  cout << "\"apples\" compared to \"apple\" == " << strcmp_case_insensitive("apples", "apple") << endl << endl;

  assert(strcmp_case_insensitive("apple", "apples") == -1);
  cout << "\"apple\" compared to \"apples\" == " << strcmp_case_insensitive("apple", "apples") << endl << endl;

  assert(strcmp_case_insensitive("", "Apple") == -1);
  cout << "\"\" compared to \"Apple\" == " << strcmp_case_insensitive("", "Apple") << endl << endl;

  assert(strcmp_case_insensitive("Banana", "10") == 1);
  cout << "\"Banana\" compared to \"10\" == " << strcmp_case_insensitive("Banana", "10") << endl << endl;

  assert(strcmp_case_insensitive("PeAr", "orANge") == 1);
  cout << "\"PeAr\" compared to \"orANge\" == " << strcmp_case_insensitive("PeAr", "orANge") << endl << endl;

  cout << "\nProgram ran succesfully!" << endl << endl;


  /*cout << "Please enter the first input: ";
  cin >> in1;
  cout << endl << "Please enter the second input: ";
  cin >> in2;*/
}

int strcmp_case_insensitive(string string1, string string2)
{
  int minLength{0};
  int tieBreaker{0};

  if (string1.length() > string2.length())
  {
    minLength = string2.length();
    tieBreaker = 1;
  }
  else if (string1.length() == string2.length())
  {
    minLength = string1.length();
    tieBreaker = 0;
  }
  else
  {
    minLength = string1.length();
    tieBreaker = 2;
  }

  if (string1 == "")
  {
    return -1;
  }
  else if (string2 == "")
  {
    return 1;
  }
  else if (string1 == "" && string2 == "")
  {
    return 0;
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
