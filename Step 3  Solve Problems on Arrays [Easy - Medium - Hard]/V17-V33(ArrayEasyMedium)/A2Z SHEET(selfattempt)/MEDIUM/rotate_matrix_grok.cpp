#include <vector>

void rotateMatrix(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    // Process each layer
    for (int layer = 0; layer < n / 2; ++layer) {
        // Iterate over elements in the current layer
        for (int j = layer; j < n - layer - 1; ++j) {
            // Store the top element in temp
            int temp = matrix[layer][j];
            // Move left to top
            matrix[layer][j] = matrix[n - 1 - j][layer];
            // Move bottom to left
            matrix[n - 1 - j][layer] = matrix[n - 1 - layer][n - 1 - j];
            // Move right to bottom
            matrix[n - 1 - layer][n - 1 - j] = matrix[j][n - 1 - layer];
            // Move temp (top) to right
            matrix[j][n - 1 - layer] = temp;
        }
    }
}

// Example usage (for testing):
/*
#include <iostream>

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotateMatrix(matrix);
    // Print the rotated matrix
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
*/