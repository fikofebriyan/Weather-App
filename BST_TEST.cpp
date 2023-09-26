#include <iostream>
#include <string>

#include <fstream>

#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree<int> BSTs;


void PrintData(int &data)
{
    cout << data << " ";
}

int main7(void)
{
        BSTs.insertNode(7);
        BSTs.insertNode(1);
        BSTs.insertNode(88);
        BSTs.insertNode(45);
        BSTs.insertNode(71);
        BSTs.insertNode(11);
        BSTs.insertNode(80);
        BSTs.insertNode(13);
        BSTs.insertNode(48);

        cout << "Print tree pre order before adding numbers" <<endl;
        BSTs.preOrderTraversal(PrintData);
        cout <<endl;
        cout << "=========================================" << endl;

        cout << "Print tree in order before adding numbers" <<endl;
        BSTs.inOrderTraversal(PrintData);
        cout <<endl;
        cout << "=========================================" << endl;

        cout << "Print tree post order before adding numbers" <<endl;
        BSTs.postOrderTraversal(PrintData);
        cout <<endl;
        cout << "=========================================" << endl;

        cout << "Higest value in the tree is : " <<  BSTs.MaximumValue() << endl;
        cout << "=========================================" << endl;

        cout << "Lowest value in the tree is: " << BSTs.minValue() << endl;
        cout << "=========================================" << endl;

        for (int i = 0; i<25; i++)
        {
            BSTs.insertNode(i);
        }
        cout << "Total nodes in the tree" << endl;
        BSTs.inOrderTraversal(PrintData);
        cout <<endl;
        cout << "======================================" << endl;

        cout << "After clearing nodes, re-print 0-25" << endl;
        BSTs.DeleteTree();
        for (int i = 0; i<=25; i++)
        {
            BSTs.insertNode(i);
        }
        BSTs.inOrderTraversal(PrintData);
        cout <<endl;
        cout << "======================================" << endl;

        int findNode;
        cout << "Enter number to see if there is node in the tree (1=true,0=false) : ";
        cin >> findNode;
        cout << BSTs.searchNode(findNode);
        cout << endl;

}
