#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
  Stack s;
  int i,match=1;
  int countin=0,countout=0;
  char c;
  /*for(i=1;i<argc;i++){
    if(argv[i][0]=='x'){  //pop
      s.pop();
    }else{  //push it
      s.push(atoi(argv[i]));
    }
  }*/
  for(int j=1; j<argc;j++){
  
  for(i=0;i<strlen(argv[j]);i++){
    
    switch(argv[j][i]){
      //if open bracket = push
      case '[' :
      case '{' : 
        s.push(argv[j][i]);
        countin++;//push and break altogether
        break;
      //if close bracket = pop
      case ']' : 
          c = s.pop();
          countout++;
          if(c!='[') match=0;
        break;
      case '}' :
          c = s.pop();
          countout++;
       if(c!='{') match=0;
        break;
      default: break;
    
    }
    
  }
  
  if(match==0) cout<< "\n===Parentheses not match===\n"<< endl;
    else if(countin<countout) cout<<"\ntoo many close bracket\n"<<endl;
    else if(countin>countout)  cout<<"\ntoo many in bracket\n"<<endl;
    else cout<<"\n===Parentheses  match===\n"<<endl;

  }
 /*s.push(5);
  s.push(1);
  s.push(7);
  s.push(6);
  s.pop();//6
  s.pop();//7
  s.push(3);
  s.push(4);
 s.pop();//4
  s.pop();//3
  s.pop();//1
    s.pop();//5
    s.pop();
    s.pop();*/
}