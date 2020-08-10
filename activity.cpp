
/**********************************************

Name: Nicki Wahlers
CS202
Program 1

*********************************************/


/**********************************************

This is the activity.cpp file.
maintains all of the function definitions for the activity classes
and resulting derived classes of activity.

**********************************************/


#include "activity.h" 


/***************

default constructor
initialize data members

****************/

activity::activity(): name(NULL), start(0), end(0), time(0)
{
}

/**************

constructor to initialize w/ entered data

**************/

activity::activity(char * name_add, int start_add, int end_add, int time_add): 
	start(start_add), 
	end(end_add), 
	time(time_add)
{
	name = new char [strlen(name_add) + 1];
	strcpy(name, name_add);
}

/****************

copy constructor 
used b/c activity has dynamic memory

****************/

activity::activity(const activity & to_copy)
{
	if(!to_copy.name)
		name = NULL;	

	name = new char[strlen(to_copy.name) + 1];
	strcpy(name, to_copy.name);

	start = to_copy.start;
	end = to_copy.end;
	time = to_copy.time;
}


/***************

activity destructor
release dynamic memory

****************/

activity::~activity(){
	if(name){
		delete [] name;
		name = NULL;
	}
}


/*****************
activity display function
*****************/

void activity::display()
{
	cout << "ACTIVITY NAME: " << name << endl;
	cout << "START TIME: " << start << endl;
	cout << "END TIME: " << end << endl;
	cout << "TOTAL TIME: " << time << endl;
}

/****************
activity update name function
****************/

void activity::change_name(char * change)
{
	if(name)
		delete name;
	
	name = new char[strlen(change) + 1];
	strcpy(name, change);
}

/*************
activity update start time
************/

void activity::change_start(int change)
{
	start = change;
}


/************
activity update end time
************/

void activity::change_end(int change)
{
	end = change;
}

/***********
activity update total time 
***********/

void activity::change_time(int change)
{
	time = change;
}



/******************************START WORKOUT SECTION*************************/



/***************

workout default constructor
set members to NULL

***************/

workout::workout(): location(NULL), type(NULL), miles_ran(0)
{

}


/**************

workout copy constructor

**************/

workout::workout(const workout & to_copy): activity(to_copy)
{
	if(!to_copy.location)
		location = NULL;

	if(!to_copy.type)
		type = NULL;

	location = new char[strlen(to_copy.location) + 1];
	strcpy(location, to_copy.location);

	type = new char[strlen(to_copy.type) + 1];
	strcpy(type, to_copy.type);
	
	miles_ran = to_copy.miles_ran;

}

/***************

constructor with args to initalize workout node

**************/

workout::workout(const activity & to_add, char * location_add, char * type_add, int miles_add): 
	activity(to_add),
	miles_ran(miles_add)
{
	location = new char[strlen(location_add) + 1];
	strcpy(location, location_add);

	type = new char[strlen(type_add) + 1];
	strcpy(type, type_add);
}

/*************

workout destructor
release dynamic memory

**************/

workout::~workout()
{
	if(location){
		delete [] location;
		location = NULL;
	}

	if(type){
		delete [] type;
		type = NULL;
	}
}

/**************

workout display function

**************/

void workout::display()
{
	activity::display();
	cout << "LOCATION: " << location << endl;
	cout << "WORKOUT TYPE: " << type << endl;
	cout << "MILES RAN: " << miles_ran << endl;
}




/**************
gold star
displays a gold star message if workout exceeds two hours
**************/

void workout::gold_star()
{
	cout << "CONGRATS ON YOUR WORKOUT! YOU GET A GOLD STAR" << endl;
	return;
}

/*************
water reminder
*************/

void workout::water()
{
	cout << "Remember to replenish and drink lots of water after this workout! " << endl;
}


/**************
website
************/

void workout::website()
{
	cout << "check out these websites for cool workout suggestions: " << endl;
	cout << "www.workout.com" << endl;
	cout << "nike.com/ntc-app" << endl;
	cout << "You got this! " << endl;
}

/***************

workout node default constructor
set data members to NULL

***************/

workout_node::workout_node(): prev(NULL), next(NULL)
{
}


/**************

workout node constructor for set

*************/

workout_node::workout_node(const workout & set): workout(set), prev(NULL), next(NULL)
{
}





/***********

go next function
return workout node *
gets address of next node

*************/

workout_node *& workout_node::go_next()
{
	return next;
}


/***********

go previous function
return workout node *
gets address of previous node

*************/

workout_node *& workout_node::go_prev()
{
	return prev;
}


/*************

connect next function
takes in pointer to a node
connects next to that node

**************/

void workout_node::connect_next(workout_node * to_connect)
{
	next = to_connect;
}


/*************

connect previous function
takes in pointer to a node
connects previous to that node

**************/

void workout_node::connect_prev(workout_node * to_connect)
{
	prev = to_connect;
}



/************************************START STUDY SECTION***********************************/

/***************
study default constructor
set data members to NULL value
***************/

study::study():subject(NULL), distracted(0), despair_level(0)
{
}

/*************

study copy constructor

*************/

study::study(const study & to_copy): activity(to_copy)
{
	if(!to_copy.subject)
		subject = NULL;

	subject = new char[strlen(to_copy.subject) + 1];
	strcpy(subject, to_copy.subject);

	distracted = to_copy.distracted;
	despair_level = to_copy.despair_level;

}

/**********

study constructor with args to fill study

************/
study::study(const activity & to_add, char * subject_add, int distracted_add, int despair_add):
	activity(to_add),
	distracted(distracted_add),
	despair_level(despair_add)
{
	subject = new char [strlen(subject_add) + 1];
	strcpy(subject, subject_add);
}

/***********

study destructor
releases dynamic

***********/

study::~study(){
	if(subject){
		delete subject;
		subject = NULL;
	}
}

/*************
display study node
************/

void study::display(){
	activity::display();
	cout << "SUBJECT: " << subject << endl;
	if(distracted){
		cout << "WE WERE DISTRACTED" << endl;
	}
	else{
		cout << "GOOD STUDY SESH, NOT DISTRACTED " << endl;
	}

	cout << "DESPAIR LEVEL: " << despair_level << endl;
	
}


/*****************
outputs info on how to get help from a tutor
****************/


void study::get_tutor_help(){
	cout << endl << endl;
	cout << "SOUNDS LIKE YOU NEED HELP FROM A TUTOR" << endl;
	cout << "HERE IS THE SCHEDULE FOR TCSS HOMEWORK RECITATION: " << endl;
	cout << "MONDAY 2-3:50" << endl;
	cout << "TUESDAY 2-5:50 " << endl;
	cout << "WEDNESDAY 2-3:50 " << endl;
	cout << "THURSDAY 2-5:50" << endl;
	cout << "FRIDAY 12-3:50" << endl;

	cout << "CHECK CANVAS FOR ZOOM ID AND PASSWORD; " << endl;

	cout << endl;
	cout << "GOOD LUCK YOU GOT THIS" << endl << endl;
}
/******************
outputs advice to go get help from karla
*****************/
void study::get_karla_help()
{
	cout << "Karla is usually available to help via email or slack" << endl;
	cout << "So as she always says GO THERE and get some help!" << endl;
}



/*****************
outputs words of encouragement

*****************/
void study::encouragement()
{
	cout << "YOU GOT THIS!! WOOHOO!! CS202 IS NOT IMPOSSIBLE " << endl;
}


/**************

suggests that the user add a relax session next

************/
void study::suggestion()
{
	cout << "Since your despair level was so high maybe you should schedule a relax session for this day next" << endl;
}



/*************

study node default constructor

*************/

study_node::study_node():prev(NULL), next(NULL)
{
}

/*************

studynode constructor to set study

************/

study_node::study_node(const study & set): study(set), prev(NULL), next(NULL)
{
}


/***********

go next function
return study node *&
gets address of next node

*************/

study_node *& study_node::go_next()
{
	return next;
}


/***********

go previous function
return study node *&
gets address of next prev

*************/

study_node *& study_node::go_prev()
{
	return prev;
}


/*************

connect next function
takes in pointer to a node
connects next to that node

**************/

void study_node::connect_next(study_node * to_connect)
{
	next = to_connect;
}



/*************

connect prev function
takes in pointer to a node
connects prev to that node

**************/

void study_node::connect_prev(study_node * to_connect)
{
	next = to_connect;
}

/************************************RELAX SECTION************************/

/************
default constructor
************/

relax::relax():notes(NULL), feel_better(0)
{
}

/***********
copy constructor
***********/
relax::relax(const relax & to_copy): activity(to_copy)
{
	if(!to_copy.notes)
		notes = NULL;
	
	notes = new char[strlen(to_copy.notes) + 1];
	strcpy(notes, to_copy.notes);

	feel_better = to_copy.feel_better;
}

/*************
constructor with args
initialize parent class
and data members
*************/

relax::relax(const activity & to_add, char * notes_add, bool feeling_add): 
	activity(to_add),
	feel_better(feeling_add)
{
	notes = new char[strlen(notes_add) + 1];
	strcpy(notes, notes_add);
}


/**************
destructor
release dynamic memory
**************/

relax::~relax()
{
	if(notes){
		delete [] notes;
		notes = NULL;
	}
}

/*************
relax display
*************/

void relax::display()
{
	activity::display();

	cout << "NOTES ABOUT THIS RELAX SESH: " << notes << endl;
	if(feel_better){
		cout << "WE ARE FEELING BETTER" << endl;
		}
	else{
		cout << "WE ARE NOT FEELING BETTER" << endl;
	}
}

/**************
guided meditation
**************/

void relax::meditate()
{

	cout << "Here are some quick tips for a successful meditation session that might help " << endl;
	cout << "Make sure you are siting in a comfortable position where you can rest without fidgeting " << endl;
	cout << "Take deep breaths in through your nose and out through your mouth" << endl;
	cout << "Try not to focus on any one thing" << endl;
	
}

void relax::walk()
{
	cout << endl << endl;
	cout << "Another great way to relax is to take a walk! " << endl;
}

/*************
drink
************/

void relax::drink()
{
	cout << endl << endl;
	cout << "One way to unwind at the end of the week is a cold (or warm if thats your jam) drink!" << endl;
}

/**************
suggest seeing friends
socially distant of course
**************/

void relax::see_friends()
{
	cout << endl << endl;
	cout << "One option is to go see some friends " << endl;
	cout << "Socially distant of course" << endl;

}


/*************
relax_node constructor
*************/

relax_node::relax_node(): prev(NULL), next(NULL)
{
}

/************
relax node constructor to set relax
***********/

relax_node::relax_node(const relax & set): relax(set), prev(NULL), next(NULL)
{
}


/***********

go next function
return study node *&
gets address of next node

*************/

relax_node *& relax_node::go_next()
{
	return next;
}


/***********

go previous function
return study node *&
gets address of next node

*************/

relax_node *& relax_node::go_prev()
{
	return prev;
}


/*************

connect next function
takes in pointer to a node
connects next to that node

**************/

void relax_node::connect_next(relax_node * to_connect)
{
	next = to_connect;
}


/*************

connect next function
takes in pointer to a node
connects next to that node

**************/

void relax_node::connect_prev(relax_node * to_connect)
{
	next = to_connect;
}


