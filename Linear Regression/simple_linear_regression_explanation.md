
# Simple Linear Regression from Scratch

This document explains the implementation of a simple linear regression model from scratch in Python. The approach involves considering all possible lines (combinations of slopes and intercepts), calculating errors for each line, and choosing the line with the minimum error.

## Code Explanation

### 1. **Importing Necessary Libraries**

```python
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
```

- **`pandas`**: Used for loading and handling data from a CSV file.
- **`numpy`**: Used for numerical operations and handling arrays.
- **`matplotlib`**: Used for plotting the original data points and the best-fit line.

### 2. **Function to Calculate Mean Squared Error (MSE)**

```python
def calculate_mse(y_true, y_pred):
    return np.mean((y_true - y_pred) ** 2)
```

- **`calculate_mse`**: This function computes the Mean Squared Error (MSE) between the actual \( y \) values (`y_true`) and the predicted \( y \) values (`y_pred`). The MSE is a common metric used to evaluate the performance of regression models. It calculates the average squared difference between the predicted and actual values.

### 3. **Function to Make Predictions**

```python
def predict(x, beta0, beta1):
    return beta0 + beta1 * x
```

- **`predict`**: This function generates predictions based on the input \( x \), intercept (`beta0`), and slope (`beta1`). The prediction is calculated using the linear equation \( \hat{y} = beta_0 + beta_1 x \).

### 4. **Loading the CSV File**

```python
file_path = 'your_dataset.csv'
df = pd.read_csv(file_path)
```

- **Loading Data**: The `pandas` library is used to read the dataset from a CSV file. The path to the CSV file is specified in `file_path`.

### 5. **Extracting Independent and Dependent Variables**

```python
x = df['feature'].values
y = df['target'].values
```

- **Extracting Columns**: The `x` and `y` variables are extracted from the DataFrame. Replace `'feature'` and `'target'` with the actual column names from your dataset.

### 6. **Generating Possible Slopes and Intercepts**

```python
slopes = np.linspace(-10, 10, 100)
intercepts = np.linspace(-10, 10, 100)
```

- **Range of Slopes and Intercepts**: The code generates a range of possible slopes and intercepts using `np.linspace`. This function creates evenly spaced values over the specified range. Here, we generate 100 possible values for slopes and intercepts ranging from -10 to 10.

### 7. **Finding the Best Line (Brute-Force Search)**

```python
best_mse = float('inf')
best_beta0 = None
best_beta1 = None

for beta1 in slopes:
    for beta0 in intercepts:
        y_pred = predict(x, beta0, beta1)
        mse = calculate_mse(y, y_pred)
        if mse < best_mse:
            best_mse = mse
            best_beta0 = beta0
            best_beta1 = beta1
```

- **Brute-Force Search**: The code performs a brute-force search over all possible combinations of slopes and intercepts. It calculates the MSE for each combination and keeps track of the combination that results in the smallest MSE.

### 8. **Printing and Plotting the Results**

```python
print(f"Best Intercept (beta0): {best_beta0}")
print(f"Best Slope (beta1): {best_beta1}")
print(f"Best MSE: {best_mse}")

y_best_pred = predict(x, best_beta0, best_beta1)

plt.scatter(x, y, color='blue', label='Original Data')
plt.plot(x, y_best_pred, color='red', label='Best Fit Line')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.show()
```

- **Printing Coefficients**: The best-fit slope (`beta1`), intercept (`beta0`), and the corresponding MSE are printed.
- **Plotting**: The original data points are plotted as a scatter plot, and the best-fit line is plotted on top.

## Conclusion

This code provides a manual implementation of linear regression by considering all possible lines and selecting the one that minimizes the error. While this brute-force approach is computationally expensive and not practical for large datasets, it offers a clear understanding of the underlying principles of linear regression.
