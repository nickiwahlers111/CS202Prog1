
/**********************************************

Name: Nicki Wahlers
CS202
Program 1

*********************************************/


/***************
client.cpp
this file runs the main function
the main driver of the program

**************/

#include "activity.h" 
#include "week.h" 


const int MAX = 500;
int main(){

	//START ACTUAL MAIN HERE DELETE ABOVE WHEN DONE

	week my_week; //instance of week class. creates a week 
	int response; //constrols switch statement
	int num1, num2, num3; //temp numbers used to enter in user responses
	char temp[MAX], temp2[MAX]; //temporary char arrays to hold user responses
	bool distracted_enter, feelings; //user responses
	char again = 'Y'; //controls do while loop

	int weekday = 0;

	cout << "Welcome to Week Planner" << endl;
	do{

		cout << "Lets create an activity!" << endl;
		cout << "Would you like to add, " << endl;
		cout << "1. Study Session" << endl;
		cout << "2. Workout Session" << endl;
		cout << "3. Relax Session" << endl;

		cout << " Enter: ";
		cin >>response;
		cin.ignore(100, '\n');

		switch(response) 
		{
			case 1:
				{
					cout << "OK Lets create a Study Session" << endl;
					cout << "Enter 'Study': ";
					cin.get(temp, 100, '\n');
					cin.ignore(100, '\n');

					cout << "What is the start time: ";
					cin >> num1;
					cin.ignore(100, '\n');

					cout << "What is the end time: ";
					cin >> num2;
					cin.ignore(100, '\n');

					cout << "What is the total time: ";
					cin >> num3;
					cin.ignore(100, '\n');

					activity my_activity(temp, num1, num2, num3);

					cout << "What subject will you study: ";
				cin.get(temp, 100 ,'\n');
					cin.ignore(100, '\n');

					cout << "Do you anticipate being distracted (1-yes, 0-no): ";
					cin >> distracted_enter;
					cin.ignore(100, '\n');

					cout << "What is your despair level about the material you need to study(1-10): ";
					cin >>num1;

					study my_study(my_activity, temp, distracted_enter, num1);


					cout << endl << endl;
					cout << "Ok we have created a study session. Now lets add it to a day of this week" << endl;
					cout << "Enter a day to work with" << endl;
					cout << "Enter 0-Monday 6-Sunday: ";
					cin >> weekday;
					cin.ignore(100, '\n');
					
					cout << "Ok lets add this study to that day " << endl;

					my_week.add_study(my_study, weekday);

					if(num1 > 5){
						my_study.get_tutor_help();
						my_study.get_karla_help();
						my_study.encouragement();	
						my_study.suggestion();
					}

					cout << endl << endl;


					break;
				}
			case 2: 
				{
					cout << "OK Lets create a Workout Session" << endl;
					cout << "Enter 'Workout': ";
					cin.get(temp,100, '\n');
					cin.ignore(100, '\n');

					cout << "What is the start time: ";
					cin >> num1;
					cin.ignore(100, '\n');

					cout << "What is the end time: ";
					cin >> num2;
					cin.ignore(100, '\n');

					cout << "What is the total time: ";
					cin >> num3;
					cin.ignore(100, '\n');

					activity my_activity(temp, num1, num2, num3);

					cout << "Where did this workout take place: ";
					cin.get(temp, 100, '\n');
					cin.ignore(100, '\n');

					cout << "What type of workout was this(cardio, strength, etc): ";
					cin.get(temp2, 100, '\n');
					cin.ignore(100, '\n');

					cout << "Finally, how many miles did you run: ";
					cin >>num1;

					workout my_workout(my_activity, temp, temp2, num1);

					cout << endl << endl;
					cout << "Ok we have created a workout. Now lets add it to a day of this week" << endl;
					cout << "Enter a day to work with" << endl;
					cout << "Enter 0-Monday 6-Sunday: ";
					cin >> weekday;
					cin.ignore(100, '\n');

					cout << "Ok lets add this workout to that day " << endl;
					my_week.add_workout(my_workout, weekday);					

					my_workout.gold_star();
					my_workout.water();
					my_workout.website();



					break;
				}
			case 3: 
				{
					cout << "Ok lets create a relax session" << endl;

					cout << "enter 'Relax': " << endl;
					cin.get(temp, 100, '\n');
					cin.ignore(100, '\n');

					cout << "what is the start time: ";
					cin >> num1;
					cin.ignore(100, '\n');

					cout << "What is the end time: ";
					cin >> num2;
					cin.ignore(100, '\n');

					cout << "What is the total time: ";
					cin >>num3;
					cin.ignore(100, '\n');

					activity my_activity(temp, num1, num2, num3);

					cout << "Enter any notes about this relaxation session: ";
					cin.get(temp, 100, '\n');
					cin.ignore(100, '\n');

					cout << "How do you feel going in to this session(0-bad, 1-good): ";
					cin >> feelings;
					cin.ignore(100, '\n');

					relax my_relax(my_activity, temp, feelings);

					cout << endl << endl;
					cout << "Ok we have created a relax session. Now lets add it to a day of this week" << endl;
					cout << "Enter a day to work with" << endl;
					cout << "Enter 0-Monday 6-Sunday: ";
					cin >> weekday;
					cin.ignore(100, '\n');

					cout << "Ok lets add this relax session to that day " << endl;

					my_week.add_relax(my_relax, weekday);

					my_relax.meditate();
					my_relax.walk();
					my_relax.see_friends();
					
					if(weekday > 4){
						my_relax.drink();
					}


					break;
				}
		}

		cout << "Shall we add another activity(y/n): ";
		cin >>again;
		cin.ignore(100, '\n');
	}while(toupper(again) == 'Y');

	cout << endl << endl;
	cout << " Ok now that you're done entering activities, lets display all of your plans for the week " << endl;
	my_week.display_week();




	return 0;
}
