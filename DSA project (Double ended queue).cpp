#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

struct node {
    int info;
    struct node *link;
};

struct Button {
    int left, top, right, bottom;
    char label[6];
//    const char* label = "Insert";
    bool isClicked;
};
//void takeQuiz();
//int counter = 0;
int selectedNumber = -1; // Added variable to track selected number
struct node *front, *rear;

bool isNumberSelected() 
{
    return selectedNumber != -1;
}

void drawButtons(Button buttons[], int buttonCount) 
{
    setfillstyle(SOLID_FILL, WHITE);
    setbkcolor(WHITE);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 2);
    
    for (int i = 0; i < buttonCount; ++i) 
	{
//        rectangle(buttons[i].left, buttons[i].top, buttons[i].right, buttons[i].bottom);
        setcolor(RED);
        rectangle(buttons[i].left, buttons[i].top, buttons[i].right, buttons[i].bottom);
        int x = (buttons[i].left + buttons[i].right) / 2 - textwidth(buttons[i].label) / 2;
        int y = (buttons[i].top + buttons[i].bottom) / 2 - textheight(buttons[i].label) / 2;
        outtextxy(x, y, buttons[i].label);
    }
}

void drawNumbers() 
{
    setfillstyle(SOLID_FILL, WHITE);

    for (int i = 0; i <= 9; i++) 
	{
        char number[2];
        sprintf(number, "%d", i);

        // Right Matrix
//        bar(1040, i * 40 + 40, 1190, (i + 1) * 40 + 40);
        setlinestyle(3, 3, 4);
        setcolor(RED);
        rectangle(1040, i * 40 + 40, 1190, (i + 1) * 40 + 40);
    
        outtextxy(1120 - textwidth(number) / 2, i * 40 + 60 - textheight(number) / 2, number);
    }
}

void drawList() 
{
    struct node *q;
    int x = 50, y = 150;

    if (rear == NULL && front == NULL) {
        return;
    } 
	else 
	{
        q = front;
        while (q->link != front) 
		{
            char buffer[10];
            sprintf(buffer, "%d", q->info);
            rectangle(x - 40, y - 20, x + textwidth(buffer) + 40, y + textheight(buffer) + 20);
            outtextxy(x, y, buffer);
            x += 120;
//            lin
            q = q->link;
        }
        char buffer[10];
        sprintf(buffer, "%d", rear->info);
        rectangle(x - 40, y - 20, x + textwidth(buffer) + 40, y + textheight(buffer) + 20);
        outtextxy(x, y, buffer);
    }
}

void dText() 
{
    setcolor(BLUE);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 4);
    outtextxy(500, 50, "Dequeue_Project");
    setcolor(BLUE);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 2);
    outtextxy(230, 560, "Press any Button");
    setcolor(BLUE);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 2);
    outtextxy(1025, 0, "First click me ");
}

int checkButtonClick(Button buttons[], int buttonCount, int x, int y) 
{
    for (int i = 0; i < buttonCount; ++i) 
	{
        if (x >= buttons[i].left && x <= buttons[i].right && y >= buttons[i].top && y <= buttons[i].bottom) 
		{
            return i;
        }
    }
    return -1;
}

void insert_front() 
{
    if (isNumberSelected()) 
	{
        struct node *tmp;
        tmp = new node();
        tmp->info = selectedNumber;
        tmp->link = NULL;

        if (rear == NULL && front == NULL) {
            rear = tmp;
            front = tmp;
            rear->link = front;
        } else {
            tmp->link = front;
            front = tmp;
            rear->link = front;
        }

        // Reset selected number after insertion
        selectedNumber = -1;
    } else {
        cout << "First select a number from 0 to 9." << endl;
    }
}

void insert_rear() {
    if (isNumberSelected()) {
        struct node *tmp;
        tmp = new node();
        tmp->info = selectedNumber;
        tmp->link = NULL;

        if (rear == NULL && front == NULL) {
            rear = tmp;
            front = tmp;
            rear->link = front;
        } else {
            rear->link = tmp;
            rear = tmp;
            rear->link = front;
        }

        // Reset selected number after insertion
        selectedNumber = -1;
    } else {
        cout << "First select a number from 0 to 9." << endl;
    }
}

void del_front() {
    struct node *temp;
    if (rear == front) {
        temp = rear;
        delete (temp);
        rear = front = NULL;
    } else {
        temp = front;
        front = front->link;
        rear->link = front;
        delete (temp);
    }
}

void del_rear() {
    struct node *temp, *q;
    if (rear == front) {
        temp = rear;
        delete (temp);
        rear = front = NULL;
    } else {
        q = front;
        while (q->link != rear) {
            q = q->link;
        }
        temp = rear;
        rear = q;
        rear->link = front;
        delete (temp);
    }
}

void display() {
    struct node *q;
    if (rear == NULL && front == NULL) {
        cout << "List is empty" << endl;
        return;
    } else {
        q = front;
        cout << "List is:" << endl;
        while (q->link != front) {
            cout << q->info << "   ";
            q = q->link;
        }
        cout << rear->info << endl;
    }
}

void performButtonAction(int buttonIndex) {
    switch (buttonIndex) 
	{
        case 0:
            insert_front();
            break;
        case 1:
            insert_rear();
            break;
        case 2:
            del_front();
            break;
        case 3:
            del_rear();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
    }
}

void working()
{
	cout<<"-------------------------------Intoduction-----------------------------------------------\n"<<endl;
	cout<<"A deque, short for (double-ended queue) is a data structure"
	      " that allows insertion and deletion of elements from both ends"
		  " with constant time complexity. This flexibility makes it useful"
		  " in scenarios where elements need to be efficiently added or removed"
		  " from both the front and back of the queue. Deques can be implemented"
		  " using arrays or linked lists, and they provide a versatile alternative"
		  " to traditional queues or stacks\n\n";
	
	cout<<"-------------------------------Working------------------------------------------------------\n"<<endl;
	cout<<" A deque (double-ended queue) allows constant-time insertion"
		" and removal of elements at both ends. You can add elements to"
		" the front or back using push_front or push_back and remove them"
		" with pop_front or pop_back. This versatility makes deques suitable"
		" for scenarios requiring efficient manipulation at both ends."
		" Implementation choices, like arrays or linked lists, impact the" 
		" efficiency of deque operations.\n\n";
}
void graphics()
{
	initwindow(1370, 710, "");
    Button buttons[5] = 
	{
        {220, getmaxy() - 70, 360, getmaxy() - 10, "PushF", false},
        {370, getmaxy() - 70, 520, getmaxy() - 10, "PushR", false},
        {540, getmaxy() - 70, 680, getmaxy() - 10, "DelF", false},
        {700, getmaxy() - 70, 850, getmaxy() - 10, "DelR", false},
        
    };
    
    while (true) 
	{
        cleardevice();
        dText();
        drawButtons(buttons, 5);
        drawNumbers();
        drawList();

        delay(100);

        if (ismouseclick(WM_LBUTTONDOWN)) 
		{
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            int clickedButton = checkButtonClick(buttons, 5, x, y);
            if (clickedButton != -1) 
			{
                if (strcmp(buttons[clickedButton].label, "DelF") == 0 || strcmp(buttons[clickedButton].label, "DelR") == 0 ) 
				{
                    buttons[clickedButton].isClicked = true;
                } 
				else 
				{
                    if (isNumberSelected())
					{
                        buttons[clickedButton].isClicked = true;
                    } 
					else 
					{
                        cout << "First select a number from 0 to 9." << endl;
                    }
                }
            }

            if (x >= 1000 && x <= 1150 && y >= 40 && y <= 440) 
			{
                selectedNumber = (y - 40) / 40;
               
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }

        for (int i = 0; i < 5; ++i) 
		{
            if (buttons[i].isClicked) 
			{
//                rectangle(buttons[i].left, buttons[i].top, buttons[i].right, buttons[i].bottom);
               
			    performButtonAction(i);
                
				delay(200);
               
			    buttons[i].isClicked = false;
            }
        }
    }

    closegraph();

  
}
void Quiz()
{

    int score = 0;

    cout << "Welcome to the Dequeue MCQ Quiz!\n\n";

    // Question 1
    cout << "1. What does the acronym 'DSA' stand for in the context of C++ programming?\n";
    cout << "a. Data Structure and Analysis\nb. Digital System Architecture\nc. Dynamic System Allocation\nd. Data Structures and Algorithms\n";
    char answer1;
    cin >> answer1;
    if (answer1 == 'd') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'd'.\n";
    }

    // Question 2
    cout << "2. In C++, which library is commonly used for implementing graphics and visual elements?\n";
    cout << "a. stdlib.h\nb. iostream\nc. graphics.h\nd. windows.h\n";
    char answer2;
    cin >> answer2;
    if (answer2 == 'c') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'c'.\n";
    }

    // Question 3
    cout << "3. What is the primary purpose of a dequeue in data structures?\n";
    cout << "a. Efficient sorting\nb. Real-time processing\nc. Efficient insertion and removal from both ends\nd. Searching elements\n";
    char answer3;
    cin >> answer3;
    if (answer3 == 'c') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'c'.\n";
    }

    // Question 4
    cout << "4. Which operation is used to add an element to the front of a dequeue?\n";
    cout << "a. enqueueFront()\nb. pushFront()\nc. insertFront()\nd. addFront()\n";
    char answer4;
    cin >> answer4;
    if (answer4 == 'c') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'c'.\n";
    }

    // Question 5
    cout << "5. What is the time complexity of inserting an element at the front of a dequeue?\n";
    cout << "a. O(1)\nb. O(n)\nc. O(log n)\nd. O(n^2)\n";
    char answer5;
    cin >> answer5;
    if (answer5 == 'a') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'a'.\n";
    }

    // Question 6
    cout << "6. In a dequeue, elements can be removed from which ends?\n";
    cout << "a. Front only\nb. Rear only\nc. Both front and rear\nd. Middle\n";
    char answer6;
    cin >> answer6;
    if (answer6 == 'c') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'c'.\n";
    }

    // Question 7
    cout << "7. Which data structure is most similar to a dequeue?\n";
    cout << "a. Stack\nb. Queue\nc. Arrays\nd. Linked List\n";
    char answer7;
    cin >> answer7;
    if (answer7 == 'b') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'b'.\n";
    }

    // Question 8
    cout << "8. What is the main advantage of using a dequeue over a regular queue?\n";
    cout << "a. Faster access time\nb. More memory-efficient\nc. Allows insertion and removal at both ends\nd. Simpler implementation\n";
    char answer8;
    cin >> answer8;
    if (answer8 == 'c') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'c'.\n";
    }

    // Question 9
    cout << "9. Which operation is used to add an element to the rear of a dequeue?\n";
    cout << "a. enqueueRear()\nb. pushRear()\nc. insertRear()\nd. addRear()\n";
    char answer9;
    cin >> answer9;
    if (answer9 == 'c') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'c'.\n";
    }

    // Question 10
    cout << "10. In a dequeue, what is the time complexity of removing an element from the rear?\n";
    cout << "a. O(1)\nb. O(n)\nc. O(log n)\nd. O(n^2)\n";
    char answer10;
    cin >> answer10;
    if (answer10 == 'a') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'a'.\n";
    }

    // Question 11
    cout << "11. Which of the following is a valid implementation of a dequeue?\n";
    cout << "a. Using an array\nb. Using a linked list\nc. Using a dynamic array\nd. All of the above\n";
    char answer11;
    cin >> answer11;
    if (answer11 == 'd') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'd'.\n";
    }

    // Question 12
    cout << "12. What happens when you try to remove an element from an empty dequeue?\n";
    cout << "a. Program crashes\nb. Nothing happens\nc. Exception is thrown\nd. Compile-time error\n";
    char answer12;
    cin >> answer12;
    if (answer12 == 'c') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'c'.\n";
    }

    // Question 13
    cout << "13. Which of the following is a disadvantage of using a dequeue?\n";
    cout << "a. Slower access time\nb. More memory usage\nc. Limited capacity\nd. Complexity in implementation\n";
    char answer13;
    cin >> answer13;
    if (answer13 == 'd') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'd'.\n";
    }

    // Question 14
    cout << "14. In a double-ended queue, elements are always added to the:\n";
    cout << "a. Front\nb. Rear\nc. Both sides\nd. Random position\n";
    char answer14;
    cin >> answer14;
    if (answer14 == 'c') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'c'.\n";
    }

    // Question 15
    cout << "15. Which of the following is an application where a dequeue is commonly used?\n";
    cout << "a. Expression evaluation\nb. Tower of Hanoi\nc. Breadth-first search\nd. Memory allocation\n";
    char answer15;
    cin >> answer15;
    if (answer15 == 'a') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'a'.\n";
    }

    // Question 16
    cout << "16. What is the purpose of the front() function in a dequeue?\n";
    cout << "a. Add element to front\nb. Retrieve front element\nc. Remove front element\nd. Check if dequeue is empty\n";
    char answer16;
    cin >> answer16;
    if (answer16 == 'b') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'b'.\n";
    }

    // Question 17
    cout << "17. Which STL container in C++ can be used to implement a dequeue?\n";
    cout << "a. vector\nb. list\nc. deque\nd. map\n";
    char answer17;
    cin >> answer17;
    if (answer17 == 'c') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'c'.\n";
    }

    // Question 18
    cout << "18.\n What is the output of the front() function when the dequeue is empty?\n";
    cout << "a. 0\nb. Garbage value\nc. Exception is thrown\nd. Compile-time error\n";
    char answer18;
    cin >> answer18;
    if (answer18 == 'c') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'c'.\n";
    }

    // Question 19
   cout<<"19.\nHow is a Dequeue different from a Queue in C++?\n"
"a. Dequeue allows elements to be added or removed only from the front.\n"
"b. Dequeue allows elements to be added or removed only from the rear.\n"
"c. Dequeue allows elements to be added or removed from both front and rear.\n"
"d. Dequeue follows the Last In, First Out (LIFO) principle.\n";
     char answer19;
    cin >> answer19;
    if (answer19 == 'c') 
	{
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'c'.\n";
    }

    // Question 20
    cout << "20. What is the purpose of the size() function in a dequeue?\n";
    cout << "a. Add elements to the dequeue\nb. Retrieve the size of the dequeue\nc. Remove elements from the dequeue\nd. Check if dequeue is full\n";
    char answer20;
    cin >> answer20;
    if (answer20 == 'b') 
	{
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'b'.\n";
    }
	//21
	cout << "21\nThe implementation of Dequeue using a circular array in C++ helps to:\n";
    cout << "a. Reduce the time complexity\n";
    cout << "b. Eliminate the need for a rear pointer\n";
    cout << "c. Improve cache performance\n";
    cout << "d. Simplify the code\n";

    char answer21;
    cout << "Enter your choice  ";
    cin >> answer21;

    if (answer21 == 'c' || answer21 == 'C') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is c. Improve cache performance.\n";
    }

    // Question 22
    cout << "21. Which of the following is a disadvantage of using an array-based implementation of a dequeue?\n";
    cout << "a. Fixed capacity\nb. Dynamic resizing\nc. Fast access time\nd. Automatic memory management\n";
    char answer22;
    cin >> answer22;
    if (answer22 == 'a') {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is 'a'.\n";
    }
	//question # 23
	cout<<"23.\nWhat is the time complexity of removing an element from the front of a Dequeue implemented using a array in C++?\n"
		   "a. O(1)\n"
		   "b. O(log n)\n"
		   "c. O(n)\n"
	 	  "d. O(n^2)\n";

    char answer23;
    cout << "Enter your choice : ";
    cin >> answer23;

    if (answer23 == 'a' || answer23 == 'A') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect. The correct answer is c. Improve cache performance.\n";
    }

	// 24
	cout << "24.\nRear Pointer will Indicate at ?\n";
    cout << "a. Starting Node \n";
    cout << "b. Start->link\n";
    cout << "c. Ending Node\n";
    cout << "d. Middle of Linklist\n";

    char answer24;
    cout << "Enter your choice : \n";
    cin >> answer24;
    if (answer24 == 'c') {
        cout << "Correct!\n";
        score++;
    }
	 else 
	{
        cout << "Incorrect. The correct answer is c.\n";
    }
	 
	 // 25
    cout << "25\nThe size of a Dequeue in C++ is defined as:\n";
    cout << "a. The number of elements it can store\n";
    cout << "b. The length of the linklist used for implementation\n";
    cout << "c. The sum of front and rear pointers\n";
    cout << "d. The maximum capacity set during initialization\n";

    char answer25;
    cout << "Enter your choice :";
    cin >> answer25;
    if (answer25 == 'b') 
	{
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is b.\n";
    }
	
	//26
    cout << "26\nWhich of the following is an application of a Dequeue in C++?\n";
    cout << "a. Arithmetic expression evaluation\n";
    cout << "b. Binary search tree traversal\n";
    cout << "c. Hash table implementation\n";
    cout << "d. Graph traversal\n";

    char answer26;
    cout << "Enter your choice : \n";
    cin >> answer26;
    if (answer26 == 'a')
	 {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is a.\n";
    }
	
	//27
    cout << "27.\nThe term \"front\" in a Dequeue in C++ refers to:\n";
    cout << "a. The first element in the queue\n";
    cout << "b. The last element in the queue\n";
    cout << "c. The middle element in the queue\n";
    cout << "d. The largest element in the queue\n";

    char answer27;
    cout << "Enter your choice \n";
    cin >> answer27;
    if (answer27 == 'a')
	 {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is a.\n";
    }

	// 28
    cout << "\nWhich of the following operations is not performed in a Dequeue in C++?\n";
    cout << "a. Insertion at the front\n";
    cout << "b. Deletion from the middle\n";
    cout << "c. Insertion at the rear\n";
    cout << "d. Deletion from the front\n";

    char answer28;
    cout << "Enter your choice : \n";
    cin >> answer28;
    if (answer28 == 'b')
	{
        cout << "Correct!\n";
    	score++;
	} 
	else 
	{
        cout << "Incorrect. The correct answer is b.\n";
    }
	
	//29
    cout << "29.\nIn C++, the process of adding an element to the front of a Dequeue is also known as:\n";
    cout << "a. Enqueue\n";
    cout << "b. Push\n";
    cout << "c. Inject\n";
    cout << "d. Insert\n";

    char answer29;
    cout << "Enter your choice (a, b, c, or d): ";
    cin >> answer29;
    if (answer29 == 'c') 
	{
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer is c.\n";
    }

	//20
    cout << "30.\nThe data structure that allows elements to be added or removed from both ends with constant time complexity in C++ is: \n";
    cout << "a. Stack\n";
    cout << "b. Queue\n";
    cout << "c. Priority Queue\n";
    cout << "d. Dequeue\n";

    char answer30;
    cout << "Enter your choice (a, b, c, or d): ";
    cin >> answer30;
    if (answer30 == 'd' || answer30 =='D') 
	{
        cout << "Correct!\n";
        score++;
    }
	else 
	{
        cout << "Incorrect. The correct answer is d.\n";
    }

    cout<<"---------------------------------------------------------------------\n\n"<<endl;
    cout << "Test completed!\n";
    cout << "Your score: " << score << " out of 30\n\n";
    cout<<"---------------------------------------------------------------------\n\n"<<endl;
}

void Time_Com()
{
	cout<<"--------------Time Complexity of Dequeue--------------------------\n"<<endl;
	cout<<"   BASE CASE :\n"<<endl;
	cout<<" Insertion (push_front and push_back) : Big O(1) "<<endl;
	cout<<" Deletion (pop_front and pop_back) : Big O(1)"<<endl;	
	cout<<" Accessing Elements (by index) : Big O(n) \n"<<endl;
	cout<<"---------------------------------------------------------------------\n\n"<<endl;
	cout<<"   AVARAGE CASE :\n"<<endl;
	cout<<" Insertion (push_front and push_back) : Big O(1) "<<endl;
	cout<<" Deletion (pop_front and pop_back) : Big O(1)"<<endl;	
	cout<<" Accessing Elements (by index) : Big O(n) \n"<<endl;
	cout<<"---------------------------------------------------------------------\n\n"<<endl;
	cout<<"   Worst Case :\n"<<endl;
	cout<<" Insertion (push_front and push_back) : Big O(1) "<<endl;
	cout<<" Deletion (pop_front and pop_back) : Big O(1)"<<endl;	
	cout<<" Accessing Elements (by index) : Big O(n) \n"<<endl;
	cout<<"-----------------------------------------------------------------\n\n";
	
}	
int main() 
{
    int choice;
	while(1)
	{
	cout<<"Press 1. for Working "<<endl;
	cout<<"Press 2. for Graphics "<<endl;
	cout<<"Press 3. for Quiz"<<endl;
	cout<<"Press 4. for Time Complexity"<<endl;
	cout<<"Enter Your Choice : " ;
	cin>>choice;	
		switch(choice)
		{
			case 1: 
			{
				working();
				break;
			}
			case 2:
				{
					graphics();
					break;
				}
			case 3:
				{
					char y;
					cout<<"First Prepare the Quiz "<<endl;
					cout<<"Do You Read All Chapters ? (Yes/no)"<<endl;
					cin>>y;
					if(y=='y' || y=='Y')
					{
					Quiz();
					}
					else
					{
						cout<<"First read"<<endl;
						working();
						Time_Com();
					}
					break;
				}
			case 4:
				{
					Time_Com();
					break;
				}
			default :
				{
					cout<<"Not a valid choice"<<endl;
				}
		}
	}
}
