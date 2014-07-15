/*
 * testFStream.cpp
 *
 *  Created on: Jul 13, 2014
 *      Author: Brandon
 */

#include <iostream>
#include <string>
#include "Dictionary.hpp"
#include "DictionaryTester.hpp"
#include "swansonInput.hpp"
using namespace std;

int main () {

   ThemeDictionary mobyDict( Dictionary::UNRESTRICTED , "moby.txt" );

   cout << "there are " << mobyDict.NumWords() << " unique words in this text"
         << endl;

   //cout << mobyDict.GetWordAt(0) << "/";
   // getchar();
   //cout << mobyDict.GetWordAt(1);
   //getchar();

   if(!mobyDict.constructionWasSuccesfull){
	cout << endl;
	cout << "something bad has happened";
	return(1);	
    }


   do {
      cout << "\n\n\n\n\n";
      for ( int i = 0 ; i < 20 ; i++ ) {
         int numwords = swansonUtil::GetRandomInRange( 4 , 9 );
         for ( int x = 0 ; x < numwords ; x++ ) {
            cout << mobyDict.GetRandomWord() << " ";
         }
         cout << endl;
      }
   } while ( swansonInput::yesNo( "more phrases" ) );

}
