#include "../Chapter 1_Vectors/vector_nD.hpp"
int main(){
    // creating an array of five floating point numbers.
    float list[5] = {2.34, 5.64, 6.77, 2.33, 7.45};
    // creating an array of six floating point numbers.
    float list2[6] = {1.1, 2.22, 3.333, 4.4444, 5.55555, 6.666666};
    // initializing two vectors with dimension 5 from the above two arrays.
    vector_nD<float> vef(list, 5), vef2(list2, 5);
    cout << vef << endl; // displaying vec1.
    cout << vef2 << endl; // displaying vec2.
    cout << vef + vef2 << endl; // displaying vec1 + vec2.
    vef += vef2; // incrementing vec1 by vec2.
    cout << vef << endl; // displaying vec1.
    cout << vef - vef2 << endl; // displaying vec1 - vec2.
    cout << vef * 2.5 << endl; // displaying vec1 * 2.5.
    cout << 'n' * vef2 << endl; // displaying 'n' * vef2.
    cout << vef.norm() << endl; // displaying the norm of vec1.
    cout << vef.unit() << endl; // displaying the unit vector in the direction of vec1.
    cout << vef.dot(vef2) << endl; // displaying the dot product of vec1 and vec2.
    cout << vef.angle(1) << endl; // displaying the direction angle of vec1 according to the second component.
    cout << vef.angle(0) << endl; // dipsplaying the direction angle of vec1 according to the first component.
}