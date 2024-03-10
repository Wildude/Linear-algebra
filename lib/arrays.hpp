// simplifying namespace usage.
using namespace std;
template <class T>
// implementing the array class.
class array{
    private: // private data-fields.
        T* p; // the pointer to any data-type.
        int size; // the size of the array.
    public:
     // default constructor.
    array(){
        size = 0;
        p = NULL;
    }
    // returns the pointer of the array.
    T* getp(){ 
        return p;
    }
    // returns the size of the array.
    int getsize(){
        return size;
    }
    // resets the size and elements of the array (as well as the pointer).
    void reset(T* p, int size){
        delete this->p;
        this->size = size;
        this->p = new T[size];
        copy_array(p, &this->p, size);
    }
    // copies an array onto another.
    template <class W>
    static void copy_array(W* list, W** list2, int size){
        for(int i = 0; i < size; i++){
            list2[0][i] = list[i];
        }
    }
    // copies this array onto another.
    void copy_array(T** list2, int size = 0){
        size = (size ? size : this->size);
        copy_array(p, list2, size);
    }
    // displays an array.
    template <class W>
    static void display(W* list, int size){
        for(int i = 0; i < size; i++){
            cout << ' ' << (i + 1) << ". " << list[i] << endl;
        }
    }
    // displays this array.
    void display(){
        display<T>(p, size);
    }
    // sorts an array.
    template <class W>
    static void sort(W** list, int size){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(list[0][i] < list[0][j]){
                    swap(list[0][i], list[0][j]);
                }
            }
        }
    }
    // sorts this array.
    void sort(){
        sort(&p, size);
    }
    // removes the duplicate of this array.
    void dup_rem(){
        sort();
        int* duplicate_indices = new int[size];
        int count = 0;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(i == j)continue;
                if(p[i] == p[j]){
                    if(i > j){
                        break;
                    }
                    duplicate_indices[count++] = j;
                }
            }
        }
        int original_size = size;
        T* temporary_list = new T[original_size - count];
        int count2 = 0;
        for(int i = 0; i < size; i++){
            bool not_duplicate = true;
            for(int j = 0; j < count; j++){
                if(i == duplicate_indices[j]){
                    not_duplicate = false;
                    break;
                }
            }
            if(not_duplicate){
                temporary_list[count2++] = p[i];
            }
        }
        delete p;
        p = new int[original_size - count];
        size = original_size - count;
        copy_array(temporary_list, &p, original_size - count);
    }
    void accept(){
        cout << " Enter " << size << " elements:\n";
        for(int i = 0; i < size; i++){
            cout << ' ' << (i + 1) <<". ";
            cin >> p[i];
        }
    }
    // searches for an element in an array.
    template <class W>
    static int search(W* list, W item, int n){
        for(int i = 0; i < n; i++){
            if(item == list[i])return i;
        }
        return -1;
    }
    // searches for an element in this array.
    int search(T item){
        return search(this->p, item, this->size);
    }
};
