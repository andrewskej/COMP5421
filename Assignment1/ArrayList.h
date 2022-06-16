#ifndef ArrayList_h
#define ArrayList_h
using std::ostream;

class ArrayList {
private:
    int* pArray;  //pointer of the Arraylist
    int capacity; //whole size of the Arraylist
    int used;     //used size of the Arraylist
    void resize(); //resize the Arraylist
public:
    ArrayList();  //basic constructor

    ArrayList(const ArrayList&); //copy constructor

    ArrayList(ArrayList&&) noexcept; //move constructor

    virtual ~ArrayList(); //destructor

    ArrayList& operator=(const ArrayList& rhs); //copy assignment

    ArrayList& operator=(ArrayList&& rhs) noexcept; //move assignment

    bool empty() const; //checks if empty

    bool full() const; //checks if full

    int size() const; //returns its size

    void pushBack(int x); //push the value into the Arraylist

    bool contains(int x) const; //checks if the Arraylist contains the given value

    bool get(int position, int& value) const; //checks if the given value is located at given position

    int getCapacity() const; //returns capacity of the Arraylist

    void print(ostream& sout) const; //print the Arraylist

};

ostream& operator<<(ostream& sout, const ArrayList& f); //operator overloading

#endif 