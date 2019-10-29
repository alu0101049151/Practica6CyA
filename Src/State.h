/**
 * @Author Basilio Gómez Navarro
 * @date 27/10/2019
 * University of La Laguna
 * Higher School of Engineering and Technology
 * Computer Ingineering Degree
 * Grade: 2nd
 * Practice 6 - Deterministic Finite Automaton
 * Email: alu0101049151@ull.edu.es
 * State.h file: State class. It represents a state of a 
 *               Deterministic Finite Automaton.
 *               This file contains the class definition.
 * References:
 *                Practice statement:
 *                https://campusvirtual.ull.es/1920/pluginfile.php/176735/mod_assign/introattachment/0/CYA_1920_Practica_6.pdf?forcedownload=1
 * Revision history:
 *                27/10/2019 - Creation (first version) of the code
 */

#ifndef PRACTICE6_STATE_H
#define PRACTICE6_STATE_H

#include <set>
#include <string>

#include "Transition.h"

class State {
	
	public:
		State(std::string stateId);
		State(const State& state);
		~State();

		std::string getStateId() const;
		int transitionsNumber() const;
		std::set<Transition> getTransitions() const;

		/**
		 * @brief Inserts a new transition into the transtions set of a state.
		 * @param transition new transnition to insert.
		 */
		void insertTransitions(Transition transition);

		int operator< (const State& state) const;

	private:
		std::string stateId_;               //!< State Identifier.
		int  transitionsNumber_;           //!< Number of state transitions.
		std::set<Transition> transitions_; //!< Transitions of the state.
};


#endif //PRACTICE6_STATE_H

