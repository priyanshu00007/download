#include <iostream>
#include <list>
#include <vector>
#include <string>

class StringHashTable {
private:
    static const int hashGroups = 10;
    std::vector<std::list<std::pair<std::string, int>>> table;

    // Hash function to convert a string key into an index
    int hashFunction(const std::string& key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue += ch;
        }
        return hashValue % hashGroups;
    }

public:
    StringHashTable() {
        table.resize(hashGroups);
    }

    // Insert a key-value pair
    void insert(const std::string& key, int value) {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        // Check for existing key
        for (auto& pair : cell) {
            if (pair.first == key) {
                std::cout << "Key already exists. Updating value.\n";
                pair.second = value;
                return;
            }
        }
        cell.emplace_back(key, value);
        std::cout << "Key-value pair inserted.\n";
    }

    // Search for a value using a key
    int search(const std::string& key) {
        int hashValue = hashFunction(key);
        const auto& cell = table[hashValue];
        for (const auto& pair : cell) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        // Return a sentinel value if key is not found
        std::cout << "Key not found. Returning -1." << std::endl;
        return -1;
    }

    // Delete a key-value pair
    void remove(const std::string& key) {
        int hashValue = hashFunction(key);
        auto& cell = table[hashValue];
        for (auto it = cell.begin(); it != cell.end(); ++it) {
            if (it->first == key) {
                cell.erase(it);
                std::cout << "Key-value pair removed.\n";
                return;
            }
        }
        std::cout << "Key not found. Nothing to remove.\n";
    }

    // Display the entire hash table
    void display() {
        for (int i = 0; i < hashGroups; ++i) {
            std::cout << "Bucket " << i;
            if (table[i].empty()) {
                std::cout << " -> (empty)\n";
            } else {
                std::cout << " -> ";
                for (const auto& pair : table[i]) {
                    std::cout << "(" << pair.first << ", " << pair.second << ") -> ";
                }
                std::cout << "end\n";
            }
        }
    }
};

int main() {
    StringHashTable ht;
    ht.insert("John", 101);
    ht.insert("Lisa", 102);
    ht.insert("David", 103);
    ht.insert("Mary", 104);

    ht.display();

    std::cout << "\nSearching for key 'Lisa': " << ht.search("Lisa") << std::endl;
    std::cout << "Searching for key 'Peter': " << ht.search("Peter") << std::endl;
    
    ht.remove("David");
    ht.remove("Peter");

    ht.display();

    return 0;
}
// #include <iostream>
// #include <list>
// #include <vector>

// class HashTable {
// private:
//     static const int hashGroups = 10;
//     // The table is a vector of lists (for chaining)
//     std::vector<std::list<std::pair<int, std::string>>> table;

//     // The hash function to map a key to an index
//     int hashFunction(int key) {
//         return key % hashGroups;
//     }

// public:
//     HashTable() {
//         // Initialize the vector with a fixed size
//         table.resize(hashGroups);
//     }

//     // Insert a key-value pair
//     void insert(int key, std::string value) {
//         int hashValue = hashFunction(key);
//         // Get the list at the hash index
//         auto& cell = table[hashValue];
//         // Check if the key already exists
//         for (auto& pair : cell) {
//             if (pair.first == key) {
//                 std::cout << "Key already exists. Updating value.\n";
//                 pair.second = value;
//                 return;
//             }
//         }
//         // If key doesn't exist, add the new pair to the list
//         cell.emplace_back(key, value);
//         std::cout << "Key-value pair inserted.\n";
//     }

//     // Search for a value using a key
//     std::string search(int key) {
//         int hashValue = hashFunction(key);
//         const auto& cell = table[hashValue];
//         for (const auto& pair : cell) {
//             if (pair.first == key) {
//                 return pair.second;
//             }
//         }
//         return "Key not found.";
//     }

//     // Delete a key-value pair
//     void remove(int key) {
//         int hashValue = hashFunction(key);
//         auto& cell = table[hashValue];
//         for (auto it = cell.begin(); it != cell.end(); ++it) {
//             if (it->first == key) {
//                 cell.erase(it);
//                 std::cout << "Key-value pair removed.\n";
//                 return;
//             }
//         }
//         std::cout << "Key not found. Nothing to remove.\n";
//     }

//     // Display the entire hash table
//     void display() {
//         for (int i = 0; i < hashGroups; ++i) {
//             std::cout << "Bucket " << i;
//             if (table[i].empty()) {
//                 std::cout << " -> (empty)\n";
//             } else {
//                 std::cout << " -> ";
//                 for (const auto& pair : table[i]) {
//                     std::cout << "(" << pair.first << ", " << pair.second << ") -> ";
//                 }
//                 std::cout << "end\n";
//             }
//         }
//     }
// };

// int main() {
//     HashTable ht;
//     ht.insert(10, "Apple");
//     ht.insert(20, "Banana");
//     ht.insert(30, "Cherry");
//     ht.insert(40, "Date");
//     ht.insert(50, "Elderberry"); // This will cause a collision with 20

//     ht.display();

//     std::cout << "\nSearching for key 20: " << ht.search(20) << std::endl;
//     std::cout << "Searching for key 25: " << ht.search(25) << std::endl;
    
//     ht.remove(30);
//     ht.remove(25);

//     ht.display();

//     return 0;
// }