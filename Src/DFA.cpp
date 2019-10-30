/**
 * @Author Basilio Gómez Navarro
 * @date 27/10/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 6 - Deterministic Finite Automaton
 * Email: alu0101049151@ull.edu.es
 * DFA.cpp file: DFA class. It represents a Deterministic Finite Automaton.
 *               This file contains the class implementation of the class. 
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/176735/mod_assign/introattachment/0/CYA_1920_Practica_6.pdf?forcedownload=1
 * Revision history:
 *                27/10/2019 - Creation (first version) of the code
 */


#include "DFA.h"

DFA::DFA(std::string& inputFile) {
  readAndBuildDFA(inputFile);
}


DFA::~DFA() {}

/**
* Reads the input file with the DFA definition and build the automaton 
* from the read data
*/
void DFA::readAndBuildDFA(std::string& dfaDefinition) {
  std::ifstream inputFile;
  inputFile.open(dfaDefinition);

  if (!inputFile.is_open()) {
    std::cerr << "There was a problem opening the input file, ";
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
     int temp;  //!< Used for store the amounts (alpabet symbols, states, etc.)
                //!< temporarily
     
     //================================
     // Reading the alphabet symbols
     //================================

     
     std::getline(inputFile, readed);  // Read the number of alphabet symbols
     temp = stoi(readed);
     readed.clear();
     char auxChar;

     for (int i = 0; i < temp; i++) {
       std::getline(inputFile, readed); 
       auxChar = readed[0];
       alphabet_.insertAlphabet(auxChar);
       readed.clear();
     }

     //==============================
     // Reading of DFA states
     //==============================

     std::getline(inputFile, readed);  // Read the number of automaton states.
     temp = stoi(readed); 
     readed.clear();

     for (int i = 0; i < temp; ++i) {
       std::getline(inputFile, readed);
       State auxState(readed);
       states_.insert(auxState);
       readed.clear();
     }

     //==============================
     // Reading of start state
     //==============================

     std::getline(inputFile, readed); // Read the star state.
     startState_ = readed;
     readed.clear();

     //==============================
     // Reading final states
     //==============================

     std::getline(inputFile, readed); // Read the number of final states.
     temp = stoi(readed);
     readed.clear();

     for (int i = 0; i < temp; ++i) {
       std::getline(inputFile, readed);
       finalStates_.insert(readed);
       readed.clear();
     }

     //================================
     // Reading automaton transitions
     //================================

     std::getline(inputFile, readed); // Read the number of transitions.
     temp = stoi(readed);
     readed.clear();

     std::string auxCurrentSate;
     std::string auxInput;
     std::string auxDestination;
     
     for (int i = 0; i < temp; ++i) {
       std::getline(inputFile, readed);
       std::stringstream iss(readed);
       iss >> auxCurrentSate;

       bool found = false;
       std::set<State>::iterator it = states_.begin();
       while (it != states_.end() && !found) {
         if ((*it).getStateId() == auxCurrentSate) {
           found = true;
           iss >> auxInput;
           iss >> auxDestination;
           
           Transition auxTransition(auxInput, auxDestination);
           (*it).insertTransitions(auxTransition);
         }
       }
     }
   }
  }
}


void DFA::setStartState(std::string& startState) {
  startState_ = startState;
}
