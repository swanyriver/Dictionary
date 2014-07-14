/*
 * testFStream.cpp
 *
 *  Created on: Jul 13, 2014
 *      Author: Brandon
 */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "myFunctions.hpp"
#include "Dictionary.hpp"
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

    myDictonary = Dictionary(8);

   //dictionary testing
    myDictonary.TestDictionary();

    Dictionary shortDict(6);
    shortDict.TestDictionary();

    Dictionary failDict(Dictionary::UNRESTRICTED,"hello.txt");
    cout << "this one success:" << failDict.succesfull;
    getchar();


    int numRands = 5;
    while(numRands<=3200){
       cout << endl <<"get "<< numRands << " randoms" << endl;
       getchar();
       for (int var = 0; var < numRands; ++var) {
          cout << myDictonary.GetRandomWord() <<"/";
       }
       numRands = numRands*5;
       getchar();
    }





   /*ifstream instream;
   string nextWord;

   map<string,long int> wordMap;
   long int mapValue =0;

   instream.open("dictionary.txt");
   cout << "opened";

   //list <string> words;

   while(!instream.eof()){
      while(!swansonString::IsALetter((instream.peek()))){
         instream.ignore(1);
      }
      string nextWord;
      getline(instream,nextWord,' ');
      while(swansonString::IsALetter(!nextWord.back())){
         nextWord.pop_back();
      }

      if(!nextWord.empty() && swansonString::AllLetters(nextWord) ){
         words.push_back(nextWord);
      }


      getline(instream,nextWord);
      mapValue++;
      wordMap[nextWord] = mapValue;
      //cout << "adding word " << nextWord;



   }
   //words added

   instream.close();





   while(!words.empty()){
      cout << words.back() << "/";
      words.pop_back();
   }
   long int size = wordMap.size();
   cout << endl << endl << size << " words" << endl;

   string test[] = {"hello","goodbye","toodaloo", "6454klj", "thank you", "japan", "frost"};

   for(int i=0; i<7; i++){
      cout << test[i] << ((wordMap.count(test[i])>0)? " is a word": " isn't a word" ) << endl;
   }

   return 0;



*/
}

