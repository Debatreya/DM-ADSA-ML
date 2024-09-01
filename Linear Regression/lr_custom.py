import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Function to calculate MSE
def calculate_mse(y_true, y_pred):
    return np.mean((y_true - y_pred) ** 2)

# Function to make predictions
def predict(x, slope, intercept):
    return slope + intercept * x

# Load the CSV file
file_path = './LR.csv'
df = pd.read_csv(file_path)

# CSV file has columns "Income" and "Food Expenditure"
x = df["Income"].values
y = df["Food Expenditure"].values

# Generate a range of possible slopes and intercepts
slopes = np.linspace(-10, 10, 1000) 
intercepts = np.linspace(-10, 10, 1000) 

best_mse = float('inf')
best_slope = None
best_intercept = None

# Iterate over all possible lines
for intercept in slopes:
    for slope in intercepts:
        # Calculate predictions
        y_pred = predict(x, slope, intercept)
        # Calculate the mean squared error
        mse = calculate_mse(y, y_pred)
        # Check if this is the best model so far
        if mse < best_mse:
            best_mse = mse
            best_slope = slope
            best_intercept = intercept

# Print the best coefficients
print(f"Best Intercept (slope): {best_slope}")
print(f"Best Slope (intercept): {best_intercept}")
print(f"Best MSE: {best_mse}")

# Make predictions using the best model
y_best_pred = predict(x, best_slope, best_intercept)

# Plot the results
plt.scatter(x, y, color='blue', label='Original Data')
plt.plot(x, y_best_pred, color='red', label='Best Fit Line')
plt.xlabel('Income')
plt.ylabel('Food Expenditure')
plt.legend()
plt.show()
