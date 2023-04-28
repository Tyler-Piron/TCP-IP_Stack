#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileWriter {
private:
    string filename;

public:
    FileWriter(string filename) {
        this->filename = filename;
    }

    void writeToFile(string content) {
        ofstream file;
        file.open(filename);
        file << content;
        file.close();
        cout << "File saved to " << filename << endl;
        system(("start " + filename).c_str()); // opens file directly on Windows
    }
};

//int main() {
 //   string content = "This is the content that will be written to the file.";
  //  FileWriter writer("example.txt");
  //  writer.writeToFile(content);
  //  return 0;
//}
