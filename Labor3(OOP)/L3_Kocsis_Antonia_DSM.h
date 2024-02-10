#include <iostream>
#include <fstream>

using namespace std;

class Dsm {
private:
    int **dependencyStrMatrix;
    int current_size;
    int capacity = 7;
    string *elementNames;


    void resize_up();

public:

    /** Konstruktor 1 **/

    Dsm(int elementCount);

    /** Konstruktor 2 **/

    Dsm(string elementNames[], int elementCount);

    /** Destruktor **/

    ~Dsm();

    /** Kopierkonstruktor **/
    Dsm(const Dsm &matrix);

    void printDsm();

    void printElems();

    int size() const;

    string getName(int index);

    void update_attr(string element);

    void setElementName(int index, const string &elementName);

    void addLink(const string &fromElement, const string &toElement, int weight);

    void deleteLink(const string &fromElement, const string &toElement);

    bool hasLink(const string& fromElement, const string& toElement);

    int linkWeight(const string& fromElement, const string& toElement);

    int countToLinks(const string& elementName);

    int countFromLinks(const string& elementName);

    int countAllLinks();

    void writeToFile();
    static Dsm writeFromFile();

};