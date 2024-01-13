#ifndef SDDS_SELECTION_H
#define SDDS_SELECTION_H
namespace sdds {

	/// <summary>
	/// Locates the key within array
	/// </summary>
	/// <typeparam name="arrayType"></typeparam>
	/// <typeparam name="keyType">Must support overload == with primitive types AND const char*</typeparam>
	/// <param name="array"></param>
	/// <param name="key"></param>
	/// <param name="size"></param>
	/// <returns>returns the indices for which the keys are located</returns>
	template <typename arrayType, typename keyType>
    int* select(arrayType array[], keyType key, size_t size) {

        int* newArr = nullptr;
        int matches = 0;
        for (size_t i = 0; i < size; i++) {
            if (array[i] == key) {
                matches++;
            }
        }

        newArr = new int[matches + 1];
        matches = 0;
        for (size_t i = 0; i < size; i++) {
            if (array[i] == key) {
                newArr[matches++] = i;
            }
        }

        newArr[matches++] = -1;
        return newArr;
    }

    /// <summary>
    /// Displays the selected indices in an array as comma seperated value
    /// </summary>
    /// <typeparam name="arrayType"></typeparam>
    /// <param name="title"></param>
    /// <param name="array"></param>
    /// <param name="indices"></param>
    template <typename arrayType>
    void csvDisplaySelection(const char* title, arrayType array[], int* indices) {
        std::cout << title << std::endl;
        if (indices != nullptr) {
            array[indices[0]].display(std::cout);
            int i = 1;
            while (indices[i] != -1) {
                array[indices[i]].display(std::cout << ", ");
                i++;
            }
        }
        else {
            std::cout << "Empty Selection";
        }
        std::cout << std::endl;
    }
}
#endif // !SDDS_SELECTION_H
