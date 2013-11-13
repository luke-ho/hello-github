#include <iostream>

using namespace std;

template <class T>
class StackNode {
    protected:
        T val;
        StackNode<T> * next;
    public:
        StackNode() {
            val = 0;
            next = NULL;
        }
        StackNode(T v) {
            val = v;
            next = NULL;
        }
        StackNode(T * v) : StackNode() {
            if ( v ) {
                val = v->val;
                next = v->next;
            } else {
                cout << "(" << __LINE__ << "): Error: ptr passed in is NULL" << endl;
            }
        }
        StackNode(T v, StackNode<T> * n) :  StackNode() {
            val = v;
            next = n;
        }
        ~StackNode() {
            if ( next ) {
                next = NULL;
            }
        }
        T getVal() {
            return val;
        }
        StackNode<T> * getNext() {
            return next;
        }
        void setVal(T n) {
            val = n;
        }   
        void setNext(StackNode<T> * n) {
            next = n;
        }
};

template <class T>
class Stack {
    protected:
        int count;
        StackNode<T> * top;
    public:
        Stack() {
            count = 0;
            top = NULL;
        }

        ~Stack() {
            StackNode<T> * tmp; 
            if ( top )  {
                while(top) {
                    tmp = top;
                    top = top->getNext();
                    delete tmp;
                }
                count = 0;
            }
        }

        bool push(T val) {
            if ( !val ) {
                return false;
            }
            if ( top ) {
                StackNode<T> * tmp = top;
                top = new (nothrow) StackNode<T>(val);
                if ( !top ) {
                    cout << "(" << __LINE__ << "): Ran out of memory while trying to allocate new node" << endl;
                    return false;
                }
                top->setNext(tmp);
                count++;
                return true;
            } else {
                top = new (nothrow) StackNode<T>(val);
                if ( !top ) {
                    cout << "(" << __LINE__ << "): Ran out of memory while trying to allocate new node" << endl;
                    return false;
                }
                count++;
                return true;
            }
        }

        bool push(StackNode<T> * s) {
            if ( !s ) {
                return false;
            }
            if ( top ) {
                StackNode<T> * tmp = top;
                top = new (nothrow) StackNode<T>(s);
                if ( !top ) {
                    cout << "(" << __LINE__ << "): Ran out of memory while trying to allocate new node" << endl;
                    return false;
                }
                top->setNext(tmp);
                count++;
                return true;
            } else {
                top = new (nothrow) StackNode<T>(s);
                if ( !top ) {
                    cout << "(" << __LINE__ << "): Ran out of memory while trying to allocate new node" << endl;
                    return false;
                }
                count++;
                return true;
            }
        }

        StackNode<T> * pop() {
            if ( count > 0 ) { 
                StackNode<T> * tmp = top;
                top = top->getNext();
                count--;
                return tmp;
            } else {
                return NULL;
            }
            return NULL;
        }

        int getCount() {
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
