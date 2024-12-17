#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Structure to store personal record details
struct PersonalRecord
{
    string name;
    string dob;
    string phone;

    // Overloading < operator to compare PersonalRecord by name (for sorting)
    bool operator<(const PersonalRecord& other) const
    {
        return name < other.name;  // Compare by name
    }

    // Overloading == operator to check if two PersonalRecord objects are equal (by name)
    bool operator==(const PersonalRecord& other) const
    {
        return name == other.name;  // Check if names are equal
    }
};

// Vector to store the records
vector<PersonalRecord> records;

// Function to insert a new record into the vector
void insertRecord()
{
    PersonalRecord record;
    cout << "Enter Name: ";
    cin.ignore();  // Clear the input buffer to avoid issues with getline
    getline(cin, record.name);  
    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    getline(cin, record.dob);  
    cout << "Enter Telephone Number: ";
    getline(cin, record.phone);  
    records.push_back(record);  
}

// Function to display all records
void displayRecords()
{
    if (records.empty())  // Check if there are no records
    {
        cout << "\nNo records available.\n";
        return;
    }
    cout << "\n--- Personnel Records ---\n";
    // Loop through the records vector and display each record
    for (const auto& record : records)
    {
        cout << "Name: " << record.name << "\n";
        cout << "Date of Birth: " << record.dob << "\n";
        cout << "Telephone Number: " << record.phone << "\n";
        cout << "----------------------------\n";
    }
}

// Function to search a record by name
void searchRecord()
{
    string name;
    cout << "\nEnter Name to Search: ";
    cin.ignore();  // To clear the input buffer
    getline(cin, name);  // Get the name to search

    // Find the record by name using find_if and lambda function
    auto it = find_if(records.begin(), records.end(), [&name](const PersonalRecord& record)
    {
        return record.name == name;  // Compare the name
    });

    // Check if the record was found and display the result
    if (it != records.end())
    {
        cout << "\nRecord Found!\n";
        cout << "Name: " << it->name << "\n";
        cout << "Date of Birth: " << it->dob << "\n";
        cout << "Telephone Number: " << it->phone << "\n";
    }
    else
    {
        cout << "\nRecord not found!\n";
    }
}

// Function to sort records by name
void sortRecords()
{
    sort(records.begin(), records.end());  // Sort the vector using overloaded < operator
    cout << "\nRecords have been sorted by name.\n";
}

// Function to delete a record by name
void deleteRecord()
{
    string name;
    cout << "\nEnter Name to Delete: ";
    cin.ignore();  // To clear the input buffer
    getline(cin, name);  // Get the name of the record to delete

    // Find the record and remove it using remove_if and lambda function
    auto it = remove_if(records.begin(), records.end(), [&name](const PersonalRecord& record)
    {
        return record.name == name;  // Compare the name to find the record to delete
    });

    // If the record was found, erase it from the vector
    if (it != records.end())
    {
        records.erase(it, records.end());  // Remove the element from the vector
        cout << "\nRecord deleted successfully.\n";
    }
    else
    {
        cout << "\nRecord not found!\n";
    }
}

int main()
{
    int choice;  // To store the user's menu choice
    do
    {
        // Display menu for user interaction
        cout << "\n***** Menu *****";
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Sort";
        cout << "\n5. Delete";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;  // Get the user's choice

        switch (choice)
        {
        case 1:
            insertRecord();  
            break;
        case 2:
            displayRecords();  
            break;
        case 3:
            searchRecord();  
            break;
        case 4:
            sortRecords();  
            break;
        case 5:
            deleteRecord();  
            break;
        case 6:
            cout << "Exiting...\n";  
            break;
        default:
            cout << "Invalid choice! Please try again.\n";  
        }
    }
    while (choice != 6);  

    return 0;  
}

////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class item {
public:
    char name[20];
    int qty;
    float cost;
    int code;
    bool operator==(const item& i1) const {
        return code == i1.code;
    }
    bool operator<(const item& i1) const {
        return code < i1.code;
    }
};
vector<item> v1;
void print(const item& i1) {
    cout << "Name : " << i1.name << endl;
    cout << "Quantity : " << i1.qty << endl;
    cout << "Cost : " << i1.cost << endl;
    cout << "Code : " << i1.code << endl;
}
void insert() {
    item i1;
    cout << "Enter name of item : ";
    cin >> i1.name;
    cout << "Enter qty : ";
    cin >> i1.qty;
    cout << "Enter the cost : ";
    cin >> i1.cost;
    cout << "Enter the code : ";
    cin >> i1.code;
    v1.push_back(i1);
    
}
void search() {
    int code;
    cout << "Enter the code to search : ";
    cin >> code;
    item temp;
    temp.code = code;
    vector<item> :: iterator it;
    it = find(v1.begin(), v1.end(), temp);
    if (it != v1.end()) {
        cout << "Item found:" << endl;
        print(*it);
    } else {
        cout << "Item not found." << endl;
    }
}
void display() {
    if (v1.empty()) {
        cout << "No items to display." << endl;
        return;
    }
    cout << "Displaying all items:" << endl;
    for_each(v1.begin(), v1.end(), print);
}
bool compare(const item& i1, const item& i2) {
    return i1.cost < i2.cost;
}

int main() {
    int choice;
    while (true) {
        cout << "\n..........MENU.........." << endl;
        cout << "1. Insert an item" << endl;
        cout << "2. Search for an item" << endl;
        cout << "3. Display all items" << endl;
        cout << "4. Sort items by cost" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                display();
                break;
            case 4:
                sort(v1.begin(), v1.end(), compare);
                cout << "Items sorted by cost:" << endl;
                display();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}




