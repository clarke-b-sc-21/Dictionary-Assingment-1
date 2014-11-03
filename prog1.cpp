#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>



/*
Author: Logan Clarke
Dictionary Assignment 1
Purpose: The purpose of this porgram is to read a text file and 
build a dictionary of words found in that file. The dictionary will
output the words found in the file as well as the frequency of those
words. The dictionary will not be case sensitive and will have a
max word size and a max allowed number of words.
*/


using namespace std;

int main() {

char ch;
int newLine= 0;
int num=0;
int count = 0;
int xnum;
char dict [10][132]={0};
char tempA [999]={0};
const char tempB [999]={0};
int freq [10]={0};
int length[10]={0};
int i = 0;
int j = 0;
bool out = true;
bool newWRD = true;
bool bigW ;
bool hugeW; 



cout << "Word                    Frequency"<<endl;                                 //output table
cout << "---------------------------------" <<endl;  


while( cin.good() )
{
 ch = cin.get();
 if ( isalpha(ch) )  /* function test is ch  is A-Z, a-z */                       //while is alpha reads true
    {										  //I add char to my array
   	
      if( (j<132)&&(i<10) ){ ch = char(tolower(ch)); dict[i][j] = ch;}	 	  //IF there are more than 10
      else if (j>=132 || i>=10) { ch = char(tolower(ch)); tempA[j] = ch;}	  //words already processed new   
      newLine = 1;  							          //char are added to tempA array     													                                                                                      
      j++;  												        
    }
														
 else  if (newLine) 
                                                                                  //when is alpha fails
          {                                                                       //i look at the new word
                  
          
               newLine = 0;



        	
                                                                                                                      //array of char and 
              		for ( int x =0; x<i; x++){                                                                    //compare to others
                		    if ( ( !strcmp(dict[i],dict[x]) )||( !strcmp(tempA,dict[x]) )  ) {                
					freq[x]= (freq[x] + 1) ;                                                       //if same i increase 
					for( int y=0; y<j; y++){ dict[i][y]=0;}                                        //appropriate freq, 
                        		out = false;								       //delete the new,
                                        newWRD = false;                                                                   
                        		i--;                                         
		    		 } 	       
               		}

              if(i<10){

             		 if( out == true){                                    //if the cuurent array is new 
                		
				freq[i] = 1;                                  //I increase its freq to 1 and get 
                		length[i]=j;                                  //the length of the word for later
                	  } 	

			 


                        
 	    		                                                                                          
            		i++;                                                  //increase i pointer
            		out = true;                                           //reset the bool out
                       

		}
		
                 j=0; 							     //reset j to zero to process next word
                 for(int x = 0; x< 999; x++) {tempA[x]=tempB[x];}            //reset temp to be empty for next word
		 if (newWRD==true)count++;
                 newWRD = true;
	    } 
                                                   

}                                                   


      for (int x = 0; x<i; x++){                                 //once I am out of the while loop 
                                                                 //and have all my input I output   
      	for( int y=0; y<15; y++){                                //my dictionary and the frequency of each word
   	  	cout<< dict[x][y];
   	  	num++;
           	}   
                                                                 
        if(length[x]<15) xnum = (30- length[x]);                 //add a number of spaces depending on
        else {xnum = 15;  bigW=true;}                            //the length of the word and set some bool
        if(length[x]>=132) {hugeW=true;}                         //statements to true or false depending on word length
                               
        for(int z=0 ; z<xnum; z++) {cout<< " ";}       
          
         cout << freq[x] <<endl ;
         
             num=0;
         }
         
 	
         cout<<endl<<endl;
                                                                                                                 


   if(bigW == true){cout << "Dictionary will display 15 characters of the longer words in the file" <<endl;}         
   if(hugeW == true){ cout<< "Some words were too large for the dictionary to process entirely"<<endl;}
   if(count>10) {cout<<"There were too many words for the dictionary"<<endl;}

return 0;
}







