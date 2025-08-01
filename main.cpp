#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	
	int choice, taskNumber;
    vector<string> tasks;
    string task, removedTask;
    bool running = true, menu=false;
    
    // TODO: Write your code here
    cout<< "Welcome to Task List Tool!"<<endl;
	cout<<"\nMenu Options:"<<endl;
    cout<<"1. Add Task"<<endl;
    cout<<"2. View Tasks"<<endl;
    cout<<"3. Remove Task"<<endl;
    cout<<"4. Quit"<<endl;
    cout<<"\nTask list system initialized and ready!"<<endl;
	    
	while(running) {
	
		if(menu) {
			
			cout<<"\nMenu Options:"<<endl;
	    	cout<<"1. Add Task"<<endl;
	    	cout<<"2. View Tasks"<<endl;
	    	cout<<"3. Remove Task"<<endl;
	    	cout<<"4. Quit"<<endl;
			cout<<endl;	
		}

    
		cout<<"Choose an option: ";
		cin>>choice;
		cin.ignore();
		
        if(choice == 1) {
        	cout<<"Task to add: ";
			getline(cin, task);
    		tasks.push_back(task);
			cout<<"Task \""<<tasks[tasks.size()-1]<<"\" added successfully!"<<endl;
    		cout<<"Total tasks: "<<tasks.size()<<endl;
    		menu = true;
		
		} else if(choice == 2) {
    
		    if (tasks.empty()) {
		        cout << "No tasks available." <<endl;
		    } else {
		        cout << "Your Tasks:" << endl;
		        for (int i = 0; i < tasks.size(); i++) {
		            cout << (i + 1) << ". " << tasks[i] <<endl;
		        }
		        cout << "Total tasks: " << tasks.size() <<endl;
		    }
			menu = true;
		} else if(choice == 3) {
		
		    if(tasks.empty()){
		        cout<<"No task to delete."<<endl;
		    } else {
		    	
		    	cout<<"Number of task to remove: ";
		    	cin>>taskNumber;
		    
			    if(taskNumber>=1 && taskNumber <=tasks.size()) {
			    removedTask = tasks[taskNumber - 1];
			    tasks.erase(tasks.begin() + taskNumber-1);
			    cout<<"Task \""<<removedTask<<"\" removed successfully!"<<endl;
		        
				cout<<"Remaining Tasks:"<<endl;
				if(tasks.empty()) {
					cout<<"None"<<endl;
				} else{
					for(int i =0; i<tasks.size(); i++) {
		            cout<<i+1<<". "<<tasks[i]<<endl;
		        	}	
				}
		    } else {
		    	if(tasks.size()== 1) {
		    		cout<<"Error: Invalid task number. There's only one task."<<endl;
				} else {
					cout<<"Error: Invalid task number. Please enter a number between 1 and "<<tasks.size()<<"."<<endl;	
				}
		    }
		}
		    
		    cout<<"Total tasks: "<<tasks.size()<<endl;
    		menu = true;
    		
		} else if(choice == 4) {
			running = false;
			cout<<"Thank you for using Task List Tool!";

		} else {
			cout<<"Invalid choice. Please try again."<<endl;
		}
    }
    return 0;
}
