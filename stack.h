#ifndef stack_h
#define  stack_h
#include "node.h"

class Stack{
private:
	 NodePtr top;
  NodePtr new_node;
	int size;
public:
    Stack(NodePtr = NULL);
    ~Stack();
    int pop();
    void push(char);
};

Stack::Stack(NodePtr t){
  if(t) {
    top=t;
    size=1;
  }
 else{
   top=NULL;
	 size=0;
   }
}
void Stack::push(char x){
   NodePtr new_node=new NODE(x);
  if(new_node){
    // exercises…1
	 	new_node->set_next(top); 
    top=new_node;
    ++size;
   }
 else cout<<"\n===No memory left for new nodes===\n"<<endl;
		 
}
int Stack::pop(){
 	   NodePtr t=top;
		int value;		
	 if(t)	{
    
     value=t->get_value();
     top=t->get_next();
	// exercises2
    --size;
     delete t;
     return value;
     }
    
		cout<<"\n===Empty stack===\n"<<endl;
   return 0;
	}
Stack::~Stack(){
   cout<<"\n===Clearing all stacks===\n"<<endl;
  	int i;
  NodePtr t=top;
for(i=0;i<size;i++){
   	//exercises3
    top=top->get_next();
     delete t;
     t=top;
  }
}
#endif