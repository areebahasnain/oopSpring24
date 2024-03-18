/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Image {
private:
    int width, height;
    int* data;

public:
    Image(int w, int h, int* data) : width(w), height(h){
        this->data = new int[width*height];

        for(int i = 0; i < width*height; i++){
            this->data[i] = data[i];
        }
    }
    
    Image(const Image& obj) : width(obj.width), height(obj.height) {
        this->data = new int[width*height];

        for(int i = 0; i < width*height; i++){
            this->data[i] = obj.data[i];
        }
    }

    ~Image() {
        delete[] data;
    }

    void display() {
        for(int i = 0; i < height; i++){
            for (int j=0; j < width; j++){
                cout << *(data + i*width + j) << "\t";
            }
            cout << endl;
        }
    }

    void updateData() {
        for (int i = 0; i < width*height; i++) {
            if (data[i] > 0) continue;
            data[i] = rand()%255 + 1;
        }
    }
};

int main(){
    srand(time(0));

    int sample[2*3] = {-2, -1, 0, 1, 2, 3};
    Image i1(2,3,sample);
    Image copyImage(i1);

    i1.display();
    cout << endl;
    copyImage.display();
    cout << endl;

    i1.updateData();
    cout << endl;
    copyImage.updateData();
    cout << endl << endl;

    i1.display();
    cout << endl;
    copyImage.display();
    cout << endl;
}
