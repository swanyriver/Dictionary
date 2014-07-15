/***********************************************************
 * Author: Brandon Swanson
 * Date Created: 07-13-2014
 * Last Modification Date: 07-13-2014
 * Filename: Dictionary.hpp
 *
 * Overview: Create a searchable map of words
 *
 * Input: a file with alpha only, lower case, return character separated words
 *
 * Output: a dictionary object that can be polled for number of words contained
 * and if a single string element exists in the dictionary
 *
 ***********************************************************/

#ifndef DICTIONARY_HPP_
#define DICTIONARY_HPP_


#include <fstream>
#include <string>
#include <set>
#include <algorithm> //for string compare less<string>, used by set<>
#include <iterator>
#include "swansonUtils.hpp"

using namespace std;

class Dictionary {
private:


   set<string> wordSet;
   set<string>::iterator lookup;

   /**************************************************************
    *
    * * Entry: a file with only alpha, lower case, return character separated
    *          words
    *
    * * Exit: an inflated map
    *
    *
    * * Purpose:  read all words from a file,
    *             excluding ones greater than max length
    *
    * ***************************************************************/
   bool InflateDict ( string filename , int MaxWordLength ) {

      fstream instream;
      string nextWord;

      //open dictionary file
      instream.open( filename.c_str() );

      if ( instream.fail() ) {
         return false;
      }

      while ( !instream.eof() ) {
         getline( instream , nextWord ); // Retrieve next word
         if ( MaxWordLength == UNRESTRICTED
               || nextWord.size() <= MaxWordLength ) {
            wordSet.insert(nextWord);
         }
      }
      //words added  //close file
      instream.close();

      if (wordSet.empty()) return false;

      return true;

   }

public:
   bool succesfull;
   static const int UNRESTRICTED = -1;

   ///constructors
   Dictionary ( bool dummy ) {
      succesfull = false;  //used to instantiate an empty dictionary
   }
   Dictionary ( int maxWordLenght = UNRESTRICTED , string filename =
         "dictionary.txt" ) {
      succesfull = InflateDict( filename , maxWordLenght );
   }

   /**************************************************************
    *
    * * Entry:an inflated map
    *
    *
    * * Exit:true if map contains 1 or more of element, false otherwise
    *
    *
    * * Purpose: determine if passed in word is a word in dictionary
    *
    *
    * ***************************************************************/
   bool IsAWord ( string word ) {
      if ( wordSet.count( word ) > 0 )
         return true;
      else
         return false;
   }

   //returns number of words
   long int NumWords () {
      return wordSet.size();
   }

   string GetWordAt(int position){
      lookup = wordSet.begin();
      advance(lookup, position);
      return *lookup;

   }

   string GetRandomWord(){
      int position = swansonUtil::GetRandomInRange(NumWords());
      return GetWordAt(position);
   }






};

#endif /* DICTIONARY_HPP_ */

