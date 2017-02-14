#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

string determine_min_jumps_path(vector<int> canyon){
    
    int number_of_flights=canyon.size();
    vector<int> dp_computation(number_of_flights,INT_MAX);
    string path_taken="";
    int steps=0;
    try{
    	throw exception("hello");
	}
	catch(exception e){
		cout<<"here";
	}
    for(int current_index=number_of_flights-1;current_index>=0;current_index--){
            
            /*It is not possible to go beyond the last index from this point as it might have dragon*/
            if(canyon[current_index]==0)
                    dp_computation[current_index]=INT_MAX;
            /*This says that last index can be easily reached from this point*/
            else if(canyon[current_index]>number_of_flights-current_index-1)
                    dp_computation[current_index]=1;
            else{
                  int min_to_find=INT_MAX;
                  for(int already_computed_steps=current_index+1; already_computed_steps<number_of_flights && already_computed_steps<=canyon[current_index]+current_index; already_computed_steps++){
                            if(dp_computation[already_computed_steps]<min_to_find)
                                min_to_find=dp_computation[already_computed_steps];
                              
                                
                    }
                       /*To ensure overflow does not occur*/
                    if(min_to_find!=INT_MAX)
                        dp_computation[current_index]=min_to_find+1;
                    else
                        min_to_find =INT_MAX;
            }
    }
   
    /*Backtracking begins to find the path taken*/
    /* If part is satisfied when there is no appropriate path*/
    if(dp_computation[0]==0||dp_computation[0]==INT_MAX)
            path_taken="failure";
    else{
            steps=dp_computation[0];
            path_taken+=to_string(0);
            steps=steps-1;
            int invariant=0;
            
                for(;invariant<number_of_flights&&steps;invariant++){
                    if(dp_computation[invariant]==steps){
                        steps--;
                        path_taken+=", "+to_string(invariant);
                    }
                    
            }
       /* if(steps==0&&invariant!=number_of_flights){
                path_taken+=", "+to_string(number_of_flights-1);
        }*/
                path_taken+=", out";          
    }
        return path_taken;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int number_of_flights;
    string path_taken;
    
    
    vector<int> canyon;
    int input_holder;
    while(cin>>input_holder){
        canyon.push_back(input_holder);
    }

    path_taken=determine_min_jumps_path(canyon);//number_of_flights)
    cout<<path_taken;
    return 0;
}
