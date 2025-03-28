#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <set>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>

// ANSI escape sequence macros for formatting output
#define BOLD(text) "\033[1m" text "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

// ---------------------------------------------------------------------------
// Ford Class
// ---------------------------------------------------------------------------
class Ford {
private:
    std::vector<int> _vseq;
    std::list<int> _lseq;
    // Hidden default constructor
    Ford();

public:
    Ford(const std::vector<int> &nb, const std::list<int> &lnb);
    Ford(const Ford &rhs);
    Ford &operator=(const Ford &rhs);
    ~Ford();

    std::vector<int> getVector(void) const;
    std::list<int> getList(void) const;
};

Ford::Ford() {}

Ford::~Ford() {}

Ford::Ford(const std::vector<int> &nb, const std::list<int> &lnb)
    : _vseq(nb), _lseq(lnb) {}

Ford::Ford(const Ford &rhs) { 
    *this = rhs; 
}

Ford &Ford::operator=(const Ford &rhs) {
    if (this != &rhs) {
        this->_vseq = rhs._vseq;
        this->_lseq = rhs._lseq;
    }
    return *this;
}

std::vector<int> Ford::getVector(void) const { 
    return _vseq; 
}

std::list<int> Ford::getList(void) const { 
    return _lseq; 
}

// Global flag to control printing of the sorted sequence
bool later = true;

// ---------------------------------------------------------------------------
// Sorting Functions (Merge/Insertion Sort)
// ---------------------------------------------------------------------------

// Merge two sorted ranges [first, mid) and [mid, last)
template <typename Iterator>
void merge(Iterator first, Iterator mid, Iterator last) {
    typedef typename std::iterator_traits<Iterator>::value_type T;
    std::vector<T> sortedSeq;
    sortedSeq.reserve(std::distance(first, last));

    Iterator it1 = first;
    Iterator it2 = mid;
    while (it1 != mid && it2 != last) {
        if (*it1 < *it2) {
            sortedSeq.push_back(*it1);
            ++it1;
        } else {
            sortedSeq.push_back(*it2);
            ++it2;
        }
    }
    while (it1 != mid) {
        sortedSeq.push_back(*it1);
        ++it1;
    }
    while (it2 != last) {
        sortedSeq.push_back(*it2);
        ++it2;
    }
    std::copy(sortedSeq.begin(), sortedSeq.end(), first);
}

// Simple insertion sort for small ranges.
template <typename Iterator>
void insertionSort(Iterator first, Iterator last) {
    typedef typename std::iterator_traits<Iterator>::value_type ValueType;
    if (first == last)
        return;
    for (Iterator it = first; it != last; ++it) {
        Iterator current = it;
        Iterator previous = it;
        if (current != first)
            --previous;
        ValueType key = *current;
        while (current != first && *previous > key) {
            *current = *previous;
            current = previous;
            if (previous != first)
                --previous;
        }
        *current = key;
    }
}

// Threshold for switching to insertion sort
const int threshold = 10;

// Recursively sort the range using merge insertion sort.
template <typename Iterator>
void mergeInsertSortRecursively(Iterator first, Iterator last) {
    if (std::distance(first, last) <= 1)
        return;
    if (std::distance(first, last) <= threshold) {
        insertionSort(first, last);
        return;
    }
    Iterator mid = first;
    std::advance(mid, std::distance(first, last) / 2);
    mergeInsertSortRecursively(first, mid);
    mergeInsertSortRecursively(mid, last);
    merge(first, mid, last);
}

// Convenience function to sort an entire container.
template <typename Container>
void mergeInsertSort(Container &seq) {
    mergeInsertSortRecursively(seq.begin(), seq.end());
}

// ---------------------------------------------------------------------------
// Utility Functions
// ---------------------------------------------------------------------------

// Validate and process command-line input; builds a container of positive numbers.
// Throws an exception if a number is non-positive or duplicated.
template <typename Container>
Container validateAndProcessInput(char **input, int &elements) {
    Container numbers;
    std::set<typename Container::value_type> seenNumbers;
    for (int i = 1; i < elements; ++i) {
        int num = std::atoi(input[i]);
        if (num <= 0) {
            throw std::invalid_argument("Number must be positive.");
        }
        if (!seenNumbers.insert(num).second) {
            std::cout << BOLD("Error:") << " Duplicate number detected: " << num << std::endl;
            throw std::invalid_argument("Duplicate number detected.");
        }
        numbers.push_back(num);
    }
    return numbers;
}

// Print each element of the container in blue.
template <typename Container>
void printSequence(const Container &seq) {
    for (typename Container::const_iterator it = seq.begin(); it != seq.end(); ++it) {
        std::cout << BLUE << *it << RESET << " ";
    }
    std::cout << std::endl;
}

// Display the sorted container and timing information.
// The element count is printed in bold, the container name in blue,
// and the processing time in green.
template <typename Container>
void displayTime(Container &seq, const std::string &containerName) {
    clock_t start = clock();
    mergeInsertSort(seq);
    clock_t end = clock();

    if (later) {
        std::cout << BOLD("After sort:") << std::endl;
        printSequence(seq);
        std::cout << std::endl;
    }
    double timeInSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    // Format the element count and time as strings
    std::ostringstream oss;
    oss << seq.size();
    std::string sizeStr = oss.str();
    oss.str("");
    oss.clear();
    oss << (timeInSeconds * 1000.0);
    std::string timeStr = oss.str();

    std::cout << "Time to process a range of " 
              << BOLD(sizeStr)     // Bold for element count
              << " elements with " 
              << BLUE << "std::" << containerName << RESET  // Blue for container name
              << ": " 
              << GREEN << timeStr << RESET   // Green for processing time
              << " ms" << std::endl;
}

// ---------------------------------------------------------------------------
// Main Function
// ---------------------------------------------------------------------------
int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " number1 number2 ..." << std::endl;
        return 1;
    }

    try {
        // Validate input and build containers for numbers
        std::vector<int> vec = validateAndProcessInput< std::vector<int> >(argv, argc);
        std::list<int> lst = validateAndProcessInput< std::list<int> >(argv, argc);

        // Create a Ford instance using the two containers
        Ford ford(vec, lst);

        // Display the unsorted sequences
        std::cout << BOLD("Before sort (vector):") << std::endl;
        printSequence(vec);
        std::cout << BOLD("Before sort (list):") << std::endl;
        printSequence(lst);
        std::cout << std::endl;

        // Sort and display the sorted sequence along with timing info
        displayTime(vec, "vector");
        displayTime(lst, "list");

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
