class MyQueue {
public:
stack<int>st1;//Push Operation
    stack<int>st2;//Pop Operation
    MyQueue() {
        
    }
    bool empty() {
        return st1.empty() && st2.empty();
    }
    
    void push(int x) {
             st1.push(x);
    }
    //jo stack 2 khali na hoy to st2 ma already st1 na element store thai gaya chee tem kehvay atle st2 mathii j remove karvana
    
    int pop() {
             if(empty()){
            return -1;
        }
        //jo stack 2 khali na hoy to st2 ma already st1 na element store thai gaya chee tem kehvay atle st2 mathii j remove karvana
        if(!st2.empty()){
         int element=st2.top();
         st2.pop();
         return element;
        }
        else{
            //stack 1 khali nathii atle stack 1 mathii stack 2 ma element ne pela nakhava padse
            while(!st1.empty()){
             st2.push(st1.top());
             st1.pop();
            }
            int element=st2.top();
            st2.pop();
            return element;
        }
    }
    
int peek() {
    if (empty()) {
        return 0;
    }

    if (st2.empty()) {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
    }
    return st2.top();
}
};  // closes class


/*Note: stack 1 ae push mate and stack 2 ae pop mate chee jo stack 2 khali chee to stack 1 mathii element ne stack 2 ma java do and pachii npop karo otherwise am samjo ke elemet direct vaya j gaya chee*/



/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
