/**
 * @Author Basilio Gómez Navarro
 * @date 27/10/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 6 - Deterministic Finite Automaton
 * Email: alu0101049151@ull.edu.es
 * DFA.h file: DFA class. It represents a Deterministic Finite Automaton.
 *             This file contains the class implementation of the class. 
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/176735/mod_assign/introattachment/0/CYA_1920_Practica_6.pdf?forcedownload=1
 * Revision history:
 *                27/10/2019 - Creation (first version) of the code
 */


#include "DFA.h"

DFA::DFA(std::string& inputFile) {
  read&buildDFA(inputFile);
}


DFA::~DFA() {}

/**
* Reads the input file with the DFA definition and build the automaton 
* from the read data
*/
void DFA::read&buildDFA(std::string& dfaDefinition) {
  std::ifstream inputFile;
  inputFile.open(dfaDefintion);

  if (!inputFile.is_open()) {
    std::cerr << "There was a problem opening the input file, "
    std::cerr << "please, try it again." << NEWLINE;
  }
  else {
   std::string readed;      //!< Stores what is read every time we read a line from the file

   std::getline(inputFile, readed);

   bool isComment1 = readed[0] == SLASH;
   bool isComment2 = readed[1] == SLASH;
   bool noEndComment = readed != ENDOFCOMMENTS; // ENDOFCOMMENTS = "////" means the end of comments
  
  //================================================
  // Reading header comments
  //================================================
   while (isComment1 && isComment2 && noEndComment) {
     comments_.push_back(readed);
     readed.clear();
   }
   
   if (readed == ENDOFCOMMENTS)
     readed.clear();
   
   else {
     int tempN;  //!< Used for store the amounts (alpabet symbols, states, etc.)
     std::getline(inputFile, readed);
     temp = stoi(tempN);
     readed.clear();
     
     //=============================
     // Reading the alphabet symbols
     //=============================
     char auxChar;

     for (int i = 0; i < temp; ++) {
       std::getline(inputFile, readed);
       auxChar = readed[0];
       alphabet_.insertAlphabet(auxChar);
       readed.clear();
     }

     //==============================
     // Reading states of the DFA
     //==============================

     


   }
  }
}
