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
#include "swansonString.hpp"

#include <iostream> //remove when testing is finished

using namespace std;

class Dictionary {

private:
   set<string> wordSet;
   set<string>::iterator lookup;

protected:
   virtual void ReadFromFile ( fstream &instream , set<string> &wordSet ,
         const int MaxWordLength ) {

      string nextWord;

      while ( !instream.eof() ) {
         getline( instream , nextWord ); // Retrieve next word
         if ( MaxWordLength == UNRESTRICTED
               || nextWord.size() <= MaxWordLength ) {
            wordSet.insert( nextWord );
         }
      }

   }

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
   bool InflateDict ( string filename , const int MaxWordLength ) {

      fstream instream;

      cout << "inside inflate now,  filename is " << filename << endl;

      //open dictionary file
      instream.open( filename.c_str() );

      if ( instream.fail() ) {
         return false;
      }

      //read words from file
      this->ReadFromFile( instream , wordSet , MaxWordLength );

      //words added  //close file
      instream.close();

      if ( wordSet.empty() )
         return false;

      return true;

   }

public:
   bool constructionWasSuccesfull;
   static const int UNRESTRICTED = -1;

   ///constructors
   Dictionary ( bool dummy ) {
      constructionWasSuccesfull = false; //used to instantiate an empty dictionary
   }
   Dictionary ( int maxWordLenght = UNRESTRICTED , string filename =
         "dictionary.txt" , bool construct = true) {

      cout << "inside constructor filename is " << filename << endl;
      if(construct)
         constructionWasSuccesfull = InflateDict( filename , maxWordLenght );
      else
         constructionWasSuccesfull = false;
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

   string GetWordAt ( int position ) {
      lookup = wordSet.begin();
      advance( lookup , position );
      return *lookup;

   }

   string GetRandomWord () {
      int position = swansonUtil::GetRandomInRange( NumWords() );
      return GetWordAt( position );
   }

   //for testing
   set<string>::iterator GetIterator(){
      return wordSet.begin();
   }
};

/**************************************************************
 *
 * * Entry:
 *
 *
 * * Exit:
 *
 *
 * * Purpose: A dictionary object with a non optimized input stream file
 *            Considerably longer input time but possibly more fun
 *
 *
 * ***************************************************************/

class ThemeDictionary: public Dictionary {
public:

   ///constructors
   /*ThemeDictionary ( bool dummy ) : Dictionary(dummy){}  //call parent constructor
   ThemeDictionary ( int maxWordLenght = UNRESTRICTED , string filename =
         "dictionary.txt" ) :Dictionary(maxWordLenght,filename){}
*/
   /*ThemeDictionary ( bool dummy ) {
      constructionWasSuccesfull = false; //used to instantiate an empty dictionary
   }
   ThemeDictionary ( int maxWordLenght = UNRESTRICTED , string filename =
         "dictionary.txt" ) {
      cout << "inside child constructor filename is " << filename << endl;
      constructionWasSuccesfull = InflateDict( filename , maxWordLenght );
   }*/

   ThemeDictionary ( bool dummy ) : Dictionary(dummy){}  //call parent constructor
   ThemeDictionary ( int maxWordLenght = UNRESTRICTED , string filename =
         "dictionary.txt" , bool construct = false)
         :Dictionary(maxWordLenght,filename,false){
      /*must use this two staged inflation,  base class will by default
       * inflate upon construction, but then the overridden subclass method
       * is not called during the inflate method, because the 'this' pointer
       * is still referencing the base class,  in this constructor the construct
       * =false flag is sent to the super constructor to prevent it from
       * inflating using parent method default arguments, then the derived
       * class inflates with its specialized word parsing method
      */
      constructionWasSuccesfull = InflateDict( filename , maxWordLenght );
   }



private:
   void ReadFromFile ( fstream &instream , set<string> &wordSet ,
         const int MaxWordLength ) {

      //testing
      ofstream output;
      output.open("wordsgotten.txt");


      string nextWord;

      cout << "subclass method is running";
      getchar();


      while ( !instream.eof() ) {
         while ( !swansonString::IsALetter( (instream.peek()) ) ) {
            instream.ignore( 1 );
         }
         string nextWord;
         getline( instream , nextWord , ' ' );
         while ( swansonString::IsALetter( !nextWord.back() ) ) {
            nextWord.pop_back();
         }

         if ( !nextWord.empty() && swansonString::AllLetters( nextWord ) ) {
            nextWord = swansonString::LowerCase(nextWord);

            if(!IsAWord(nextWord)) output << nextWord << endl; //testingß

            wordSet.insert(nextWord);



            //if(wordSet.count(nextWord)==0)wordSet.insert( nextWord );
            //if(!IsAWord(nextWord)) wordSet.insert( nextWord );

         }

      }

      output.close();

   }


};

#endif /* DICTIONARY_HPP_ */

