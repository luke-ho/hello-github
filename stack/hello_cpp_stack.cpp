#include <iostream>

using namespace std;

template <class TYPE>
class StackNode {
    protected:
        TYPE val;
        StackNode<TYPE> * next;
    public:
        StackNode() {
            val = 0;
            next = NULL;
        }
        StackNode(TYPE v) {
            val = v;
            next = NULL;
        }
        StackNode(TYPE * v) : StackNode() {
            if ( v ) {
                val = v->val;
                next = v->next;
            } else {
                cout << "(" << __LINE__ << "): Error: ptr passed in is NULL" << endl;
            }
        }
        StackNode(TYPE v, StackNode<TYPE> * n) :  StackNode() {
            val = v;
            next = n;
        }
        ~StackNode() {
            if ( next ) {
                next = NULL;
            }
        }
        TYPE getVal() const {
            return val;
        }
        StackNode<TYPE> * getNext() const {
            return next;
        }
        void setVal(TYPE n) {
            val = n;
        }   
        void setNext(StackNode<TYPE> * n) {
            next = n;
        }
};

template <class TYPE>
class Stack {
    protected:
        int count;
        StackNode<TYPE> * top;
    public:
        Stack() {
            count = 0;
            top = NULL;
        }

        ~Stack() {
            StackNode<TYPE> * tmp; 
            if ( top )  {
                while(top) {
                    tmp = top;
                    top = top->getNext();
                    delete tmp;
                }
                count = 0;
            }
        }

        bool push(TYPE val) {
            if ( !val ) {
                return false;
            }
            if ( top ) {
                StackNode<TYPE> * tmp = top;
                top = new (nothrow) StackNode<TYPE>(val);
                if ( !top ) {
                    cout << "(" << __LINE__ << "): Ran out of memory while trying to allocate new node" << endl;
                    return false;
                }
                top->setNext(tmp);
                count++;
                return true;
            } else {
                top = new (nothrow) StackNode<TYPE>(val);
                if ( !top ) {
                    cout << "(" << __LINE__ << "): Ran out of memory while trying to allocate new node" << endl;
                    return false;
                }
                count++;
                return true;
            }
        }

        bool push(StackNode<TYPE> * s) {
            if ( !s ) {
                return false;
            }
            if ( top ) {
                StackNode<TYPE> * tmp = top;
                top = new (nothrow) StackNode<TYPE>(s);
                if ( !top ) {
                    cout << "(" << __LINE__ << "): Ran out of memory while trying to allocate new node" << endl;
                    return false;
                }
                top->setNext(tmp);
                count++;
                return true;
            } else {
                top = new (nothrow) StackNode<TYPE>(s);
                if ( !top ) {
                    cout << "(" << __LINE__ << "): Ran out of memory while trying to allocate new node" << endl;
                    return false;
                }
                count++;
                return true;
            }
        }

        StackNode<TYPE> * pop() {
            if ( count > 0 ) { 
                StackNode<TYPE> * tmp = top;
                top = top->getNext();
                count--;
                return tmp;
            } else {
                return NULL;
            }
            return NULL;
        }

        int getCount() const {
            return count;
        }
};

int main() {
    Stack<char> s;
    StackNode<char> * tmp;

    s.push('!');
    s.push('b');
    s.push('u');
    s.push('H');
    s.push('t');
    s.push('i');
    s.push('G');
    s.push(' ');
    s.push(',');
    s.push('o');
    s.push('l');
    s.push('l');
    s.push('e');
    s.push('H');

    while ( s.getCount() > 0 ) {
        tmp = s.pop();
        cout << tmp->getVal();
        delete tmp;
    }

    cout << endl;
    return 0;
}
