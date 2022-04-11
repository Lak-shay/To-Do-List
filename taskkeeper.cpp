#include <iostream>
#include <stack>
#include<vector>
#include<conio.h>

using namespace std;

void main_menu();
void display_list(stack<string> );
void remove_tasks(stack<string>*);
void insert_at_top(stack<string>*);
void insert_at_pos(stack<string>*, int, string);

int main()
{
    int number;
    cout << "\tEnter the number of tasks that you want to enter : ";
    cin >> number;
    stack<string> s;
    vector<pair<int, string>> v;

    int loop = number;

    while (loop--)
    {
        int order;
        string task;
        cout << "\n\tEnter the priority order of the task : ";
        cin >> order;
        cout << "\tEnter the task that you want to enter : ";
        cin >> task;
        v.push_back(make_pair(order, task));
        cout << endl;
    }

    int size = v.size();
    int check = number;
    for (int i = 0; i < size; i++)
    {
        if (v[i].first == check)
        {
            s.push(v[i].second);
            i = -1; // done this to search the whole vector again
            check--;
        }
    }
    display_list(s);                // To display the user defined task list.
    
    char menu_choice;
    do
    {
        getch();
        system("CLS");
        int choice;
        main_menu();
        cin >> choice;
        cout << "\n\n";

        if(choice == 1)                     // Insert at top
        {   
            insert_at_top(&s);
        }

        else if(choice == 2)                // To remove the tasks
        {
            remove_tasks(&s);               
        }
        
        else if(choice == 3)                // Display list
        {
            display_list(s);
        }
        
        else if(choice == 4)                // Insert a task at a specefic position
        {
            display_list(s);
                cout << endl;
                string task;
                cout << "\tEnter the task that you want to add:\t";
                cin >> task;
                int pos;
                cout << "\tEnter the position at which you want to enter the task:\t";
                cin >> pos;
                insert_at_pos(&s, pos, task);
                display_list(s);
        }
        
        else                                // Exit
        {
            break;
        }

        cout << "\tDo you want to perform anything else on your list?(y/n)\t";
        cin >> menu_choice;
        cout << "\n\n";

    } while (menu_choice == 'y');
    
    return 0;
}

void main_menu()
{
    cout<<"\n\t ----------------------------";
	cout<<"\n\t\t TASK ORGANISER";
	cout<<"\n\t ----------------------------";
	cout<<"\n\t\t What do you want to do?";	 																					
	cout<<"\n\n\t\t <1> Insert a task at the top";
	cout<<"\n\t\t <2> Delete a task";
	cout<<"\n\t\t <3> Display the list";
	cout<<"\n\t\t <4> Insert a task at a specefic postion";
	cout<<"\n\t\t <5> Exit \n\n";
	cout<<"\t\tEnter Your Choice :"<<"\t";
}

void display_list(stack<string> s)
{
    if (s.empty() == 1)
    {
        cout << "\tYou have completed all the tasks. Good Work!" << endl;
    }
    else
    {
        cout << "\tThe current pending list is as follows" << endl
             << endl;
        while (!s.empty())
        {
            cout << "\t" << s.top() << endl;
            s.pop();
        }
        cout << endl;
    }
}

void remove_tasks(stack<string> *ptrs)
{
    char option;
    int remove;
    display_list(*ptrs);
    cout << "\n";
    cout << "\tHave you completed some tasks ? (y/n)\t";
    cin >> option;
    
    if (option == 'y')
    {
        cout << "\tEnter the number of tasks that you have completed : ";
        cin >> remove;
        while (remove-- && remove >= 0)
        {
            ptrs->pop();
        }
    }
    
    else
    {
        cout << "\tKeep working." << endl;
    }

    display_list(*ptrs);
}

void insert_at_top(stack <string>* ptrs)
{
    display_list(*ptrs);
    string task;
    cout << "\tEnter the task that you want to add:\t";
    cin >> task;
    ptrs->push(task);
}

void insert_at_pos(stack<string>* ptrs, int pos, string task)
{
    stack<string> temp;
    
    if(pos > ptrs->size())                      // task has to be placed at the bottom of the stack
    {
        while(ptrs->empty() == 0)               // Stack is not empty
        {
            temp.push(ptrs->top());
            ptrs->pop();
        }
        // temp stack has all the tasks

        ptrs->push(task);
        // Inserting task into stack

        while(temp.empty() == 0)
        {
            ptrs->push(temp.top());
            temp.pop();
        }
        // Now all the tasks are back into stack
    }

    else                // Task has to be placed in between the stack
    {
        for(int i = 1; i <= pos-1; i++)
        {
            temp.push(ptrs->top());
            ptrs->pop();
        }

        ptrs->push(task);
        // pushed the task at the required position

        while(temp.empty() == 0)
        {
            ptrs->push(temp.top());
            temp.pop();
        }
        // Now all the tasks are back into stack

    }
}