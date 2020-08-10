
/**********************************************

Name: Nicki Wahlers
CS202
Program 1

*********************************************/

/******************
week.h
holds all of the class interfaces that run the data structure

week manages the array
day manages the doubly linked lists
*****************/

#ifndef WEEK_H
#define WEEK_H

#include "activity.h"

/********************

menu class
manages all of the functions that run main

********************/

class menu
{
	public:
		menu();


		int day_menu();
		int workout_menu();
		int relax_menu();
		int study_menu();

	protected:

};


/***********************

day class
manages three DLLs
contains pointers to these heads 

***********************/
class day 
{
	public:
		day(); //constructors
		~day(); //call destroy_lists();

		void destroy_w_list(workout_node *& w_head); //delete lists, set heads to NULL
		void destroy_s_list(study_node *& s_head);
		void destroy_r_list(relax_node *& r_head);

		void destroy_w_list(); //destroy list wrappers
		void destroy_s_list();
		void destroy_r_list();

		bool set_relax(relax &); //add relax node to day
		bool set_workout(workout &); //add workout node to day
		bool set_study(study &); //add study node to day

		void display_day() const; //display three lists 

		void display_w_list() const; //wrapper for display workout list
		void display_w_list(workout_node * w_head)const; //recursively display a list

		void display_s_list() const;
		void display_s_list(study_node * s_head) const;

		void display_r_list() const;
		void display_r_list(relax_node * r_head) const;



		bool copy_activity(); //copy function
		bool edit_activity(); //update and edit function
		bool delete_activity(); //delete an activity

	protected:
		relax_node * r_head; //head pointer for relax node list
		workout_node * w_head; //head pointer for workout node list
		study_node * s_head; //head pointer for study node list
		int day_num; //which day of the week are we in 0-monday 7-sunday
		int gold_star; //gold star 

};

class week
{
	public:
		week(); //constructor
		~week(); // delete a_week set to NULL

		bool add_workout(workout & to_set, int what_day); //add a wrokout to the week
		bool add_study(study & to_set, int what_day); //add a study to the week
		bool add_relax(relax & to_set, int what_day); //add a relax to the week

		void display_week(int & control) const; //recurviselt go through array and call day displays
		void display_week(); //wrapper for display

	protected:
		day * a_week; //pointer to an array of days
		int size; //size of array
};




#endif
