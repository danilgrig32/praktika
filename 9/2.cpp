#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <windows.h>

using namespace std;

string remove_extra_spaces(const string& input) {
    string result;
    unique_copy(input.begin(), input.end(), back_inserter(result),
                [](char a, char b) { return isspace(a) && isspace(b); });
    return result;
}

string process_string(const string& line) {
    string processed = remove_extra_spaces(line);

    size_t start = processed.find_first_not_of(" \t");
    if (start != string::npos) {
        size_t end = processed.find_last_not_of(" \t");
        processed = processed.substr(start, end - start + 1);
    } else {
        processed = "";
    }

    if (!processed.empty()) {
        processed = "НАЧАЛО " + processed + " КОНЕЦ";
    } else {
        processed = "НАЧАЛО КОНЕЦ";
    }
    
    return processed;
}

void process_files(const string& input_filename, const string& output_filename) {
    ifstream in_file(input_filename);
    ofstream out_file(output_filename);
    
    if (!in_file.is_open()) {
        cerr << "Не удалось открыть входной файл " << input_filename << endl;
        return;
    }
    
    if (!out_file.is_open()) {
        cerr << "Не удалось открыть выходной файл " << output_filename << endl;
        in_file.close();
        return;
    }
    
    string line;
    while (getline(in_file, line)) {
        string processed_line = process_string(line);
        out_file << processed_line << endl;
    }
    
    in_file.close();
    out_file.close();
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    process_files("9/F1.txt", "9/F2.txt");
    
    return 0;
}
