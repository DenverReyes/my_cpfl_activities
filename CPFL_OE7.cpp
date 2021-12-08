//Name: Denver S. Reyes
//Activity: OE7
//Description: Using a C-string, create login credentials with a username and password
//Date: 12-08-2021

#include<iostream>
#include<cstring>

using namespace std;

//Function Declaration

void promptAndWait();
void login();
void search(int input[], int count);
void sort_asc(int input[], int count);
void sort_des(int input[], int count);

const int size = 100;

int main (){

    login();
    system("cls");
    int input[size], count, ch;
    cout << "\nEnter Number of Elements in Array\n";
    cin >> count;
     
    cout << "Enter " << count << " numbers \n";
      
    // Read array elements
    for(int i = 0; i < count; i++){
        cin >> input[i];
    }

    do
    {
        system("cls");
        cout << " << Arrays Sorting App >>" << endl;
        cout << " [1] Searching Array " << endl;
        cout << " [2] Sort Array Ascending " << endl;
        cout << " [3] Sort Array Descending " << endl;
        cout << " [0] Exit " << endl;
        cout << " Select an option : ";
        cin >> ch;

        switch (ch)
        {
            case 1:{
                
                search(input, count);
                promptAndWait();
                break;
            }

            case 2:{
                
                sort_asc(input, count);
                promptAndWait();
                break;
            }

            case 3:{
                
                sort_des(input, count);
                promptAndWait();
                break;
            }

            case 0:{
                
                cout << "Thank you for using the App !!!" << endl;
                return 0;
            }                
            
            default:{

                cout << "Invalid Input!!!" << endl;
                promptAndWait();
                break;
            }
        }
    }while (true);
    
}

//Function Definition

void promptAndWait(){

    cin.ignore();
    cout << "\nPress Enter or Return to Continue...";
    cin.get();
}

void search(int input[], int count){


    //Search 
   for(int x = 0; x < count; x++){

        cout << "\n Unsorted Array Elmement [" << x << "] "<< input[x] << endl;
    }
}

void sort_asc(int input[], int count){

    int j, y, temp;

     //Sorting an array in ascending order
    for(y=0; y<count; y++){
    
        for(j=y+1; j<count; j++){
        
            
            if(input[j] < input[y]){
            
                temp = input[y];
                input[y] = input[j];
                input[j] = temp;
            }
        }
    }
    //Output
    cout<<"\nElements of array in Ascending order : "<<endl;
    for(y=0; y<count; y++){
    
        cout<<input[y]<<endl;
    }
}

void sort_des(int input[], int count){

    int j, y, temp;

    //Sorting an array in descending order
    for (y = 0; y < count; ++y){   
    
        for (j = y + 1; j < count; ++j){
        
            if (input[y] < input[j]){
            
                temp = input[y];
                input[y] = input[j];
                input[j] = temp;
            }
        }
    }

    //Output
    cout<<"\nElements of array in Descending Order : \n";
    for (y = 0; y < count; ++y){

        cout<<input[y] << endl;
    
    }
}


void login(){
    char my_username[50] = "Denver Reyes";
    char username[50];

    char my_password[50] = "10115";
    char password[50];

    cout << "Enter Username : ";
    cin.getline(username, 50);

    if(!(strcmp(my_username, username))){

         cout << "Correct Username " << endl;

         cout << "\nEnter Password : ";
         cin.getline(password, 50);

        if(!(strcmp(my_password, password))){

            cout << "Correct Password " << endl;
            system("pause");
        }

        else{
            cout << "Incorrect Password " << endl;
            exit(1);
        }

    }

    else{
        cout << "Incorrect Username " << endl;
        exit(1);
    }
}
