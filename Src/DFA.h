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
 *             This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/176735/mod_assign/introattachment/0/CYA_1920_Practica_6.pdf?forcedownload=1
 * Revision history:
 *                27/10/2019 - Creation (first version) of the code
 */


#ifndef PRACTICE6_DFA_H
#define PRACTICE6_DFA_H

#include <vector>
#include <sstream>

#include "Alphabet.h"
#include "State.h"

const char NEWLINE='\n';
const char SLASH='/';
const std::string ENDOFCOMMENTS="////";


class DFA {
	public:
    DFA(std::string& inputFile);
    ~DFA();

    void setStartState(std::string& startState);

	protected: 
    /**
    * @brief read the input file and builds the DFA
    * @param inputFile is the name of the input file.
    */
    void readAndBuildDFA(std::string& dfaDefinition);

	private:
		std::string startState_;              //!< Is the boot state.
		std::set<State> states_;             //!< Set with all the states of the DFA.
		std::set<std::string> finalStates_;  //!< Set of id's of the final states.
		Alphabet alphabet_;                  //!< Alphabet of the DFA.
    std::vector<std::string> comments_;  //!< Stores all the comments at the
                                         //!< beginning of the file.

};
#endif //PRACTICE6_DFA_H

