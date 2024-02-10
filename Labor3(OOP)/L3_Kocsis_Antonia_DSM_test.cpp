#include <iostream>
#include "L3_Kocsis_Antonia_DSM.h"
#include <cassert>

void CountLinksTest(Dsm matrix) {
    cout << "------ Has link test ------" << endl;
    assert(matrix.hasLink("Emergency Department", "Inpatient Ward") == 1);
    cout << "------ Link weight test ------" << endl;
    assert(matrix.linkWeight("Laboratory", "Medical Equipment") == 40);
    cout << "------ Count from links test ------" << endl;
    assert(matrix.countFromLinks("Emergency Department") == 5);
    cout << "------ Count to links test ------" << endl;
    assert(matrix.countToLinks("Medical Equipment") == 4);
    cout << "------ Count all links test ------" << endl;
    assert(matrix.countAllLinks() == 14);
    cout << endl;

}

Dsm myExample() {

    string strings[3] = {"Emergency Department", "Operating Rooms", "Radiology Department"};
    Dsm matrix(strings, 3);
    matrix.addLink("Emergency Department", "Radiology Department", 20);
    matrix.addLink("Emergency Department", "Pharmacy", 20);
    matrix.addLink("Emergency Department", "Inpatient Ward", 20);
    matrix.addLink("Emergency Department", "Laboratory", 20);
    matrix.addLink("Emergency Department", "Medical Equipment", 20);
    matrix.addLink("Operating Rooms", "Laboratory", 30);
    matrix.addLink("Operating Rooms", "Radiology Department", 30);
    matrix.addLink("Operating Rooms", "Medical Equipment", 30);
    matrix.addLink("Radiology Department", "Medical Equipment", 30);
    matrix.addLink("Inpatient Ward", "Operating Rooms", 20);
    matrix.addLink("Inpatient Ward", "Radiology Department", 20);
    matrix.addLink("Inpatient Ward", "Pharmacy", 20);
    matrix.addLink("Inpatient Ward", "Laboratory", 20);
    matrix.addLink("Laboratory", "Medical Equipment", 40);
    return matrix;
}

void addLinkTest(Dsm matrix) {
    cout << "------ Add link test------" << endl;
    matrix.addLink("Laboratory", "Medical Equipment", 40);
    assert(matrix.linkWeight("Laboratory", "Medical Equipment") == 40);
}

void deleteLinkTest(Dsm matrix) {
    cout << "------ Delete link test ------" << endl;
    matrix.deleteLink("Laboratory", "Medical Equipment");
    assert(matrix.linkWeight("Laboratory", "Medical Equipment") == 0);
}

void sizeTest(Dsm matrix) {
    cout << endl;
    cout << "------ Size test ------" << endl;
    assert(matrix.size() == 7);
}

void getNameTest(Dsm matrix) {
    cout << "------ Get name test ------" << endl;
    assert(matrix.getName(0) == "Emergency Department");


}

void setElementNameTest(Dsm matrix) {
    cout << "------ Set element test ------" << endl;
    matrix.setElementName(0, "hello");
    assert(matrix.getName(0) == "hello");
    matrix.setElementName(0, "Emergency Department");

}


bool found(int matrixElemsSize, string *matrixElems, string elem) {
    for (int i = 0; i < matrixElemsSize; i++)
        if (elem == matrixElems[i])
            return true;
    return false;

}

void bonusTest() {
    cout << "------ Bonus test ------" << endl;
    Dsm matrix = myExample();
    matrix.writeToFile();
    Dsm newMatrix = matrix.writeFromFile();
    string *matrixElems = new string[7];
    int matrixElemsSize = 0;
    int newMatrixElemsSize = 0;
    string *newMatrixElems = new string[7];
    for (int i = 0; i < matrix.size(); i++) {
        matrixElems[matrixElemsSize] = matrix.getName(i);
        matrixElemsSize++;
    }
    for (int i = 0; i < matrix.size(); i++) {
        newMatrixElems[newMatrixElemsSize] = newMatrix.getName(i);
        newMatrixElemsSize++;
    }
    for (int i = 0; i < newMatrixElemsSize; i++)
        assert(found(matrixElemsSize, matrixElems, newMatrixElems[i]) == true);

    for (int i = 0; i < matrixElemsSize; i++)
        for (int j = 0; j < matrixElemsSize; j++)
            if (i != j)
                if (matrix.hasLink(matrixElems[i], matrixElems[j]))
                    assert(newMatrix.hasLink(matrixElems[i], matrixElems[j]) == true);

}

void allTests() {
    for (int i = 0; i < 112; i++)
        cout << "-";
    cout << endl;
    Dsm matrix = myExample();
    sizeTest(matrix);
    getNameTest(matrix);
    setElementNameTest(matrix);
    addLinkTest(matrix);
    deleteLinkTest(matrix);
    CountLinksTest(matrix);
    bonusTest();
    for (int i = 0; i < 112; i++)
        cout << "-";
    cout << endl;
}

void printingElementsAndMatrix() {
    Dsm matrix = myExample();
    matrix.printElems();
    matrix.printDsm();
}

int main() {
    printingElementsAndMatrix();
    allTests();

    return 0;
}
