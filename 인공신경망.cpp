#include <iostream> 
using namespace std; 
#define MAX2(a, b) (a) > (b) ? (a) : (b) 

class Neuron { 
    public: double w_; //가중치 변수 설정
    double b_; // 편향 변수 설정
    double getActivation(const double& x) 
    { // for linear or identity activation functions 
    return x; // for ReLU activation functions 
              //return MAX2(0.0,x); 
} 
double feedForward(const double& input) 
{ 
    // output y = f(\sigma) 
    // \sigma = w_ * input X + b 
    //for multipl inputs, 
    // \sigma = w0_ * x0_ + w1_ * x1 + ... + b 
    
    const double sigma = w_ * input + b_; 
    return getActivation(sigma); 
    }

}; int main()

{ 
    Neuron my_neuron; 
    my_neuron.w_ = 0.0; 
    my_neuron.b_ = 1.0; 
    std::cout << "Input = 1.0" << my_neuron.feedForward(1.0)<< std::endl; 
    std::cout << "W = 0.0" << my_neuron.feedForward(2.0)<< std::endl;
    std::cout << "output = 1.0" << my_neuron.feedForward(3.0)<< std::endl; 
}

