/**********************************************

Name: Nicki Wahlers
CS202
Program 1

*********************************************/

/*****************
activity.h file. 
holds class interfaces for all functions derived from activity
activity, workout, relax, study, workout_node, relax_node, study_node
****************/

#ifndef ACTIVITY_H
#define ACTIVITY_H



#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

/***************************************
Activity class
base for all activities
***************************************/
class activity
{
	public:
		activity(); //default constructor
		~activity(); //destructor
		activity(const activity & to_copy); //copy constructor does this need to be a bool func
		activity(char * name_add, int start_add, int end_add, int time_add); //constructor to initialize data members
		
		void change_name(char * to_enter); //function to update the name of the actiivty
		void change_start(int start_time); //function to update start time
		void change_end(int end_time); //function to update end time
		void change_time(int total_time); //function to update total time

		void display(); //display function. displays one activity

	protected:
		char * name; //name of activity: workout, relax, study
		int start; //start time of activity
		int end; // end time of activity
		int time; //total time of activity
};

/*************************************
relax class
derived from activity class
relax IS activity + more
**************************************/
class relax: public activity
{
	public:
		relax(); //default constructor
		~relax(); //destructor
		relax(const relax &); //copy constructor
		relax(const activity &, char * notes, bool feel_better); //constructor to initialize member data with passed in info

		void display(); //display function that displays one relax
		void meditate(); //displays meditation tips
		void walk(); //suggests going for a walk
		void drink(); //suggest a drink
		void see_friends(); //suggest hanging with friends socially distant
			

	protected:
		char * notes; //what did you do to relax
		bool feel_better; //yes or no


};



/*********************************
relax node class
derived from relax
**********************************/

class relax_node: public relax
{
	public:
		relax_node(); //relax node constructor
		relax_node(const relax&); //relax node constructor to initialize relax

		relax_node *& go_prev(); //go to the previous node`
		relax_node *& go_next(); //go to the next node
		void connect_prev(relax_node * connection); //connect current nodes previous pointer to a passed in node
		void connect_next(relax_node * connection); //connect current nodes next pointer to a passed in node

	protected:
		relax_node * prev; //previous pointer
		relax_node * next; //next pointer

};


/*********************************
workout class
derived from activity
IS A activity + more
********************************/

class workout: public activity
{
	
	public:
		workout(); //default constructor
		~workout(); //destructor
		workout(const workout &); //copy constructor
		workout(const activity &, char * location_add, char * type_add, int miles_add); //constructor to initlialize data members with passed in info

		
		void update(char * location_add, char * type_add, int miles); //unused function
		void display(); //displays one object
		void gold_star(); //returns a gold star for every hour of workout time
		void water(); //reminder to drink water
		void website(); //links to a website for workout suggestions


	protected:
		char * location; //location where the workout took place`
		char * type; //cardio or lifting
		int miles_ran;  //how many miles you plan on running
};


/*********************************
workout node class
derived from workout class
IS A workout + more
*********************************/
class workout_node: public workout
{
	public:
		workout_node(); //workout node default constructor
		workout_node(const workout & set); //constructor to initialize workout

		workout_node *& go_prev(); //traverses previous
		workout_node *& go_next(); //traverses next
		void connect_prev(workout_node * connection); //connect nodes previous to passed in node
		void connect_next(workout_node * connection); //connect nodes next to passed in node

	protected:
		workout_node * prev; //previous pointer
		workout_node * next; //next pointer
};



/*******************************
study node 
derived from activity
IS A activity + more
*******************************/

class study: public activity
{
	public:
		study(); //default constructor 
		~study(); //destructor
		study(const study &); //copy constructor
		study(const activity & to_add, char * subject_add, int distracted_add, int despair_add); //constructor to initialize parent

		void update(char * new_subject, bool was_distracted, int despair_level); //used to update study
		void display(); //display object
		void get_tutor_help(); //output tutor info
		void get_karla_help(); //output info on how to get help with karla 
		void encouragement(); //output encouragement
		void suggestion(); //suggest adding a relaxation

	protected:
		char * subject; //subject info
		bool distracted; //distracted or not
		int despair_level; //1-10

};



/******************************
study node class
derived from study class
IS A study plus more
*****************************/

class study_node: public study
{
	public:
		study_node(); //constructor
		study_node (const study & set); //initialize study

		study_node *& go_prev(); //traverse previous
		study_node *& go_next(); //traverse next
		void connect_prev(study_node * connection); //connect current node to previous to passed in node
		void connect_next(study_node * connection); //connect current node next to passed in node

	protected:
		study_node * prev; //previous pointer
		study_node * next; //next pointer
};




#endif
