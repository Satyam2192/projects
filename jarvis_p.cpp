#include <iostream>
#include <string>
#include <map>

using namespace std;

// A class representing the Jarvis assistant
class Jarvis {
  public:
    Jarvis();
    void Run();
  private:
    map<string, void (Jarvis::*)()> commands_;
    void Hello();
    void WhatIsTheTime();
    void WhatIsTheWeather();
    void WhatIsTheDate();
    void HowAreYou();
    void UnknownCommand();
};

// Implement the member functions of the Jarvis class

int main() {
    Jarvis jarvis;
    jarvis.Run();
    return 0;
}
