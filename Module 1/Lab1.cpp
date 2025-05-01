#include <iostream>
#include <string>

struct Square{
    int length;
    int width;
public:
    Square(int l, int w){
        length = l;
        width = w;
    }
    void get_info(){
        std::cout << "Length: " << length << ". Width: " << width << "." << std::endl;
    }
    void get_sq(){
        std::cout << "Square of this square is: " << length*width << std::endl;
    }
};

int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    
    return 0;
}