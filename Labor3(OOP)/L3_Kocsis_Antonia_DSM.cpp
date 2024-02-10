#include "L3_Kocsis_Antonia_DSM.h"

/** Konstruktor 1 **/

Dsm::Dsm(int elementCount) {
    if (elementCount < 0)
        throw invalid_argument("Invalid argument!!");
    current_size = elementCount;
    this->elementNames = new string[capacity];
    dependencyStrMatrix = new int *[capacity];
    for (int i = 0; i < elementCount; i++)
        dependencyStrMatrix[i] = new int[capacity];
    for (int i = 0; i < elementCount; i++)
        for (int j = 0; j < elementCount; j++)
            dependencyStrMatrix[i][j] = 0;
}

/** Konstruktor 2 **/

Dsm::Dsm(string elementNames[], int elementCount) {
    if (elementCount < 0)
        throw invalid_argument("Invalid argument!!");
    current_size = elementCount;
    this->elementNames = new string[7];
    for (int i = 0; i < current_size; i++)
        this->elementNames[i] = elementNames[i];
    dependencyStrMatrix = new int *[7];
    for (int i = 0; i < current_size; i++) {
        dependencyStrMatrix[i] = new int[7];
        for (int j = 0; j < current_size; j++)
            dependencyStrMatrix[i][j] = 0;
    }
}

/** Kopierkonstruktor **/

Dsm::Dsm(const Dsm &matrix) {
    //??
//    delete[]this->elementNames;
//    for (int i = 0; i < this->current_size; i++)
//        delete[] this->dependencyStrMatrix[i];
//    delete[] this->dependencyStrMatrix;
    // copy
    this->current_size = matrix.current_size;
    this->capacity = matrix.capacity;
    this->elementNames = new string[current_size];
    for (int i = 0; i < current_size; i++)
        this->elementNames[i] = matrix.elementNames[i];
    dependencyStrMatrix = new int *[current_size];
    for (int i = 0; i < current_size; i++)
        dependencyStrMatrix[i] = new int[current_size];
    for (int i = 0; i < current_size; i++)
        for (int j = 0; j < current_size; j++)
            dependencyStrMatrix[i][j] = matrix.dependencyStrMatrix[i][j];


}

/** Destruktor **/

Dsm::~Dsm() {
    delete[]elementNames;
    for (int i = 0; i < current_size; i++)
        delete[] dependencyStrMatrix[i];
    delete[] dependencyStrMatrix;
}

/** Resize up **/
void Dsm::resize_up() {
    int newCapacity = 2 * capacity;
    string *newElementNames = new string[newCapacity];

    for (int i = 0; i < capacity; i++)
        newElementNames[i] = elementNames[i];
    int **newDependencyStrMatrix = new int *[newCapacity];
    for (int i = 0; i < capacity; i++)
        newDependencyStrMatrix[i] = new int[newCapacity];
    for (int i = 0; i < capacity; i++)
        for (int j = 0; j < capacity; j++)
            newDependencyStrMatrix[i][j] = dependencyStrMatrix[i][j];
    for (int i = 0; i < capacity; i++)
        delete[] dependencyStrMatrix[i];
    delete[] dependencyStrMatrix;
    delete[] elementNames;
    this->elementNames = newElementNames;
    this->dependencyStrMatrix = newDependencyStrMatrix;
    this->capacity = newCapacity;

}

/** Printing matrix **/
void Dsm::printDsm() {
    for (int i = 0; i < 112; i++)
        cout << "-";
    cout << endl;
    cout << "--Printing Dependency-Structure-Matrix--" << endl << endl;
    for (int i = 0; i < current_size; i++) {
        for (int j = 0; j < current_size; j++)
            cout << dependencyStrMatrix[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < 112; i++)
        cout << "-";
}

/** Printing elements **/
void Dsm::printElems() {
    for (int i = 0; i < 112; i++)
        cout << "-";
    cout << endl;
    cout << "--Printing Elements--" << endl << endl;
    for (int i = 0; i < current_size; i++)
        cout << elementNames[i] << endl;
    cout << endl;
    for (int i = 0; i < 112; i++)
        cout << "-";
    cout << endl;
}

int Dsm::size() const {
    return current_size;
}

void Dsm::update_attr(string element) {
    if (current_size == capacity)
        resize_up();
    elementNames[current_size] = element;
    int **new_matrix = new int *[capacity];
    for (int i = 0; i < current_size + 1; i++)
        new_matrix[i] = new int[capacity];
    for (int i = 0; i < current_size + 1; i++)
        for (int j = 0; j < current_size + 1; j++) {
            if (i != current_size && j != current_size)
                new_matrix[i][j] = dependencyStrMatrix[i][j];
            else
                new_matrix[i][j] = 0;
        }
    for (int i = 0; i < current_size; i++)
        delete[] dependencyStrMatrix[i];
    delete[] dependencyStrMatrix;
    dependencyStrMatrix = new_matrix;
    current_size++;
}

string Dsm::getName(int index) {
    if (index < 0 || current_size == 0 || index > current_size - 1)
        throw invalid_argument("Invalid argument!");
    return elementNames[index];
}

void Dsm::setElementName(int index, const string &elementName) {
    if (index < 0 || index >= current_size)
        throw invalid_argument("Invalid argument!");
    if (index < current_size)
        elementNames[index] = elementName;
}

void Dsm::addLink(const string &fromElement, const string &toElement, int weight) {
    if (current_size == capacity)
        resize_up();
    int index_to = -1;
    int index_from = -1;
    for (int i = 0; i < current_size; i++) {
        if (elementNames[i] == fromElement)
            index_from = i;
        if (elementNames[i] == toElement)
            index_to = i;
    }
    if (index_from != -1 && index_to != -1)
        dependencyStrMatrix[index_from][index_to] = weight;
    else if (index_from == -1) {
        update_attr(fromElement);
        index_from = current_size - 1;
        if (index_to == -1) {
            update_attr(toElement);
            index_to = current_size - 1;

        }
        dependencyStrMatrix[index_from][index_to] = weight;

    } else {
        update_attr(toElement);
        index_to = current_size - 1;
        dependencyStrMatrix[index_from][index_to] = weight;
    }

}

void Dsm::deleteLink(const string &fromElement, const string &toElement) {
    int index_to = -1;
    int index_from = -1;
    for (int i = 0; i < current_size; i++) {
        if (elementNames[i] == fromElement)
            index_from = i;
        if (elementNames[i] == toElement)
            index_to = i;
    }
    if (index_from == -1 || index_to == -1)
        throw invalid_argument("Invalild argument!");
    dependencyStrMatrix[index_from][index_to] = 0;

}

bool Dsm::hasLink(const string &fromElement, const string &toElement) {
    int index_to = -1;
    int index_from = -1;
    for (int i = 0; i < current_size; i++) {
        if (elementNames[i] == fromElement)
            index_from = i;
        if (elementNames[i] == toElement)
            index_to = i;
    }
    if (dependencyStrMatrix[index_from][index_to] != 0)
        return true;
    return false;
}

int Dsm::linkWeight(const string &fromElement, const string &toElement) {
    if (!hasLink(fromElement, toElement))
        return 0;
    int index_to = -1;
    int index_from = -1;
    for (int i = 0; i < current_size; i++) {
        if (elementNames[i] == fromElement)
            index_from = i;
        if (elementNames[i] == toElement)
            index_to = i;
    }
    return dependencyStrMatrix[index_from][index_to];

}

int Dsm::countFromLinks(const string &elementName) {
    int fromLinks = 0;
    int index = -1;
    for (int i = 0; i < current_size; i++)
        if (elementName == elementNames[i])
            index = i;
    if (index == -1)
        throw invalid_argument("Invalid argument!");
    for (int j = 0; j < current_size; j++)
        if (dependencyStrMatrix[index][j] != 0)
            fromLinks++;
    return fromLinks;
}

int Dsm::countToLinks(const string &elementName) {
    int toLinks = 0;
    int index = -1;
    for (int i = 0; i < current_size; i++)
        if (elementName == elementNames[i])
            index = i;
    if (index == -1)
        throw invalid_argument("Invalid argument!");
    for (int j = 0; j < current_size; j++)
        if (dependencyStrMatrix[j][index] != 0)
            toLinks++;
    return toLinks;
}

int Dsm::countAllLinks() {
    int count = 0;
    for (int i = 0; i < current_size; i++)
        for (int j = 0; j < current_size; j++)
            if (dependencyStrMatrix[i][j] != 0)
                count++;
    return count;
}

void Dsm::writeToFile() {
    ofstream file;
    file.open("output.txt");
    for (int i = 0; i < current_size; i++) {
        string fromElementName = elementNames[i];
        for (int j = 0; j < current_size; j++) {
            string toElementName = elementNames[j];
            if (dependencyStrMatrix[i][j] != 0) {
                string output = fromElementName + "," + to_string(dependencyStrMatrix[i][j]) + "," + toElementName;
                file << output;
                file << endl;
            }
        }
    }
}

Dsm Dsm::writeFromFile() {
    ifstream file;
    file.open("output.txt");
    string line;
    string *elements = new string[200];
    string *forRelation = new string[200];
    int total_relations = 0;
    int elem_size = 0;
    while (getline(file, line)) {

        string word;
        int ct = 0;
        for (char c: line) {
            if (c != ',') {
                word += c;
            } else {
                ct++;
                bool unique = true;
                for (int i = 0; i < elem_size; i++)
                    if (elements[i] == word) {
                        unique = false;
                        break;
                    }
                if (unique && ct != 2) {
                    elements[elem_size] = word;
                    elem_size++;
                }

                forRelation[total_relations] = word;
                total_relations++;

                word.clear();

            }

        }
        bool unique = true;
        for (int i = 0; i < elem_size; i++)
            if (elements[i] == word) {
                unique = false;
                break;
            }
        if (unique) {
            elements[elem_size] = word;
            elem_size++;
        }
        forRelation[total_relations] = word;
        total_relations++;

    }
    Dsm matrix(elements, elem_size);
    for (int i = 0; i < total_relations; i++) {

        matrix.addLink(forRelation[i], forRelation[i + 2], stoi(forRelation[i + 1]));
        i = i + 2;
    }
    return matrix;
}