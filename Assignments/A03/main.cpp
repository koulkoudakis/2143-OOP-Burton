///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Sharome Burton
// Email:            koulkoudakis@gmail.com
// Label:            A03
// Title:            Commenting Code
// Course:           CMPS 2143
// Semester:         Spring 2021
//
// Description:
//       This program implements a list data structure that links together nodes of integers.
//       
// Usage: 
//      - $ ./main filename
//      - This will read in a file containing whatever values to be read into our list/array. 
//      
// Files:            
//      main.cpp    : driver program 
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;


/**
 * CircularArrayQue
 * 
 * Description:
 *      This class implements a list data structure that links together nodes of integers.
 * 
 * Public Methods:
 *                          CircularArrayQue()
 *                          CircularArrayQue(int size)
 *      void                Push(int item)
 *      int                 Pop()
 * 
 * Private Methods:
 *      bool                Full()
 * 
 * Usage: 
 * 
 *      CircularArrayQue():                        // Create Instance of a queue using default size(10)
 *      CircularArrayQue(int size)                 // Create Instance of a queue using user-defined
                                                   // integer value for size
 *      
 *      Push(int item)                             // Push a new integer to the queue
 *      Pop()                                      // Pop an integer from the rear of the queue
 *      
 *
 *      Full()                                     // Checks whether queue is full in order to
 *                                                 // provide appropriate feedback to user
 *                                                 // and prevent data corruption
 */

class CircularArrayQue {
private:
    int *Container;                     // Pointer to new array to hold integers
    int Front;                          // Front of queue
    int Rear;                           // Rear of queue
    int QueSize;                        // Declared size of queue
    int CurrentSize;                    // Current number of items in the queue
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }
    
        /**
     * Private: full
     * 
     * Description:
     *      Checks whether queue is full in order to provide appropriate feedback to user
     *      and prevent data corruption
     * 
     * Params:
     * 
     * Returns:
     *      CurrentSize   : Current number of items in the queue
     */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    
    /**
     * Public : CircularArrayQue
     * 
     * Description:
     *      Constructor for a list data structure that links together nodes of integers.
     * 
     * Params:
     * 
     * Returns:
     */
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    
     /**
     * Public : CircularArrayQue
     * 
     * Description:
     *      Constructor for a list data structure that links together nodes of integers.
     * 
     * Params:
     *      int     :  array size
     * Returns:
     */
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }
    
     /**
     * Public : Push
     * 
     * Description:
     *      Push a new integer to the queue
     * 
     * Params:
     *      int item    :  integer value to add to queue
     * 
     * Returns:
     */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

        /**
     * Public : Pop
     * 
     * Description:
     *      
            Pop an integer from the rear of the queue
     * 
     * Params:
     * 
     * Returns:
     *      temp   : integer that was popped from queue
     */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};


// Overloaded operator used to simplify outputing contents of queue
ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
