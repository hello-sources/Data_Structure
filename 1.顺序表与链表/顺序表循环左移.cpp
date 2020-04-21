#include <iostream>

using namespace std;

class Vector{
private :
    int size, length;
    int *data;
public:
    Vector(int input_size)
    {   
        size = input_size;
        length = 0;
        data = new int[size];
    }   
    ~Vector()
    {   
        delete [] data;
    }   
    
    bool insert(int loc, int value)
    {   
        if(loc < 0 || loc > length)
        {
            return false;
        }
        if(length >= size)
        {
            return false;
        }
        for(int i=length; i>loc; --i)
        {
            data[i] = data[i-1];
        }
        data[loc] = value;
        length++;
        return true;
    }   
    
    bool remove(int index)
    {   
        if(index < 0 || index >= length)
        {
            return false;
        }
        for(int i=index+1; i<length; i++)
        {
            data[i-1] = data[i];
        }
        length--;
        return true;
    }   
    
    int search(int value)
    {   
       for(int i=0; i<length; i++)
       {
           if(data[i] == value)
           {
               return i;
           }
       }
       return -1;
    }

    void print()
    {
        for(int i=0; i<length; i++)
        {
            if(i>0)
            {
                cout << " ";
            }
            cout << data[i];
        }
        cout << endl;
    }

    void expand()
    {
        int *old_data = data;
        size *= 2;
        data = new int[size];
        for(int i=0; i<length; i++)
        {
            data[i] = old_data[i];
        }
        delete [] old_data;
    }

    bool move_left(int offset)
    {
        if(offset < 0 || offset >= length)
        {
            return false;
        }
        
        //开辟临时空间存储右半部分数据结构
        int* temp_data = new int[offset];
        for(int i=0; i<offset; i++)
        {
            temp_data[i] = data[i];
        }
        
        //将左半部分数据结构整体向右偏移3位
        for(int i=0; i<length-offset; i++)
        {
            data[i] = data[i+offset];
        }

        //将左半边数据结构整追加
        for(int i=length, j=offset; j>0; --i, --j )
        {
            data[i-1]= temp_data[j-1];
        }

        delete [] temp_data;
        return true;
    }
};

int main()
{
    int n,k,value;
    cin >> n;
    cin >> k;
    Vector vec(n);
    for(int i=0; i<n; i++)
    {
        cin >> value;
        vec.insert(i,value);
    }
    vec.move_left(k);
    vec.print();
    return 0;
}   
