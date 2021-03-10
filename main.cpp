#include <iostream>
#include "PGM.h"
#include "ImageProcessing.h"
using namespace std;

int main()
{
    // Path to the file
    // If image is in the same directory as executable
    //string fileName = "lena.pgm";

    // Clion paths if cloned from repo

    //char repeat = 'y';
    //while(repeat == 'y')
    //{
        string fileName = "..\\test_images\\"; // Path name for input file
        string outputName = "..\\processed_images\\"; // Path name for output file
        // Prompt users for input
        string file;
        cout << "Enter Original File: ";
        cin >> file;
        fileName = fileName + file; // Concatenate path to user-entered file name

        //Open File set information
        if (openPGM(fileName)) {
            // Get Image Size Information
            int width = getPGMWidth();
            int height = getPGMHeight();

            // Declare and allocate memory for data
            int **original; // pointer to the original (input) data
            original = new int *[height];
            for (int i = 0; i < height; i++) {
                original[i] = new int[width];
            }

            int **processed;  // pointer to the processed (output) data
            processed = new int *[height];
            for (int i = 0; i < height; i++) {
                processed[i] = new int[width];
            }

            int OprNum; // User-input code (0,1,2,3) for the operation
            string outFile;

            // Continue to prompt for input

            cout << "File Successfully Opened" << endl;
            cout << "Select Operation:" << endl;
            cout << "\t(0) Copy Image" << endl;
            cout << "\t(1) Flip Vertical" << endl;
            cout << "\t(2) Flip Horizontal" << endl;
            cout << "\t(3) Median Filter" << endl;
            cout << "Enter Selection: ";
            cin >> OprNum;
            cout << "Enter Save File Name: ";
            cin >> outFile;
            outputName = outputName + outFile;
            getPGMData(original); // Save data from selected image to original
            switch (OprNum) {
                case 0:
                    processed = copyImage(original, width, height);
                    break;
                case 1:
                    processed = flipVertical(original, width, height);
                    break;
                case 2:
                    processed = flipHorizontal(original, width, height);
                    break;
                default:
                    cout << "Wrong Operation Input" << endl;
                    break;
            }
            cout << "Performing Operation..." << endl;





            // Get the data
            //cout << *(*(processed+5)+7) << endl;
            //cout << width << endl;
            //cout << height << endl;

            cout << "Writing out the File..." << endl;
            // Write back out the same image
            if (!writePGM(outputName, processed)) {
                cout << "Failed to write out file\n";
            }
            cout << "Cleaning up now!" << endl;
            // Clean up memory
            for (int i = 0; i < height; i++) {
                delete[] original[i];
            }
            delete original;

            for (int i = 0; i < height; i++) {
                delete[] processed[i];
            }
            delete processed;
            cout << "Clean-up finished." << endl;
            //cout << "Perform another operation [y/n]?";
            //cin >> repeat;

        } else {
            cout << "Cannot open file " << fileName << endl;
        }
    //}
    // Prompt user input


}
