


/***********************

This is the week.cpp file
Manages all function implementations for
week class, day class
manager of data structure.

*************************/

#include "week.h" 


/*******************MENU SECTION****************/

/***********

default constructor

***********/

menu::menu(){

}


/***********

  menu for what you can do with day class

 ************/

int menu::day_menu()
{

	cout << "OK for today, would you like to: " << endl;
	cout << "1. Add Workout " << endl;
	cout << "2. Add Study" << endl;
	cout << "3. Add Relax " << endl;
	cout << "4. Display Day" << endl;
	cout << "5. Delete Activities for today" << endl;
	cout << "6. Return to week " << endl;

	int response;

	cout << "Enter: ";
	cin >> response;
	cin.ignore(100, '\n');

	return response;
}


/***********

  menu for what you can do with relax 

 ***********/

int menu::relax_menu()
{
	cout << "OK now that you have created a relax session what would you like to do: " << endl;
	cout << "1. Meditation tips" << endl;
	//TODO ADD MORE AS I FIGURE OUT MEMBER FUNCTIONS

	int response;

	cout << "Enter: ";
	cin >> response;
	cin.ignore(100, '\n');

	return response;

}

/*************

  menu for what you can do with workout class

 *************/

int menu::workout_menu()
{
	cout << "OK now that youve created a workout session, what would you like to do: " << endl;
	cout << "1. " << endl;

	//TODO ADD MORE AS I FIGURE OUT MEMBER FUNCTIONS

	int response;

	cout << "Enter: ";
	cin >> response;
	cin.ignore(100, '\n');

	return response;
}

/************

  menu for what you can do with study

 ***********/

int menu::study_menu()
{
	cout << "OK now that you've created a workout session, what would you like to do: " << endl;
	cout << "1. " << endl;

	int response;

	cout << "Enter: ";
	cin >> response;
	cin.ignore(100, '\n');

	return response;
}


/*******************WEEK SECTION*****************/

/************

  week constructor
  sets an array of days

 ************/

week::week(){
	a_week = new day[7];	
}



/***********

  week destructor

 ************/

week::~week()
{
	if(a_week){
		delete [] a_week;
		a_week = NULL;
	}
}


/*************

  add workout function
  client calls this to access day and a workout for that day
  returns bool true/false for if it was successful

 **************/

bool week::add_workout(workout & to_set, int what_day)
{


	if(a_week[what_day].set_workout(to_set))
		return true;
	return false;
}



/**************

  add study function
  client calls this to access day and a study for that day
  returns bool true/false for if it was successful

 ***************/

bool week::add_study(study & to_set, int what_day)
{

	if(a_week[what_day].set_study(to_set))
		return true;
	return false;
}


/***************

  add rekax function
  client calls this to access day and a relax for that day
  returns bool true/false for if it was successful

 **************/

bool week::add_relax(relax & to_set, int what_day)
{
	if(a_week[what_day].set_relax(to_set))
		return true;
	return false;
}


/**************
  display week 
  recursively work through week array
 **************/
void week::display_week(){
	int	control = 0;
	display_week(control);
}

void week::display_week(int & control)const
{
	if(control == 7){
		control = 0;
		return;
	}
	cout << "DAY " << control << endl;
	a_week[control].display_day();
	++control;
	return display_week(control);
}



/*******************DAY SECTION*****************/

day::day(): r_head(NULL), w_head(NULL), s_head(NULL), day_num(0), gold_star(0)
{

}


day::~day()
{
	destroy_w_list(w_head);
	destroy_s_list(s_head);
	destroy_r_list(r_head);
}


/**********

  destroy lists in each day

 **********/

void day::destroy_w_list(workout_node *& w_head)
{
	if(!w_head)
		return;

	workout_node * temp = w_head -> go_next();
	delete w_head;
	w_head = temp;

	destroy_w_list(w_head);
}


void day::destroy_s_list(study_node *& s_head)
{
	if(!s_head)
		return;

	study_node * temp = s_head -> go_next();
	delete s_head;
	s_head = temp;

	destroy_s_list(s_head);
}

void day::destroy_r_list(relax_node *& r_head)
{
	if(!r_head)
		return;
	relax_node * temp = r_head -> go_next();
	delete r_head;
	r_head = temp;

	destroy_r_list(r_head);
}


/*************
add activities to days
************/

bool day::set_workout(workout & to_set)
{

	if(!w_head){
		w_head = new workout_node(to_set);
		return true;
	}

	else{
		workout_node * test_node = new workout_node(to_set);
		test_node -> connect_next(w_head);
		w_head -> connect_prev(test_node);
		return true;
	}
	return false;
}

bool day::set_study(study & to_set)
{
	if(!s_head){
		s_head = new study_node(to_set);
		return true;
	}

	else{
		study_node * test_node = new study_node(to_set);	
		test_node -> connect_next(s_head);
		s_head -> connect_prev(test_node);
		return true;
	}	
	return false;
}

bool day::set_relax(relax & to_set)
{
	if(!r_head){
		r_head = new relax_node(to_set);
		return true;
	}

	else{
		relax_node * test_node = new relax_node(to_set);
		test_node -> connect_next(r_head);
		r_head -> connect_prev(test_node);
		
		return true;
	}
	return false;
}

/************

  display all lists in one day

 ************/

void day::display_day() const
{
	display_w_list();
	display_s_list();
	display_r_list();
	return;
}

/**********
  wrapper for recursive display list for workout
 *********/

void day::display_w_list() const
{
	return display_w_list(w_head);
}

/***********
  recursively workout display list
 ***********/

void day::display_w_list(workout_node * w_head) const
{
	if(w_head){
		w_head -> display();
		return display_w_list(w_head -> go_next());
	}

	return;
}

/***********
  wrapper for recursive display list for study
 ***********/

void day::display_s_list() const
{
	return display_s_list(s_head);
}

/***********
  recursvely display study list
 ***********/

void day::display_s_list(study_node * s_head) const
{
	if(s_head){
		s_head -> display();
		return display_s_list(s_head -> go_next());
	}

	return;
}

/***********
  wrapper for recursive display list for relax
 ***********/

void day::display_r_list() const
{
	return display_r_list(r_head);
}


/**********
  recursively display relax list
 *********/

void day::display_r_list(relax_node * r_head) const
{
	if(r_head){
		r_head -> display();
		return display_r_list(r_head -> go_next());
	}

	return;
}













