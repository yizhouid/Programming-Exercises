// The Greplin Programming Challenege Level #1
// "The password is the longest substring that is the same in reverse."
// As an example, if the input was "I like racecars that go fast"
// the password would be "racecar".
//
// Yi Zhou, Oct 10, 2012

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <algorithm>

bool check_palindrome(std::string subString) {
  int start = 0;
  int end = subString.length()-1;

  // Compare first char with last char
  // If they are the same then continue
  // If not then not a palindrome!
  while(end > start) {
    if(subString[start] != subString[end])
      return false;
    start++;
    end--;
  }

  return true;
}

int main() {
  std::string inputString = "FourscoreandsevenyearsagoourfaathersbroughtforthonthiscontainentanewnationconceivedinzLibertyanddedicatedtothepropositionthatallmenarecreatedequalNowweareengagedinagreahtcivilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
  std::string subString = "";
  std::string longestPalindrome = "";
  std::map<char, std::list<int> > char_map;

  std::map<char, std::list<int> >::iterator i;
  std::list<int>::iterator j;
  std::list<int>::reverse_iterator k;

  // Convert the string to lowercase for Map + Comparison
  std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);

  // Populate Map with indexes of each character
  for(int i = 0; i != inputString.length(); i++)
    char_map[inputString[i]].push_back(i);
  
  // For each unique same char pair, get the substring and check if it is a palindrome or not
  for(i = char_map.begin() ; i != char_map.end(); i++) {
    for(j = (*i).second.begin(); j != (*i).second.end(); j++) {
      for(k = (*i).second.rbegin(); (*k) != (*j); k++) {
        if(longestPalindrome.length() >= ((*k)-(*j)+1))
          break;
          
        subString = inputString.substr((*j), (*k)-(*j)+1);
        if(check_palindrome(subString)) {
          longestPalindrome = subString;
          break;
        }  
      }
    }
  }

  std::cout << longestPalindrome << std::endl;

  return 0;
}
