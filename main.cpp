#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

void searchAskDelete(const string& filename, const string& word) {
    ifstream file(filename);
    string line;
    bool found = false;

    // 🔎 مرحله 1: سرچ
    while (getline(file, line)) {
        if (line.find(word) != string::npos) {
            cout << "Found: " << line << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Not found!" << endl;
        return;
    }

    // ❓ مرحله 2: سوال از کاربر
    char choice;
    cout << "Do you want to delete it? (y/n): ";
    cin >> choice;

    if (choice != 'y' && choice != 'Y') {
        cout << "Nothing deleted." << endl;
        return;
    }

    // 🧨 مرحله 3: حذف از فایل
    ifstream file2(filename);
    ofstream temp("temp.txt");

    while (getline(file2, line)) {
        if (line.find(word) == string::npos) {
            temp << line << endl;
        }
    }

    file2.close();
    temp.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    cout << "Deleted successfully!" << endl;
}

int main() {
    string name, num, word;

    // 📝 گرفتن اطلاعات
    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Number: ";
    cin >> num;

    // 💾 ذخیره در فایل number.txt
    ofstream file("number.txt", ios::app);
    file << name << " " << num << endl;
    file.close();

    // 🔍 سرچ + حذف
    cout << "Enter word to search: ";
    cin >> word;

    searchAskDelete("number.txt", word);

    return 0;
}
