/**
 * @Author Basilio Gómez Navarro
 * @date 27/10/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 6 - Deterministic Finite Automaton
 * Email: alu0101049151@ull.edu.es
 * Transition.h file: Transition class. It represents a transition between the
 *                    current state and another state of the automaton. The 
 *                    destination depends on the entry that reaches the current 
 *                    state. This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/176735/mod_assign/introattachment/0/CYA_1920_Practica_6.pdf?forcedownload=1
 * Revision history:
 *                27/10/2019 - Creation (first version) of the code
 */

#ifndef PRACTICE6_TRANSITION_H
#define PRACTICE6_TRANSITION_H

class Transition {

	public:
		Transition(char input, int destination);
		Transition(const Transition& transition);
		~Transition();

		char getInput() const;
		int getDestination() const;

		int operator< (const Transition& transition) const;

	private:
		char input_;          //!< Input symbol that determines the state to which transit the current state
		int  destination_;    //!< Id of the destination state to which it transits with "input_"
};

#endif //PRACTICE6_TRANSITION_H
