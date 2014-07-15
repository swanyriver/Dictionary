/*
 * testFStream.cpp
 *
 *  Created on: Jul 13, 2014
 *      Author: Brandon
 */


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include "Dictionary.hpp"
#include "DictionaryTester.hpp"
#include "swansonInput.hpp"
using namespace std;

/*
class Dictionary{
private:
   string mFilename;

public:
   Dictionary(string filename="dictionary.txt"){
      mFilename=filename;
   }
};
*/

int main(){


    Dictionary myDictonary(false);

   //inflate dictionary

    ThemeDictionary greyDict(Dictionary::UNRESTRICTED, "grey.txt");
   //ThemeDictionary greyDict;
   //ThemeDictionary *point= new ThemeDictionary(Dictionary::UNRESTRICTED, "grey.txt");
   //greyDict = *point;
    //Dictionary greyDict = ThemeDictionary(Dictionary::UNRESTRICTED, "grey.txt");


    cout << "this one success:" << greyDict.constructionWasSuccesfull;
    cout << "there are " << greyDict.NumWords() << " words in this text" << endl;
    DictionaryTester::TestDictionary(greyDict);



   myDictonary = Dictionary(8);
   DictionaryTester::TestDictionary(myDictonary);


    Dictionary shortDict(6);
    DictionaryTester::TestDictionary(myDictonary);


    Dictionary failDict(Dictionary::UNRESTRICTED,"hello.txt");
    cout << "this one success:" << failDict.constructionWasSuccesfull;

    //getchar();

   do {
      cout << "\n\n\n\n\n";
      for(int i=0; i<20; i++){
         int numwords = swansonUtil::GetRandomInRange(4,9);
         for (int x=0;x<numwords;x++){
            cout << greyDict.GetRandomWord() << " ";
         }
         cout << endl;
      }
   } while (swansonInput::yesNo("more phrases"));


    /*///test random retrival
    int numRands = 5;
    while(numRands<=3200){
       cout << endl <<"get "<< numRands << " randoms" << endl;
       getchar();
       for (int var = 0; var < numRands; ++var) {
          cout << greyDict.GetRandomWord() <<"/";
       }
       numRands = numRands*5;
       getchar();
    }*/
}
