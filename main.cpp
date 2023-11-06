#include <iostream>
#include <string>

using namespace std;

class Player {
    private:
        std::string pl_name;
        size_t pl_points;
    public:
        void SetName(const std::string& name) {
            pl_name = name;
        }
        std::string GetName() const {
           return pl_name;
        }
        void SetPoints(const size_t& points) {
            pl_points = points;
        }
        size_t GetPoints() const {
            return pl_points;
        }
};

void ReadLine(std::string& line) {
    std::getline(std::cin, line);
}

void ReadNumber(size_t& number) {
    std::cin >> number;
    std::string line;
    ReadLine(line);
}

void FillArray(Player* arr, const size_t& players_number) {
    for (size_t i = 0; i < players_number; ++i) {
        std::cout << "\nEnter the name for the " << i + 1 << " player: ";
        std::string name;
        ReadLine(name);
        arr[i].SetName(name); //(arr + i)->SetName(name);
        

        std::cout << "Enter the number of points for the " << i + 1 << " player: ";
        size_t points;
        ReadNumber(points);
        arr[i].SetPoints(points); //(arr + i)->SetPoints(points);
        
    }
}


void SortArray(Player* arr, const size_t& players_number, bool isDescending = true) {
    for (size_t i = 0; i < players_number; ++i) {
        for (size_t j = 0; j < players_number; ++j) {
            if(isDescending && arr[i].GetPoints() > arr[j].GetPoints()) {
                Player temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            } 
            if (!isDescending && arr[i].GetPoints() < arr[j].GetPoints()) {
                Player temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void PrintArray(const Player* const arr, const size_t& players_number) {
    for (size_t i = 0; i < players_number; ++i) {
        std::cout << "Player " << arr[i].GetName() << " has "
                    << arr[i].GetPoints() << " points" << std::endl;
    }
}

int main() {
    std::cout << "How many players do you want to add? ";
    size_t players_number;
    ReadNumber(players_number);
    
    Player* arr = new Player[players_number];

    FillArray(arr, players_number);
    std::cout << "\nArray of players before sorting\n";
    PrintArray(arr, players_number);
    SortArray(arr, players_number);
    std::cout << "\nArray of players after sorting\n";
    PrintArray(arr, players_number);

    delete [] arr;
    return 0;
}