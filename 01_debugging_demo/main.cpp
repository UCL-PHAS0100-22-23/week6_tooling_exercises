#include <iostream>
#include <exception>
#include <memory>
#include <string>

using std::cout, std::end;

class Array2D {
  public:
    Array2D(int n_rows_in, int n_cols_in)
    : n_rows(n_rows_in)
    , n_cols(n_cols_in)
    , total_size(n_rows*n_cols)
    {
      data = std::make_unique<int[]>(total_size);
      setAll(0.0);
    }

    int& get(int i, int j) {
      // Get writable value at i,j
      int idx = i + n_rows*j;
      return data[idx];
    }

    const int& get(int i, int j) const {
      // Get read only value at i,j
      int idx = i + n_rows*j;
      return data[idx];
    }

    void setAll(int val) {
      // Set every element
      for(int i=0; i<n_rows; ++i) {
        for(int j=0; j<n_cols; ++j) {
          get(i,j) = val;
        }
      }
    }

    void increment() {
      // Increment all elements
      for (int i=0; i<n_rows; ++i) {
        for (int j=0; j<n_cols; ++i) {
          get(i, j)+=1;
        }
      }
    }

    int size() const {
      return total_size;
    }

  private:
    int total_size;
    int n_rows;
    int n_cols;
    std::unique_ptr<int[]> data;
};

void test(bool test_value, const std::string msg = "") {
  std::cout << msg << ": " << (test_value ? ":)" : ":(") << std::endl;
}

int main() {
  Array2D arr(10, 5);

  test(arr.get(1, 2) == 0, "Before increment");
  arr.increment();
  test(arr.get(1, 2) == 1, "After increment");

  arr.get(10, 5) = 2.0;
  test(arr.get(10, 5) == 2.0, "Operator test");

  return 0;
}
