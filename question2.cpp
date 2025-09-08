#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Define the Rectangle struct
struct Rectangle {
    double width;
    double height; 
    double thickness;
    double density;
    char material[100];
};

// Output function to print plate details
void print_plate(int index, double width, double height,
                 double density, double mass, const char* material) {
    cout << "Plate[" << index << "]: "
         << "width=" << width << ", "
         << "height=" << height << ", "
         << "density=" << density << ", "
         << "mass=" << mass << ", "
         << "material=" << material << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    int num_plates;
    input >> num_plates;
    input.ignore(); // skip newline after number

    const int MAX_PLATES = 10;

    // Create an array of Rectangle structs
    Rectangle plates[MAX_PLATES];

    // Read plate data from input
    for (int i = 0; i < num_plates; i++) {
        input >> plates[i].width;
        input >> plates[i].height;
        input >> plates[i].thickness;
        input >> plates[i].density;
        input.ignore();  // Skip the newline after density
        input.getline(plates[i].material, 100);  // Read the material name
    }

    // Compute mass for each plate and call print_plate
    for (int i = 0; i < num_plates; i++) {
        // Calculate mass: mass = width * height * thickness * density
        double mass = plates[i].width * plates[i].height * plates[i].thickness * plates[i].density;
        print_plate(i, plates[i].width, plates[i].height, plates[i].density, mass, plates[i].material);
    }

    return 0;
}
