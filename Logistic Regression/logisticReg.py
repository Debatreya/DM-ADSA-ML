import pandas as pd
import numpy as np

# Load the CSV file
data = pd.read_csv('./bank/bank.csv', sep=';')

# Initial data head print
print("Initial Data Head:")
print(data.head())

# Convert categorical columns using One Hot Encoding
data = pd.get_dummies(data, drop_first=True)

# Print data after encoding
print("\nData after One Hot Encoding:")
print(data.head())

# Drop rows with 'unknown' values (if there are any)
data = data[(data != 'unknown').all(axis=1)]

# Features array (all columns except the last one)
X = data.iloc[:, :-1].values

# Output array (the last column)
y = data.iloc[:, -1].values
X = np.array(X,dtype=int)

# Print features and output arrays
print("\nFeatures Array (X) Head:")
print(X[:5])
print(f"X shape: {X.shape}")

print("\nOutput Array (y) Head:")
print(y[:5])

# Manually calculate mean and standard deviation across axis 0 (columns)
X_mean = np.mean(X, axis=0)
X_std = np.std(X, axis=0)

print(f"\nMean of X: {X_mean}")
print(f"Standard Deviation of X: {X_std}")

# Check if X_std has any zero values to prevent division by zero
X_std[X_std == 0] = 1

# Normalize the features
X = (X - X_mean) / X_std

print("\nNormalized Features Array (X) Head:")
print(X[:5])

class LogisticRegressionManual:
    def __init__(self, learning_rate=0.001, iterations=1000):
        self.learning_rate = learning_rate
        self.iterations = iterations
    
    def sigmoid(self, z):
        z = np.clip(z, -500, 500)  # Clip to avoid overflow
        return 1 / (1 + np.exp(-z))
    
    def fit(self, X, y):
        self.m, self.n = X.shape
        self.W = np.zeros(self.n)
        self.b = 0
        self.X = X
        self.y = y
        
        for i in range(self.iterations):
            # Linear model
            z = np.dot(self.X, self.W) + self.b
            # Sigmoid function
            y_pred = self.sigmoid(z)
            
            # Gradient descent
            dW = (1/self.m) * np.dot(self.X.T, (y_pred - self.y))
            db = (1/self.m) * np.sum(y_pred - self.y)
            
            # Update weights
            self.W -= self.learning_rate * dW
            self.b -= self.learning_rate * db
            
            # Debugging prints for first few iterations
            if i < 5:
                print(f"Iteration {i+1}: Weight vector W:")
                print(self.W)
                print(f"Bias b: {self.b}")
    
    def predict(self, X):
        z = np.dot(X, self.W) + self.b
        y_pred = self.sigmoid(z)
        y_pred_class = [1 if i > 0.5 else 0 for i in y_pred]
        return y_pred_class

split_ratio = 0.7
split_index = int(split_ratio * len(X))

X_train, X_test = X[:split_index], X[split_index:]
y_train, y_test = y[:split_index], y[split_index:]

model = LogisticRegressionManual(learning_rate=0.001, iterations=1000)
model.fit(X_train, y_train)

y_pred = model.predict(X_test)

print("\nPredicted vs Actual:")
print("Predicted:", y_pred[:10])
print("Actual:   ", y_test[:10])

accuracy = np.sum(y_pred == y_test) / len(y_test)
print(f"\nModel accuracy: {accuracy * 100:.2f}%")
