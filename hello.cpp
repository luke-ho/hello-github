#include <iostream>

using namespace std;

class Greeting {
    protected:
        string s;
    public:
        Greeting(){
            s = "Hello, ";
        }
        virtual ~Greeting() { }
        virtual void printGreeting() = 0;
};

class GitHubGreeting : public Greeting {
    public: 
        GitHubGreeting() { 
            s += "GitHub!";
            printGreeting();
        }
        GitHubGreeting(GitHubGreeting & h) { GitHubGreeting(); }
        GitHubGreeting(GitHubGreeting * h) { GitHubGreeting(); }
        virtual ~GitHubGreeting() { }
        void operator=(GitHubGreeting & h) { }
        void printGreeting() { 
            cout << s << endl; 
        }
};

int main() {
    GitHubGreeting h;
    return 0;
}
