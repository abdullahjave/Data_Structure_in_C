#include<iostream>
using namespace std;

float average(float arr[],int length)
{
	int sum=0;
	for(int i=0;i<length;i++)
	{
		sum+=arr[i];
	}
	return sum/length;
}

int main()
{
	float gpa,total_marks,obtained_marks,quiz_assignment_total,thoery_mid,lab_mid,total_mid;
	int theory_assignments,credit_hours,quizzes,lab_assignments;
	string grade;
	while(1)
	{
		cout<<"ENTER CREDIT HOURS OF SUBJECT:";
		cin>>credit_hours;
		if(credit_hours <3 || credit_hours>4)
		{
			cout<<"THIS PROGRAM IS ONLY FOR 3 AND 4 CREDIT HOURS SUBJECTS."<<endl;
			continue;
		}
	
		cout<<"HOW MANY THEORY ASSIGMENTS HAVE BEEN DONE SO FAR:";
		cin>>theory_assignments;
	
		float assignment_marks[theory_assignments];
	
		for(int i=0;i<theory_assignments;i++)
		{
			cout<<"ENTER TOTAL MARKS OF ASSIGNMENT # "<<i+1<<" : ";
			cin>>total_marks;
			cout<<"ENTER OBTAINED MARKS OF ASSIGNMENT # "<<i+1<<" : ";
			cin>>obtained_marks;
			assignment_marks[i]=(obtained_marks/total_marks)*100;
		}
		float assignments_total=average(assignment_marks,theory_assignments) *0.10;
		//cout<<"assignments_total:"<<assignments_total<<endl;
	
		cout<<"HOW MANY QUIZZES HAVE BEEN DONE SO FAR:";
		cin>>quizzes;
	
		float quizzes_marks[quizzes];
	
		for(int i=0;i<quizzes;i++)
		{
			cout<<"ENTER TOTAL MARKS OF QUIZ # "<<i+1<<" : ";
			cin>>total_marks;
			cout<<"ENTER OBTAINED MARKS OF QUIZ # "<<i+1<<" : ";
			cin>>obtained_marks;
			quizzes_marks[i]=(obtained_marks/total_marks)*100;
		}
		float quizzes_total=average(quizzes_marks,quizzes) *0.15;
		//cout<<"quizzes_total:"<<quizzes_total<<endl;
		cout<<"ENTER TOTAL MARKS OF MIDTERM THEORY EXAMS: ";
		cin>>total_marks;
		cout<<"ENTER OBTAINED MARKS OF MIDTERM THEORY EXAMS: ";
		cin>>obtained_marks;
		thoery_mid=((obtained_marks/total_marks) * 100) * 0.25;
	
		if(credit_hours==4)
		{
			cout<<"HOW MANY LAB ASSIGMENTS HAVE BEEN DONE SO FAR:";
			cin>>lab_assignments;
	
			float lab_marks[lab_assignments];
	
			for(int i=0;i<lab_assignments;i++)
			{
				cout<<"ENTER TOTAL MARKS OF LAB ASSIGNMENT # "<<i+1<<" : ";
				cin>>total_marks;
				cout<<"ENTER OBTAINED MARKS OF LAB ASSIGNMENT # "<<i+1<<" : ";
				cin>>obtained_marks;
				lab_marks[i]=(obtained_marks/total_marks)*100;
			}
			float lab_total=average(lab_marks,lab_assignments) * 0.25;
			//	cout<<"lab_total:"<<lab_total;
			quiz_assignment_total=(lab_total * 0.3) + (quizzes_total * 0.7) + (assignments_total * 0.7);
			//cout<<"quiz_assignment_total:"<<quiz_assignment_total;
			cout<<"ENTER TOTAL MARKS OF MIDTERM LAB EXAMS: ";
			cin>>total_marks;
			cout<<"ENTER OBTAINED MARKS OF MIDTERM LAB EXAMS: ";
			cin>>obtained_marks;
			lab_mid=((obtained_marks/total_marks) * 100) * 0.25;
			//	cout<<"lab_mid:"<<lab_mid<<endl;
			total_mid = (lab_mid * 0.3) + (thoery_mid * 0.7);
			//	cout<<"total_mid:"<<total_mid<<endl;
		}
		else
		{
			quiz_assignment_total=quizzes_total+assignments_total;
			total_mid = thoery_mid ;
		}
		float total_percentage=(total_mid + quiz_assignment_total)*2;
		//cout<<"total_percentage:"<<total_percentage<<endl;
		if(total_percentage>=85)//85-100
		{
			grade = "A";
			gpa = 4.0;
		}
		else if(total_percentage>=80)//80-84
		{
			grade = "A-";
			gpa = 3.66;
		}
		else if(total_percentage>=75)//75-79
		{
			grade = "B+";
			gpa = 3.33;
		}
		else if(total_percentage>=70)//70-74
		{
			grade = "B";
			gpa = 3.0;
		}
		else if(total_percentage>=66)//66-69
		{
			grade = "B-";
			gpa = 2.66;
		}
		else if(total_percentage>=63)//63-65
		{
			grade = "C+";
			gpa = 2.33;
		}
		else if(total_percentage>=60)//60-62
		{
			grade = "C";
			gpa = 2.0;
		}
	
		else if(total_percentage>=57)//57-59
		{
			grade = "C-";
			gpa = 1.66;
		}
		else if(total_percentage>=54)//54-56
		{
			grade = "D+";
			gpa = 1.3;
		}
		else if(total_percentage>=50)//50-53
		{
			grade = "D";
			gpa = 1.0;
		}
		else
		{
			grade = "F";
			gpa = 0.0;
		}
		cout<<"TOTAL QUIZ/ASSIGNMENT MARKS: "<<quiz_assignment_total<<endl;
		cout<<"TOTAL MID TERM MARKS: "<<total_mid<<endl;
		cout<<"TOTAL PERCENTAGE SO FAR: "<<total_percentage<<endl;
		cout<<"GRADE OF THIS SUBJECT: "<<grade<<endl;
		cout<<"GPA OF THIS SUBJECT: "<<gpa<<endl;
		break;
	}
	return 0;
}
