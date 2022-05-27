#ifndef ArrayList_h
#define ArrayList_h
using std::ostream;

class ArrayList {
    private:
        int *pArray;
        int capacity;
        int used;
        void resize();
    public:
        ArrayList();
    
        ArrayList(const ArrayList&);

        ArrayList(ArrayList&&) noexcept;
        
        virtual ~ArrayList();
        
        ArrayList& operator=(const ArrayList& rhs);
        
        ArrayList& operator=(ArrayList&& rhs) noexcept;

        bool empty() const;
        
        bool full() const;
        
        int size() const;
            
        void pushBack(int x);
            
        bool contains (int x) const;
            
        bool get (int position, int& value) const;
            
        int getCapacity() const;
            
        void print (ostream& sout) const;
    
};

ostream& operator<<(ostream& sout, const ArrayList& f);

#endif 
