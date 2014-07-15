/*
 * dictionaryTester.hpp
 *
 *  Created on: Jul 14, 2014
 *      Author: Brandon
 */

#ifndef DICTIONARYTESTER_HPP_
#define DICTIONARYTESTER_HPP_

#include <iostream>
#include <string>
#include "Dictionary.hpp"

class DictionaryTester {
public:
   //////////////////////test functions of dictionary /////////////////////////
   static void TestDictionary ( Dictionary testDict ) {
      const int NUMRANDOM = 10;
      long int size = testDict.NumWords();
      cout << endl << endl << size << " words" << endl;

      string test[] = { "hello", "goodbye", "toodaloo", "6454klj", "thank you",
            "japan", "frost" };

      for ( int i = 0 ; i < 7 ; i++ ) {
         cout << test[i]
               << (testDict.IsAWord( test[i] ) ? " is a word" : " isn't a word")
               << endl;

      }
      cout << endl << "random words" << endl;
      for ( int i = 0 ; i < NUMRANDOM ; i++ )
         cout << testDict.GetRandomWord() << endl;

      getchar();
   }
   ///////////////////////end of test functions ///////////////////////////////
};

#endif /* DICTIONARYTESTER_HPP_ */
