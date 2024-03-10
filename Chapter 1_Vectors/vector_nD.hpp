#include "../lib/inclusions.hpp"
template <typename T>
// inherits from array<T> class.
// implementation of vector in n-space.
class vector_nD: public array<T>{
    private: // no private data-fields.
    public: // here the public data-fields.
        // constructor.
        // takes a pointer to a list and the size to copy.
        vector_nD(T* list, int size){
            // calls reset in array<T>.
            this->reset(list, size);
        }
        // default constructor.
        vector_nD(){
            // does nothing.
        }
        // overloading the output stream.
        // this helps display contents of the vector like any other datatype using cout.
        template <class W>
        friend ostream& operator<<(ostream& os, vector_nD<W> vect){
            os << '(' ;
            for(int i = 0; i < vect.getsize(); i++){
                os << vect.getp()[i];
                if(i != vect.getsize() - 1) os << ", ";
            }
            os << ')';
            return os;
        }
        // overloading addition (for vector addtion).
        template <class W>
        friend vector_nD<W> operator+(vector_nD<W> vec1, vector_nD<W> vec2){
            if(vec1.getsize() != vec2.getsize())return vector_nD<W>();
            W* list = new W[vec1.getsize()];
            for(int i = 0; i < vec1.getsize(); i++){
                list[i] = vec1.getp()[i] + vec2.getp()[i];
            }
            return vector_nD<W>(list, vec1.getsize());
        }
        // overloading subtraction (for vector subtraction).
        template <class W>
        friend vector_nD<W> operator-(vector_nD<W> vec1, vector_nD<W> vec2){
            if(vec1.getsize() != vec2.getsize())return vector_nD<W>();
            W* list = new W[vec1.getsize()];
            for(int i = 0; i < vec1.getsize(); i++){
                list[i] = vec1.getp()[i] - vec2.getp()[i];
            }
            return vector_nD<W>(list, vec1.getsize());
        }
        // overloading scalar mutliplication vector * scalar.
        template <class W, class D>
        friend vector_nD<W> operator*(vector_nD<W> vec1, D scalar){
            W* list = new W[vec1.getsize()];
            for(int i = 0; i < vec1.getsize(); i++){
                list[i] = vec1.getp()[i] * scalar;
            }
            return vector_nD<W>(list, vec1.getsize());
        }
        // overloading scalar mutliplication scalar * vector.
        template <class W, class D>
        friend vector_nD<W> operator*(D scalar, vector_nD<W> vec1){
            W* list = new W[vec1.getsize()];
            for(int i = 0; i < vec1.getsize(); i++){
                list[i] = vec1.getp()[i] * scalar;
            }
            return vector_nD<W>(list, vec1.getsize());
        }
        // dot product of two vectors.
        T dot(vector_nD<T> vec){
            if(vec.getsize() != this->getsize())return numeric_limits<T>::min();
            T dotproduct = 0;
            for(int i = 0; i < vec.getsize(); i++){
                dotproduct += vec.getp()[i] * this->getp()[i];
            }
            return dotproduct;
        }
        // overloading the assignment operator.
        vector_nD<T> operator=(vector_nD<T> vec){
            this->reset(vec.getp(), vec.getsize());
            return *this;
        }
        // overloading the increment by value operator.
        vector_nD<T> operator+=(vector_nD<T> vec){
            *this = *this + vec;
            return *this;
        }
        // overloading the decrement by value operator.
        vector_nD<T> operator-=(vector_nD<T> vec){
            *this = *this - vec;
            return *this;
        }
        // norm/magnitude of a vector.
        T norm(){
            T sum_of_squares = 0;
            for(int i = 0; i < this->getsize(); i++){
                sum_of_squares += this->getp()[i] * this->getp()[i];
            }
            return sqrt(sum_of_squares);
        }
        // unit vector.
        vector_nD<T> unit(){
            T* list = new T[this->getsize()];
            T mag = norm();
            for(int i = 0; i < this->getsize(); i++){
                list[i] = this->getp()[i] / mag;
            }
            return vector_nD<T>(list, this->getsize());
        }
        // direction angle (derived from arccosine of direction cosine).
        T angle(int i){
            return acos(this->getp()[i] / norm());
        }
};
// simplifying float template.
typedef vector_nD<float> vf_nD;