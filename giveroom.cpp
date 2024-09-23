#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// Function to read the list of available rooms from a file
vector<string> readAvailableRooms(const string& filePath) {
    vector<string> availableRooms;
    ifstream file(filePath);
    string room;

    if (file.is_open()) {
        while (getline(file, room)) {
            availableRooms.push_back(room);
        }
        file.close();
    } else {
        cerr << "File not found: " << filePath << endl;
    }

    return availableRooms;
}

// Function to read the list of occupied rooms from a file
vector<string> readOccupiedRooms(const string& filePath) {
    vector<string> occupiedRooms;
    ifstream file(filePath);
    string room;

    if (file.is_open()) {
        while (getline(file, room)) {
            occupiedRooms.push_back(room);
        }
        file.close();
    } else {
        cerr << "File not found: " << filePath << endl;
    }

    return occupiedRooms;
}

// Function to write a list of rooms to a file
void writeRoomsToFile(const string& filePath, const vector<string>& rooms) {
    ofstream file(filePath);

    if (file.is_open()) {
        for (const string& room : rooms) {
            file << room << endl;
        }
        file.close();
    } else {
        cerr << "Unable to write to file: " << filePath << endl;
    }
}

// Function to find the next available room and update occupied rooms
pair<string, vector<string>> allocateNextAvailableRoom(vector<string>& availableRooms, vector<string>& occupiedRooms) {
    for (auto it = availableRooms.begin(); it != availableRooms.end(); ++it) {
        const string& room = *it;
        if (find(occupiedRooms.begin(), occupiedRooms.end(), room) == occupiedRooms.end()) {
            occupiedRooms.push_back(room);
            availableRooms.erase(it);
            writeRoomsToFile("E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\occupied_rooms.txt", occupiedRooms);
            writeRoomsToFile("E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\available_rooms.txt", availableRooms);
            return make_pair(room, occupiedRooms);
        }
    }
    return make_pair("No available rooms at the moment", occupiedRooms);
}

string giveroom() {
    string availableRoomsFile = "E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\available_rooms.txt";
    string occupiedRoomsFile = "E:\\EL_diablo\\cpp-hostel-management-system-main\\cpp-hostel-management-system-main\\occupied_rooms.txt";

    vector<string> availableRooms = readAvailableRooms(availableRoomsFile);
    vector<string> occupiedRooms = readOccupiedRooms(occupiedRoomsFile);

    pair<string, vector<string>> result = allocateNextAvailableRoom(availableRooms, occupiedRooms);

//    cout << "The next available room is: " << result.first << endl;

    if (result.first != "No available rooms at the moment") {
//        cout << "Updated list of occupied rooms:" << endl;
        string r_room;
        for (const string& room : result.second) {
//            cout << room << endl;
            r_room=room;
        }
        return r_room;
//cout<<endl<<endl<<r_room;
    } else {
        cout << "No available rooms at the moment." << endl;
        return "";
    }

//    return 0;
}
