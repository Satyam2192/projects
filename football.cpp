#include <iostream>
#include <string>
#include <vector>

using namespace std;

// A class representing a football player
class Player {
  public:
    Player(string name, int skill) : name_(name), skill_(skill) {}
    string GetName() const { return name_; }
    int GetSkill() const { return skill_; }
  private:
    string name_;
    int skill_;
};

// A class representing a football team
class Team {
  public:
    Team(string name) : name_(name) {}
    void AddPlayer(Player player);
    string GetName() const { return name_; }
    int GetTotalSkill() const;
  private:
    string name_;
    vector<Player> players_;
};

// A class representing a football game
class Game {
  public:
    Game(Team team1, Team team2);
    void Play();
    Team GetWinner() const;
  private:
    Team team1_;
    Team team2_;
    Team winner_;
};

// Implement the member functions of the Player, Team, and Game classes

int main() {
    // Create some teams and players
    Team team1("Team 1");
    team1.AddPlayer(Player("Alice", 5));
    team1.AddPlayer(Player("Bob", 3));
    team1.AddPlayer(Player("Charlie", 4));

    Team team2("Team 2");
    team2.AddPlayer(Player("Dave", 7));
    team2.AddPlayer(Player("Eve", 8));
    team2.AddPlayer(Player("Frank", 6));

    // Create a game and play it
    Game game(team1, team2);
    game.Play();

    // Print the winner
    Team winner = game.GetWinner();
    cout << "The winner is " << winner.GetName() << endl;

    return 0;
}
